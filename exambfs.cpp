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
void morbid_BFS(vector<pair<int,int>> Degree,vector<vt> adj_list){
    vt assigned_color (Degree.sz,-1);
    int color=0;
    //first is location second is dist
    FORV(Degree.sz){
        int cur=Degree[v].second;
        if(assigned_color[cur]>=0) continue;
        vt holder ={cur};
            FOR(adj_list.sz){
                bool found=false;
                for(auto u:holder)
                if(find(adj_list[u].begin(),adj_list[u].end(),i)!=adj_list[u].end()) {
                    found=true;break;
                }
                if(!found) {
                    assigned_color[i]=color;
                    holder.pb(i);
                }
        }
    color++;
    }
   // Print(assigned_color);
    cout<<color<<endl;
}
int main(){
    int t;
    cin>>t;
    FORV(t){
        int x,y,e;cin>>x>>e;
        if(!x||!y) {
            cout<<0<<endl;continue;
        }
        vector<vt> Graph(x);
        vector<pair<int,int>> Degree(x);
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
        //Print(Graph);
        morbid_BFS(Degree,Graph);
        
        //cout<<color<<endl;
    }
}
/* 
2 4 3 1 2 1 2 1 1 1 0 

3 1 2 1 2 3 2 1 1 1 0

1
10 12
1 2
2 5
5 6
4 5
3 1
3 4
3 6
7 10
7 2
8 1
6 2
2 3
*/