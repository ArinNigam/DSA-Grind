// Regions Cut By Slashes (Medium)

// An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
// Given the grid grid represented as a string array, return the number of regions.
// Note that backslash characters are escaped, so a '\' is represented as '\\'.

// Input: grid = [" /","/ "]
// Output: 2

#include<bits/stdc++.h>
using namespace std;

class DSU{
public:
    vector<int>parent;
    vector<int>size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
            size[i] = 1;
        }
    }
    void setParent(int x,int y){
        parent[x] = y;
    }
    int findParent(int x){
        if (parent[x] == x){
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    int Union(int x,int y){
        int a = findParent(x);
        int b = findParent(y);
        if (a==b) return 1;
        if (size[a] > size[b]){
            swap(a,b);
        }
        size[b]+=size[a];
        parent[a] = parent[b];
        return 0;
    }

};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int total = (n+1)*(n+1);
        DSU dsu(total);
        for (int i = 0; i < (n+1); i++) {
            for (int j = 0; j < (n+1); j++) {
                if (i == 0 || j == 0 || i == (n+1) - 1 || j == (n+1) - 1) {
                    int point = i * (n+1) + j;
                    dsu.setParent(point,0);
                }
            }
        }
       
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    int topRight = i * (n+1) + (j + 1);
                    int bottomLeft = (i + 1) * (n+1) + j;
                    ans += dsu.Union(topRight, bottomLeft);
                } 
                else if (grid[i][j] == '\\') {
                    int topLeft = i * (n+1) + j;
                    int bottomRight = (i + 1) * (n+1) + (j + 1);
                    ans += dsu.Union(topLeft, bottomRight);
                }
            }
        }

        return ans;
    }
};

signed main()
{  
  int n;
  cin>>n;
  vector<int>nums(n);
  for (int i=0;i<n;i++){
    cin>>nums[i];
  }
  Solution ob;
  auto ans = ob.solve(nums);
  cout<<ans;
  return 0;
}