#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main(void) {
	int n, l;
    deque<vector<int>> s;

	cin >> n;
	cin >> l;

    int v;
    cout << "N: " << n;
    for(int i = 0; i < n; i++){

        s.push_back(vector<int> ());

        cout << i   << " " << n;
        
        for(int j = 0; j < 3; j++){
            cin >> v;
            cout<<j<<endl;
            s.back().push_back(v);
        }
        cout<<"uscito dall'aarray";
        s.back().push_back(0);
        
        cout << "Insered one";
    }

        cout << "finisched input"<<endl;

    bool arrived = false;
    int counter = 0;
    int position = 0;
    while(!arrived) {
        counter++;

        for(int i = 0; i < s.size(); i++){ 
            if(s[i][3] == 0) {
                if(counter % s[i][1] == 0) {
                    s[i][3] == 1;
                }
            }else if(s[i][3] == 1) {
                if(counter % s[i][2] == 0) {
                    s[i][3] == 0;
                }
            }
        }

        if(position == s.front()[0]) {
            s.pop_front();
        }

        if(position < s.front()[0] - 1) {
            position++;
        } else if(position = s.front()[0] - 1) {
            if(s.front()[3] == 1)
                position++;
        } 

        if(position >= l)
            arrived = true;
    }
    cout << counter;

    return 0;
}

