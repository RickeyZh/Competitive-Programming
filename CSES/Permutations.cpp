#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if(n==1){
        cout << "1\n";
    } else if(n<=3){
        cout << "NO SOLUTION\n";
    } else{
        for(int i=2; i<=n; i+=2){
            cout << i << " ";
        }
        for(int i=1; i<=n; i+=2){
            cout << i << " ";
        }
    }

    return 0;
}
