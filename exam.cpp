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
void Print(vector<bool> x){
    FOR(x.sz) if(x[i]) cout<<"1 ";
    else cout<<"0 ";
    cout<<endl;
}
//use pair to identify colors
int main(){
    int t;
    cin>>t;
    FORV(t){
        int x,y,e;cin>>x>>e;
        if(x==0) {
            cout<<0<<endl;continue;
        }
        vector<vector<int>> Graph(x);
        vector<pair<int,int>> Degree(x);
        vt assigned_color (x,0);
        int color=1;
        FOR(e){
            cin>>x>>y;x--;y--;
            Graph[x].pb(y);
            Graph[y].pb(x);
        }
        int highest=0;
        FOR(Graph.sz){
            Degree[i]=pair<int,int>(Graph[i].sz,i);
        }
        sort(Degree.rbegin(),Degree.rend());
        FOR(Degree.sz){
            vector<bool> curr(color+1,false);
            int x=Degree[i].second;
            FORJ(Graph[x].sz){
                int col=assigned_color[Graph[x][j]];
                if(col==0) continue; 
                curr[col]=true;
            }
            int j;bool found=false;
          //  Print(curr);
            for(j=1;j<curr.sz;j++) if(!curr[j]) {found=true;break;}
           // Print(curr);
            if(found) assigned_color[x]=j;
            else {
                color++;
                assigned_color[x]=color;
            } 
        }
       // cout<<endl;
      //  Print(assigned_color);
        cout<<color<<endl;
    }
}
/* 
2 4 3 1 2 1 2 1 1 1 0 

3 1 2 1 2 3 2 1 1 1 0

1
10 14
1 2
2 5
5 6
4 5
3 1
3 4
3 6
1 2
7 10
7 2
8 1
6 2
2 3
2 5
*/