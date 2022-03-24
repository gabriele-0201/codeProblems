#include <algorithm>
#include <iostream>

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue == target)
            return 0;

        int tmp1 = 0,  tmp2 = 0;

        if(startValue < target) {
            int mult;

            mult =  target / startValue;
            
            tmp1 = mult + brokenCalc(startValue * mult, target);
        }

        if((startValue - 1) * 2 >= target) 
            tmp2 = 1 + brokenCalc(startValue - 1, target);

        if(tmp1 == 0)
            return tmp2;
        if(tmp2 == 0)
            return tmp1;

        return std::min(tmp1, tmp2);

    }
};

int main(void) {

    Solution sol;

    std::cout << sol.brokenCalc(2, 3) <<std::endl;
}

