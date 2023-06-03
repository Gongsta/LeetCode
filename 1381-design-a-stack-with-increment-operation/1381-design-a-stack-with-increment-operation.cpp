struct Node {
    int val;
    Node* next;
    Node(int val): val{val} {
        next = nullptr;
    }
};
class CustomStack {
public:
    Node* head;
    int n; // keep track on size of stack
    int max_size;
    CustomStack(int maxSize) {
        max_size = maxSize;
        head = nullptr;
        n = 0;
    }
    
    void push(int x) {
        if (n >= max_size) {
            return;
        }
        if (head == nullptr) {
            head = new Node{x};
        } else {
            Node* new_node = new Node{x};
            new_node->next = head;
            head = new_node;
        }
        n++;
    }
    
    int pop() {
        if (head == nullptr) return -1;
        Node* node = head;
        head = head->next;
        int val = node->val;
        delete node;
        n--;
        return val;
    }
    
    void increment(int k, int val) {
        Node* curr = head;
        for (int i=0;i<n;i++) {
            if (i >= (n-k)) {
                curr->val += val;
            }
            curr = curr->next;
        }
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */