#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
 
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++){
            cin >> arr[i];
        }
        vector<ll> l(n);
        for(ll i=0; i<n; i++){
            l[i] = arr[i]+i+1;
            if(i!=0) l[i] = max(l[i], l[i-1]);
        }
        vector<ll> r(n);
        for(int i=n-1; i>=0; i--){
            r[i] = arr[i]-i-1;
            if(i!=n-1) r[i] = max(r[i], r[i+1]);
        }
        ll sol = 0;
        for(int i=1; i<n-1; i++){
            sol = max(sol, arr[i]+l[i-1]+r[i+1]);
        }
        cout << sol << "\n";
    }
 
    return 0;
}