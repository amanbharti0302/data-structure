/*
You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively. servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds.
Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the queue is empty.
At second j, the jth task is inserted into the queue (starting with the 0th task being inserted at second 0). As long as there are free servers and the queue is not empty, the task in the front of the queue will be assigned to a free server with the smallest weight, and in case of a tie, it is assigned to a free server with the smallest index.
If there are no free servers and the queue is not empty, we wait until a server becomes free and immediately assign the next task. If multiple servers become free at the same time, then multiple tasks from the queue will be assigned in order of insertion following the weight and index priorities above.
A server that is assigned task j at second t will be free again at second t + tasks[j].
Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be assigned to.
Return the array ans​​​​.
*/

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue< vector<int> ,vector< vector<int> >,greater<>> busy_server,pq;
        
        for(int i= 0;i<servers.size();i++)pq.push({servers[i],i,0});
        
        vector<int>ans(tasks.size(),0);
        
        for(int i = 0;i<tasks.size();i++){
            
            while(!busy_server.empty()&&busy_server.top()[0]<=i){
                auto temp = busy_server.top();
                pq.push({temp[1],temp[2],i});
                busy_server.pop();
            }
            
            //pq = > wt,ind,time
            //busy=>time,wt,ind
            
            if(pq.empty()){
                auto temp = busy_server.top();
                pq.push({temp[1],temp[2],temp[0]});
                busy_server.pop();
            }
            
            int sec = pq.top()[2]+tasks[i];
            if(pq.top()[2]<i){sec = i+tasks[i];}
            
            ans[i] = pq.top()[1];
            busy_server.push({sec,pq.top()[0],pq.top()[1]});
            pq.pop();            
        }
        
        return ans;
    }
};