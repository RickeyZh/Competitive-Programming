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
        int sol = 0;
        for(int i=1; i<=n; i++){
            sol = i;
            if(n%i!=0) break;
        }
        for(int i=0; i<n; i++){
            cout << (char)('a' + (i%sol));
        }
        cout << "\n";
    }
 
    return 0;
}