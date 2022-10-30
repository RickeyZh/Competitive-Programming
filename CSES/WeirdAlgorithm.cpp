#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    while(n!=1){
        cout << n << " ";
        if(n%2==0) n/=2;
        else n = n*3 + 1;
    }
    cout << "1\n";

    return 0;
}
