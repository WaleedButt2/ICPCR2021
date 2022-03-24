#include <bits/stdc++.h>
#include <sstream>
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
vt in,post;
class Node{
public:
    Node* left;
    Node* right;
    int value;
    int index;
    static int count;
Node(){
    left=NULL;right=NULL;index=count++;
}
};
int Node::count=0;
void Print(vector<int> v){
    FOR(v.sz) cout<<v[i]<<' '; 
    cout<<endl;
}
vt Update(){
    string s,x,y;getline(cin,s);getline(cin,x);getline(cin,y);
    istringstream is( s );
    vector<int> Inorder( ( istream_iterator<int>( is ) ), ( istream_iterator<int>() ) );
    istringstream as( x );
    vector<int> Pstorder( ( istream_iterator<int>( as ) ), (istream_iterator<int>() ) );
    istringstream ds( y );
    vector<int> queuries( ( istream_iterator<int>( ds ) ), ( istream_iterator<int>() ) );
    in=Inorder;post=Pstorder;return queuries;
}
int find(int start,int end,int find){
    for(int i=start;i<=end;i++)if(find==in[i]) return i;
    return 0;
}
Node* call(int instart,int inend,int &pindex){
    if(instart>inend) return NULL;
    Node* node=new Node;
    node->value=post[pindex];
    pindex--;
    if(instart==inend) return node;
    int found=find(instart,inend,node->value);
    //cout<<found<<' '<<post[pindex+1]<<endl;
    node->right=call(found+1,inend,pindex);
    node->left=call(instart,found-1,pindex);
    return node;
}
void Print_tree(Node* node){
    if(node==NULL) return;
    cout<<node->value<<' ';
    Print_tree(node->left);
    Print_tree(node->right);
}
void go_down(Node* node,vt &m,int prv){
    if(node==NULL) return;
    m[node->index]=prv+node->value;
    go_down(node->left,m,prv+node->value);
    go_down(node->right,m,prv+node->value);   
}
int main(){
    int t;
    cin>>t;cin.ignore();
    FORV(t){
       vt q= Update();
       int a=post.sz-1;
      // cout<<find(in.begin(),in.end(),3)-in.begin()<<endl;
    //cout<<found<<' '<<post[pindex+1]<<endl;
      Node* node=call(0,in.sz-1,a);
      vt sol(post.sz);
      go_down(node,sol,0);
     // Print(sol);
      FOR(q.sz){
          if(find(sol.begin(),sol.end(),q[i])!=sol.end()) cout<<"TRUE\n";
          else cout<<"FALSE\n";
      }
    }
}
/*
1
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1
3 4 7 8 24 12 2 0
*/