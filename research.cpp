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
    cout<<"  ";
    FOR(v.sz) cout<<i<<"  ";
    cout<<endl;
    FOR(v.sz) {
        cout<<i<<' ';
    FORJ(v[i].sz){ 
        cout<<v[i][j];
        if(v[i][j]>=10) cout<<" ";
        else if(v[i][j]>=0) cout<<"  ";
        else cout<<" ";
    } 
    cout<<endl;
    }
    cout<<endl;
}
int main(){
    int x,y;
    cin>>x>>y;
    vector<vt> maze(x,vt(y));
    FOR(x){
        FORJ(y){
            cin>>maze[i][j];
        }
    }
    int q;cin>>q;
    FORV(q){
        int ans=0;
        int x1,y1,x2,y2;
        cin>>y1>>x1>>y2>>x2;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                ans=ans ^ maze[i][j];
            }
        }
        cout<<"Query #"<<v+1<<": "<<ans<<endl;
    }
}
/*
7 7
0 0 192 0 0 16 0
12 0 24 0 48 255 96
0 24 0 0 64 128 0
0 0 48 0 128 0 0
48 0 0 24 0 0 255
0 0 255 0 48 0 0
0 0 0 192 0 12 32
5
4 1 6 2
6 6 6 6
2 3 3 4
0 1 1 2
0 0 6 6
*/