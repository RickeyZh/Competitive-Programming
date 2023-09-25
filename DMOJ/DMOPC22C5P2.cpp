#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> odd = {0, 0, 1, 1};
    vector<bool> cur = {0, 1, 1, 0};
    if(n&1) cur = odd;
    int big = 0;
    int small = 0;
    vector<int> sol;
    for(int i=0; i<n; i++){
        if(cur[i%4]){
            sol.push_back(-1*(big+1));
        }
        else{
            sol.push_back(-1*(small-1));
        }
        small = min({0, sol[i], small+sol[i]});
        big = max({0, sol[i], big+sol[i]});
    }

    for(auto& it:sol) cout << it << " ";
    cout << "\n";

    return 0;
}