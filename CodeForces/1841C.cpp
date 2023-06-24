#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll calcNum(string str){
    ll num = 0;
    vector<ll> arr = {1, 10, 100, 1000, 10000};
    ll biggest = 0;
    for(ll i=str.size()-1; i>=0; i--){
        ll cur = arr[str[i]-'A'];
        if(cur<biggest){
            num -= cur;
        }
        else{
            biggest = cur;
            num += cur;
        }
    }
    return num;

}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        vector<ll> first(5);
        vector<ll> last(5);
        for(ll i=str.size()-1; i>=0; i--){
            ll index = str[i]-'A';
            if(first[index]==0){
                first[index] = i;
            }
            last[index] = i;
        }
        vector<char> c = {'A', 'B', 'C', 'D', 'E'};
        ll sol = calcNum(str);
        for(ll i=0; i<5; i++){
            char cur = str[first[i]];
            for(ll j=0; j<5; j++){
                str[first[i]] = c[j];
                sol = max(sol, calcNum(str));
            }
            str[first[i]] = cur;
        }
        for(ll i=0; i<5; i++){
            char cur = str[last[i]];
            for(ll j=0; j<5; j++){
                str[last[i]] = c[j];
                sol = max(sol, calcNum(str));
            }
            str[last[i]] = cur;
        }

        cout << sol << "\n";

    }


    return 0;
}