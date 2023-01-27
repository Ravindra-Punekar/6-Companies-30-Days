/*
https://leetcode.com/problems/max-area-of-island/https://leetcode.com/problems/max-area-of-island/
*/

class Solution {
public:
    int n,m;
    set<pair<int,int>> vis;
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(vis.count({i,j})) return 0;
        vis.insert({i,j});
        if(grid[i][j]==0) return 0;

       return 1+ dfs(i-1, j, grid) + dfs(i+1, j, grid) +dfs(i, j-1, grid) +dfs(i, j+1, grid); 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        n = grid.size();
        m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    maxArea = max(maxArea, dfs(i,j,grid));
            }
        }

        return maxArea;
    }
};
