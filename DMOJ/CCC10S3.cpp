#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll M = 1000000;
bool work(vector<ll>& arr, ll len, ll k, ll n){
    for(int i=0; i<n; i++){
        ll j=i;
        ll start = INT_MIN;
        ll counter = 0;
        bool x = true;
        while(x){
            ll curlen;
            if(arr[j]<start){
                curlen = (M-start) + arr[j];
            }
            else{
                curlen = arr[j]-start;
            }

            if(curlen>len){
                start = arr[j];
                counter++;
            }

            if(counter>k) break;
            j++;
            j %= n;
            if(j==i) x = false;
        }
        if(counter<=k) return true;
    }
    return false;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(auto& i:arr){
        cin >> i;
    }
    sort(arr.begin(), arr.end());
    ll k;
    cin >> k;

    ll l = 0;
    ll r = M;
    ll sol = 0;
    while(l<=r){
        ll m = l + (r-l)/2;
        if(work(arr, m, k, n)){
            sol = m/2 + m%2;
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    cout << sol << "\n";


    return 0;
}