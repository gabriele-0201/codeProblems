#include<iostream>

using namespace std;


int getMinPermutation(vector<int> vec) {
    
    vector<int> tmp;
    int count = 0;
    for(int i = 0; i < vec.size(); ++i) {

        if(vec[i])

    }

    return count; 
}

int main(void) {

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int n;
        //seq = vector<int>{};
        vector<int> seq;

        cin >> n;

        int tmp;
        for(int j = 0; j < n; ++j) {
            cin >> tmp;
            seq.push_back(tmp);
        }

        cout << getMinPermutation(vec) <<endl;

     }
}

// 1 3 2 4
// x n y      2 < 3 YUP - scambio ok
//       x
//
//
// 2 1 4 5 3
// 
// x x y y y 
//
// 2 4 1 6 3 5 7
//
