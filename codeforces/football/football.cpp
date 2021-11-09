#include<iostream>

using namespace std;

int main (void) {
	string p;

	cin >> p;
	
	int cur, count, j;
	
	for(int i = 0; i < p.size(); i++) {
		cur = p[i];

		count = 1;
		j = 1;

		while(p[i + j] == cur && count < 7 && (i + j) < p.size()) {
			count++;	
			j++;
		}
		
		if(count >= 7)
			break;

		count = 0;
		j = 1;

		while(p[i + j] != cur && count < 7 && (i + j) < p.size()) {
			count++;	
			j++;
		}

		if(count >= 7)
			break;

		if(j == 1)
			i = (i + j) - 1;
		else
			i = (i + j) - 2;
	}

	
	if(count >= 7)
		cout <<  "YES";
	else
		cout <<  "NO";
	
	return 0;
}
