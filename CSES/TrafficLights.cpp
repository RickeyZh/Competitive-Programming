#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;
    set<int> loc;
    loc.insert(0);
    loc.insert(x);
    priority_queue<int> dis;
    dis.push(x);
    priority_queue<int> update;
    while(n--){
        int pos;
        cin >> pos;
        auto r = loc.upper_bound(pos);
        auto l = r;
        l--;
        update.push(*r-*l);
        dis.push(pos-*l);
        dis.push(*r-pos);
        loc.insert(pos);
        while(!dis.empty() && !update.empty() && dis.top()==update.top()){
            update.pop();
            dis.pop();
        }
        cout << dis.top() << " ";
    }

    return 0;
}