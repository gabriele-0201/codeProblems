#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int from =  0, to = nums.size() - 1;

        while(from <= to) {
            int mid = (from + to) / 2;

            if(nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                from  = mid + 1;
            else 
                to = mid - 1;

        }

        return -1;
    }
};

int main(void) {
    Solution s;

    vector<int> v {-1};
    
    cout << s.search(v, 2);
}
