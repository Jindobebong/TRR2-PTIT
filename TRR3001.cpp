#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, u;
set<int>adj[maxn];
int deg[maxn];
bool vis[maxn];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v])
            dfs(v);
    }
}
void nhap(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x == 1 && i < j){
                adj[i].insert(j);
                adj[j].insert(i);
                deg[i]++;
                deg[j]++;
            }
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
    return cnt == 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> t; 
    if(t == 1) cin >> n; 
    else cin >> n >> u;
    nhap();
    if(t == 1){
        int odd = 0; 
        for(int i = 1; i <= n; ++i){
            if(deg[i] % 2) ++odd;
        }
        if(!tplt()) cout << 0; 
        else{
            if(odd == 2) cout << 2; 
            else if(odd == 0) cout << 1; 
            else cout << 0;
        }
    }
    else if(t == 2){
        stack<int>st;
        st.push(u);
        vector<int>path;
        while(!st.empty()){
            int u = st.top();
            
            if(!adj[u].empty()){
                int v = *adj[u].begin();
                st.push(v);
                adj[u].erase(v);
                adj[v].erase(u);
            }
            else{
                st.pop();
                path.push_back(u);
            }
        }
        reverse(path.begin(), path.end());
        for(auto x : path)
            cout << x << " ";
    }
    return 0;
}