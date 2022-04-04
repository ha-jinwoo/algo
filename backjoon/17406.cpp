#include <bits/stdc++.h>

using namespace std;

struct h{
  int r1;
  int c1;
  int size;
};

int n,m,k;
int T[100];
int result = INT_MAX;
vector<struct h> a;
vector<vector<int>> arr;

void rotate(int r, int c, int s) {
	for (int d = 1; d <= s; d++) {
		int tmp = arr[r - d - 1][c - d - 1];

		for (int i = r - d + 1; i <= r + d; i++) {
			arr[i - 2][c - d - 1] = arr[i - 1][c - d - 1];
		}

		for (int i = c - d + 1; i <= c + d; i++) {
			arr[r + d - 1][i - 2] = arr[r + d - 1][i - 1];
		}

		for (int i = r + d - 1; i >= r - d; i--) {
			arr[i][c + d - 1] = arr[i - 1][c + d - 1];
		}

		for (int i = c + d - 1; i > c - d; i--) {
			arr[r - d - 1][i] = arr[r - d - 1][i - 1];
		}
		arr[r - d - 1][c - d] = tmp;
	}
}

int min_arr(){
  int r = INT_MAX;
  for(int i = 0; i<n; i++){
    int temp=0;
    for(int j = 0; j<m; j++){
      temp+=arr[i][j];
    }
    r = min(r, temp);
  }
  return r;
}

void process(int q){
  vector<vector<int>> temp(n,vector<int>(m));
  temp = arr;
  for(int i = q-1; i>= 0; i--){
    struct h h1 = a[T[i]-1];
    rotate(h1.r1, h1.c1, h1.size);
  }
  result = min(result, min_arr());
  arr = temp;
}

void Perm(int n, int r, int q,vector<int> &data){
  if(r == 0){process(q);return;}
  for(int i = n-1; i>=0; i--){
    swap(data[i], data[n-1]);
    T[r-1] = data[n-1];
    Perm(n-1, r-1, q,data);
    swap(data[i], data[n-1]);
  }
}

int main(){
  // freopen("Input.txt", "r", stdin);

  cin>>n>>m>>k;
  vector<int> b(m);
  for(int i = 0; i<n; i++)arr.push_back(b);

  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      cin>>arr[i][j];
    }
  }

  for(int i = 0; i<k; i++){
    struct h h1;
    cin>>h1.r1>>h1.c1>>h1.size;
    a.push_back(h1);
  }
  
  vector<int> data;
  for(int i = 1; i<=k; i++) data.push_back(i);
	Perm(k,k,k,data);

  cout<<result;
  return 0;
}