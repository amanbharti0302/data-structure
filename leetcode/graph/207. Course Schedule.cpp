/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

===========================>>>using kahn algo we can find this (used for topological sorting)
*/

vector<int>adj[100005];
vector<int>in(100005);
vector<int>visited(100005);

bool kahn(int n){
    //bfs
    queue<int>q;
    int cnt =0;
    
    for(int i=0;i<n;i++){
        if(in[i]==0){
            q.push(i);
            while(!q.empty()){
                int src = q.front();
                q.pop();
                for(auto to :adj[src]){
                    if(--in[to]==0)
                    q.push(to);
                }
                in[src]--;
                cnt++;
            }
        }
    }
    if(cnt==n)return true;
    return false;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        for(int i=0;i<=numCourses+1;i++){
            adj[i].clear();
            in[i]=0;
            visited[i]=false;
        }
        
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            in[pre[i][0]]++;
        }
        return kahn(numCourses);
        //return true;
    }
};