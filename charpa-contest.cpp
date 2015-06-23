//God & me // ya mahdi adrekni
#include <iostream>
using namespace std;
int f[20000],c[20000][20000],M=1e9+7;
int n;
int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    c[i][0]=1,c[i][i]=1;
    for(int j=1;j<i;j++)
      c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
  }
  f[0]=f[1]=1;
  for(int i=2;i<=n;i++)
    for(int j=0;j<i;j++)
      f[i]+=(c[i][i-j]*(long long int)f[j])%M,f[i]%=M;
  cout<<f[n]<<endl;
  return 0;
}
