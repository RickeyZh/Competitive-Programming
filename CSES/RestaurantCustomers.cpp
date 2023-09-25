#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll index = 0;
    ll sol = 0;
    for(int i=0; i<n; i++){
        while(index<n && b[index]<=a[i]){
            index++;
        }
        sol = max(sol, i-index+1);
    }
    cout << sol << "\n";
    return 0;
}