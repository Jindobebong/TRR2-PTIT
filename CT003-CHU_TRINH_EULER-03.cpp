#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, u;
vector<set<int>>adj(maxn), adj_t(maxn);
bool vis[maxn];
int in[maxn], out[maxn];

void nhap(){
    for(int i = 1; i <= n; ++i){
        int k; cin >> k; 
        for(int j = 0; j < k; ++j){
            int x; cin >> x; 
            adj[i].insert(x);
            adj_t[x].insert(i);
            out[i]++;
            in[x]++;
        }
    }
}
stack<int>st; // lưu thứ tự duyệt 
void dfs1(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v])
            dfs1(v);
    }
    st.push(u);
}

//dfs lần 2 trên trans của adj
void dfs2(int u){
    vis[u] = true;
    for(int v : adj_t[u]){
        if(!vis[v])
            dfs2(v);
    }
}

bool scc(){
    //bước 1: lấy thứ tự duyệt
    for(int i = 1; i <= n; ++i){
        if(!vis[i] && (in[i] > 0 || out[i] > 0)){
            dfs1(i);
        }
    }
    
    // reset vis
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
    return cnt <= 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);
    cin >> t; 
    if(t == 1) cin >> n; 
    else cin >> n >> u; 
    nhap();
    if(t == 1){
        int x = 0, y = 0, check = 1;
        for(int i = 1; i <= n; ++i){
            if(in[i] == out[i]) continue;
            else if(out[i] - in[i] == 1) ++x;
            else if(in[i] - out[i] == 1) ++y;
            else{
                check = 0;
                break;
            }
        }
        if(!check) cout << 0;
        else if(x == 1 && y == 1) cout << 2;
        else if(x == 0 && y == 0) cout << 1;
        else cout << 0;
    }
    else if(t == 2){
        stack<int>st1;
        st1.push(u);
        vector<int>path;
        while(!st1.empty()){
            int u = st1.top();
            if(!adj[u].empty()){
                int v = *adj[u].begin();
                st1.push(v);
                adj[u].erase(v);
            }
            else{
                path.push_back(u);
                st1.pop();
            }
        }
        reverse(path.begin(), path.end());
        for(auto x : path)
            cout << x << " ";
    }
    return 0;
}