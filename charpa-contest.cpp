//God & me // ya mahdi adrekni
#include <iostream>
using namespace std;
int df[20000],dc[20000][20000],M=1e9+7;
int n,c;
int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    dc[i][0]=1,dc[i][i]=1;
    for(int j=1;j<i;j++)
      dc[i][j]=(dc[i-1][j-1]+dc[i-1][j])%M;
  }
  df[0]=df[1]=1;
  for(int i=2;i<=n;i++)
    for(int j=0;j<i;j++)
      df[i]+=(dc[i][i-j]*(long long int)df[j])%M,df[i]%=M;
  cout<<df[n]<<endl;
  return 0;
}
