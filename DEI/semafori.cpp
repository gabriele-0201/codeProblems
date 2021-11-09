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
    for(int i = 0; i < n; i++){
        s.push_back(vector<int> ());
        for(int j = 0; j < 3; j++){
            cin >> v;
            s.back().push_back(v);
        }
        s.back().push_back(0);
        s.back().push_back(-1); //color to be
    }


    bool arrived = false;
    int counter = 0;
    int position = 0;
    while(!arrived) {
        counter++;
        for(auto i = s.begin(); i != s.end(); i++){ 

            if(i -> at(3) == 0) {
                if(counter % i -> at(1) == 0) {
                    i -> at(3) = 1;
                }
            }else if(i -> at(3) == 1) {
                if(counter % i -> at(2) == 0) {
                    i -> at(3) = 0;
                }
            }
        }

        if(!s.empty() && position >= s.front()[0]) {
            s.pop_front();
        }

        if(!s.empty() && position < s.front()[0] - 1) {
            position++;
        } else if(!s.empty() && position == s.front()[0] - 1) {
            if(s.front()[3] == 1)
                position++;
        } else if(s.empty()) {
            position++;
        }

        if(position >= l)
            arrived = true;

    }
    cout << counter;

    return 0;
}

