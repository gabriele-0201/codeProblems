#include<iostream>
#include<vector>

using namespace std;

int getMax(vector<int>& vals) {
	int max = vals[0];

	for(int i = 0; i < vals.size(); i++) {
		if(vals[i] > max)	
			max = vals[i];
	}

	return max;
}

int main(void) {
	int t;
	vector<int> ns;
	vector<vector<int>> vals;
	
	cin >> t;

	for(int i = 0; i < t; i++) {
		int n;
		cin >> n;
		ns.push_back(n);
		vector<int> t;
		for(int j = 0; j < n; j++) {
			int v;	
			cin >> v;
			t.push_back(v);
		}
		vals.push_back(t);
	}
	
	for(int z = 0; z < t; z++){
		vector<int> sums;
		for(int i = 0; i < ns[z]; i++) {
			int sum = 0;
			for(int j = 0; j < ns[z]; j++) {
				if(vals[z][i] <= vals[z][j])
					sum += vals[z][i];
			}
			sums.push_back(sum);
		}
		int mS = getMax(sums);
		cout << mS <<endl;
	}
}


