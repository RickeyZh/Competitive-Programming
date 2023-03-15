#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1e9  + 7;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    while(n--){
        ll a, b;
        cin >> a >> b;
        ll sol = 1;
        while(b>0){
            if(b%2==1) sol *= a;
            sol %= MOD;
            a *= a;
            a %= MOD;
            b /= 2;
        }
        cout << sol << "\n";
    }

    return 0;
}