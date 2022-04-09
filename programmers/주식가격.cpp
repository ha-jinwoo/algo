#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    int i,j,n=(int)prices.size();
    vector<int> answer;
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(prices[i]>prices[j]){
                answer.push_back(j-i);
                break;
            }
        }
        if(j==n)answer.push_back(n-i-1);
    }
    
    return answer;
}