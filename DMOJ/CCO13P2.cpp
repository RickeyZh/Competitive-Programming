#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll sk[5000000]; // skill
ll pl[5000000]; // player
ll arr[5000000];
ll counter = 0;
void init(ll n, ll l, ll r){
    if(l==r){
        sk[n] = arr[l];
        pl[n] = l;
        return;
    }
    ll m = l + (r-l)/2;
    init(n*2, l, m);
    init(n*2+1, m+1, r);
    ll a = sk[n*2];
    ll b = sk[n*2+1];
    if(a>b){
        sk[n] = a;
        pl[n] = pl[n*2];
    }
    else{
        sk[n] = b;
        pl[n] = pl[n*2+1];
    }
}
void upd(ll n, ll l, ll r, ll i){
    if(l==i && r==i){
        sk[n] = arr[l];
        pl[n] = l;
        return;
    }
    ll m = l + (r-l)/2;
    if(i<=m){
        upd(n*2, l, m, i);
    }
    else{
        upd(n*2+1, m+1, r, i);
    }

    ll a = sk[n*2];
    ll b = sk[n*2+1];
    if(a>b){
        sk[n] = a;
        pl[n] = pl[n*2];
    }
    else{
        sk[n] = b;
        pl[n] = pl[n*2+1];
    }
}
void q(ll n, ll l, ll r, ll i){
    if(l==i && r==i) return;

    if(pl[n]==i) counter++;

    ll m = l + (r-l)/2;
    if(i<=m){
        q(n*2, l, m, i);
    }
    else{
        q(n*2+1, m+1, r, i);
    }

}
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    n = 1<<n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    init(1, 1, n);

    while(m--){
        char a;
        cin >> a;
        if(a=='W'){
            cout << pl[1] << "\n";
        }
        else if(a=='S'){
            int b;
            cin >> b;
            counter = 0;
            q(1, 1, n, b);
            cout << counter << "\n";
        }
        else{
            int b, c;
            cin >> b >> c;
            arr[b] = c;
            upd(1, 1, n, b);
        }
    }
    return 0;
}