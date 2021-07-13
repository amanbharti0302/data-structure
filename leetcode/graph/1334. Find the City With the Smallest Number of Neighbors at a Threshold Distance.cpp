/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

Example 1:


Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:


Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.


==================================>>>>>>>>>>>>> floyd warshall law
*/



class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dp[n+1][n+1];
        
        for(int i = 0;i<=n;i++)
        for(int j = 0;j<=n;j++)
        if(i==j)dp[i][j] =0;
        else dp[i][j] = INT_MAX;
        
        for(auto x:edges)
        dp[x[0]][x[1]] = dp[x[1]][x[0]] = x[2];

        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(dp[i][k]==INT_MAX||dp[k][j]==INT_MAX)continue;
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        
        int ans_val = INT_MAX,ans = n-1;
        
        for(int i = n-1;i>=0;i--){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(i==j)continue;
                if(dp[i][j]<=distanceThreshold&&dp[i][j]!=0)cnt++;
            }
            if(cnt<ans_val){ans = i;ans_val = cnt;}
        }
        
        
        return ans;
        
    }
};