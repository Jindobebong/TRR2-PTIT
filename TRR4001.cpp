#include <bits/stdc++.h>
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, s;
vector<pair<int, int>>dscanh;
vector<int>adj[maxn];
bool vis[maxn];
int cnt;
vector<pair<int, int>>res, res1;

void dfs(int u){
    vis[u] = true;
    cnt++;
    for(int v : adj[u]){
        if(!vis[v]){
            res.push_back({u, v});
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int>q; 
    q.push(u); 
    vis[u] = true;
    cnt++;
    while(!q.empty()){
        auto x = q.front(); q.pop(); 
        for(int v : adj[x]){
            if(!vis[v]){
                res.push_back({x, v});
                vis[v] = true;
                cnt++;
                q.push(v);
            }
        }
    }
}


void nhap(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x == 1){
                if(i < j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> t >> n >> s; 
    nhap();
    if(t == 1)
        dfs(s);
    else    
        bfs(s);
    
    if(cnt == n){
        cout << res.size() << endl;
        for(auto [x, y] : res)
            cout << min(x, y) << " " << max(x, y) << endl;
    }
    else    
        cout << 0;
    return 0;
}