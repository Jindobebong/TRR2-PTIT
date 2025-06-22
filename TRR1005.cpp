#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int deg[105];
vector<int>adj[105];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t, n, m; cin >> t >> n >> m; 
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v; 
        deg[u]++;
        deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i)
            cout << deg[i] << " ";
    }
    else if(t == 2){
        cout << n << endl;
        for(int i = 1; i <= n; ++i){
            cout << adj[i].size() << " ";
            sort(adj[i].begin(), adj[i].end());
            for(auto x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}