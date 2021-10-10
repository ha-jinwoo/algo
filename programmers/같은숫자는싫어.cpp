#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int k = arr[0];
    answer.push_back(k);
    for(int i = 1; i<arr.size(); i++){
        if(k != arr[i]){
            k=arr[i];
            answer.push_back(k);
        }
    }
    return answer;
}