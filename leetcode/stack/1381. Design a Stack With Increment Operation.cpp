/*
Design a stack which supports the following operations.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack or do nothing if the stack reached the maxSize.
void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
int pop() Pops and returns the top of stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, just increment all the elements in the stack.
 

Example 1:

Input
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
Output
[null,null,null,2,null,null,null,null,null,103,202,201,-1]

*/

class CustomStack {
public:
    vector<int>s;
    int sz;
    
    CustomStack(int maxSize) {
        sz = maxSize;
    }
    
    void push(int x) {
        if(sz==s.size())return;
        s.push_back(x);
    }
    
    int pop() {
        if(s.size()==0)return -1;
        int temp = s.back();
        s.pop_back();
        return temp;
    }
    
    void increment(int k, int val) {
        int siz = s.size();
        for(int i = 0;i<min(k,siz);i++)s[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */