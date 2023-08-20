#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int dp[1005];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> coins(n+1);
    vector<vector<int>> arr(n+1);
    for(int i=1; i<=n; i++){
        cin >> coins[i];
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }
    for(int i=0; i<1005; i++) dp[i] = INT_MIN;
    dp[1] = 0;

    queue<vector<ll>> q;
    q.push({1, 0, 0});
    while(!q.empty()){
        int a = q.front()[0];
        int b = q.front()[1];
        int c2 = q.front()[2];
        q.pop();
        if(dp[a] > c2 - c*b*b) continue;
        dp[a] = c2 - c*b*b;
        for(auto it:arr[a]){
            q.push({it, b+1, c2 + coins[it]});
        }

    }


    cout << dp[1] << "\n";


    return 0;
}