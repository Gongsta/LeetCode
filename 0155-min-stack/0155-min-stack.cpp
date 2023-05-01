class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        this->val_vec.push_back(val);
        if (this->idx_vec.empty() || val_vec[this->idx_vec.back()] > val) {
            this->idx_vec.push_back(idx_vec.size());
        } else {
            this->idx_vec.push_back(idx_vec.back());
            
        }
    }
    
    void pop() {
        this->val_vec.pop_back();
        this->idx_vec.pop_back();
        
    }
    
    int top() {
        return this->val_vec.back();
    }
    
    int getMin() {
        return this->val_vec[this->idx_vec.back()];
    }
    
private:
    vector<int> val_vec;
    vector<int> idx_vec;
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */