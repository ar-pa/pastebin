//God & me //ya mahdi adrekni
#include <iostream>
#include <vector>
#include <set>
#define pb push_back
using namespace std;
int t1,t2,m;
vector<int>queue;
set<int>e[200012],ce[200012],v,cv;
void out(set<int>o){
  for(set<int>::iterator it=o.begin();it!=o.end();it++)
    cout<<*it<<" ";
  cout<<endl;
}
int dfs(int v,int par){
  int maxi=0;
  for(set<int>::iterator it=e[v].begin();it!=e[v].end();it++)
    if(*it!=par){
      maxi=max(maxi,dfs(*it,v));
    }
  return maxi+1;
}
void cut(){
  for(set<int>::iterator it=v.begin();it!=v.end();it++)
    if(e[*it].size()==1){
      queue.pb(*it);
    }
  return ;
}
int main(){
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>t1>>t2;
    e[t1].insert(t2),e[t2].insert(t1),v.insert(t1),v.insert(t2);
  }
  for(set<int>::iterator it=v.begin();it!=v.end();it++)
    ce[*it]=e[*it];
  cv=v;
  while(v.size()>2){
    //cout<<"size: "<<v.size()<<endl;
    cut();
    for(int i=0;i<queue.size();i++)
      e[*(e[queue[i]].begin())].erase(queue[i]),v.erase(queue[i]);
    queue.clear();
  }
  int r1=*(v.begin()),r2=*(v.end());
  v=cv;
  cerr<<r1<<" "<<r2<<endl;
  for(set<int>::iterator it=v.begin();it!=v.end();it++)
    e[*it]=ce[*it];
  cout<<min(dfs(r1,-1),dfs(r2,-1))-1<<endl;
  return 0;
}
