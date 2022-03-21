// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

// input data
int N;
long long K;
vector<int> V;

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("inputWine.txt");
//  ofstream cout("output.txt");

    cin >> N >> K;
    V.resize(N);
    int totSum = 0;
    for (int i = 0; i < N; i++) {
        //cout << "soos" ;
        cin >> V[i];
        totSum += V[i];
    }

    //cout << "toto sum " <<totSum << endl;

    // insert your code here
    int S= 42, E = 69;
    //unordered_set<int, pair<int, int>> set;
    int k = 0;

    for(int p = 1; p <= totSum; ++p) {

        int j = 0;
        int counter = 0;
        for(int i = 0; i < N; ++i) {
            

            counter += V[i];
            //cout << j << " " << i << endl;
            //cout << counter <<endl;

            if(counter == p) {
                k++;
                //cout << "sssusss" <<endl;
                counter -= V[j];
                if(k != K)
                    j++;
            } else if(counter > p) {

                if(j < i) {
                    counter -= V[j];
                    j++;
                    counter -= V[i];
                    i--;
                } else {
                    counter -= V[i];
                    j++;
                }
            }

            if(k == K) {
                S = j;
                E = i;
                break;
            }


        }

        if(k == K) {
            break;
        }
    }

    // print the result
    cout << S << ' ' << E << endl;
    return 0;
}
