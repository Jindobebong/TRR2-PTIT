#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int t, n, u;
vector<int>adj[105];
bool vis[105];
vector<pair<int, int>>res;
void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            res.push_back({min(u, v), max(u, v)});
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int>q; 
    q.push(u);
    vis[u] = true; 
    while(!q.empty()){
        int u = q.front(); q.pop(); 
        for(int v : adj[u]){
            if(!vis[v]){
                res.push_back({min(u, v), max(u, v)});
                q.push(v); 
                vis[v] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> t >> n >> u;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x == 1) adj[i].push_back(j); 
        }
    }
    if(t == 1){
        dfs(u);
        cout << res.size() << endl; 
        for(auto [x, y] : res){
            cout << x << " " << y << endl;
        }
    }
    else if(t == 2){
        bfs(u);
        cout << res.size() << endl; 
        for(auto [x, y] : res){
            cout << x << " " << y << endl;
        }
    }
    return 0;
}