#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define matrix vector<vector<ll>>
#define endl "\n"
using namespace std;

int t, n, m, u, v;
vector<int>adj[maxn];
int a[105][105], p[105];
bool vis[maxn];

void bfs(int u){
    queue<int>q; 
    q.push(u);
    vis[u] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int v : adj[x]){
            if(!vis[v]){
                p[v] = x;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> t >> n >> u >> v;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if(a[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }
    if(t == 1){
        int res[n + 5][n + 5] = {0};
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                for(int k = 1; k <= n; ++k)
                    res[i][j] = (res[i][j] + a[i][k] * a[k][j]);
            }
        }
        cout << res[u][v];
    }
    else{
        vector<int>res;
        bfs(u);
        if(!vis[v]) cout << 0; 
        else{
            while(v != u){
                res.push_back(v);
                v = p[v];
            }
            res.push_back(u);
            reverse(res.begin(), res.end());
            for(auto x : res)
                cout << x << " ";
        }
    }
    return 0;
}