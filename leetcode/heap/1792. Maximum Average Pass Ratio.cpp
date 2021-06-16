/*There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
*/


double profit(double a,double b){
    return (double)(a+1)/(b+1)-(double)a/b;
}

typedef pair<double,int> pd;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0.0;
        priority_queue<pd>pq;
        
        for(int i = 0;i<classes.size();i++)
        if(profit(classes[i][0],classes[i][1])<1)
        pq.push({profit(classes[i][0],classes[i][1]),i});

        while(extraStudents--){
            auto ind = pq.top().second;
            pq.pop();
            classes[ind][0]+=1;
            classes[ind][1]+=1;
            if(profit(classes[ind][0],classes[ind][1])<1)
            pq.push({profit(classes[ind][0],classes[ind][1]),ind});
        }
        
        for(int i = 0;i<classes.size();i++){
            ans+=(double)((double)(classes[i][0]*1.0)/(double)classes[i][1]);
        }
        
        ans=ans/(double)classes.size();
        return ans;
    }
};