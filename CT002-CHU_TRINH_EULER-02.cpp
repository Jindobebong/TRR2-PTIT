#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define endl "\n"
using namespace std;

int t, n, u, deg[105];
set<int>ke[105];

void nhap(){
    cin >> n; 
    if(t == 2) cin >> u; 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x; 
            if(x == 1){
                deg[i]++;
                ke[i].insert(j);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    nhap();
    if(t == 1){
        int odd = 0; 
        for(int i = 1; i <= n; ++i)
            if(deg[i] % 2) ++odd;
        if(odd == 2) cout << 2; 
        else if(odd = 0) cout << 1; 
        else cout << 0;
    }
    else if(t == 2){
        stack<int>st;
        st.push(u);
        vector<int>res;
        while(!st.empty()){
            int u = st.top();
            if(!ke[u].empty()){
                int v = *ke[u].begin();
                st.push(v);
                ke[u].erase(v);
                ke[v].erase(u);
            }
            else{
                res.push_back(u);
                st.pop();
            }
        }
        reverse(res.begin(), res.end());
        for(auto x : res)
            cout << x << " ";
    }
    return 0;
}