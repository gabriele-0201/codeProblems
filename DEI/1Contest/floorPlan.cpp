#include<iostream>
#include<math.h>

#define PI 3.14159265

using namespace std;

int main(void) {
    long long n, a, b, k;
    double m;

    cin >> n;

    bool found = false;

    double tethaP = asin(1 / sqrt(n + 1));
    double tetha = tethaP;
    k = 1;

    while (!found && tetha < PI/4) {

        m = k / sin(tetha);

        if(m - floor(m) == 0)
            found = true;

        tethaP = tethaP + tetha;
        k++;
    }
   
    if(found)
        cout << m <<" " << k;
    else
        cout<<"impossible";

}