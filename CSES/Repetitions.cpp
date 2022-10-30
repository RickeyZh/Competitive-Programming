#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    char prev = '$';
    int curCount = 0;
    int maxCount = 0;
    for(char ch:str){
        if(ch==prev){
            curCount++;
        }
        else{
            maxCount = max(maxCount, curCount);
            prev = ch;
            curCount = 1;
        }
    }
    maxCount = max(maxCount, curCount);
    cout << maxCount << "\n";

    return 0;
}
