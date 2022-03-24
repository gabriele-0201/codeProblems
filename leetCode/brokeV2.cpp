
#include <algorithm>
#include <iostream>

class Solution {
public:
    int brokenCalc(int startValue, int target) {

        int counter = 0;
        while(target != startValue) {

            if(target > startValue && target % 2 == 0) {
                target = target /2;
                counter++;
            }
            else {
                target += 1;
                counter++;
            }

        }

        return counter;

    }
};

int main(void) {

    Solution sol;

    std::cout << sol.brokenCalc(5, 8) <<std::endl;
}
