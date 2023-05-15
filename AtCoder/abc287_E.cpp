#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[2000005];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
 
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i];
 
    sort(arr.begin(), arr.end());
 
    vector<ll> in(n);
    priority_queue<pair<ll, ll>> pq;
    unordered_map<ll, bool> visited;
 
    for(ll i=0; i<n; i++){
        bool x = false;
        for(ll j=0; j<n; j++){
            if(j==i) continue;
            else if(arr[i]%arr[j]==0){
                if(arr[i]==arr[j] && !visited[arr[i]]) continue;
 
                x = true;
                break;
            }
        }
        if(x) continue;
        pq.push({-1*arr[i], i});
        visited[arr[i]] = true;
    }
 
    int dpsize = 0;
    while(dpsize<=k && !pq.empty()){
        ll cur = -1*pq.top().first;
        ll index = pq.top().second;
        pq.pop();

        dp[dpsize] = cur;
        dpsize++;
 
        while(in[index] <= dpsize && visited[arr[index] + dp[in[index]]]) in[index]++;
 
        if(in[index]>dpsize) continue;

        pq.push({-1*(arr[index] + dp[in[index]]), index});
        visited[arr[index] + dp[in[index]]] = true;
        in[index]++;
    }
 
    cout << dp[k-1] << "\n";
 
    return 0;
}