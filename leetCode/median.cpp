#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:

    float result;
    int indexMedian;
    bool odd;

    int bs(vector<int>& arr, int val) {
        int from = 0, to = arr.size() - 1;
        while(from <= to) {

            int mid = (from + to) / 2;
            if(arr[mid] == val){
                while(arr[mid++] == val && mid < arr.size());
                return mid - 1;
            }
            else if(arr[mid] < val) 
                from = mid + 1;
            else 
                to = mid - 1;

        }
        //cout << "from: " <<from << " to: " <<to <<endl;
        //return from - 1;
        return max(from, to);
    }

    
    bool bsbs(vector<int>& nums1, vector<int>& nums2) {

        int from = 0, to = nums1.size() - 1;
        //int from2 = 0, to2 = nums2.size();

        while(from <= to) {

            int index1 = (from + to) / 2;

            int index2 = bs(nums2, nums1[index1]);

            cout << "index1: " << index1 << " index2: " <<index2 <<endl;

            if(index1 + index2 == indexMedian) {
                if(odd)
                    result = (float)nums1[index1];
                else {

                    if(index1 + 1 < nums1.size())
                        result = ((float)nums1[index1] + (float)min(nums1[index1 + 1], nums2[index2])) / 2.0;
                    else
                        result = ((float)nums1[index1] + (float)nums2[index2]) / 2.0;
                }
                return true;
            } else if (index1 + index2 < indexMedian) {
                from = index1 + 1;
            } else 
                to = index1 - 1;
        }

        cout <<"noope" <<endl;
        return false;
    }

    

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        odd = (nums1.size() + nums2.size()) % 2 == 1;

        indexMedian = (nums1.size() + nums2.size()) / 2;

        if(!odd)
            indexMedian--;

        
        if(nums1.empty()) {
            if(odd)
                result = (float)nums2[indexMedian];
            else 
                result = ((float)nums2[indexMedian] + (float)nums2[indexMedian + 1]) / 2.0;
        } else if(nums2.empty()) {

            if(odd)
                result = (float)nums1[indexMedian];
            else 
                result = ((float)nums1[indexMedian] + (float)nums1[indexMedian + 1]) / 2.0;
        } else
            //cout << "index median" <<indexMedian <<endl;
            if(!bsbs(nums1, nums2))
                bsbs(nums2, nums1);

        return result;

    }
};

int main(void) {
    vector<int> nums1 = {1, 2, 2};
    vector<int> nums2 = {1, 2, 3};

    Solution s;

    cout << s.findMedianSortedArrays(nums1, nums2) <<endl;
}
