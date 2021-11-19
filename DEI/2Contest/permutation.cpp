#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>

using namespace std;

unordered_map<int, int> cp1;
unordered_map<int, int> cp2;

vector<string> colors;

vector<bool> chosen;
vector<int> permutation;

int ctn;
int maxValue;
string maxPaint;

vector<int> ctns;
vector<string> maxPaints;

int findInColors(string s);

int getVal() {
	int sum = 0;

	for(int p : permutation) {
		sum += findInColors(colors[p]);
	}

	return sum;
}

void search() {
	if(permutation.size() == colors.size()) {
		//for(int i = 0; i < colors.size(); i++){
		//	cout << colors[permutation[i]] <<" ";
		//}
		//cout <<endl;
		ctn++;

		int val = getVal();

		if(val > maxValue) {
			maxValue = val;
			maxPaint = "";
			for(int p : permutation) {
				maxPaint += colors[p] + " ";
			}
		}
	}
	else {
		for(int i = 0; i < colors.size(); i++){

			//for(int j = 0; j < permutation.size(); j++){
				//cout << permutation[j] <<" ";
			//}
			//cout <<endl;

			if(chosen[i]) continue;
			if(permutation.size() != 0) {
				auto itr1 = cp1.find(permutation.back());
				auto itr2 = cp2.find(permutation.back());
				if((itr1 != cp1.end() && (itr1 -> second == i)) || (itr2 != cp2.end() && (itr2 -> second == i))) {
					continue;
				}
			}
		
			chosen[i] = true;
			permutation.push_back(i);
			search();
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}



int findInColors(string s) {
	for(int i = 0; i < colors.size(); i++)
		if (colors[i] == s)
			return i;
	return -1;
}

int main(void) {

	int t, n, m; 
	string stringColors, color;
	cin >> t;

	for(int i = 0; i < t; i++) {
		cp1.clear();
		cp2.clear();
		cin >> n;
		chosen = vector<bool> (n);
		ctn = 0;
		maxPaint = "";
		maxValue = 0;
		colors.clear();

		//used bevause cin do not get rid of all new line
		cin.ignore();
		getline(cin, stringColors, '\n');
		stringstream X(stringColors);

		while(getline(X, color, ' '))
			colors.push_back(color);

		cin >> m;
		cin.ignore();

		for(int j=0; j < m; j++) {
			getline(cin, stringColors, '\n');
			stringstream X(stringColors);

			vector<string> couple;

			while(getline(X, color, ' '))
				couple.push_back(color);
			
			cp1[findInColors(couple[0])] = findInColors(couple[1]);
			cp2[findInColors(couple[1])] = findInColors(couple[0]);
		}

		search();

		ctns.push_back(ctn);
		maxPaints.push_back(maxPaint);

	}

	for(int i = 0; i < t; i++) {
		cout << ctns[i] << endl;
		cout << maxPaints[i] << endl;
	}

	return 0;
}
