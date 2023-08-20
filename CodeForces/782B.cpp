#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(15);

    ll n;
    cin >> n;
    vector<ll> x(n), v(n);
    for(auto& it:x) cin >> it;
    for(auto& it:v) cin >> it;

    double l = 0;
    double r = 1e9;
    ll t = 100;

    while(t--){
        double m = l + (r-l)/2;
        double lx = 1;
        double rx = 1e9;
        for(int i=0; i<n; i++){
            lx = max(lx, x[i] - m*v[i]);
            rx = min(rx, x[i] + m*v[i]);
        }
        if(lx <= rx) r = m;
        else l = m;


    }
    cout << r << "\n";



    return 0;
}