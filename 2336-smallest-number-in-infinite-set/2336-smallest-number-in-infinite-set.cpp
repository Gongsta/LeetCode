class SmallestInfiniteSet {
public:
    unordered_set<int> removed;
    int smallest;
    SmallestInfiniteSet() {
        smallest = 1;
        
    }
    
    int popSmallest() {
        int i=smallest;
        while (removed.count(i)) {
            i++;
        }
        removed.insert(i);
        smallest = i+1;
        return i;
    }
    
    void addBack(int num) {
        if (removed.count(num)) {
            if (num < smallest) {
                smallest = num;
            }
            removed.erase(num);
        }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */