#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int dp[100005][25][3];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    ll n, k;
    cin >> n >> k;
    map<char, int> m;
    m['H'] = 0;
    m['S'] = 1;
    m['P'] = 2;
    for(int i=1; i<=n; i++){
        char a;
        cin >> a;
        for(int j=0; j<=k; j++){
            for(int l=0; l<3; l++){
                if(l==m[a]){
                    dp[i][j][l] = dp[i-1][j][l]+1;
                    if(j>0){
                        dp[i][j][l] = max({dp[i][j][l], dp[i-1][j-1][(l+1)%3]+1, dp[i-1][j-1][(l+2)%3]+1});
                    }
                }
                else{
                    dp[i][j][l] = dp[i-1][j][l];
                }
            }
        }
    }
    int sol = 0;
    for(int i=0; i<=k; i++){
        sol = max(sol, dp[n][i][0]);
        sol = max(sol, dp[n][i][1]);
        sol = max(sol, dp[n][i][2]);
    }
    cout << sol << "\n" ;
    return 0;
}