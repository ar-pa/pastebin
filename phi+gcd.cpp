//God & me // ya mahdi adrekni
#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
const int mod=12757,oo=1e8;
bool isp[oo];
vector<int>pr;
int gcd(int u, int v){
  int shl = 0;
  while ( u && v && u!=v ) {
    bool eu = !(u & 1);
    bool ev = !(v & 1);
    if ( eu && ev ) {
      ++shl;
      u >>= 1;
      v >>= 1;
    }
    else if ( eu && !ev ) u >>= 1;
    else if ( !eu && ev ) v >>= 1;
    else if ( u>=v ) u = (u-v)>>1;
    else {
      int tmp = u;
      u = (v-u)>>1;
      v = tmp;
    }
  }
 
  return !u? v<<shl : u<<shl;
}
int phi(const int n){
  // Base case
  if ( n < 2 )
    return 0;
 
  // Lehmer's conjecture
  if (!isp[n])
    return n-1;
 
  // Even number?
  if ( n & 1 == 0 ) {
    int m = n >> 1;
    return !(m & 1) ? phi(m)<<1 : phi(m);
  }
 
  // For all primes ...
  for ( vector<int>::iterator p = pr.begin();
        p != pr.end() && *p <= n;
        ++p )
    {
      int m = *p;
      if ( n % m  ) continue;
 
      // phi is multiplicative
      int o = n/m;
      int d = gcd(m, o);
      return d==1? phi(m)*phi(o) : phi(m)*phi(o)*d/phi(d);
    }
}
int n;
int main(){
  isp[0]=isp[1]=1;
  for(int i=2;i*i<oo;i++)
    for(int j=1LL*i*i;j<oo;j+=i)
      isp[j]=1;
  for(int i=2;i<oo;i++)
    if(!isp[i])
      pr.pb(i);
  cout<<"cin"<<endl;
  cin>>n;
  cout<<phi(n)<<endl;
  return 0;
}
