#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct hashFunction
{
  size_t operator()(const pair<int , 
                    int> &x) const
  {
    return x.first + x.second * 31;
  }
};


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        unordered_set<int> s;
        unordered_set<int> possJudge;
        unordered_set<pair<int, int>, hashFunction> cuples;

        for(vector<int> v : trust) {

            cuples.insert({v[0], v[1]});
            
            s.insert(v[0]);

            possJudge.erase(v[0]);

            if(s.find(v[1]) == s.end())
                possJudge.insert(v[1]);
            
        }

        for(auto s : possJudge) {
            //cout << "test" << s <<endl;
            bool allTrust = true;

            for(int i = 1; i <= n; i++) {
                //cout << "testing cuople " << i << " " << s <<endl;
                if(i != s && cuples.find({i, s}) == cuples.end()) {
                    //cout<< "ajklfhalfh" << endl;
                    allTrust = false;
                    break;
                }
            }

            if(allTrust)
                return s;
        }

        //if(possJudge.empty())
            return -1;

        //return *possJudge.begin();
        
    }
};

int main(void) {

    Solution s;

    vector<vector<int>> v {{1,3},{1,4},{2,3}};

    cout << s.findJudge(4, v) << endl;

}
