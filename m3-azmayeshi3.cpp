//God & me // ya mahdi adrekni
#include <iostream>
#include <vector>
#include <cmath>
#define pb push_back
using namespace std;
const long long int MOD=12043;
void m(int &a){
  while(a<0)
    a+=MOD;
  a%=MOD;
}
bool pr[1000012],np[1000012],ac[1000012];
int xs[1000012],ps[1000012],all;
vector<int>prv;
long long int s;
int n;
int main(){
  cin>>n;
  for(int i=1;i<=n;i++)
    xs[i]=n,ac[i]=1;
  //PRIME
  pr[0]=pr[1]=1;
  for(long long int i=2;i<=n;i++){
    if(!pr[i]){
      ac[i]=1;
      for(long long int j=i;j<=n && j<i*i;j+=i)
	np[j]^=1;
      //cout<<i<<endl;
      for(long long int j=i*i,action=0;j<=n;j+=i,action++,action%=i)
	pr[j]=1,np[j]^=1,ac[j]=action && ac[j];
    }
    if(ac[i]){
      if(np[i])
	for(long long int j=i;j<=n;j+=i)
	  xs[j]-=n/i;
      else
	for(long long int j=i;j<=n;j+=i)
	  xs[j]+=n/i;
    }
  }
  //END OF PRIME
  //cout<<"\rOK prime"<<endl;
  //cout<<"\rfirst task complete"<<endl;
  for(int i=2;i<=n;i++)
    all+=((long long int)xs[i]*(i-1))%MOD,all%=MOD;
  ps[n]=xs[n];
  for(int i=n-1;i>0;i--)
    ps[i]=ps[i+1]+xs[i],ps[i]%=MOD;
  for(int i=1;i<n;i++){
    s+=((long long int)xs[i]*all)%MOD;
    s%=MOD;
    all-=ps[i+1];
    m(all);
  }
  s*=2;
  s%=MOD;
  cout<<s<<endl;
  //cout<<"----------------------"<<endl;for(int i=1;i<=n;i++)cout<<i<<":"<<xs[i]<<" "<<ac[i]<<" "<<np[i]<<endl;
  return 0;
}
