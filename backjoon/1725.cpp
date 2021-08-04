// 히스토그램
#include <bits/stdc++.h>

using namespace std;

int N, ans, h[100002];
stack<int> s;

int main() 
{

  int a = 100;
  int result = 0;
for(int i = 1; i<=2;i++){
      result = a >> i;
      cout<<a;
      cout<<result<<endl;
      result = result +1;
      cout<<result<<endl;
}
       
cout<<result;

}