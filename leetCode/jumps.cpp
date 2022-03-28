#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int jump(vector<int>& nums) {
        
        int counter = 0;
        for(int i = 0; i < nums.size() - 1;) {

            counter++;

            if(i + nums[i] >= nums.size() - 1)
                break;
            
            int maxIndex = i + 1; 
            
            for(int j = maxIndex + 1; j <= i + nums[i]; ++j) {
                //cout << "controllo: " << j;
                if(maxIndex + nums[maxIndex] < j + nums[j])
                    maxIndex = j;
                //cout << endl;
            }
            
            i = maxIndex;
            //cout << "winner " << maxIndex <<endl;
            
        }
        
        return counter;
    }
};

// [5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5]

int main(void) {
    Solution s;

    //vector<int> j {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    vector<int> j {2,3,1,1,4};
                                                                                              
    cout << s.jump(j) <<endl;
}
