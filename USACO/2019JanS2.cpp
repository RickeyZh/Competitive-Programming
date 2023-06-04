#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
char arr[1005][1005];
bool visited[1005][1005];
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> q;
    int area = 0;
    int per = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int curPer = 0;
            int curArea = 0;
            if(arr[i][j]=='#' && !visited[i][j]){
                q.push({i, j});
                visited[i][j] = true;
            }
            while(!q.empty()){
                int a = q.front().first;
                int b = q.front().second;
                curArea++;
                q.pop();
                if(!visited[a+1][b]){
                    if(arr[a+1][b]=='#'){
                        q.push({a+1, b});
                        visited[a+1][b] = true;
                    }
                    else{
                        curPer++;
                    }
                }

                if(!visited[a-1][b]){
                    if(arr[a-1][b]=='#'){
                        q.push({a-1, b});
                        visited[a-1][b] = true;
                    }
                    else{
                        curPer++;
                    }
                }

                if(!visited[a][b+1]){
                    if(arr[a][b+1]=='#'){
                        q.push({a, b+1});
                        visited[a][b+1] = true;
                    }
                    else{
                        curPer++;
                    }
                }

                if(!visited[a][b-1]){
                    if(arr[a][b-1]=='#'){
                        q.push({a, b-1});
                        visited[a][b-1] = true;
                    }
                    else{
                        curPer++;
                    }
                }
            }
            if(curArea>area){
                area = curArea;
                per = curPer;
            }
            else if(curArea==area){
                per = min(per, curPer);
            }
        }
    }
    cout << area << " " << per << "\n";
    return 0;
}