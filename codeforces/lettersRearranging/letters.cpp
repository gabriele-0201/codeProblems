#include<iostream>
#include<vector>

using namespace std;

bool isPal(string s, int a, int b) {
	if(a > b)
		return true;

	if(s[a] == s[b]) 
		return isPal(s, a+1, b-1);

	return false;
}

bool tryRearrenge(string s) {
	char first = s[0];
	for(int i = 1; i < s.size(); i++) {
		if(first != s[i])
			return true;
	}

	return false;
}

string rearrange(string s) {
	char first = s[0];
	for(int i = 1; i < s.size(); i++) {
		if(first != s[i]) {
			s[0] = s[i];
			s[i] = first;
			break;
		}
	}
	return s;
}

int main(void) {
	int t;
	vector<string> ss;

	cin >> t;

	for(int i=0; i < t; i++) {
		string s;
		cin >> s;
		ss.push_back(s);
	}

	for(int i=0; i < t; i++) {
		bool pal = isPal(ss[i], 0, ss[i].size() - 1);	

		if(!pal) {		
			cout << ss[i] <<endl;
		}
		else {
			bool pos = tryRearrenge(ss[i]);
			if(pos)
				cout << rearrange(ss[i]) <<endl;
			else 
				cout << "-1" <<endl;
		}
					
	}
}
