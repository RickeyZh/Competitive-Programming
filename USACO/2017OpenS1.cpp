#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    ll n;
    cin >> n;
    map<ll, ll> m;
    vector<pair<ll, ll>> arr;
    for(ll i=0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        arr.push_back({y, x});
    }
    sort(arr.begin(), arr.end());
    ll r = n-1;
    ll l = 0;
    ll sol = 0;
    while(l<=r){
        sol = max(sol, arr[r].first+arr[l].first);
        ll sub = min(arr[r].second, arr[l].second);
        arr[r].second -= sub;
        arr[l].second -= sub;
        if(arr[r].second<=0) r--;
        if(arr[l].second<=0) l++;
    }
    cout << sol << "\n";

    return 0;
}