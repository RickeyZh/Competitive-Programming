#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string str;
    cin >> str;
    map<char, bool> m;
    int dif = 0;
    for(int i=0; i<n; i++){
        if(!m[str[i]]){
            dif++;
            m[str[i]] = true;
        }
    }
    int l = 0;
    int r = 0;
    int counter = 0;
    map<char, int> caught;
    int sol = INT_MAX;
    while(r<n){
        if(caught[str[r]]==0){
            counter++;
        }
        caught[str[r]]++;
        while(counter==dif){
            sol = min(sol, r-l+1);
            caught[str[l]]--;
            if(caught[str[l]]==0){
                counter--;
            }
            l++;
        }
        r++;
    }
    cout << sol << "\n";

    return 0;
}