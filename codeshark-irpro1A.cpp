//God & me // ya mahdi adrekni
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
const int m=11717;
vector<int>f,r[1000012];
int n;
void out(){
  for(int i=0;i<=n;i++){
    cout<<i<<": ";
    for(int j=0;j<r[i].size();j++)
      cout<<r[i][j]<<" ";
    cout<<endl;
  }
  return ;
}
int main(){/*
  cin>>n;
  f.pb(1),f.pb(1);
  for(int i=2;f[i-1]<=n;i++)
    f.pb(f[i-1]+f[i-2]);
  r[1].pb(1),r[0].pb(1);
  for(int i=2;i<=n;i++){
    for(int j=0;j<f.size();j++)
      if(i-f[j]>=0)
	for(int k=0;k<r[i-f[j]].size();k++)
	  if(f[j]>r[i-f[j]][k])
	    r[i].pb(f[j]);
  }
  cout<<"ans="<<r[n].size()<<endl;*/
  long long int x=1;
    for(int i=1;i<=94;i++)
    x*=318,x%=m;
    cout<<x<<endl;
  return 0;
}

