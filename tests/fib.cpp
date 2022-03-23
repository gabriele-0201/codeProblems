#include <iostream>

using namespace std;

int fib(int db[], int n) {

    cout << "chiamata con n: " <<n <<endl;

    if(db[n] != 0)
        return db[n];

    int res;
    if(n == 0)
        res = 0;
    else if(n == 1)
        res = 1;
    else 
        res = fib(db, n - 1) + fib(db, n - 2);

    db[n] = res;
    return res;
}

int main(void) {
    int n;
    do {
        cin >> n;
    } while(n <= 0);

    int db[n + 1] = { 0 };
    cout << fib(db, n) <<endl;

}

