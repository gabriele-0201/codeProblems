#include<vector>
#include<iostream>

class Solution {
public:

    int bs(vector<int>& arr, int val) {
        int from = 0, to = arr.size();
        while(from <= to) {

            int mid = (from + to) / 2;
            if(arr[mid] == val)
                return mid;
            else if(arr[mid] < val) 
                from = mid + 1;
            else 
                to = mid - 1;

        }
        return from;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       // weird stuff 
    }
};

int main(void) {
    vector<int> nums1 = {1,3};
    vector<int> nums1 = {2};

    Solution s;

    count << s.findMedianSortedArrays(nums1, nums2); <<endl;
}
