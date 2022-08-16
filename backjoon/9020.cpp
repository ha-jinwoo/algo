#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> getChe1(int num) {
	vector<int >a;
	int *arr;

	arr = (int *) malloc(sizeof(int) * num);



	// 입력받은 수 만큼 배열에 모두 초기화 해둔다

	for (int i = 2; i <= num; i++) {

		arr[i] = i;

	}



	for (int i = 2; i <= num; i++) {  // 나누는 값 : i

		for (int j = 2; j <= num; j++) {

			if (arr[j] != i && arr[j] % i == 0) {  // 자신과 같지않고 0으로 떨어지면 소수아님

				arr[j] = 0; // 소수가 아닌 경우 0을 넣어둔다

			}

		}

	}



	// 출력

	for (int i = 2; i<= num; i++) {

		if (arr[i] != 0)

			a.push_back(arr[i]);

	}
	return a;
}



int main() {

	int m;
	cin>>m;
	vector<int>a=getChe1(10000);
	for(int j=0;j<m;j++){
		int n;
		cin>>n;
		int a1,a2;
		std::vector<int>::iterator low;
		for(int i=0;a[i]<=n/2;i++){
			low=std::lower_bound (a.begin(), a.end(), n-a[i]);
			if(a[low-a.begin()]+a[i]==n){
				a1=a[i];
				a2=a[low-a.begin()];
			}
		}
	cout<<a1<<" "<<a2<<endl;
	}


	return 0;
}