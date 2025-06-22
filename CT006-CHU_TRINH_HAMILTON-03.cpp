#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int n, u, a[105][105];
bool vis[105];
vector<int>path;
int mini = 1e9;
vector<int>ans;
int check;

void backtrack(int current, int cnt, int cost){
    if(cnt == n){
        if(a[current][u] != 10000 && a[current][u]){
            if(mini > cost + a[current][u]){
                check = 1;
                mini = cost + a[current][u];
                ans = path;
            }
        }
        return;
    }
    for(int v = 1; v <= n; ++v){
        if(!vis[v] && a[current][v] && a[current][v] != 10000){
            vis[v] = true;
            path.push_back(v);
            backtrack(v, cnt + 1, cost + a[current][v]);
            vis[v] = false;
            path.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> u; 
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    
    vis[u] = true;
    path.push_back(u);
    backtrack(u, 1, 0);

    if(check){
        cout << mini << endl;
        for(int i : ans)
            cout << i << " ";
        cout << u;
    }
    else cout << 0;
    return 0;
}