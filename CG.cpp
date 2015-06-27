//God & me // ya mahdi adrekni
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
vector<int>e[200012];
int n,t1,t2;
vector<int>all;
int mini=2e9;
int dfs(int v,int par){
  //cout<<"on "<<v<<" with par: "<<par<<endl;
  int maxi=0;
  for(int i=0;i<e[v].size();i++)
    if(e[v][i]!=par){
      maxi=max(maxi,dfs(e[v][i],v));
      if(maxi>=mini){
	//cout<<"BREAK"<<endl;
	return maxi;
      }
    }
  return maxi+1;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>t1>>t2;
    all.pb(t1),all.pb(t2);
    e[t1].pb(t2);
    e[t2].pb(t1);
  }
  for(int i=0;i<all.size();i++){
    //cout<<i<<"OKed"<<endl;
    mini=min(mini,dfs(all[i],-1));
  }
  cout<<mini-1<<endl;
  return 0;
}

