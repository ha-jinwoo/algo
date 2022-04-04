#include <bits/stdc++.h>

using namespace std;

const char *number2comma(long long n){
  static char comma_str[64]; 
  char str[64]; int idx, len, cidx = 0, mod; 
  sprintf(str, "%ld", n); 
  len = strlen(str); mod = len % 3; 
  for(idx = 0; idx < len; idx++) { 
    if(idx != 0 && (idx) % 3 == mod) { 
      comma_str[cidx++] = ','; 
    } 
    comma_str[cidx++] = str[idx]; 
  } 
  comma_str[cidx] = 0x00; 
  return comma_str; 
}

const char *number2comma2(long long n){
  static char comma_str[64]; 
  char str[64]; int idx, len, cidx = 0, mod; 
  sprintf(str, "%ld", n); 
  len = strlen(str); mod = len % 3; 
  for(idx = 0; idx < len; idx++) { 
    if(idx != 0 && (idx) % 3 == mod) { 
      comma_str[cidx++] = ','; 
    } 
    comma_str[cidx++] = str[idx]; 
  } 
  comma_str[cidx] = 0x00; 
  return comma_str; 
}

int main(){
  double a,b;
  long long money;
  cin>>a>>b>>money;
  
  double c=a,d=b;
  vector<double> k;
  vector<double> y;

  for(int i = 0; i<20; i++){
    a*=1.03;
    b*=1.09;
    
    k.push_back(a);
    y.push_back(b);
  }

  for(int i = 19; i>=0; i--){
    long long be = money*int(round(y[i]/d * 100))/100-money;
    cout<<(i+1)*3<<"%"<<"       "<<round(k[i])<<"       "<<round(y[i] * 100) / 100<<"       "<<round(y[i]/d * 100)<<"%"<<"       "<<number2comma(money*int(round(y[i]/d * 100))/100)<<"       "<<number2comma2(be)<<endl;
  }

  a=c;
  b=d;
  cout<<"0%"<<"       "<<round(a)<<"       "<<round(b * 100) / 100<<"       "<<round(b/d * 100)<<"%"<<"       "<<number2comma(money)<<"       "<<"0"<<endl;
  for(int i = 0; i<20; i++){
    a*=0.97;
    b*=0.91;
    long long be = money-money*int(round(b/d * 100))/100;
    cout<<"-"<<(i+1)*3<<"%"<<"       "<<round(a)<<"       "<<round(b * 100) / 100<<"       "<<round(b/d * 100)<<"%"<<"       "<<number2comma(money*int(round(b/d * 100))/100)<<"       -"<<number2comma2(be)<<endl;
  }
}