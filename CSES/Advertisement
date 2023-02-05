#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    stack<pair<ll, ll>> stk;
    ll sol = 0;
    for(ll i=0; i<n; i++){
        ll a;
        cin >> a;
        ll left = i;
        while(!stk.empty() && stk.top().first>=a){
            left = stk.top().second;
            sol = max(sol, stk.top().first * (i-stk.top().second));
            stk.pop();
        }
        stk.push({a, left});
    }
    while(!stk.empty()){
        sol = max(sol, stk.top().first * (n-stk.top().second));
        stk.pop();
    }
    cout << sol << "\n";

    return 0;
}
