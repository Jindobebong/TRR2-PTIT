#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, m, in[maxn], out[maxn], cnt;
vector<vector<int>>a(105, vector<int>(105, 0));
vector<pair<int, int>>adj;
void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int x, y; cin >> x >> y;
        out[x]++;
        in[y]++;
        adj.push_back({x, y});
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
        cout << n << " " << m << endl;
        for(int i = 0; i < adj.size(); ++i){
            auto [x, y] = adj[i];
            a[x][i + 1] = 1;
            a[y][i + 1] = -1;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}