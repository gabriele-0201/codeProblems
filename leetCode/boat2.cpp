#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());
        reverse(people.begin(), people.end());

        vector<int> boats {};
        int counter = 0;

        for(int w : people) {
            
            for(auto itr = boats.begin(); itr != boats.end();) {
                if(*itr + w <= limit)
                    *itr += w;

                if(*itr == limit) {
                    itr = boats.erase(itr);
                    counter++;
                }
                else 
                    itr++;

            }

        }

        return counter + boats.size();
    }
};

int main(void) {
    Solution s;

    vector<int> p =  {1, 2};
    int limit = 3;

    cout << s.numRescueBoats(p, limit);

}
