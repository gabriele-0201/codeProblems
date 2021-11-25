#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

vector<int> dp;
vector<vector<int>> input;

void setDp(vector<int> v, int index) {
    if(index >= v.size())
        return;

    if(index == 0) {
        dp[index] = 1;
        return setDp(v, index + 1);
    } 

    int max = 0;
    for(int i = 1; index - i >= 0; i++) {
       if(v[index] > v[index - i]){
           if(dp[index - i] > max)
                max = dp[index - i];
       }
    }

    if(max == 0){
        dp[index] = 1;
    } else {
        dp[index] = max + 1;
    }

    return setDp(v, index + 1);
}

int findMax() {
    int max = dp[0];
    for(int i : dp) {
        if(i > max)
            max = i;
    }
    return max;
}

void printLex(int nInput) {
    int max = findMax();
    int indexNotAfter = input[nInput].size();
    cout <<max << " ";
    vector<int> q;
    for(int i = max; i > 0; i--) {
        
        int min = -1;
        int inded;
        for(int j = 0; j < indexNotAfter; j++){
            if(i == dp[j] && (min == -1 || input[nInput][j] < min)) {
                min = input[nInput][j];
                inded = j;
            }
        }
        indexNotAfter = inded;
        q.push_back(min);
    }

    while(!q.empty()){
        cout << q.back() << " ";
        q.pop_back();
    }

    cout << endl;
}

int main(void) {


    string line, val;   
    bool getInput = true;


    while(getInput) {

        input.push_back(vector<int>());

        getline(cin, line);

		stringstream X(line);

        int t;
        while(getline(X, val, ' ')) {
            t = stoi(val);
            if(t == 0) {
                getInput = false;
                input.pop_back();
                break;
            }
            else {
                input.back().push_back(t);
            }
        }
        input.back().erase(input.back().begin());

    }

    for(int i=0; i < input.size(); i++) {
        dp = vector<int> (input[i].size());
        setDp(input[i], 0);

        //for(int i : dp)
        //    cout <<i << " ";
        //cout <<endl;

        printLex(i);
    }
    return 0;
}

// 5 3 7 2 10