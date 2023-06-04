#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    string cur = "";
    map<int, int> m;
    m[0]++;
    int rem = 0;
    int digit = 1;
    int counter = 0;
    for(ll i=str.size()-1; i>=0; i--){
        int cur = (str[i]-'0') * digit;
        cur %= 2019;

        digit *= 10;
        digit %= 2019;

        rem += cur;
        rem %= 2019;

        counter += m[rem];
        m[rem]++;
    }
    cout << counter << "\n";

    return 0;
}