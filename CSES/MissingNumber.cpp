#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll rem = n*(n+1)/2;
    for(int i=0; i<n-1; i++){
        int in;
        cin >> in;
        rem -= in;
    }
    cout << rem << "\n";
  
    return 0;
}
