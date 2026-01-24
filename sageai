# Technical Architecture Review: cf-sage-ai-backend

> **Review Date**: 2026-01-24
> **Reviewer**: Staff Software Engineer (External Review)
> **Scope**: Architecture, reliability, scalability, and failure mode analysis

---

## Executive Summary

This is a **multi-tenant real-time AI customer support platform** built in Go, integrating LiveKit (WebRTC) for real-time communication, Flowise AI for workflow orchestration, and a React dashboard for operator tooling. The architecture follows clean layered patterns with strong tenant isolation, but has notable gaps in reliability primitives (retry logic, circuit breakers, delivery guarantees).

---

## Table of Contents

1. [High-Level Architecture](#1-high-level-architecture)
2. [Real-Time Chat Deep Dive](#2-real-time-chat-deep-dive)
3. [Server-Driven Conversation State](#3-server-driven-conversation-state)
4. [AI Workflow Analysis (Flowise)](#4-ai-workflow-analysis-flowise)
5. [WebRTC/LiveKit Analysis](#5-webrtclivekit-analysis)
6. [Web Dashboard Analysis](#6-web-dashboard-analysis)
7. [Failure Mode Table](#7-failure-mode-table)
8. [Scalability Analysis](#8-scalability-analysis)
9. [Interview Questions for Validation](#9-interview-questions-for-validation)
10. [Missing Documentation](#10-missing-documentation--design-artifacts)

---

## 1. High-Level Architecture

```
┌─────────────────────────────────────────────────────────────────────────────────┐
│                              SYSTEM BOUNDARIES                                   │
├─────────────────────────────────────────────────────────────────────────────────┤
│                                                                                  │
│  ┌─────────────┐        ┌──────────────────────────────────────────────────┐   │
│  │  Mobile SDK │◄──────►│              LIVEKIT CLOUD                        │   │
│  │  (iOS/And)  │  WSS   │  ┌─────────────────────────────────────────────┐  │   │
│  └─────────────┘        │  │ Signaling + TURN/STUN + Media Routing (SFU) │  │   │
│        │                │  └─────────────────────────────────────────────┘  │   │
│        │ HTTPS          └───────────────────────┬──────────────────────────┘   │
│        │ (/init)                                │                               │
│        ▼                                        │ Webhooks                      │
│  ┌───────────────────────────────────────────────────────────────────────────┐ │
│  │                         CHAT GATEWAY (Go/Gin)                              │ │
│  │  ┌─────────────┐  ┌──────────────┐  ┌─────────────┐  ┌────────────────┐  │ │
│  │  │ Init Handler│  │Webhook Handler│  │ Dashboard   │  │ Server-to-Server│ │ │
│  │  │ /api/v1/init│  │/livekit/webhook│ │ /dashboard/*│  │ /server/*      │  │ │
│  │  └──────┬──────┘  └───────┬───────┘  └──────┬──────┘  └───────┬────────┘  │ │
│  │         │                 │                  │                 │           │ │
│  │         ▼                 ▼                  ▼                 ▼           │ │
│  │  ┌───────────────────────────────────────────────────────────────────┐    │ │
│  │  │                      SERVICE LAYER                                 │    │ │
│  │  │  ┌─────────────────┐  ┌────────────┐  ┌──────────────────────┐   │    │ │
│  │  │  │AgentOrchestrator│  │FlowService │  │ResponseProcessor      │   │    │ │
│  │  │  │ (per-room agent)│  │(Flowise)   │  │(Widget/Text/Batch)   │   │    │ │
│  │  │  └────────┬────────┘  └─────┬──────┘  └──────────────────────┘   │    │ │
│  │  │           │                 │                                     │    │ │
│  │  │  ┌────────┴─────────────────┴──────────────────────────────┐     │    │ │
│  │  │  │ LiveKitService │ AssignmentService │ NotificationService │    │    │ │
│  │  │  └───────────────────────────────────────────────────────────┘   │    │ │
│  │  └───────────────────────────────────────────────────────────────────┘    │ │
│  └───────────────────────────────────────────────────────────────────────────┘ │
│        │                                                          │             │
│        ▼                                                          ▼             │
│  ┌─────────────────┐                                    ┌──────────────────┐   │
│  │  PERSISTENCE    │                                    │ THIRD-PARTY AI    │   │
│  │  ┌───────────┐  │                                    │  ┌────────────┐   │   │
│  │  │PostgreSQL │  │                                    │  │ Flowise    │   │   │
│  │  │ (GORM)    │  │                                    │  │ (n8n-like) │   │   │
│  │  └───────────┘  │                                    │  └────────────┘   │   │
│  │  ┌───────────┐  │                                    │  ┌────────────┐   │   │
│  │  │ Valkey/   │  │                                    │  │ LLM APIs   │   │   │
│  │  │ Redis     │  │                                    │  │ (via Flow) │   │   │
│  │  └───────────┘  │                                    │  └────────────┘   │   │
│  └─────────────────┘                                    └──────────────────┘   │
│                                                                                  │
│  ┌───────────────────────────────────────────────────────────────────────────┐ │
│  │                    ADMIN DASHBOARD (React/Vite)                            │ │
│  │  ┌─────────┐  ┌──────────┐  ┌──────────┐  ┌─────────┐  ┌──────────────┐  │ │
│  │  │ Inbox   │  │ Analytics│  │ Widgets  │  │ Teams   │  │ SSE Streams  │  │ │
│  │  └─────────┘  └──────────┘  └──────────┘  └─────────┘  └──────────────┘  │ │
│  └───────────────────────────────────────────────────────────────────────────┘ │
│                                                                                  │
│  ┌───────────────────────────────────────────────────────────────────────────┐ │
│  │                         OBSERVABILITY (Partial)                            │ │
│  │     Sentry (errors) │ Zap (structured logs) │ CloudWatch (ECS logs)       │ │
│  └───────────────────────────────────────────────────────────────────────────┘ │
└─────────────────────────────────────────────────────────────────────────────────┘
```

### Component Boundaries

| Boundary | Owner | Protocol | Notes |
|----------|-------|----------|-------|
| **SDK Client ↔ Gateway** | Mobile teams | HTTPS (`/init`) | Returns LiveKit token |
| **SDK Client ↔ LiveKit** | LiveKit/Mobile | WebSocket (WSS) | Real-time chat data |
| **Gateway ↔ LiveKit** | Backend | HTTPS webhooks + SDK | Room mgmt, webhooks |
| **Gateway ↔ Flowise** | Backend | REST (HTTP) | Flow execution, 60s timeout |
| **Gateway ↔ Persistence** | Backend | TCP (pg) / TCP (redis) | Tenant-isolated |
| **Dashboard ↔ Gateway** | Frontend | REST + SSE | Bearer auth |
| **Flowise ↔ LLM** | Flowise | Varies | OpenAI, Claude, etc. |
| **Gateway ↔ Cityflo Backend** | Backend | REST webhooks | Ticket sync |

### Key Files by Boundary

- **SDK entry point**: `internal/handler/init_handler.go` (438 lines)
- **Chat gateway core**: `internal/service/agent_orchestrator.go` (2265 lines)
- **Workflow orchestration**: `internal/service/flow_service.go`, `pkg/flowise/flowise.go`
- **Persistence**: `internal/repository/`, `pkg/database/database.go`, `pkg/redis/redis.go`
- **Dashboard API**: `internal/handler/dashboard_*.go`, `internal/handler/inbox_handler.go`
- **Observability**: `pkg/logger/logger.go`, Sentry init in `cmd/api/main.go`

---

## 2. Real-Time Chat Deep Dive

### 2.1 Connection Lifecycle

```
Mobile App                    Gateway                    LiveKit
│                            │                          │
│──POST /init───────────────►│                          │
│  {user_id, conversation_id}│                          │
│                            │──CreateRoom──────────────►│
│                            │◄──room_sid───────────────│
│                            │                          │
│◄───{token, room_id}────────│                          │
│                            │                          │
│──Connect(token)───────────────────────────────────────►│
│                            │◄──room_started webhook───│
│                            │                          │
│                            │──Start AI Agent──────────►│ (joins as participant)
│                            │                          │
│◄─────────────────────participant_joined────────────────│
│                            │                          │
│──SendData({msg})──────────────────────────────────────►│
│                            │◄──data_packet (via SDK)──│
│                            │                          │
│                            │  [Process via Flowise]   │
│                            │                          │
│◄───────────────────────────data_packet (response)──────│
│                            │                          │
│──Disconnect────────────────────────────────────────────►│
│                            │◄──participant_left───────│
│                            │                          │
│                            │◄──room_finished (5m)─────│
```

**Authentication**:
- Mobile obtains JWT from `/init` using `X-API-Key` (tenant-scoped)
- Token encodes: identity (`customer_{user_id}`), room permissions, 24h TTL
- Human agents get `human_agent_{user_id}_{timestamp}` identity

**Session Creation** (`internal/handler/init_handler.go:84-200`):
- Creates or retrieves `Conversation` record
- Generates unique room name: `tenant_{tenant_id}_conv_{conversation_id}`
- LiveKit room created with 5-minute empty timeout, 10 max participants

**Reconnect Handling** (`internal/service/agent_orchestrator.go:800-850`):
- LiveKit SDK handles transport reconnection automatically
- `OnReconnecting` / `OnReconnected` callbacks log state
- Agent state persisted in Redis for cross-instance recovery
- `RecoverAgents()` runs 5s after startup, reconnects orphaned rooms

**Presence**:
- `participant_joined` / `participant_left` webhooks track presence
- `Customer.Online` boolean stored in conversation record
- No heartbeat from mobile—relies entirely on LiveKit events

**Gap**: No explicit session resume with message replay after network loss. Client rejoins but may miss messages sent during disconnection.

### 2.2 Message Delivery Semantics

**Current Implementation: At-Most-Once (with caveats)**

```go
// internal/service/agent_orchestrator.go:1200
err := localParticipant.PublishDataPacket(
packet,
lksdk.WithDataPublishReliable(true), // Uses SCTP reliable channel
)
```

**Analysis**:

| Guarantee | Status | Evidence |
|-----------|--------|----------|
| **At-most-once** | ✅ Achievable | No explicit retry on send failure |
| **At-least-once** | ❌ Not implemented | No ack/retry, no dead-letter queue |
| **Exactly-once** | ❌ Not implemented | No idempotency keys, no dedup at receiver |

**Why exactly-once is hard here**:
1. LiveKit data channels are fire-and-forget at app layer
2. No message sequence numbers in protocol
3. No server-side message queue with delivery tracking
4. Client-side deduplication relies on `message.id` (UUID), but retries would generate new UUIDs

**Realistic Target**: **At-least-once with idempotency**
- Add client-side message ID before send
- Server stores ID in Redis with TTL
- On receive, deduplicate by ID
- Retry with exponential backoff on send failure

**Current Deduplication** (`agent_orchestrator.go:600-650`):
```go
// SHA256(content + sender + timestamp_rounded_to_second)
// Stored in sync.Map with 1-minute TTL goroutine cleanup
```
This catches rapid duplicates but not cross-reconnect retries.

### 2.3 Ordering Guarantees

**Per-Conversation Ordering**: Partial

- LiveKit data channels (SCTP) provide **ordered delivery** within a single connection
- Agent processes messages through single-buffered channel (100 capacity) per room
- Messages processed sequentially in `processMessages()` goroutine
- **However**: No sequence numbers persisted to DB; ordering relies on `CreatedAt` timestamps

**Risk**: Race condition if human agent and AI agent both respond simultaneously. Both publish to same room; client receives in transport order, not logical order.

**Global Ordering**: Not applicable (conversations isolated)

**Causal Ordering**: Not implemented
- No vector clocks or Lamport timestamps
- Widget clicks don't carry "in response to message X" metadata

**Batch Ordering** (`agent_orchestrator.go:1350`):
```go
for i, msg := range messages {
// Send each message
if i < len(messages)-1 {
    time.Sleep(100 * time.Millisecond) // Artificial delay for ordering
}
}
```

### 2.4 Backpressure & Rate Limiting

**Server-Side**:
- Message channel: 100-buffer per agent (`make(chan IncomingMessage, 100)`)
- No explicit rate limiting middleware visible in code
- Flowise calls have 60s timeout (implicit backpressure)

**Client-Side**:
- Not controlled by backend; depends on SDK implementation
- No documented message rate limits in API

**Recommendations**:
1. Add token bucket rate limiter per tenant (`pkg/ratelimit/` exists but not wired to chat)
2. Implement circuit breaker for Flowise calls
3. Add queue depth metrics to detect overload

### 2.5 Idempotency Design

**Current State**: Minimal

| Operation | Idempotent? | Mechanism |
|-----------|-------------|-----------|
| Room creation | ✅ Yes | `GetOrCreateRoom()` checks existence first |
| Agent startup | ✅ Yes | Redis `SetNX` distributed lock |
| Message send | ❌ No | Each publish creates new message |
| Widget click | ❌ No | Metadata updated every time |
| Assignment create | ❌ No | No unique constraint check |

**Recommended Idempotency Pattern**:
```go
// Client sends: {idempotency_key: "uuid-from-client", content: "..."}
// Server:
if exists := redis.SetNX(ctx, "idempotency:"+key, 1, 24*time.Hour); !exists {
return cachedResponse
}
// Process and cache response
```

---

## 3. Server-Driven Conversation State

### 3.1 State Machine vs Event Sourcing vs Snapshotting

**Current Approach: Hybrid (Mutable State + Event Log)**

The system uses **mutable state in PostgreSQL** with implicit event logging:

```go
// internal/models/conversation.go - Mutable state
type Conversation struct {
Status           string    // open, in_progress, resolved, closed, escalated
Priority         int
AssignedToID     *string
HumanAgentTakeover bool
Metadata         JSONB     // Accumulated widget selections, flow context
// 18 timestamps track state transitions implicitly
}
```

**State Machine** (implicit in code):
```
                ┌─────────────────┐
                │     OPEN        │
                └────────┬────────┘
                            │ agent accepts / AI responds
                ┌────────▼────────┐
                │   IN_PROGRESS   │◄──────────┐
                └────────┬────────┘           │
        AI resolves │       │ escalate           │ reopen
                    │  ┌────▼────────┐           │
                    │  │  ESCALATED  │───────────┤
                    │  └─────────────┘           │
            ┌────▼────────┐                   │
            │  RESOLVED   │───────────────────┘
            └────┬────────┘
                    │ final close
            ┌────▼────────┐
            │   CLOSED    │
            └─────────────┘
```

**Event Sourcing Elements**:
- `Message` table acts as append-only event log
- `ConversationChange` table (`internal/models/ticket_context.go`) tracks field-level changes
- `ConversationAssignment` tracks assignment workflow events

**Snapshotting Elements**:
- `Conversation.Metadata` JSONB stores accumulated state snapshot
- No periodic snapshots; metadata mutated in place
- Redis stores agent runtime state for recovery

### 3.2 Where State Lives and Why

| State Type | Location | Why |
|------------|----------|-----|
| Conversation record | PostgreSQL | Durability, querying, multi-instance |
| Message history | PostgreSQL | Compliance, search, analytics |
| Assignment workflow | PostgreSQL | Audit trail, SLA tracking |
| Active flow context | `Conversation.Metadata` JSONB | Avoid separate table, flexible schema |
| Flowise session ID | `Conversation.FlowiseSessionID` | Quick lookup, separate from metadata |
| Agent connection state | Redis | Fast access, distributed lock, ephemeral |
| Message dedup hashes | In-memory `sync.Map` | Per-instance, short-lived |
| Widget selections | `Conversation.Metadata` | Persist across messages |

### 3.3 Tool Calls / Workflow Steps: Determinism & Replayability

**Current Flowise Integration**:

Flowise handles all workflow execution server-side. The backend:
1. Sends user message + `startState` (accumulated metadata)
2. Receives response (text/widget/flags)
3. Updates conversation metadata from response
4. No explicit tool call logging in backend

**Determinism Concerns**:

| Aspect | Status | Issue |
|--------|--------|-------|
| Same input → same output | ❌ No | LLM responses non-deterministic |
| Retry produces same state | ⚠️ Partial | Metadata updates may diverge |
| Workflow step logging | ❌ No | Only final response persisted |

**Replayability**:
- Messages stored with content, enabling manual replay
- No `startState` persisted per message—lost context
- `ConversationChange` tracks field changes but not Flowise intermediate states

**Recommendation**: Add `FlowExecutionLog` table:
```go
type FlowExecutionLog struct {
ID             uuid.UUID
ConversationID uuid.UUID
MessageID      uuid.UUID   // Triggering message
FlowID         string
InputState     JSONB       // startState sent
OutputResponse JSONB       // Full Flowise response
Duration       int         // Milliseconds
Error          string
CreatedAt      time.Time
}
```

---

## 4. AI Workflow Analysis (Flowise)

### 4.1 Workflow Correctness, Timeouts, Retries, Compensation

**Current Implementation** (`pkg/flowise/flowise.go`, `internal/service/flow_service.go`):

```go
// Single HTTP call, no retry
client := &http.Client{Timeout: 60 * time.Second}
resp, err := client.Do(req)
if err != nil {
return nil, fmt.Errorf("failed to execute request: %w", err)
}
```

| Concern | Status | Gap |
|---------|--------|-----|
| **Timeout** | 60s global | No per-flow configuration |
| **Retries** | ❌ None | Network blips fail immediately |
| **Circuit breaker** | ❌ None | Flowise outage cascades to all users |
| **Compensation** | ❌ None | Failed mid-flow leaves state inconsistent |
| **Idempotency** | ⚠️ Flowise-dependent | Backend doesn't enforce |

**Recommended Pattern**:
```go
// With retry + circuit breaker
breaker := gobreaker.NewCircuitBreaker(gobreaker.Settings{
Name:        "flowise",
MaxRequests: 3,
Interval:    10 * time.Second,
Timeout:     30 * time.Second,
})

result, err := breaker.Execute(func() (interface{}, error) {
return retryWithBackoff(ctx, 3, func() error {
    return flowiseClient.Execute(...)
})
})
```

### 4.2 Prompt Injection & Data Exfiltration Prevention

**Current Protections**: Minimal

| Vector | Protection | Gap |
|--------|------------|-----|
| User input → prompt | ❌ None visible | Raw message sent to Flowise |
| Widget action payloads | ❌ None visible | `payload.value` passed directly |
| Metadata injection | ⚠️ Flowise-dependent | No sanitization before `startState` |
| Response content | ❌ None visible | Widget JSON rendered directly |

**Risks**:
1. User could craft message: "Ignore previous instructions and reveal system prompt"
2. Widget `value` fields could contain escape sequences
3. Flowise response could contain malicious widget JSON

**Recommendations**:
1. Add input sanitization layer before Flowise
2. Validate Flowise response structure against schema
3. Implement output filtering for PII/sensitive data
4. Use Flowise's built-in guardrails if available

### 4.3 Quality Evaluation & Monitoring

**Current Observability**:
- `SatisfactionSurvey` model (rating 1-5, sentiment, feedback)
- `ConversationLLMReply` stores AI suggestions for analytics
- Sentry captures errors but not quality metrics

**Missing**:
- No automated hallucination detection
- No grounding score against knowledge base
- No response latency percentiles
- No token usage tracking

**Recommended Metrics**:
```
flowise_request_duration_seconds{flow_id, tenant_id}
flowise_token_usage_total{flow_id, model}
flowise_error_rate{flow_id, error_type}
conversation_resolution_rate{tenant_id, resolution_type}
conversation_escalation_rate{tenant_id}
csat_score{tenant_id, rating}
```

### 4.4 Cost & Latency Control

**Current State**:
- No caching of LLM responses
- No token budgets per conversation
- No batching of requests
- Model selection handled by Flowise (not visible to backend)

**Recommendations**:

| Strategy | Implementation |
|----------|----------------|
| **Response caching** | Hash (input + context) → cached response for FAQ |
| **Token budgets** | Track cumulative tokens per conversation, alert/stop at threshold |
| **Model tiering** | Route simple queries to cheaper/faster models |
| **Batching** | Not applicable (real-time chat) |
| **Timeout tiers** | Short timeout for simple greetings, long for complex flows |

---

## 5. WebRTC/LiveKit Analysis

### 5.1 Architecture Components

```
┌─────────────────────────────────────────────────────────────────┐
│                         LIVEKIT SERVER                          │
├─────────────────────────────────────────────────────────────────┤
│                                                                  │
│  ┌─────────────────┐  ┌─────────────────┐  ┌─────────────────┐ │
│  │   SIGNALING     │  │   TURN/STUN     │  │   MEDIA (SFU)   │ │
│  │                 │  │                 │  │                 │ │
│  │  - Room mgmt    │  │  - NAT traversal│  │  - Audio/video  │ │
│  │  - Participant  │  │  - ICE          │  │  - Data channels│ │
│  │  - Token auth   │  │  - Relay        │  │  - Simulcast    │ │
│  └─────────────────┘  └─────────────────┘  └─────────────────┘ │
│           ▲                                        ▲            │
│           │ WebSocket (wss://)                     │            │
│           │                                        │            │
│  ┌────────┴─────────────────────────────────────────┴────────┐ │
│  │                     WebRTC Connection                      │ │
│  │  - DTLS for encryption                                     │ │
│  │  - SCTP for reliable data (chat messages)                 │ │
│  │  - RTP for media (not used in this system)                │ │
│  └──────────────────────────────────────────────────────────┘ │
└─────────────────────────────────────────────────────────────────┘
```

**This System Uses**:
- ✅ Signaling (room creation, participant management)
- ✅ Data channels (chat messages via SCTP)
- ✅ Token-based auth
- ❓ TURN (depends on deployment config)
- ❌ Media routing (no audio/video in current implementation)

### 5.2 Authentication/Authorization Model

**Token Generation** (`internal/service/livekit_service.go:150-250`):

```go
token := auth.NewAccessToken(apiKey, apiSecret)
token.AddGrant(&auth.VideoGrant{
RoomJoin: true,
Room:     roomName,
CanPublish: true,
CanSubscribe: true,
CanPublishData: true,
})
token.SetIdentity(identity)  // "customer_{id}" or "agent_{tenant}_{ts}"
token.SetValidFor(24 * time.Hour)
```

**Authorization Matrix**:

| Participant | Permissions | Enforced By |
|-------------|-------------|-------------|
| Customer | publish, subscribe, publishData | Token grant |
| AI Agent | publish, subscribe, publishData, RoomAdmin | Token grant |
| Human Agent | publish, subscribe, publishData, RoomAdmin | Token grant |

**Webhook Verification** (`internal/handler/webhook_handler.go:50-100`):
```go
// Verify signature using tenant-specific LiveKit credentials
keyProvider := auth.NewSimpleKeyProvider(apiKey, apiSecret)
event, err := webhook.ReceiveWebhookEvent(req, keyProvider)
```

### 5.3 Network Edge Cases

| Scenario | LiveKit Behavior | Backend Should |
|----------|------------------|----------------|
| **NAT traversal** | STUN first, TURN fallback | Ensure TURN server configured |
| **Mobile backgrounding** | Connection paused/dropped | Handle `participant_left`, agent waits |
| **Network switch** | ICE restart, reconnection | Log `OnReconnecting`/`OnReconnected` |
| **Firewall blocking UDP** | Falls back to TCP TURN | Monitor connection quality metrics |
| **Prolonged disconnect** | Room empty timeout (5m) | Agent disconnects, state persisted |

**Current Handling** (`agent_orchestrator.go`):
- `OnDisconnected`: Logs warning, cleans up agent state
- `OnReconnecting`/`OnReconnected`: Logs only
- Room timeout: 300s (5 minutes) empty timeout

**Gaps**:
- No message queue for offline delivery
- No explicit handling of degraded connection quality
- No client-side message buffering strategy documented

---

## 6. Web Dashboard Analysis

### 6.1 Core Operator Workflows

Based on `dashboard/src/pages/` and `dashboard/src/lib/api.ts`:

**1. Inbox Management** (`inbox.tsx`)
- View: my assignments, queue (unassigned), all, watched
- Filter: status, city, category, reply status
- Actions: accept, decline, transfer assignment
- Real-time: SSE for new conversations

**2. Conversation Handling** (`conversation-detail.tsx`)
- Send messages via LiveKit WebSocket
- Internal notes (marked visually, not sent to customer)
- Quick response templates (6 pre-defined)
- Status transitions: open → in_progress → resolved → closed
- Customer context panels (profile, past tickets, ride info)

**3. Team Management** (`support-teams.tsx`, `team.tsx`)
- CRUD teams with routing strategies
- Assign members, set skills and capacity
- SLA configuration per team
- Working hours with timezone

**4. Widget Editor** (`widget-editor.tsx`)
- JSON template editing with CodeMirror
- Variable extraction (`{{ var }}` syntax)
- Version history
- Preview rendering

**5. Analytics** (`ai-agent-analytics.tsx`)
- Resolution rate, escalation rate
- CSAT distribution
- Weekly trends (charts)
- Funnel: AI involved → Resolved → Escalated

### 6.2 Minimal Domain Model (Frontend)

```typescript
// Core entities (from dashboard/src/lib/types.ts)
interface Conversation {
id: string;
ticket_number: number;
status: 'open' | 'in_progress' | 'resolved' | 'closed' | 'escalated';
customer_name: string;
customer_online: boolean;
livekit_room_id: string;
assigned_to_user_id?: string;
metadata: Record<string, any>;
}

interface Message {
id: string;
type: 'text' | 'widget' | 'note';
content: string;
sender_type: 'customer' | 'ai_agent' | 'human_agent' | 'system';
is_internal: boolean;
}

interface Assignment {
id: string;
conversation_id: string;
assigned_to_user_id: string;
status: 'pending' | 'accepted' | 'declined' | 'completed';
sla_deadline?: string;
}

interface Team {
id: string;
name: string;
settings: TeamSettings;
}
```

### 6.3 Audit Logging Recommendations

**Current State**:
- `ConversationChange` table tracks field changes
- No API-level audit log
- No user action logging

**Recommended Implementation**:

```go
// internal/models/audit_log.go
type AuditLog struct {
ID          uuid.UUID
TenantID    string
ActorID     string       // PlatformUser.ID
ActorType   string       // "user", "system", "api_key"
Action      string       // "conversation.status.updated"
ResourceType string      // "conversation", "assignment", "team"
ResourceID  string
OldValue    JSONB
NewValue    JSONB
IPAddress   string
UserAgent   string
CreatedAt   time.Time
}
```

**Key Actions to Audit**:
- Assignment accept/decline/transfer
- Conversation status changes
- Team membership changes
- API key creation/revocation
- Settings modifications
- Widget publish

### 6.4 RBAC Recommendations

**Current Roles** (`internal/models/api_key.go`):
- ADMIN, DEVELOPER, HUMAN_AGENT, VIEWER

**Recommended Permission Matrix**:

| Permission | ADMIN | DEVELOPER | HUMAN_AGENT | VIEWER |
|------------|-------|-----------|-------------|--------|
| View conversations | ✅ | ✅ | ✅ (assigned) | ✅ |
| Send messages | ✅ | ❌ | ✅ | ❌ |
| Change status | ✅ | ❌ | ✅ | ❌ |
| Manage assignments | ✅ | ❌ | ✅ (own) | ❌ |
| Manage teams | ✅ | ❌ | ❌ | ❌ |
| Manage widgets | ✅ | ✅ | ❌ | ❌ |
| View analytics | ✅ | ✅ | ❌ | ✅ |
| Manage API keys | ✅ | ✅ | ❌ | ❌ |
| Manage settings | ✅ | ❌ | ❌ | ❌ |

---

## 7. Failure Mode Table

| Component | Failure | User Impact | Mitigation | Detection | Recovery |
|-----------|---------|-------------|------------|-----------|----------|
| **PostgreSQL** | Connection lost | All operations fail | Connection pool retry, read replica | `db.Health()` check, Sentry | Restart, failover to replica |
| **PostgreSQL** | Slow queries | Dashboard timeouts | Query optimization, indexes | Query duration logs, p95 metrics | Add indexes, EXPLAIN ANALYZE |
| **Redis/Valkey** | Connection lost | Agent state lost, locks fail | Redis Sentinel/Cluster | `redis.Health()` check | Reconnect, recreate locks |
| **Redis** | Memory exhausted | Cache evictions, OOM | Maxmemory policy, TTLs | Memory usage metrics | Increase capacity, audit keys |
| **LiveKit** | Server down | No real-time chat | Multi-region, fallback polling | Webhook failures, connection errors | Switch region, notify users |
| **LiveKit** | Webhook delivery fails | Agent not started | Retry queue, manual trigger | Missing `room_started` events | Idempotent `/init` retry |
| **LiveKit** | Data channel drop | Messages lost | Client retry, message queue | Connection state monitoring | Reconnect, replay from DB |
| **Flowise** | Timeout (>60s) | User gets error message | Increase timeout, cache responses | Request duration metrics | Retry, fallback response |
| **Flowise** | API error | AI response fails | Fallback to human escalation | HTTP 5xx, error logs | Circuit breaker, retry |
| **Flowise** | Bad response format | Widget render fails | Schema validation | JSON parse errors | Default error widget |
| **Agent Orchestrator** | Goroutine panic | Room messages stop | `recover()` in goroutine | Panic logs in Sentry | Health check restarts agent |
| **Agent Orchestrator** | Message channel full | Backpressure, drops | Increase buffer, rate limit | Channel length metrics | Scale horizontally |
| **ECS Instance** | Crash/restart | Agents disconnected | Multi-instance, Redis state | ECS health checks | `RecoverAgents()` on startup |
| **Network** | Mobile → LK partition | User sees "connecting" | LiveKit handles reconnect | Connection state on client | ICE restart, TURN fallback |
| **Network** | Gateway → Flowise partition | AI unresponsive | Circuit breaker opens | Consecutive failures | Retry after cooldown |
| **Auth** | Token expired | 401 errors | Refresh flow, re-auth | 401 response rate | Client redirects to login |
| **Auth** | API key revoked | Tenant locked out | Grace period, notify | API key usage logs | Re-issue key |
| **SSE Stream** | Connection drop | Dashboard stale | Client reconnect with backoff | Stream error events | Exponential backoff, poll fallback |

---

## 8. Scalability Analysis

### 8.1 Main Bottlenecks

| Resource | Bottleneck | Current Limit | Scaling Strategy |
|----------|------------|---------------|------------------|
| **CPU** | Flowise response processing | Single goroutine per room | Horizontal (more ECS tasks) |
| **Memory** | Agent state (`sync.Map`), dedup hashes | ~1KB per active room | Stateless via Redis |
| **DB Connections** | GORM pool exhaustion | Default pool size | Increase pool, read replicas |
| **DB Queries** | Missing composite indexes | Query latency | Add indexes (see §6) |
| **WebSocket Fanout** | LiveKit handles this | N/A | LiveKit scales independently |
| **Workflow Execution** | Flowise single-threaded call | 60s timeout | Async queue, separate workers |
| **Redis** | Agent lock contention | 30s lock TTL | Smaller TTL, optimistic locking |

### 8.2 Horizontal Scaling Requirements

**Must Be Stateless**:
- ✅ HTTP handlers (stateless)
- ⚠️ Agent orchestrator (state in Redis, but `sync.Map` is local)
- ✅ Repositories (DB handles concurrency)
- ✅ Config (environment variables)

**Current Statefulness Issues**:
1. `agents sync.Map[roomName]*RoomAgent` is per-instance
2. `processedMsgs sync.Map` for dedup is per-instance
3. `InactivityTracker` timers are per-instance

**Recommendation**: Full Redis migration for agent state:
```go
// Instead of sync.Map
type AgentRegistry interface {
Register(roomName string, instanceID string) error
GetOwner(roomName string) (instanceID string, error)
Heartbeat(roomName string) error
}
```

### 8.3 Suggested SLOs

| Operation | p50 | p95 | p99 | Notes |
|-----------|-----|-----|-----|-------|
| **Message send (client → room)** | <50ms | <100ms | <200ms | LiveKit data channel |
| **Message deliver (agent → client)** | <100ms | <200ms | <500ms | After Flowise response |
| **Flowise response** | <2s | <5s | <10s | Depends on flow complexity |
| **Conversation list (dashboard)** | <200ms | <500ms | <1s | Pagination required |
| **Init endpoint** | <500ms | <1s | <2s | Includes room creation |
| **Webhook processing** | <100ms | <200ms | <500ms | Async where possible |
| **Assignment creation** | <100ms | <200ms | <500ms | DB write + notification |

**Availability Targets**:
- Chat gateway: 99.9% (8.7h downtime/year)
- Dashboard API: 99.5% (43.8h downtime/year)
- Flowise: 99% (87.6h downtime/year) — external dependency

---

## 9. Interview Questions for Validation

If interviewing the engineer(s) who built this system, these questions would validate deep understanding:

### Architecture & Design

1. **Why did you choose LiveKit over alternatives like Agora, PubNub, or raw WebSocket?** What specific features (data channels, webhooks, SFU) drove the decision, and what tradeoffs did you accept?

2. **Walk me through what happens when a customer reconnects after 30 seconds of network loss.** How are missed messages handled? What state might be inconsistent?

3. **The `agent_orchestrator.go` is 2265 lines. What would a refactoring look like?** How would you decompose it while maintaining the message processing guarantees?

4. **You store Flowise session state in `Conversation.Metadata` JSONB. Why not a separate `FlowState` table?** What are the query patterns that drove this decision?

### Reliability & Consistency

5. **Your message deduplication uses SHA256 of content+sender+timestamp. What happens if a customer sends the exact same message twice within 1 second intentionally?** Is this a bug or a feature?

6. **The distributed lock for agent startup uses `SetNX` with 30-second TTL. What happens if agent startup takes longer than 30 seconds?** How do you prevent two agents connecting to the same room?

7. **There's no retry logic for Flowise calls. Describe the failure scenario where this matters most and how you'd add retries without breaking idempotency.**

8. **If Flowise returns `is_resolved: true` but the widget message fails to send, what state is the conversation in?** How would you make this atomic?

### Scale & Performance

9. **You have a 100-buffer message channel per agent. Under what conditions does this fill up, and what's the user experience when it does?**

10. **The `RecoverAgents()` function runs 5 seconds after startup. What happens if ECS deploys a new task while recovery is in progress on another instance?**

11. **Your widget variable extraction uses regex. What's the computational complexity, and have you seen performance issues with deeply nested widgets?**

### Security

12. **A malicious user crafts a message designed to manipulate the Flowise prompt. What layers of defense exist, and which are missing?**

13. **The `X-API-Key` authentication stores the key hash. How do you handle key rotation without downtime?**

### Observability & Operations

14. **You're paged at 3am because "conversations are slow." Walk me through your debugging process using only the tools currently instrumented.**

15. **How would you add distributed tracing across the flow: mobile → LiveKit → gateway → Flowise → response?** What correlation IDs exist today?

---

## 10. Missing Documentation / Design Artifacts

Based on this review, the following should be added:

### Architecture Decision Records (ADRs)

1. **ADR-001**: LiveKit vs alternatives (Agora, PubNub, raw WebSocket)
2. **ADR-002**: Flowise vs custom LLM orchestration
3. **ADR-003**: Multi-tenant isolation strategy
4. **ADR-004**: Widget template system design
5. **ADR-005**: Message delivery guarantees tradeoffs

### Sequence Diagrams

1. Full message lifecycle (send → AI → deliver)
2. Assignment workflow state machine
3. Agent recovery on restart
4. Widget click → metadata update → Flowise flow

### Runbooks

1. **Flowise Outage Response**
- Detection, escalation, fallback to human agents

2. **LiveKit Webhook Backlog**
- Symptoms, diagnosis, manual agent trigger

3. **Database Connection Exhaustion**
- Pool sizing, query optimization, read replica failover

4. **Redis Memory Pressure**
- Key audit, TTL review, eviction policy

### API Contract Documentation

1. LiveKit message payload schemas (versioned)
2. Widget JSON schema with validation
3. Flowise request/response contract
4. SSE event format specification

### Capacity Planning Document

1. Concurrent conversation limits per ECS task
2. Database connection pool sizing
3. Redis memory requirements per tenant
4. LiveKit room limits and costs

### Security Threat Model

1. Prompt injection vectors and mitigations
2. Data exfiltration paths
3. Tenant isolation breach scenarios
4. API key compromise response plan

---

## Appendix: Key File Reference

| File | Lines | Purpose |
|------|-------|---------|
| `cmd/api/main.go` | 723 | Entry point, DI, route setup |
| `internal/service/agent_orchestrator.go` | 2265 | Core chat orchestration |
| `internal/service/flow_service.go` | ~400 | Flowise integration |
| `internal/service/livekit_service.go` | 474 | Room/token management |
| `internal/handler/init_handler.go` | 438 | Session initialization |
| `internal/handler/webhook_handler.go` | 516 | LiveKit webhooks |
| `internal/models/conversation.go` | ~300 | Core domain model |
| `internal/models/widget.go` | 722 | Widget template system |
| `internal/flowresponse/processor.go` | ~400 | Response processing |
| `pkg/flowise/flowise.go` | ~200 | HTTP client |
| `pkg/redis/redis.go` | ~300 | Cache layer |
| `dashboard/src/lib/types.ts` | ~500 | Frontend types |
| `dashboard/src/lib/api.ts` | ~800 | API client |
