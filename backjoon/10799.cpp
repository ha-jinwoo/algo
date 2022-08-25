#include <string>
#include <vector>
#include <iostream>
using namespace std;
using namespace std;

int solution(string arrangement) {
    int answer = 0,i=0,a=0;

while(1){
	if(arrangement[i]=='('&&arrangement[i+1]==')')
	{
		answer+=a;
		i=i+2;
	}
	else if(arrangement[i]=='('){
		answer++;
		a++;
		i++;
	}
	else if(arrangement[i]==')'){
		a--;
		i++;
	}
	else;
	if(arrangement.size()==i)break;
}

    return answer;
}

int main(){

	string a;
	cin>>a;
	int ab=solution(a);
	cout<<ab;



}