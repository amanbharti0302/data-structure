/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>s,smin;
    
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(smin.empty()||smin.top()>=val)smin.push(val);
    }
    
    void pop() {
        if(s.empty())return;
        if(s.top()==smin.top()){s.pop();smin.pop();}
        else s.pop();
    }
    
    int top() {
        if(s.empty())return -1;
        return s.top();
    }
    
    int getMin() {
        if(smin.empty())return -1;
        return smin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */