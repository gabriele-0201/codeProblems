#include<iostream>
#include<math.h>

using namespace std;

int main(void) {
    long long n, a, b, k, m;

    cin >> n;

    bool found = false;

    //int a = floor(n / 2);
    a = n;
    //for(a = n; !found && a >= l; a--) {

        if(n % a == 0) {
            b = n / a;
            if((a + b) % 2 == 0){
               found = true;
                a++;
            }       
        }

    //}

    if(found)
        cout << ((a+b)/2) <<" " << (((a + b) / 2)- b);
    else
        cout<<"impossible";

}