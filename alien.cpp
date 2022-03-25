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
    FORJ(v[i].sz){
      //  cout<<v[i][j];
        if(v[i][j]<0||v[i][j]>=10)cout<<v[i][j]<<' ';
        else cout<<' '<<v[i][j]<<' ';
    }cout<<endl;
    }
}
void Print(vector<bool> x){
    FOR(x.sz) if(x[i]) cout<<"1 ";
    else cout<<"0 ";
    cout<<endl;
}
vt part(){
    string s;getline(cin,s);
    //cout<<s<<endl;
    vt entries;
    auto itr=s.find(',');
    while(itr!=string::npos){
        if(s[0]==')')  itr=s.find(',');
        if(s[0]=='(') {s.erase(0,1);itr--;}
        //cout<<s.substr(0,itr)<<endl;
        entries.pb(stoi(s.substr(0,itr)));
        s.erase(0,itr+1);
        itr=s.find(',');
    }
    entries.pb(stoi(s));
//    Print(entries);
    return entries;
}
int main(){
    int t;
    cin>>t;cin.ignore();
    FORV(t){
        pair<int,int> start,gate;
        vt one=part();
        int x=one[0],y=one[1];
        vector<vt> maze(x,vt(y));
        vector<vt> sum(x,vt(y));
        start=pair<int,int>(one[2],one[3]);
        gate=pair<int,int>(one[4],one[5]);
        one.erase(one.begin(),one.begin()+ 6);
        //Print(one);
        int a=0;
        FOR(x){
            FORJ(y){
                maze[i][j]=one[a];a++;
            }
        }
        FOR(x){
            FORJ(y){
                sum[i][j]=maze[i][j];
                if(j==0) continue;
                sum[i][j]+=sum[i][j-1];
            }
        }
        Print(maze);
        cout<<endl;
        Print(sum);
    }
}
/*
1
8,10,(6,3),(3,8),-1,0,-2,1,0,5,0,0,0,0,0,0,0,0,-1,0,-1,-2,2,2,-1,-1,-1,-1,-1,1,-2,0,0,-1,-1,5,5,0,5,5,6,2,-1,-1,0,7,2,3,0,2,2,3,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,-2,-2,1,-2,-1,-2,-2,-3,-1,0,0,0,0,0,0,0,0,0,0,0
*/