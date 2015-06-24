//God & me // ya mahdi adrekni
#include <iostream>
#define pb push_back
using namespace std;
string out;
int n,k;
int main(){
  cin>>n>>k;
  while(--k)
    out.pb('L'),out.pb('S');
  out.pb('L');
  if(out.length()>n*n){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
    while(out.length()<n*n)
      out.pb('S');
    cout<<out.size()<<endl;
    for(int i=n;i<n*n;i+=n)
      if(i%(2*n))
	out.insert(i,"S");
      else
	out.erase(i);
    for(int i=0;i<n*n;i++){
      if(!(i%n))
	cout<<endl;
      cout<<out[i];
    }
  }

  return 0;
}
