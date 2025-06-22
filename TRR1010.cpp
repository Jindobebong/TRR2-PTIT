#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

struct edge{
    int u, v, w;
};

int t, n, m, in[maxn], out[maxn], cnt, deg[maxn];
vector<vector<int>>a(105, vector<int>(105, 10000));
vector<edge>adj;
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x != 0 && x != 10000){
                deg[i]++;
                if(i < j) adj.push_back({i, j, x});
            }
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
            cout << deg[i] << " ";
    }
    else{
        cout << n << " " << adj.size() << endl;
        for(auto [u, v, w] : adj)
            cout << u << " " << v << " " << w << endl;
    }
    return 0;
}