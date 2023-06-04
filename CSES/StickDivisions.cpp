#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
 
 
 
    ll x, n;
    cin >> x >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i=0; i<n; i++){
        ll a;
        cin >> a;
        pq.push(a);
    }
    ll sum = 0;
    while(pq.size()>1){
        ll a = pq.top();
        pq.pop();
        a += pq.top();
        pq.pop();
        pq.push(a);
        sum += a;
    }
    cout << sum << "\n";
 
 
    return 0;
}
