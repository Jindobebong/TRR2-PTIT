#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int deg[105];
vector<pair<int, int>>adj;

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
        adj.push_back({u, v});
    }
    if(t == 1){
        for(int i = 1; i <= n; ++i)
            cout << deg[i] << " ";
    }
    else if(t == 2){
        cout << n << " " << adj.size() <<  endl;
        sort(adj.begin(), adj.end());
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < adj.size(); ++j){
                if(adj[j].second == i || adj[j].first == i)
                    cout << 1 << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}