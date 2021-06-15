/*
You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available to process at enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.
*/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i = 0;i<tasks.size();i++)tasks[i].push_back(i);
        
        vector<int>ans;
        long long int cpu = 0;
        priority_queue< vector<int>, vector<vector<int>> ,greater<> >pq;
        sort(tasks.begin(),tasks.end());
        
        for(int i = 0;i<tasks.size()||!pq.empty();){
            for(;i<tasks.size();++i){
                if(tasks[i][0]>cpu)break;
                pq.push({tasks[i][1],tasks[i][2],tasks[i][0]});
            }
            
            if(!pq.empty()){
                cpu+=pq.top()[0];
                ans.push_back(pq.top()[1]);
                pq.pop();
            }
            else{
                cpu = tasks[i][0];
            }
            
        }
        
        return ans;
    }
};