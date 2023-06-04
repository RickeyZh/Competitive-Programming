#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    vector<ll> arr2(m);
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }
    for(ll i=0; i<m; i++){
        cin >> arr2[i];
    }
    ll prev = 0;
    ll sol = 0;
    for(ll i=0; i<n; i++){
        while(prev<m-1 && abs(arr2[prev+1]-arr[i]) <= abs(arr2[prev]-arr[i])){
            prev++;
        }
        sol = max(sol, abs(arr[i]-arr2[prev]));
    }
    cout << sol << "\n";
    return 0;
}