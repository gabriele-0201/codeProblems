#include <iostream>
#include <queue>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        priority_queue<pair<int, int>> q;

        //for(vector<int> r: mat) {
        for(int i = 0; i < mat.size(); ++i) {

            int counter = 0;
            for(int s: mat[i])
                if(s == 0) counter++;
            
            q.push({counter, i});

        }

        vector<int> v;
        for(int i=0; i < k; ++i){
            v.push_back(q.top().second);
            q.pop();
        }

        return v;
    }
};
