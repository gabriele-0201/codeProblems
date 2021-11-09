#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int t;
	vector<int>	ns;
	vector<vector<int>> ss;

	cin >> t;

	for(int i = 0; i < t; i++) {
		int n;

		cin >> n;

		ns.push_back(n);
		vector<int> s;
		for(int j = 0; j < n; j++) {
			int st;
			cin >> st;
			s.push_back(st);
		}
		ss.push_back(s);
	}

	for(int i = 0; i < t; i++) {
		int n = ns[t];	
		bool impossible = false;	
		for(int j = ss[n].size() - 1; j > 0; j--) {
			
			if(ss[n][j] <= ss[n][j - 1]) {
				ss[n][j]++;
				ss[n][j - 1]--;

				if(ss[n][j] < ss[n][j - 1] || ss[n][j - 1] < 0) {
					impossible = true;
					break;
				}
			}
		}

		if(!impossible)
			cout << "YES" <<endl;
		else
			cout << "NO" <<endl;
	}
}
