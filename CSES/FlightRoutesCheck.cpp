#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool can[100005];
bool visited[100005];
int pre[100005];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n+1);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }

    queue<int> q;
    stack<int> stk;
    q.push(1);
    visited[1] = true;
    int vis = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(auto it:arr[a]){
            if(!visited[it]){
                q.push(it);
                visited[it] = true;
                vis++;
            }
        }
    }
    if(vis==n) can[1] = true;
    else{
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                cout << "NO\n";
                cout << "1 " << i << "\n";
                return 0;
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(can[i]) continue;
        memset(visited, false, sizeof(visited));

        q.push(i);
        visited[i] = true;
        pre[i] = 0;

        bool work = false;
        int worked = 0;
        while(!q.empty()){
            int a = q.front();
            q.pop();
            for(auto it:arr[a]){
                if(!visited[it]){
                    visited[it] = true;
                    pre[it] = a;
                    q.push(it);

                    if(can[it]){
                        work = true;
                        worked = it;
                        while(!q.empty()) q.pop();
                        break;
                    }
                }
            }
        }
        if(work){
            while(pre[worked]!=0){
                worked = pre[worked];
                can[worked] = true;
            }
        }
        else{
            cout << "NO\n";
            cout << i << " 1\n";
            return 0;
        }
    }
    cout << "YES\n";

    return 0;
}