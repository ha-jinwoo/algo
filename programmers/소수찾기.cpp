#include <bits/stdc++.h>
using namespace std;
int T[100];
set <int> se;
bool sosu(int n) {
    if(n<2)return false;
	int k = (int)sqrt(n);
	for (int i = 2; i <= k; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void process(int q){
	string s="";
    for(int i = q-1; i>= 0; i--)s+=to_string(T[i]);
    int n = stoi(s);
    if(sosu(n))se.insert(n);
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

int solution(string numbers) {
    int answer = 0;
    int n = numbers.size();
    vector<string> s(n);
    vector<int> data;

    for(int i = 0; i<n;i++){
    	s[i] = numbers[i];
    	data.push_back(stoi(s[i]));
    }
    for(int i = 1;i<=n;i++)
    Perm(n,i,i,data);
    
    return se.size();
}