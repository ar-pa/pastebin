//God & me //ya mahdi adrekni
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define pb push_back
using namespace std;
inline char next(char &c){
  if(c==' ')
    c='A';
  else if(c=='Z')
    c=' ';
  else
    c++;
  return '+';
}
inline char prev(char &c){
  if(c==' ')
    c='Z';
  else if(c=='A')
    c=' ';
  else
    c--;
  return '-';
}
inline char next(int &a){
  a++;
  a%=30;
  return '>';
}
inline char prev(int &a){
  a--;
  if(a==-1)
    a=29;
  return '<';
}
string change(char &c,char &t){
  string r;
  if(c==t)
    return "";
  if(c==' ')
    if(t-'A'+1<=13)
      while(c!=t)
	r+=next(c);
    else
      while(c!=t)
	r+=prev(c);
 
  else if(t==' ')
    if(c-'A'+1<=13)
      while(c!=t)
	r+=prev(c);
    else
      while(c!=t)
	r+=next(c);
  else
    if(c>t)
      if(c-t<=13)
        while(c!=t)
	  r+=prev(c);
      else
        while(c!=t)
	  r+=next(c);
    else
      if(t-c<=13)
        while(c!=t)
	  r+=next(c);
      else
        while(c!=t)
	  r+=prev(c);
  return r;
}
string change(int &a,int &b){
  string r;
  int r1=max(a,b)-min(a,b),r2=30-max(a,b)+min(a,b);
  if(a>b)
    if(r1<r2)
      while(a!=b)
	r+=prev(a);
    else
      while(a!=b)
	r+=next(a);
  else
    if(r1<r2)
      while(a!=b)
	r+=next(a);
    else
      while(a!=b)
	r+=prev(a);
  return r;
}
int pos,n;
string s,m="                              ";
int count(char c){
  int r=0;
  for(int i=0;i<30;i++)
    if(m[i]==c)
      r++;
  return r;
}
inline int dis(char &c,char &t){
  return min(abs((t==' '?0:t-'A'+1)-(c==' '?0:c-'A'+1)),27-abs((t==' '?0:t-'A'+1)-(c==' '?0:c-'A'+1)));
}
inline int dis(int &a,int &b){
  return min(abs(a-b),30-(abs(a-b)));
}
int npos;
inline int pl(int &a,int &b){//operator +
  return (a+b)%30;
}
inline int pl(int &a,bool b){//operator + 
  return (a+b)%30;
}
inline int mi(int &a,int &b){//operator -
  return ((a-b)+30)%30;
}
inline int np1(int pos,int st){
  int mini=dis(s[st],m[pos]),npos=pos;
  int sta=mi(pos,mini),en=pl(pos,mini);
  for(int i=sta;i!=en;i=pl(i,1)){
    if(dis(i,pos)+dis(s[st],m[i])<mini || (dis(i,pos)+dis(s[st],m[i])==mini && count(m[pos])>count(npos)))
      mini=dis(i,pos)+dis(s[st],m[i]),npos=i;
  }
  return npos;
}
inline int np2(int pos,int st){
  int mini=dis(s[st],m[pos]),npos=pos;
  int sta=mi(pos,mini),en=pl(pos,mini);
  for(int i=sta;i!=en;i=pl(i,1))
    for(int j=0;j<30;j++)
      if(mini>dis(pos,i)+dis(s[st],m[i])+dis(i,j)+dis(s[st+1],m[j]) && count(m[pos])>count(npos))
	npos=i,mini=dis(pos,i)+dis(s[st],m[i])+dis(i,j)+dis(s[st+1],m[j]);
  return npos;
}
inline int np3(int pos,int st){
  int mini=dis(s[st],m[pos]),npos=pos;
  int sta=mi(pos,mini),en=pl(pos,mini);
  for(int i=sta;i!=en;i=pl(i,1))
    for(int j=0;j<30;j++)
      for(int k=0;k<30;k++)
	if(mini>dis(pos,i)+dis(s[st],m[i])+dis(i,j)+dis(s[st+1],m[j])+dis(j,k)+((st+2 != n)?dis(s[st+2],m[j]):0) && count(m[pos])>count(npos))
	  npos=i,mini=dis(pos,i)+dis(s[st],m[i])+dis(i,j)+dis(s[st+1],m[j])+dis(j,k)+((st+2 != n)?dis(s[st+2],m[j]):0);
  return npos;
}
string bs = s;
string x = "", y = "";
int main(){
  getline(cin,s);
  string bs = s;
  pos=0, n = s.length();
  string x = "", y = "";
  int yL;
  for(int i = 0; i < n;i++) {
    npos=np1(pos,i);
    y += change(pos,npos);
    y += change(m[pos],s[i]);
    y += ".";
  }
  yL = y.length();
  for(int k = 1; k < 4; k++) {
    for(int ank = 0; ank < k; ank++) {
      s = bs;
      m="                              ";
      x="";
      for(int i=0;i<n-1;i++){
	if(i % k == ank){
	  npos=np1(pos,i);
	  x += change(pos,npos);
	  x += change(m[pos],s[i]);
	  x += ".";
	}
	else{
	  npos=np3(pos,i);
	  x += change(pos,npos);
	  x += change(m[pos],s[i]);
	  x += ".";
	}
      }
 
      int i=s.length()-1;
      npos=np1(pos,i);
      x += change(pos,npos);
      x += change(m[pos],s[i]);
      x += ".";
 
      if(x.length() < yL)
	y = x;
    }
  }
  for(int k = 1; k < 4; k++) {
    for(int ank = 0; ank < k; ank++) {
      s = bs;
      m="                              ";
      x="";
      for(int i=0;i<n-1;i++){
	if(i % k == ank){
	  npos=np1(pos,i);
	  x += change(pos,npos);
	  x += change(m[pos],s[i]);
	  x += ".";
	}
	else{
	  npos=np2(pos,i);
	  x += change(pos,npos);
	  x += change(m[pos],s[i]);
	  x += ".";
	}
      }
 
      int i=s.length()-1;
      npos=np1(pos,i);
      x += change(pos,npos);
      x += change(m[pos],s[i]);
      x += ".";
 
      if(x.length() < yL)
	y = x;
    }
  }
  cout<<y<<endl;
  return 0;
}
