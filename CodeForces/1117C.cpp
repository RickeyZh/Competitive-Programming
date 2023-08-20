#include <bits/stdc++.h>
typedef long long ll;
int xchange[100005];
int ychange[100005];
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll x, y, x2, y2, n;
    cin >> x >> y >> x2 >> y2 >> n;
    string str;
    cin >> str;
    ll l = 0;
    ll r = 1e15;
    ll sol = -1;
    map<char, ll> m1;
    m1['L'] =  -1;
    m1['R'] = 1;
    map<char, ll> m2;
    m2['U'] = 1;
    m2['D'] = -1;
    for(int i=0; i<n; i++){
        if(i!=0){
            xchange[i] = xchange[i-1];
            ychange[i] = ychange[i-1];
        }
        xchange[i] += m1[str[i]];
        ychange[i] += m2[str[i]];
    }
    while(l<=r){
        ll m = l + (r-l)/2;
        ll cx = x;
        ll cy = y;
        cx += m/n*xchange[n-1];
        cy += m/n*ychange[n-1];
        if(m%n!=0){
            cx += xchange[(m-1)%n];
            cy += ychange[(m-1)%n];
        }

        ll ex = abs(cx-x2) + abs(cy-y2);
        if(ex <= m){
            sol = m;
            r = m-1;
        }
        else{
            l = m+1;
        }

    }

    cout << sol << "\n";



    return 0;
}