#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int n, s, t;
struct edge{
    int u, v, w;
};
vector<edge>ds;
const int INF = 10000;
int d[maxn], p[maxn];
int check;
void bel(int s, int t){
    for(int i = 1; i <= n; ++i){
        d[i] = INF;
        p[i] = -1;
    }
    d[s] = 0;
    for(int k = 1; k < n; ++k){
        for(auto [u, v, w] : ds){
            if(d[u] != INF){
                if(d[u] + w < d[v]){
                    d[v] = d[u] + w;
                    p[v] = u;
                }
            }
        }
    }
    for(auto [u, v, w] : ds){
        if(d[u] != INF && d[u] + w < d[v]){
            // nếu vẫn tối ưu -> có chu trình âm
            check = true;
            break;
        }
    }
    if(check) cout << -1;
    else{
        if(d[t] != INF){
            cout << d[t] << endl;
            vector<int>res;
            while(t != s){
                res.push_back(t);
                t = p[t];
            }
            res.push_back(s);
            reverse(res.begin(), res.end());
            for(auto x : res)
                cout << x << " ";
        }
        else cout << 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    cin >> n >> s >> t; 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x != 0 && x != 10000){
                ds.push_back({i, j, x});
            }
        }
    }
    bel(s, t);
    return 0;
}