#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int minX = -1;
int minY = -1;
int maxX = -1;
int maxY = -1;
vector<int> areas;

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

int calcArea(vector<int> r) {
    int base  = abs(r[0] - r[2]);
    int heiht = abs(r[1] - r[3]);
    return base * heiht;
}

bool checkArea() {
    int sum = 0;
    for(int a : areas)
        sum += a;

    int base  = abs(maxX - minX);
    int heiht = abs(maxY - minY);
    int area =  base * heiht;

    if(sum == area)
        return true;
    else 
        return false;
}

bool checkEdges() {

    int base  = abs(maxX - minX);
    int heiht = abs(maxY - minY);

    if (base == heiht)
        return true;
    else 
        return false;

}

int main(void) {

    int n;
   	vector<vector<int>> reqs;
   	cin >> n;

   	for(int i = 0; i < n; i++) {
        reqs.push_back(vector<int>());
   		for(int j = 0; j < 4; j++) {
   			int x;
   			cin >> x;
   			reqs[i].push_back(x);
   		}
   		findMinXY(reqs[i]);
   		findMaxXY(reqs[i]);
   	}

   	for(int i = 0; i < n; i++) {
        int a = calcArea(reqs[i]);
        areas.push_back(a);
    }

    if(checkArea()){
        if(checkEdges()){
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    else {
        cout << "NO";
    }

    return 0;
}