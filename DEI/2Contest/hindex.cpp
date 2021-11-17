#include<iostream>
#include<vector>

   using namespace std;

int n;
vector<int> v;
	
int check(int c) {
	int cnt=0;
	for(int  i=0; i < n; i++)
		if(c <= v[i])
			cnt++;
	return cnt;
	}

int main(void) {
	cin >> n;
	v = vector<int> (n);
	for(int i=0; i < n; i++)
		cin >> v[i];

	int first = 0;
    int last = n;
    int mid;
	while(first < last)	{
        mid = (first + last) / 2;
        if(check(mid) >= mid) {
            first = mid + 1;
        }
        else
            last = mid - 1;
	}

    if(check(first) >= first)
        cout << first;
    else   
        cout << first - 1;
}