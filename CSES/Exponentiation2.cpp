#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll mod = 1e9 + 7;
    ll n;
    cin >> n;
    while(n--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll helper = 1;
        while(c>0){
            if(c%2){
                helper *= b;
                helper %= mod-1;
            }
            b *= b;
            b %= mod-1;
            c /= 2;
        }
        ll helper2 = 1;
        while(helper>0){
            if(helper%2){
                helper2 *= a;
                helper2 %= mod;
            }
            a *= a;
            a %= mod;
            helper/=2;
        }
        cout << helper2 << "\n";
    }
 
    return 0;
}