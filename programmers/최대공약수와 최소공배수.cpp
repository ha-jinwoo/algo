#include <string>
#include <vector>

using namespace std;

// 최대공약수 구하기
int gcd(long long int a, long long int b)
{
    return (b==0)? a: gcd(b,a%b);
}
// 최소공배수 구하기
int lcm(long long int a, long long int b){
    return a/gcd(a,b)*b;
}

vector<int> solution(int n, int m) {
    vector<int> answer={gcd(n,m),lcm(n,m)};
    return answer;
}