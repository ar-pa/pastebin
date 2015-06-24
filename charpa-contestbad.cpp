//God & me // ya mahdi adrekni
#include <iostream>
#include <vector>
#include <set>
#define pb push_back
using namespace std;
set<vector<int> >all;
long long int ans;
int n,c;
vector<int>v;
void out(){
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  cout<<endl;
}
void dfs(){
  int r[10000]={0};
  int maxx=0;
  for(int i=0;i<v.size();i++)
    r[v[i]]++,maxx=max(maxx,v[i]);
  for(int i=0;i<maxx;i++)
    if(!r[i])
      return ;
  if(all.count(v))
    return ;
  all.insert(v);
  ans++;
  ans%=1000000000;
  out();
  for(int i=0;i<v.size();i++){
    if(v[i]<c-1){
      v[i]++;
      dfs();
      v[i]--;
    }
  }
}
int main(){
  cin>>n>>c;
  for(int i=0;i<n;i++)
    v.pb(0);
  dfs();
  cout<<ans<<endl;
  return 0;
}
