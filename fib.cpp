#include <iostream>

using namespace std;

int fib(int[]& db, int n) {
    if(db[n - 1] != 0)
        return db[n - 1];

    int res;
    if(n == 0)
        res = 0;
    else if(n == 1)
        res = 1;
    else 
        res = fib(db, n -1) + fib(db, n - 2);

    db[]

    else 

}

int main(void) {
    int f;
    do {
        cin >> f;
    } while(f <= 0);

    int db[f] = { 0 };
    cout << fib(db, n) <<endl;

}

