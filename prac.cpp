#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define repi(a,b) for (int i=a;i<b;i++)
#define repj(a,b) for (int j=a;j<b;j++)
#define repn(a,b) for (int i=a;i>=b;i--)

#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define mii map<int,int>
#define ff first
#define ss second

const int N=1e5+5;


class SegmentTree {
private:
    struct Node {
        int minValue;
        int maxValue;
        int minIndex;
        int maxIndex;
    };

    vector<Node> tree;
    vector<int> nums;

    Node merge(const Node& left, const Node& right) {
        Node result;
        result.minValue = min(left.minValue, right.minValue);
        result.maxValue = max(left.maxValue, right.maxValue);

        if (left.minValue != right.minValue) {
            result.minIndex = (left.minValue < right.minValue) ? left.minIndex : right.minIndex;
        } else {
            result.minIndex = min(left.minIndex, right.minIndex);
        }

        if (left.maxValue != right.maxValue) {
            result.maxIndex = (left.maxValue > right.maxValue) ? left.maxIndex : right.maxIndex;
        } else {
            result.maxIndex = max(left.maxIndex, right.maxIndex);
        }

        return result;
    }

    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node].minValue = nums[start];
            tree[node].maxValue = nums[start];
            tree[node].minIndex = start;
            tree[node].maxIndex = start;
        } else {
            int mid = (start + end) / 2;
            buildTree(2 * node + 1, start, mid);
            buildTree(2 * node + 2, mid + 1, end);
            tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    Node query(int node, int start, int end, int left, int right) {
        if (start > right || end < left) {
            return {INT_MAX, INT_MIN, -1, -1};
        }
        if (start >= left && end <= right) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return merge(query(2 * node + 1, start, mid, left, right),
                     query(2 * node + 2, mid + 1, end, left, right));
    }

public:
    SegmentTree(const vector<int>& input) {
        nums = input;
        int n = input.size();
        tree.resize(4 * n);
        buildTree(0, 0, n - 1);
    }

    pair<int, int> findDistinctIndexes(int left, int right) {
        Node result = query(0, 0, nums.size() - 1, left, right);

        if (result.minIndex != result.maxIndex && nums[result.minIndex] != nums[result.maxIndex]) {
            return {result.minIndex, result.maxIndex};
        } else {
            return {-1, -1};
        }
    }
};


void solve()
{
    int n;
    cin>>n;
    vi v(n);
    repi(0,n){
        cin>>v[i];
        
    }
   
    SegmentTree st(v);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        pair<int, int> ans = st.findDistinctIndexes(l-1, r-1);
        if (ans.ff != -1) {
            cout << ans.ff+1 << " " << ans.ss+1 << endl;
        } else {
            cout << -1 <<" "<<-1<< endl;
        }
    }

   
}

signed main()
{    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;    
}