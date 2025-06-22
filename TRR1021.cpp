#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, in[maxn], out[maxn];
struct edge{
    int u, v, w; 
};

vector<edge>adj;
void nhap(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x != 0 && x != 10000){
                out[i]++;
                in[j]++;
                adj.push_back({i, j, x});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n; 
    nhap();
    if(t == 1){
        for(int i = 1; i <= n; ++i){
            cout << in[i] << " " << out[i] << endl;
        }
    }
    else if(t == 2){
        cout << n << " " << adj.size() << endl;
        for(auto [u, v, w] : adj)
            cout << u << " " << v << " " << w << endl;
    }
    return 0;
}