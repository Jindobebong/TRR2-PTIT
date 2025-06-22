#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, m, in[maxn], out[maxn], cnt, deg[maxn];
vector<vector<int>>a(105, vector<int>(105, 0));
vector<pair<int, int>>adj;
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int k; cin >> k; 
        for(int j = 0; j < k; ++j){
            int x; cin >> x; 
            deg[i]++;
            if(i < x) adj.push_back({i, x});
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    cin >> t; 
    nhap();
    if(t == 1){
        for(int i = 1; i <= n; ++i)
            cout << deg[i] << " ";
    }
    else{
        cout << n << " " << adj.size() << endl;
        for(int i = 0; i < adj.size(); ++i){
            auto [x, y] = adj[i];
            a[x][i + 1] = 1;
            a[y][i + 1] = 1; 
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= adj.size(); ++j){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

