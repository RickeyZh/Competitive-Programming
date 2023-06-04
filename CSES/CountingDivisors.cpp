#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int arr[1000005];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
 
    for(int i=2; i<1000005; i++){
        for(int j=i; j<1000005; j+=i){
            arr[j]++;
        }
    }
 
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        cout << arr[x]+1 << "\n";
    }
 
 
    return 0;
}