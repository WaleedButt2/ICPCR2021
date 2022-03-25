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
        
    }
}
/*
*/