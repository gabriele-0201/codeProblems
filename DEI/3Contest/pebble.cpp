#include<iostream>
#include<vector>

using namespace std;

int getMin(vector<bool> v) {
    int minPlayer = 0;

    for(int i = 0; i < 12; i++) {
        if(v[i]){
            minPlayer++;
        }
    }

    //cout << "min first: " <<minPlayer <<endl;

    for(int i = 0; i < 12; i++) {

        if(v[i] && i - 2 >= 0) {

            if(v[i - 1] && !v[i - 2]) {
                //cout<<"SOOS1";
                vector<bool> tmp (v.begin(), v.end());
                tmp[i - 1] = false;
                tmp[i] = false;
                tmp[i - 2] = true;
                minPlayer = min(minPlayer, getMin(tmp));
            }

        }
        
        if(v[i] && i + 2 < 12) {
            
            if(v[i + 1] && (!v[i + 2])) {
                //cout<<"SOOS2 " <<i  <<endl;
                vector<bool> tmp (v.begin(), v.end());
                tmp[i + 1] = false;
                tmp[i] = false;
                tmp[i + 2] = true;
                minPlayer = min(minPlayer, getMin(tmp));
            }

        }
    }

    return minPlayer;

}


int main(void) {
    int n;
    vector<vector<bool>> lines;

    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++) {
       
        lines.push_back(vector<bool>(12));
        char c;

        for(int j = 0; j < 12; j++) {
            cin >> c;
            if(c == '-') {
                lines.back()[j] = false;
            }
            else {
                lines.back()[j] = true;
            }
        }
        
        cin.ignore();
    }
    
    /*for(vector<bool> v : lines) {
        for(bool b : v) {
            cout << b << " ";
        }
        cout<<endl;
    }

    cout <<endl;*/

    for(vector<bool> l : lines) {
        cout<< getMin(l) <<endl;
    }

    return 0;

}