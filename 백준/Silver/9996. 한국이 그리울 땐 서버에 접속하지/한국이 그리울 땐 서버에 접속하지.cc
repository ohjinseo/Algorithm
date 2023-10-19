#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
string prefix, suffix;
string pattern;

int main(){
    cin >> n;
    cin >> pattern;
    int pos = pattern.find('*');

    prefix = pattern.substr(0, pos);
    suffix = pattern.substr(pos + 1);

    for(int i = 0; i < n; i++){
        string s; cin >> s;

        if(prefix.size() + suffix.size() > s.size()) cout << "NE";
        else{
            if(s.substr(0, prefix.size()) == prefix && s.substr(s.length() - suffix.size()) == suffix){
                cout << "DA";
            }else cout << "NE";
        }

        cout << "\n";
    }



}