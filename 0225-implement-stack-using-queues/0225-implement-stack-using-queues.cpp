class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        
    }
    
    int pop() {
        int s = q.size();
        int count = 0;
        int x;
        while (count < s) {
            x = q.front(); q.pop();
            count++;
            if (count != s) {
                q.push(x);
            }
        }
        return x;
    }
    
    int top() {
        int s = q.size();
        int count = 0;
        int x;
        while (count < s) {
            x = q.front(); q.pop();
            count++;
            q.push(x);
        }
        return x;
        
        
    }
    
    bool empty() {
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */