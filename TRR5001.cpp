#include <bits/stdc++.h>
#define pii pair<int, int>
#define maxn 1005
#define oo 1000005
#define endl "\n"
using namespace std;

int n, s, t;
vector<pii>a[maxn];
int d[maxn], pre[maxn];

void dijk(int s){
    for(int i = 1; i <= n; ++i)
        d[i] = oo;
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push({d[s], s});
    while(pq.size()){
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if(d[u] != du)
            continue;
        for(int i = 0; i < a[u].size(); ++i){
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if(d[v] > d[u] + uv){
                d[v] = d[u] + uv; 
                pre[v] = u;
                pq.push({d[v], v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n >> s >> t; 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x != 0 && x != 10000){
                a[i].push_back({x, j});
            }
        }
    }
    dijk(s);
    if(d[t] == oo){
        cout << 0;
    }
    else{
        vector<int>res;
        int t1 = t;
        while(t != s){
            res.push_back(t);
            t = pre[t];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        cout << d[t1] << endl;
        for(auto x : res)
            cout << x << " ";
    }
    return 0;
}