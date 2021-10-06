#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        vector<int> data=array;
        sort(data.begin()+commands[i][0]-1,data.begin()+commands[i][1]);
        answer.push_back(data[commands[i][2]+commands[i][0]-2]);
    }
    return answer;
}