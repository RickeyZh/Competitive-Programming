#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll mod = 1e9 + 7;
vector<vector<ll>> mult(vector<vector<ll>> arr1, vector<vector<ll>> arr2){
    vector<vector<ll>> sol(2, vector<ll>(2));
    for(ll i=0; i<2; i++){
        for(ll j=0; j<2; j++){
            for(ll k=0; k<2; k++){
                sol[i][j] += (arr1[i][k]%mod) * (arr2[k][j]%mod);
                sol[i][j] %= mod;
            }
        }
    }
    return sol;
}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
 
    vector<vector<ll>> arr = {
        {1, 1},
        {1, 0}
    };
    vector<vector<ll>> sol = {
        {1, 1},
        {1, 0}
    };
    ll n;
    cin >> n;
    if(n==0){
        cout << "0\n";
        return 0;
    }
    n--;
    while(n>0){
        if(n%2){
            sol = mult(sol, arr);
        }
        arr = mult(arr, arr);
        n /= 2;
    }
    cout << sol[0][1];
 
 
 
    return 0;
}