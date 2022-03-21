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
    FOR(v.sz) cout<<v[i]+1<<' '; 
    cout<<endl;
}
int main(){
    int A,B,N,D;
    cin>>N>>D>>A>>B;
    vector<pair<int,int>> cust(N);
    FOR(N){
        int x,y;
        cin>>x>>y;
        cust[i]=pair<int,int>(x*A+y*B,i);
    }
    sort(cust.begin(),cust.end());
    int ans=0;
    vt indexs;
    while(D>=0){
        D-=cust.front().first;
        indexs.pb(cust[0].second);
        cust.erase(cust.begin());
        if(D>=0){
            ans++;
        }
        else indexs.pop_back();
    }
    cout<<ans<<endl;
    Print(indexs);
}
/*
6 4
1 1
2 0
3 2
4 4
10 0
0 1
4 2
*/