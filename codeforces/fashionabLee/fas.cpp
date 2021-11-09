#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int t;
	
	cin >>  t;

	vector<int> ns;

	for(int i = 0; i < t; i++) {
		int n;
		cin >> n;	
		ns.push_back(n);
	}

	for(int i = 0; i < t; i++) {
		if((ns[i] % 2) == 0)
			cout << "YES" <<endl;
		else
			cout << "NO" <<endl;
	}
}
