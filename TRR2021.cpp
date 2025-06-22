#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int n, a[105][105];
bool vis[105];
vector<int>adj[105];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v])
            dfs(v);
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
vector<int>res;
void canh_cau(){
    int cc = tplt();
    for(int i = 1; i <= n; ++i){
        memset(vis, 0, sizeof vis);
        vis[i] = true;
        if(cc < tplt()) res.push_back(i);
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
            cin >> a[i][j];
            if(a[i][j] == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
        }
    }
    canh_cau();
    cout << res.size() << endl;
    for(auto x : res)
        cout << x << " ";
    return 0;
}