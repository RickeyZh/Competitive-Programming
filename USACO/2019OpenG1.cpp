#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[405][405];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n+1);
    for(int i=1; i<=n; i++) cin >> arr[i];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j] = INT_MAX;
        }
    }


    for(int i=1; i<=n; i++){
        ll s = 0;
        ll m = 0;
        for(int j=1; j<=i; j++){
            s += arr[j];
            m = max(m, arr[j]);
        }
        dp[i][0] = m*i - s;

        for(int j=1; j<=k; j++){
            s = 0;
            m = 0;
            for(int l=i; l>0; l--){
                s += arr[l];
                m = max(m, arr[l]);
                dp[i][j] = min(dp[i][j], m*(i-l+1) - s + dp[l-1][j-1]);
            }
        }
    }

    cout << dp[n][k] << "\n";



    return 0;
}