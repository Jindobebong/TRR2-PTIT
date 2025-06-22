#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, m, in[maxn], out[maxn], cnt, deg[maxn];
vector<vector<int>>a(105, vector<int>(105, 10000));
vector<pair<int, int>>adj;
void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v, w; cin >> u >> v >> w;
        out[u]++;
        in[v]++;
        a[u][v] = w;
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t; 
    nhap();
    if(t == 1){
        for(int i = 1; i <= n; ++i)
            cout << in[i] << " " << out[i] << endl;
    }
    else{
        cout << n << endl;
        for(int i = 1; i <= n; ++i)
            a[i][i] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}

