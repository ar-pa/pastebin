/*
OLD CODE & THE BEST
//God & me // ya mahdi adrekni
#include <iostream>
#include <vector>
#include <string>
#define pb push_back
using namespace std;
char next(char &c){
  if(c==' ')
    c='A';
  else if(c=='Z')
    c=' ';
  else
    c++;
  return '+';
}
char prev(char &c){
  if(c==' ')
    c='Z';
  else if(c=='A')
    c=' ';
  else
    c--;
  return '-';
}
char next(int &a){
  a++;
  a%=30;
  return '>';
}
char prev(int &a){
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
string s,m="                              ";
int count(char c){
  int r=0;
  for(int i=0;i<30;i++)
    if(m[i]==c)
      r++;
  return r;
}
int dis(char a,char b){
  return change(a,b).length();
}
int dis(int a,int b){
  return change(a,b).length();
}
int np1(int pos,int st){
  int mini=1e9,npos;
  for(int i=0;i<30;i++)
    if(dis(i,pos)+dis(s[st],m[i])<mini || (dis(i,pos)+dis(s[st],m[i])==mini && count(m[pos])>count(npos)))
      mini=dis(i,pos)+dis(s[st],m[i]),npos=i;
  return npos;
}
int np2(int pos,int st){
  int mini=1e9,npos;
  for(int i=0;i<30;i++)
    for(int j=0;j<30;j++)
      if(mini>dis(pos,i)+dis(s[st],m[i])+dis(i,j)+dis(s[st+1],m[j]))
	npos=i,mini=dis(pos,i)+dis(s[st],m[i])+dis(i,j)+dis(s[st+1],m[j]);
  return npos;
}
int main(){
  getline(cin,s);
  int pos=0;
  for(int i=0;i<s.length();i++){
      int npos=np1(pos,i);
      cout<<change(pos,npos);
      cout<<change(m[pos],s[i]);
      cout<<".";
  }
  cout<<endl;
  return 0;
}
*/
//NEW CODE & have a same time with OLD CODE
//God & me // ya mahdi adrekni
#include <iostream>
#include <vector>
#include <string>
#define pb push_back
using namespace std;
char next(char &c){
  if(c==' ')
    c='A';
  else if(c=='Z')
    c=' ';
  else
    c++;
  return '+';
}
char prev(char &c){
  if(c==' ')
    c='Z';
  else if(c=='A')
    c=' ';
  else
    c--;
  return '-';
}
char next(int &a){
  a++;
  a%=30;
  return '>';
}
char prev(int &a){
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
string s,m="                              ";
int count(char c){
  int r=0;
  for(int i=0;i<30;i++)
    if(m[i]==c)
      r++;
  return r;
}
int dis(char a,char b){
  return change(a,b).length();
}
int dis(int a,int b){
  return change(a,b).length();
}
int np1(int pos,int st){
  int mini=1e9,npos;
  for(int i=0;i<30;i++)
    if(dis(i,pos)+dis(s[st],m[i])<mini || (dis(i,pos)+dis(s[st],m[i])==mini && count(m[pos])>count(npos)))
      mini=dis(i,pos)+dis(s[st],m[i]),npos=i;
  return npos;
}
int np2(int pos,int st){
  int mini=1e9,npos;
  for(int i=0;i<30;i++)
    for(int j=0;j<30;j++)
      if(mini>dis(pos,i)+dis(s[st],m[i])+dis(i,j)+dis(s[st+1],m[j]) && count(m[pos])>count(npos))
	npos=i,mini=dis(pos,i)+dis(s[st],m[i])+dis(i,j)+dis(s[st+1],m[j]);
  return npos;
}
int main(){
  getline(cin,s);
  int pos=0;
  for(int i=0;i<s.length()-1;i++){
    if(i%2){
      int npos=np1(pos,i);
      cout<<change(pos,npos);
      cout<<change(m[pos],s[i]);
      cout<<".";
    }
    else{
      int npos=np1(pos,i);
      cout<<change(pos,npos);
      cout<<change(m[pos],s[i]);
      cout<<".";
    }
  }
  {
    int i=s.length()-1;
    int npos=np1(pos,i);
    cout<<change(pos,npos);
    cout<<change(m[pos],s[i]);
    cout<<".";    
  }
  cout<<endl;
  return 0;
}
