#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int arr[1000005];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll sol = 1;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        ll c = a/sol;
        for(ll j=1; j*j<=a; j++){

            if(j > c) break;

            if(a%j==0){
                ll b = a/j;

                if(j!=b){
                    arr[b]++;
                    if(arr[b] >= 2) sol = max(sol, b);
                }
                arr[j]++;
                if(arr[j]>=2){
                    sol = max(sol, j);
                }
            }
        }
    }
    cout << sol << "\n";


    return 0;
}