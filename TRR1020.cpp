#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, k;
vector<pair<int, int>>adj;
int in[maxn], out[maxn];
int cnt;

void nhap(){
    cin >> n; 
    for(int i = 1; i <= n; ++i){
        cin >> k;
        for(int j = 0; j < k; ++j){
            int x; cin >> x;
            adj.push_back({i, x});
            out[i]++;
            in[x]++;
            ++cnt;
        }
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
    else if(t == 2){
        sort(adj.begin(), adj.end());
        vector<vector<int>>a(n + 1, vector<int>(cnt + 1, 0));
        for(int i = 1; i <= cnt; ++i){
            auto [x, y] = adj[i - 1];
            a[x][i] = 1;
            a[y][i] = -1;
        }
        cout << n << " " << cnt << endl;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= cnt; ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}