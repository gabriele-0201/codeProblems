#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int, int> cp1;
unordered_map<int, int> cp2;

vector<string> colors;

vector<bool> chosen (n);
vector<int> permutation;

string maxPaint;

void search() {
	if(permutation.size() == n) {
		for(int i = 0; i < n; i++){
			cout << colors[permutation[i]] <<" ";
		}
		cout <<endl;
	}
	else {
		for(int i = 0; i < n; i++){

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

vector<string> separate(string s) {
	vector<string> colors = "";
	string tmp = "";
	for(auto c : s) {
		if(c == ' '){
			colors.push_back(tmp);
			tmp = "";
		}
		else
			tmp += c;	
	}
	return colors;
}

int main(void) {

	int t, n, m; 
	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n;

		string c;
		cin >> c;
		colors = separate(c);

		cin >> m;

		for(int j=0; j < ms[i]; j++) {
			string s;
			cin >> s;
				
			vector<string> couple = separate(s);
			vector<int> coupleInt(2);
			coupleInt[0] =	distance(colors.begin(), colors.find(colors.begin(), colors.end(), couple[0]));
			coupleInt[1] =	distance(colors.begin(), colors.find(colors.begin(), colors.end(), couple[1]));

			
			
		}
	}



	cp1[1] = 2;
	cp2[2] = 1;
	search();
}
