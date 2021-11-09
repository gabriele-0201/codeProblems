#include<iostream>
#include<vector>

using namespace std;

bool mtx[31400][31400];
int minX = -1;
int minY = -1;
int maxX = -1;
int maxY = -1;

void draw(vector<vector<int>>& r, int n) {
	for(int i = r[n][1]; i <= r[n][3]; i++) {
		for(int j = r[n][0]; j <= r[n][2]; j++) {
			mtx[i][j] = true;
		}
	}
}

void checkSquare() {
	int i = minY;
	int j = minX;
	int cLine = 0;
	
	cout << maxY << " " << maxX << endl;
	cout << i << " " << j << endl;

	while(mtx[i][j] == true) {
		j++;
		if(j > maxX) {
			i++;
			j = minX;
			cLine++;
		}
		cout << i << " " << j << endl;
	}

	cout << cLine <<endl;

	if(cLine - 1 == (maxY - minY))
		cout << "YES";
	else 
		cout << "NO";
		
}

void findMinXY(vector<int>& v) {
	if(minX == -1 && minY == -1){
		minX = v[0];
		minY = v[1];
		return;
	}

	if(minX > v[0])	
		minX = v[0];
 	if(minY > v[1])	
		minY= v[1];
}

void findMaxXY(vector<int>& v) {
	if(maxX < v[2])	
		maxX = v[2];
 	if(maxY < v[3])	
		maxY= v[3];
}

int main(void) {
	int n;
	vector<vector<int>> reqs;
	cin >> n;	
	for(int i = 0; i < n; i++) {
		vector<int> tmp;
		for(int j = 0; j < 4; j++) {
			int x;
			cin >> x;
			tmp.push_back(x);
		}
		findMinXY(tmp);
		findMaxXY(tmp);
		reqs.push_back(tmp);
	}


	for(int i = 0; i < n; i++) {
		draw(reqs, i);		
	}

	checkSquare();	

}
