#include<iostream>
#include<vector>

using namespace std;

int main(void) {
    int t, n;

    vector<vector<int>> as;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n;
        as.push_back(vector<int> ());
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            as[i].push_back(x);
        }
    }


    for(int i = 0; i < t; i++) {
        int nope = -1;
        for(int j = as[i].size() - 1; j >= 0; j--) {
            if(as[i][j] % (j + 2) != 0) {
                as[i].erase(as[i].begin() + j);
                
                if(nope != -1) {
                    j = nope;
                    nope = -1;
                }

            } else {
                if(nope == -1)
                    nope = j;
            }
        }

        if(as[i].size() == 0)
            cout << "YES" <<endl;
        else 
            cout << "NO" <<endl;

    }
}