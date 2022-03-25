#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        unordered_set<int> s;
    
        int counter = 0;
        for(int w : people) {
            if(s.find(w) != s.end()) {
                s.erase(w);
                counter++;
                cout << "nuova nave da subito" <<endl;
            } else {
                s.insert(limit - w);
                cout << "inserito nel set " << w  <<endl;
            }
        }

        //bool nothingChange = false;
        while(!s.empty()) {
            //nothingChange = true;
            //for(auto itr = s.begin(); itr != s.end();) {
            unordered_set<int>::iterator itr = s.begin();
            int left = *itr;
            int w = limit - left;

            cout << "valutoL: " << left <<endl;
            cout << "peso: " << w  <<endl;

            bool insered = false;
            //unordered_set<int>::iterator tmp;
            while(w <= limit) {
                if(s.find(w) != s.end()) {
                    s.erase(left);
                    s.erase(w);
                    counter++;
                    cout << "nuova nave " <<endl;
                    insered= true;
                    break;
                }
                w++;
            }

            if(!insered) {
                s.erase(left);
                counter++;
            }
            //break
        }

        return counter + s.size();
    }
};

int main(void) {
    Solution s;

    vector<int> v = {3,5,3,4};
    int limit = 5;

    cout << s.numRescueBoats(v, limit);
}
