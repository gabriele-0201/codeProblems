// NOTE: it is recommended to use this even if you don't understand the
// following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


// input data
int N, Q;
vector<int> V;

int getMax() {
                
    
    int out, checkOut, outX; 
    int gr, maxValues = 0;
    bool yup = true;

    for(gr = 0; gr < N - 1; ++gr) {
        for(int i = 0; i + gr < N; ++i) {

            out = V[i];
            outX = V[i];

            for(int z = i + 1; z <= i + gr; ++z) {
                out &= V[z];
                outX ^= V[z];
            }

            std::cout << "Initial check " << out <<std::endl;
            //std::cout << "Initial check " << outX <<std::endl;

            for(int j = i + gr + 1; j < N; ++j) {
                std::cout << "check with " << V[j] <<std::endl;
                checkOut = out & V[j];
                //std::cout << "Check with others " << checkOut <<std::endl;

                //std::cout << "Check with others " << (outX ^ V[j]) <<std::endl;
                if(checkOut == 0 && ((outX ^ V[j]) == 0)){
                    yup = false;
                    std::cout << "stop" <<std::endl;
                    break;
                }

            }
            if(!yup) {
                std::cout << "stop" <<std::endl;
                break;
            }
        }
        if(yup)
            maxValues = gr + 1;
        else 
            yup = true;
    }

    return maxValues;
}

int main() {
    //  uncomment the following lines if you want to read/write from files
      ifstream cin("input.txt");
    //  ofstream cout("output.txt");

    cin >> N >> Q;
    V.resize(N);
    for (int i = 0; i < N; i++)
        cin >> V[i];

    // insert your code here

    cout << getMax() << endl; // print the result before all the updates

    for (int i = 0; i < Q; i++) {
        int pos, val;
        cin >> pos >> val;

        V[pos - 1] = val;

        cout << getMax() << endl; // print the result before all the updates

        //cout << 42 << endl; // print the result after this update
    }

    return 0;
}
