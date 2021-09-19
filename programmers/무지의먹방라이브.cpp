#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct h{
	int food;
	int index;
};
bool comp(struct h &a,struct h &b){
	return a.food<b.food;
}
bool comp2(struct h &a,struct h &b){
	return a.index<b.index;
}

int solution(vector<int> food_times, long long k) {
	int n=food_times.size();
	long long dp[200001];
	dp[0]=0;
	for(int i=1;i<=n;i++)dp[i]=dp[i-1]+food_times[i-1];
	if(dp[n]<=k)return -1;
    vector<struct h> a;
    for(int i=0;i<n;i++){struct h h1;h1.food=food_times[i];h1.index=i+1;a.push_back(h1);}
    sort(a.begin(),a.end(),comp);
        int i = 0;
        for (; i < n; i++) {
            long long diff = (i == 0 ? a[0].food : a[i].food - a[i - 1].food);
            long long total = diff * (n - i);
            if (k - total < 0) break;
            else k -= total;
        }
        k %= (n - i);
        sort(a.begin() + i, a.end(), comp2);
        return a[i + k].index;
    return 0;
}

int main(){
	vector<int> food_times={3,1,2};
	long long k=5;
	cout<<solution(food_times,k);
}