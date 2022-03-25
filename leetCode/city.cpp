#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

    bool comparator0(vector<int> &a, vector<int> &b){
        //return a[0] > b[0];
        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    bool comparator1(vector<int> &a, vector<int> &b){
        //return a[1] > b[1];
        return (a[0] - a[1]) > (b[0] - b[1]);
    }

class Solution {
public:


    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        vector<vector<int>> a;
        vector<vector<int>> b;

        int cA = 0;
        int cB = 0;
        for(vector<int> e: costs){
            if(e[0] <= e[1]) {
                a.push_back(e);
                cA += e[0];
            }
            else {
                b.push_back(e);
                cB += e[1];
            }
        }

        sort(a.begin(), a.end(), comparator0);
        sort(b.begin(), b.end(), comparator1);

        //for(auto e : a)
            //cout << e[0] << " " <<e[1] <<endl;
        //cout <<endl;

        //for(auto e : b)
            //cout << e[0] << " " <<e[1] <<endl;

        //cout << "size a " <<a.size() << " b size" << b.size() <<endl;

        int diff = (costs.size() / 2) - a.size();
        //cout << "diff " <<diff <<endl;
        if(diff < 0) {
            diff *= -1;
            for(int i = 1; i <= diff; i++) {
                vector<int> e = a[a.size() - i];
                //a.push_back()
                cA -= e[0];
                cB += e[1];
            }
        }
        else {
            for(int i = 1; i <= diff; i++) {
                vector<int> e = b[b.size() - i];
                //a.push_back()
                cA += e[0];
                cB -= e[1];
            }
        }

        return cA + cB;

    }
};

int main(void) {
    Solution s;

    //vector<vector<int>> test = {{10,20},{30,200},{400,50},{30,20}};
    //vector<vector<int>> test {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}};
    vector<vector<int>> test = {{518,518},{71,971},{121,862},{967,607},{138,754},{513,337},{499,873},{337,387},{647,917},{76,417}};

    cout << s.twoCitySchedCost(test) <<endl;


}
