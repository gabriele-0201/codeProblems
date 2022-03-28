#include <iostream>
#include <string>
#include <math.h>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        long newX = (long)x;

        bool negative = false;
        if(newX < 0) {
            negative = true;
            newX *= -1;
        }

        string s = to_string(newX);

        long counter = 0;
        for(int i = s.size() - 1; i >= 0; --i) {
            
            counter += pow(10, i) * (s[i] - 48);

            if(counter > (double)INT_MAX)
                return 0;

        }

        if(negative)
            counter *= -1;

        return counter;
        
    }
};

int main(void) {
    Solution s;
    
    cout <<  s.reverse(-2147483648);
}
/*
 * ALLLORA
 *
 * potrei sicuramente convertirlo in strnga ->
 *
 * Volendo potrei fare un doppio putantore sui bit (gruppo di )
 *
 *
 */
