class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key, int value): key{key}, value{value} {
            this->prev = nullptr;
            this->next = nullptr;
        }
};


class LRUCache {
public:
    int capacity;
    map<int, Node*> m; // information about access
    Node* head;
    Node* tail;
    int capacity_count;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->capacity_count = 0;
    }
    
    int get(int key) {
        if (m.count(key)) {
            // Move the linked list
            int value = m[key]->value;
            remove(key);
            insert(key,value);
            return m[key]->value;
        } 
        return -1;
    }
    
    void insert(int key, int value) {
        if (m.count(key)) {
            remove(key);
        }
        m[key] = new Node{key, value};
        if (capacity_count == 0) {
            head = tail = m[key];
        } else if (capacity_count == 1) { // set head->next to tail
            tail = m[key];
            tail->prev = head;
            head->next = tail;
        } else {
            tail->next = m[key];
            m[key]->prev = tail;
            tail = m[key];
        }
        capacity_count++;
        
    }
    
    void remove(int key) {
        if (!m.count(key)) return;
        if (m[key] == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        }
        if (m[key] == tail) {
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        }
        Node* prev = m[key]->prev;
        Node* next = m[key]->next;
        if (prev != nullptr) {
            prev->next = next;
        }
        if (next != nullptr) {
            next->prev = prev;
        }
            
        
        delete m[key];
        m.erase(key);
        capacity_count--;
    }
    
    void put(int key, int value) {
        insert(key, value);
        if (capacity_count > capacity) {
            remove(head->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */