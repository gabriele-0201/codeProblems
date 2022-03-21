#include<iostream> 
#include<algorithm> 
#include<vector> 
//#include<sstresm> 

using namespace std;

vector<int> a,b;
vector<vector<int>> dp;

//HAVE TO ADD A DP
//
//maybe a matrix with the right value
//
//i think that a n*m matrix is the right choise
//
//

int getMax(int indexA, int indexB, int aOb, int sum, int maxVal) {

    //cout << "a " << indexA <<endl;
    //cout << "b " << indexB <<endl;
    //cout << "current max val" <<maxVal <<endl;

    //caso base
    if(indexA >= a.size() && indexB >= b.size())
        return maxVal;

    switch(aOb) {
        case 0:
            sum += a[indexA];
            indexA++;
            break;
        case 1:
            sum += b[indexB];
            indexB++;
            break;
    }

    maxVal = max(maxVal, sum);
    int max1 = 0, max2 = 0;

    if(indexA < a.size())
        max1 = getMax(indexA, indexB, 0, sum, maxVal);
    if(indexB < b.size())
        max2 = getMax(indexA, indexB, 1, sum, maxVal);

    return max(max(max1, max2), maxVal);
}

int main(void) {
    vector<int> outs{};

    int t, counter;
    cin >> t;
    for(int z = 0; z < t; ++z) {
        int n, m, numb;
        //string line;
        //getline(cin, line);
        //stringstream X (line);

        a = vector<int>();
        b = vector<int>();

        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> numb;
            a.push_back(numb);
        }

        //string line;
        //getline(cin, line);
        //stringstream X (line);

        cin >> m;
        for(int i = 0; i < m; ++i) {
            cin >> numb;
            //cout << "something wrong" <<numb <<endl;
            b.push_back(numb);
        }

        dp = vector<vector<int>> (n, vector<int> {m, -1});
        
        //cout << "something wrong" <<numb <<endl;

        //int max1 = getMax(0,0,0,0,0);
        //int max2 = getMax(0,0,1,0,0);
        
        int maxVal = max(a[0], b[0]);
        if(maxVal < 0)
            maxVal = 0;

        for(int i = 1; i < n; ++i) {
           a[i] = a[i - 1] + a[i];
           //cout << a[i] <<" ";
           if(a[i] > maxVal)
               maxVal = a[i];
        }
        //cout << endl;

        for(int i = 1; i < m; ++i) {
           b[i] = b[i - 1] + b[i];
           //cout << b[i] <<" ";
           if(b[i] > maxVal)
               maxVal = b[i];
        }

        //cout << endl;

        for(int i = 0; i < m; ++i) {
            int val;
            for(int j = 0; j < n; ++j) {
                val = b[i] + a[j];
                //cout << val <<" ";
                if(val > maxVal)
                    maxVal = val;

            }
            //cout << endl;
        }

        outs.push_back(maxVal);
    }

    for(auto i = outs.begin(); i != outs.end(); i++)
        cout << *i << endl;

}
