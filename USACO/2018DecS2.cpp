#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(3));
    ll in = n;
    for(auto& it: arr){
        cin >> it[0] >> it[1];
        it[2] = in;
        in--;
    }

    sort(arr.begin(), arr.end());
    ll start = 0;
    ll cost = 0;

    priority_queue<pair<ll, ll>> pq;

    for(int i=0; i<n; i++){
        pq.push({arr[i][2], i});
        while(!pq.empty()){
            ll c = pq.top().second;

            start = max(start, arr[c][0]);
            while(i<n-1 && start>=arr[i+1][0]){
                pq.push({arr[i+1][2], i+1});
                i++;
            }

            c = pq.top().second;

            ll a = arr[c][0];
            ll b = arr[c][1];
            pq.pop();

            cost = max(cost, start - a);

            start += b;
        }

    }
    cout << cost << "\n";



    return 0;
}