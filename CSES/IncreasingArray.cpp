#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    int prev;
    cin >> prev;
    ll moves = 0;
    for(int i=1; i<n; i++){
        int x;
        cin >> x;
        moves += max(prev-x, 0);
        prev = max(prev, x);
    }
    cout << moves << "\n";
 
    return 0;
}
