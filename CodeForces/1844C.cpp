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
        ll odd = 0;
        bool f1 = false;
        ll even = 0;
        bool f2 = false;
        ll sol = INT_MIN;
        for(ll i=0; i<n; i++){
            cin >> arr[i];
            sol = max(sol, arr[i]);
            if(arr[i]>=0){
                if(i%2==0){
                    even += arr[i];
                    f1 = true;
                }
                else{
                    odd += arr[i];
                    f2 = true;
                }
            }
        }
        if(f1) sol = max(sol, even);
        if(f2) sol = max(sol, odd);
        cout << sol << "\n";
    }
 
    return 0;
}