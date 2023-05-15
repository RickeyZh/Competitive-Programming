#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll a = y3*x2 - y3*x1;
        ll b = y1*(x2-x1) - x1*(y2-y1);
        a -= b;
        x3 *= (y2-y1);

        if(a==x3) cout << "TOUCH\n";
        else if(a>x3) cout << "LEFT\n";
        else cout << "RIGHT\n";

    }


    return 0;
}