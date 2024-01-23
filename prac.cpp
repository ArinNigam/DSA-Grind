#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <math.h>
#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read(x) \
    int x;      \
    cin >> x
using namespace std;

void init_code()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    init_code();

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v;
        vector<int> p;
        vector<int> sideLane;
        vector<int> rem;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        p = v;

        sort(p.begin(), p.end());

        int i = 0;
        int j = 0;
        int k = -1;

        while (i < v.size() && j < v.size())
        {
            if (v[i] != p[j])
            {
                if (k != -1)
                {
                    while (sideLane[k] < v[i])
                    {
                        rem.push_back(sideLane[k]);
                        sideLane.pop_back();
                        k--;
                    }
                    sideLane.push_back(v[i]);
                    i++;
                    k++;
                }
                else
                {
                    sideLane.push_back(v[i]);
                    i++;
                    k++;
                }
            }
            else
            {
                rem.push_back(v[i]);
                i++;
                j++;
            }
        }

        for (int i = sideLane.size() - 1; i >= 0; i--)
        {
            rem.push_back(sideLane[i]);
        }

        if (rem == p)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}