#include <bits/stdc++.h>
#define ll long long
#define maxn 105
#define endl "\n"
using namespace std;

int t, n, k, in[maxn], out[maxn], cnt;
vector<int>adj[maxn];

void nhap(){
    cin >> n; 
    for(int i = 1; i <= n; ++i){
        cin >> k; 
        for(int j = 0; j < k; ++j){
            int x; cin >> x;
            out[i]++;
            in[x]++;
            adj[i].push_back(x);
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
    else{
        cout << n << " " << cnt << endl;
        for(int i = 1; i <= n; ++i){
            for(auto x : adj[i])
                cout << i << " " << x << endl;
        }
    }
    return 0;
}