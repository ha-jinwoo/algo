#include <string>
#include <vector>

using namespace std;

long long int gcd(long long int a, long long int b)
{
    return (b==0)? a: gcd(b,a%b);
}

long long int lcm(long long int a, long long int b){
    return a/gcd(a,b)*b;
}

int solution(vector<int> arr) {
    int answer = 0, tmp = arr[0];
    
    for(int k : arr){
        tmp = lcm(k,tmp);
    }
    return answer = tmp;
}