#include <string>

using namespace std;

class Solution {
    public:
        int getValue(char c) {
            switch(c) {
                case 'I':
                    return 1;
                case 'V':
                    return 5;
                case 'X':
                    return 10;
                case 'L':
                    return 50;
                case 'C':
                    return 100;
                case 'D':
                    return 500;
                case 'M':
                    return 1000;
                default:
                    return 0;
            }
        }

        int romanToInt(string s) {
            int counter = 0;
            for(int i = 0; i < s.size(); i++) {
                if(i + 1 < s.size() && (
                    ((s[i] == 'I') && (s[i + 1] == 'V' || s[i + 1] == 'x')) ||
                    ((s[i] == 'X') && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
                    ((s[i] == 'C') && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                   )) {
                    counter += getValue(s[i + 1]) - getValue(s[i]);
                    i++;
                    }
                else
                    counter += getValue(s[i]);
            }

            return counter;

        }
};
