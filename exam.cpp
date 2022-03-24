#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define l long
#define sz size()
#define vt vector<int>
#define FOR(n) for (int i = 0; i < n; i++)
#define FORV(n) for (int v = 0; v < n; v++)
#define FORJ(n) for (int j = 0; j < n; j++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
void Print(vector<int> v){
    FOR(v.sz) cout<<v[i]<<' '; 
    cout<<endl;
}
void Print(vector<vt> v){
    FOR(v.sz) {
    FORJ(v[i].sz)
        cout<<v[i][j]+1<<' ';
    cout<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    FORV(t){
        int x,y,e;cin>>x>>e;
        vector<vt> Graph(x);
        FOR(e){
            cin>>x>>y;
            Graph[x-1].pb(y-1);
            Graph[y-1].pb(x-1);
        }
        cout<<endl;
        Print(Graph);
    }
}
/*
1
6 7
1 2
2 5
5 6
4 5
3 1
3 4
3 6
*/