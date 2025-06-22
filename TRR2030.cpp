#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int n, a[maxn][maxn];
set<int>adj[maxn];
vector<pair<int, int>>dscanh;
bool vis[maxn];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int tplt(){
    int cnt = 0; 
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            ++cnt; 
            dfs(i);
        }
    }
    return cnt;
}

vector<pair<int, int>>res;
void canh_cau(){
    int cc = tplt();
    for(auto [x, y] : dscanh){
        memset(vis, 0, sizeof vis);
        adj[x].erase(y);
        adj[y].erase(x);
        if(cc < tplt()) res.push_back({x, y});
        adj[x].insert(y);
        adj[y].insert(x);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n; 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x == 1){
                adj[i].insert(j);
                adj[j].insert(i);
                if(i < j) dscanh.push_back({i, j});
            }
        }
    }
    canh_cau();
    cout << res.size() << endl;
    for(auto [x, y] : res)
        cout << x << " " << y << endl;
    return 0;
}