#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[2][1000005];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll mod = 1e9 + 7;
    dp[0][1] = 1;
    dp[1][1] = 1;
    for(int i=2; i<=1000000; i++){
        dp[0][i] = dp[0][i-1]*2 + dp[1][i-1];
        dp[0][i] %= mod;
        dp[1][i] = dp[1][i-1]*4 + dp[0][i-1];
        dp[1][i] %= mod;
    }
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << (dp[0][n] + dp[1][n])%mod << "\n";
    }
 
 
 
 
    return 0;
}