#include <bits/stdc++.h>

using namespace std;

// struct h{
//   int index;
//   int gas;
// };

// bool compare(const struct h h1, const struct h h2) {
//   return h1.index < h2.index;
// }

// int main()
// {
// 	int n,idx,g;
//   vector<struct h> h;

//   cin>>n;

//   for(int i = 0; i<n; i++){
//     cin>>idx>>g;
//     struct h h1 = {idx,g};
//     h.push_back(h1);
//   }
  
//   sort(h.begin(),h.end(),compare);

//   for(int i = 0; i<h.size(); i++){
//     struct h h1 = h[i];
//     cout<<h1.index<<" "<<h1.gas<<endl;
//   }
// 	return 0;
// }
int arr[101];

int main(){
  
  int n,a,b;
  cin>>n;
  
  for(int i = 0; i<n; i++){
    cin>>a>>b;
    arr[a] = b + 1;
  }

  for(int i = 0; i<101; i++){
    if(arr[i])cout<<i<< " " << arr[i] -1 <<endl;
  }

  return 0;
}