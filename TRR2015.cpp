#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int n; 
vector<int>adj[maxn], adj_t[maxn], weak[maxn];
bool vis[maxn];
stack<int>st;

void dfs1(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v])
            dfs1(v);
    }
    st.push(u);
}

void dfs2(int u){
    vis[u] = true;
    for(int v : adj_t[u]){
        if(!vis[v]){
            dfs2(v);
        }
    }
}

bool scc(){
    for(int i = 1; i <= n; ++i){
        if(!vis[i])
            dfs1(i);
    }
    memset(vis, 0, sizeof vis);
    int cnt = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!vis[u]){
            ++cnt; 
            dfs2(u);
        }
    }
    return cnt == 1;
}

void dfs_weak(int u){
    vis[u] = true;
    for(int v : weak[u]){
        if(!vis[v])
            dfs_weak(v);
    }
}

bool is_weakly_connected(){
    memset(vis, 0, sizeof vis);
    int cnt = 0; 
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            ++cnt; 
            dfs_weak(i);
        }
    }
    return cnt == 1;
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
                adj[i].push_back(j);
                adj_t[j].push_back(i);
                weak[i].push_back(j);
                weak[j].push_back(i);
            }   
        }
    }
    if(scc()) cout << 1;
    else if(is_weakly_connected())
        cout << 2;
    else 
        cout << 0;
    return 0;
}