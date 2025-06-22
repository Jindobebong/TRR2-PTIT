#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, m, u;
vector<set<int>>adj(maxn);
int deg[maxn];
bool vis[maxn];

void nhap(){
    if(t == 2) cin >> u; 
    for(int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }
}

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
        if(!vis[i] && deg[i] > 0){
            ++cnt; 
            dfs(i);
        }
    }
    for(int i = 1; i <= n; ++i){
        if(deg[i] > 0 && !vis[i]) return 0;
    }
    return cnt;
}

int check1(){
    if(tplt() > 1) return 0;
    int odd = 0;
    for(int i = 1; i <= n; ++i){
        if(deg[i] % 2) ++odd;
    }
    if(odd == 2) return 2;
    if(odd == 0) return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t >> n >> m;
    nhap();
    if(t == 1){
        cout << check1();
    }
    else if(t == 2){
        stack<int>st;
        st.push(u);
        vector<int>res;
        while(!st.empty()){
            int u = st.top();
            if(!adj[u].empty()){
                int v = *adj[u].begin();
                st.push(v);
                adj[u].erase(v);
                adj[v].erase(u);
            }
            else{
                res.push_back(u);
                st.pop();
            }
        }
        reverse(res.begin(), res.end());
        for(auto x : res)
            cout << x << " ";
    }
    return 0;
}