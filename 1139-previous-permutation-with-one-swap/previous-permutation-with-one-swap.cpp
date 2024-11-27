class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        /*
        Intuition, swap a bigger number with smaller number, but do what's possible

        Swap largest with second largest
        Swap second largest with third largest
        Nope

        4 1 2 3

        to
        1 4 2 3 NOPE

        3 1 2 4 YES

        5 4 3 2 1 2 3 4 5 4 3 

        1,9,4,6,7,6,5
        This becomes
        1,9,4,6,10

        */
        for (int i=arr.size()-1;i>0;i--) {
            if (arr[i-1] > arr[i]) {
                int biggest_j = i;
                for (int j=i;j<arr.size();j++) {
                    if (arr[j] < arr[i-1] && arr[j] > arr[biggest_j]) {
                        biggest_j = j;
                    }
                }
                swap(arr[biggest_j],arr[i-1]);
                break;
            }
        }

        return arr;
    }
};