#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int brokenCalc(int startValue, int target) {

        int rest = target % startValue;

        if(rest == 0)
            return target / startValue;
        else if(rest <= startValue / 2) {
            int mult = target / startValue;
            cout << "m" << mult <<endl;
            return (mult) + (target - (startValue * mult) );
        }
        else {
            int i = 1;

            while(target % (startValue - i) != 0)
                i++;
            
            cout << "s" << i <<endl;

            return (target / (startValue - i)) - 1 + i;
        }
    }
};

int main(void) {

    Solution sol;

    std::cout << sol.brokenCalc(3, 10) <<std::endl;
}

