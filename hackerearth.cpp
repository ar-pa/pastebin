//God & me 
#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
#define int long long
using namespace std;
int in(){int tmp;scanf("%lld",&tmp);return tmp;}int&in(int &x){return x=in();}
template<typename T,typename... Args>void in(T &x,Args&... args){in(x);if(sizeof...(args))in(args...);}
template <class T,class L> T& smax(T &x,L y){if(y>x)x=y;return x;}template <class T,class L> T& smin(T &x,L y){if(y<x)x=y;return x;}
typedef pair<int,int> pii;
const int maxn=1e5+17;
int n,q,a[maxn],b[maxn];
unordered_map<int,int>mp;
main(){
  in(n,q);
  bool ok=1;
  for(int i=0;i<n;i++){
    in(a[i],b[i]);
    if(a[i]>b[i])
      swap(a[i],b[i]);
    mp[b[i]-a[i]]++;
  }
  for(auto f:mp)
    if(f.Y&1)
      ok=0;
  int ans=0;
  for(int i=0;i<n;i++)
    if(i&1)
      ans+=a[i];
    else
      ans+=b[i];
  while(q--){
    int x=in();
    if(ok && x==ans)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}
