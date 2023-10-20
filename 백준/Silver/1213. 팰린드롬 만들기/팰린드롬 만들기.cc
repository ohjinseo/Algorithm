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


int cnt[200];
char mid;
string ret;
int flag;
string str;

int main()
{
    

    cin >> str;

    for(char c : str){
        cnt[c]++;
    }
    

    for(char c = 'Z'; c >= 'A'; c--){
        if(cnt[c] & 1){
            mid = c;
            flag++;
            cnt[c]--;
        }

        if(flag == 2) break;

        for(int i = 0; i < cnt[c]; i += 2){
            ret+=c;
            ret=c+ret;
        }
    }
    if(mid) ret.insert(ret.begin() + ret.length() / 2, mid);

    if(flag == 2) cout <<"I'm Sorry Hansoo";
    else{
        
        cout << ret; 
    }

    return 0;
}
