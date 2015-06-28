//God & me // ya mahdi adrekni
#include <iostream>
using namespace std;
void next(char &c){
  cout<<'+';
  if(c==' ')
    c='A';
  else if(c=='Z')
    c=' ';
  else
    c++;
  return ;
}
void prev(char &c){
  cout<<'-';
  if(c==' ')
    c='Z';
  else if(c=='A')
    c=' ';
  else
    c--;
  return ;
}
void next(int &a){
  cout<<'>';
  a++;
  a%=30;
}
void prev(int &a){
  cout<<'<';
  a--;
  if(a==-1)
    a=29;
}
void change(char &c,char &t){
  if(c==t)
    return ;
  if(c==' ')
    if(t-'A'+1<=13)
      while(c!=t)
	next(c);
    else
      while(c!=t)
	prev(c);
      
  else if(t==' ')
    if(c-'A'+1<=13)
      while(c!=t)
	prev(c);
    else
      while(c!=t)
	next(c);
  else
    if(c>t)
      if(c-t<=13)
	while(c!=t)
	  prev(c);
      else
	while(c!=t)
	  next(c);
    else
      if(t-c<=13)
	while(c!=t)
	  next(c);
      else
	while(c!=t)
	  prev(c);
    return ;
}
void change(int &a,int &b){
  int r1=max(a,b)-min(a,b),r2=30-max(a,b)+min(a,b);
  if(a>b)
    if(r1<r2)
      while(a!=b)
	prev(a);
    else
      while(a!=b)
	next(a);
  else
    if(r1<r2)
      while(a!=b)
	next(a);
    else
      while(a!=b)
	prev(a);
}
int dis(char c,char t){
  if(c==' ')
    c=0;
  else
    c-='A'-1;
  if(t==' ')
    t=0;
  else
    t-='A'-1;
  int r1=max(t,c)-min(t,c),r2=27-max(t,c)+min(t,c);
  return min(r1,r2);
}
int dis(int a,int b){
  int r1=max(a,b)-min(a,b),r2=30-max(a,b)+min(a,b);
  return min(r1,r2);
}
string s,m="                              ";
int count(char c){
  int r=0;
  for(int i=0;i<30;i++)
    if(m[i]==c)
      r++;
  return r;
}
int main(){
  getline(cin,s);
  int pos=0;
  for(int i=0;i<s.length();i++){
    int mini=1e9,npos;
    for(int j=0;j<30;j++)
      if(dis(j,pos)+dis(s[i],m[j])<mini || (dis(j,pos)+dis(s[i],m[j])==mini && count(m[j])>count(npos)))
	mini=dis(j,pos)+dis(s[i],m[j]),npos=j;
    change(pos,npos);
    change(m[pos],s[i]);
    cout<<".";
    }
    cout<<endl;
  return 0;
}
