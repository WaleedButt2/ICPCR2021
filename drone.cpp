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
    int t;
    cin>>t;
    FORV(t){
        int x;
        cin>>x;
        vt data(x);
        FOR(data.sz) data[i]=i+1;
        int jump=0;
        int current=0;
        while(data.sz!=1){
            data.erase(data.begin()+(jump+current)%data.sz);
            current=(jump+current)%(data.sz+1);
            jump++;
        }
        cout<<data[0]<<endl;
    }
}
/*
1 2 3 4 5 
2 3 4 5 |0
2 4 5 |1

*/