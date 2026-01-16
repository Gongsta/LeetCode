class Solution {
    priority_queue<int> left_pq;
    priority_queue<int, vector<int>, greater<int>> right_pq;
public:
    void insert(int num) {
        if (left_pq.empty() || num <= left_pq.top()) {
            left_pq.push(num);
        } else {
            right_pq.push(num);
        }

        if (left_pq.size() > right_pq.size() + 1) {
            right_pq.push(left_pq.top());
            left_pq.pop();
        } else if (right_pq.size() > left_pq.size()) {
            left_pq.push(right_pq.top());
            right_pq.pop();
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int num: nums1) {
            insert(num);
        }
        for (int num: nums2) {
            insert(num);
        }
        if (left_pq.size() == right_pq.size()) {
            long long left = left_pq.top(); 
            long long right = right_pq.top();
            return (right + left) / 2.0;
        }
        return left_pq.top();

    }
};