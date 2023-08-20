#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    ll l = 1;
    ll r = 1e12;
    ll med = (n*n)/2 + 1;
    while(l<=r){
        ll m = l + (r-l)/2;
        ll lx = 0;
        ll rx = 0;
        for(int i=1; i<=n; i++){
            ll temp = (m-1)/i;
            lx += min(n, temp);
            rx += max((ll)0, n-temp);
            if(m%i==0 && m/i <= n) rx--;
        }
        if(lx < med && rx < med){
            cout << m << "\n";
            return 0;
        }

        if(lx>=med){
            r = m-1;
        }
        else l = m+1;
    }

    return 0;
}