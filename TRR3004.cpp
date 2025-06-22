#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, u;
set<int>adj[maxn];
int in[maxn], out[maxn];

void nhap(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x){
                adj[i].insert(j);
                out[i]++;
                in[j]++;
            }
        }
    }
}
bool vis[maxn];
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
    return cnt == 1;
}
int check1(){
    int x = 0, y = 0;
    if(!tplt()) return 0;
    for(int i = 1; i <= n; ++i){
        if(in[i] == out[i]) continue;
        else if(in[i] - out[i] == 1) ++x;
        else if(out[i] - in[i] == 1) ++y;
        else return 0;
    }
    if(x == 0 && y == 0) return 1;
    if(x == 1 && y == 1) return 2;
    return 0;
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
    if(t == 1)
        cout << check1();
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
            }
            else{
                path.push_back(u);
                st.pop();
            }
        }
        reverse(path.begin(), path.end());
        for(auto x : path)
            cout << x << " ";
    }
    return 0;
}