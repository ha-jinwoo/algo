#include <bits/stdc++.h>

using namespace std;

int arr[100] = {0,1};

int Fibo(int i){
  cout<<i<<endl;
  if(i == 0) return 0;
  else if(i==1) return 1;
  else if(arr[i])return arr[i];
  else return arr[i] = Fibo(i-1) + Fibo(i-2);
}

int main(){
  cout<<Fibo(7);
}