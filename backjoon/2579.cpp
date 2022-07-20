#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
	int n;
	int arr[300],dp[300];

	cin>>n;

	for(int i=0;i<n;i++)cin>>arr[i];

	dp[0] = arr[0];
	dp[1]= max(arr[0]+arr[1],arr[1]);
	dp[2]=max(arr[0]+arr[2],arr[1]+arr[2]);

	for(int i=3;i<n;i++)dp[i]=max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]);
	cout<<dp[n-1];
	return 0;
}