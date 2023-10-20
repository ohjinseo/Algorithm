/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n;


int main()
{
    int T;
    cin >> T;
    

    while(T--){
        map<string, int> m;
        cin >> n;
        for(int i = 0; i < n; i++){
            string a, b;
        cin >> a >> b;
        m[b]++;
        }
        

        long long ret = 1;

    for(auto c : m){
        ret *= ((long long)c.second + 1);
    }

    cout << ret - 1 <<"\n";
    }

    

    return 0;
}
