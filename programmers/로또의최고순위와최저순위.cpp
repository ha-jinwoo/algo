#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0;
    int zerocount = 0;
    for(int i = 0; i<lottos.size(); i++){
      if(lottos[i] == 0)zerocount++;
      for(int j = 0; j<win_nums.size(); j++){
        if(lottos[i] == win_nums[j])cnt++;
      }
    }
    if(cnt+zerocount == 6)answer.push_back(1);
    else if(cnt+zerocount == 5)answer.push_back(2);
    else if(cnt+zerocount == 4)answer.push_back(3);
    else if(cnt+zerocount == 3)answer.push_back(4);
    else if(cnt+zerocount == 2)answer.push_back(5);
    else answer.push_back(6);

    if(cnt == 6)answer.push_back(1);
    else if(cnt == 5)answer.push_back(2);
    else if(cnt == 4)answer.push_back(3);
    else if(cnt == 3)answer.push_back(4);
    else if(cnt == 2)answer.push_back(5);
    else answer.push_back(6);
    return answer;
}
int main()
{
  vector<int> lottos = {44, 1, 0, 0, 31, 25};
  vector<int> win_nums = {31, 10, 45, 1, 6, 19};
  
  vector<int> result = solution(lottos, win_nums);
  cout<<result[0]<<" "<<result[1];
  return 0;
}