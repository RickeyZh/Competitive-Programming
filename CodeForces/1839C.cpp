#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        if(arr[n-1]==1){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<int> sol(n);
        int index = 0;
        int counter = 0;
        for(int i=n-1; i>=0; i--){

            if(arr[i]==1){
                counter++;
            }
            else if(counter!=0){
                sol[i+1] = counter;
                counter = 0;
            }
        }
        sol[0] = counter;

        for(int i=n-1; i>=0; i--){
            cout << sol[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}