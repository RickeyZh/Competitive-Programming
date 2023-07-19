#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> first(n/2);
    vector<int> second(n/2);
    vector<int> arr;
    map<int, bool> m;
    for(int i=0; i<n/2; i++){
        cin >> first[i];
        m[first[i]] = true;
    }
    for(int i=n/2; i<n; i++){
        cin >> second[i - n/2];
        m[second[i - n/2]] = true;
    }
    for(int i=1; i<=n*2; i++){
        if(!m[i]){
            arr.push_back(i);
        }
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    int counter = 0;
    int r = n-1;
    int l = 0;
    for(int i=n/2 - 1; i>=0; i--){
        if(arr[r] > first[i]){
            counter++;
            r--;
        }
    }
    for(int i=0; i<n/2; i++){
        if(arr[l]<second[i]){
            counter++;
            l++;
        }
    }
    cout << counter << "\n";

    return 0;
}