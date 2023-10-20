#include <iostream>

#include <string>

#include <stack>

using namespace std;

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        int N;

        cin >> N;

 

        int result = 0;

        for (int i = 0; i < N; i++)

        {

                 string str;

                 cin >> str;

 

                 stack<char> s;

 

                 for (int j = 0; j < str.length(); j++)

                 {

                         //이전 알파벳과 현재 알파벳이 같은 경우 한 쌍

                         if (!s.empty() && s.top() == str[j])

                                 s.pop();

                         else

                                 s.push(str[j]);

                 }

                

                 if (s.empty())

                         result++;

        }

        cout << result << "\n";

        return 0;

}



