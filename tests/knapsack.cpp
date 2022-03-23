#include <iostream>

#define capacity 20

using namespace std;

int weights [5] = { 3 , 5 , 10 , 4, 9};
int values[5] = { 3, 6 , 8, 5, 7};
int db[5][capacity] = { 0 };

int kc(int n, int c) {
    
    //cout << "n: " <<n <<" c: " << c << endl;

    if(db[n][c] != 0) 
        return db[n][c];

    int res;

    if(n >= sizeof(weights) / sizeof(weights[0]) || c <= 0)
        res = 0;
    else if(weights[n] > c)
        res = kc(n + 1, c);
    else {
        int tmp1 = kc(n + 1, c);
        int tmp2 = weights[n] + kc(n + 1, c - weights[n]);
        res = max(tmp1, tmp2);
    }

    db[n][c] = res;
    return res;

}

int main(void) {

    cout << "res: " << kc(0, capacity) <<endl;

}
