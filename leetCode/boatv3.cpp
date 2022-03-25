
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        unordered_map<int, int> m;
        unordered_map<int, int>::iterator tmp;
    
        int counter = 0;
        for(int w : people) {
            if((tmp = m.find(limit - w)) != m.end() && tmp -> second > 0) {
                (tmp -> second)--;
                counter++;
                //cout << "nuova nave da subito" <<endl;
            } else {
                if((tmp = m.find(w)) != m.end())
                    (tmp -> second)++;
                else
                    m.insert({w, 1});
                //cout << "inserito nel set " << w  <<endl;
            }
        }

        for(auto itr = m.begin(); itr != m.end(); itr++) {

            while(itr -> second > 0) {

                (itr -> second)--;
                counter++;
                //cout << "rimosso " << itr -> first;

                int remain = limit - (itr -> first);

                bool insered = false;
                while(!insered && remain > 0) {
                    if((tmp = m.find(remain)) != m.end() && tmp -> second > 0) {
                        (tmp -> second)--;
                        insered = true;
                        //cout << "assieme " << tmp -> first;
                    } else
                        remain--;
                }

                //cout << endl;

                
            }
        }

        return counter;
    }
};

int main(void) {
    Solution s;

    vector<int> v =  {3,8,4,9,2,2,7,1,6,10,6,7,1,7,7,6,4,4,10,1};
    int limit = 10;

    cout << s.numRescueBoats(v, limit);
}
