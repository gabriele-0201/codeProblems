#include<iostream>

using namespace std;

int main(void) {
	int n,t;
	
	string q;

	cin >> n;
	cin >> t;

	cin >> q;

	for(int i = 0; i < t; i++) {
		for(int j = 0; j < n; j++) {
			if(q[j] == 'B' && q[j + 1] == 'G') {
				q[j] = 'G';
				q[j + 1] = 'B';
				j++;
			}
		}
	}

	cout << q;


}
