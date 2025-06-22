#include <bits/stdc++.h>
#define ll long long
#define maxn 1005
#define endl "\n"
using namespace std;

int n, m, u, v, w;
struct edge{
    int u, v, w;
};
vector<edge>ds;
bool cmp(edge x, edge y){
    if(x.w != y.w)
        return x.w < y.w;
    if(x.u != y.u)
        return x.u < y.u;
    return x.v < y.v;
}
int parent[maxn], sz[maxn];
void ktao(){
    for(int i = 1; i <= n; ++i){
        parent[i] = i; 
        sz[i] = 1;
    }
}
int find(int v){
    if(v == parent[v])
        return v; 
    return parent[v] = find(parent[v]);
}
int dsu(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        ds.push_back({u, v, w});
    }
    sort(ds.begin(), ds.end(), cmp);
    // for(auto [u, v, w] : ds)
    //     cout << u << " " << v << " " << w << endl;
    int sum = 0;
    vector<edge>res;
    ktao();
    for(auto [u, v, w] : ds){
        if(dsu(u, v)){
            sum += w;
            res.push_back({u, v, w});
        }
    }
    if(res.size() != n - 1) cout << 0 << endl; 
    else{
        cout << sum << endl;
        for(auto [u, v, w] : res)
            cout << u << " " << v << " " << w << endl;
    }
    return 0;
}