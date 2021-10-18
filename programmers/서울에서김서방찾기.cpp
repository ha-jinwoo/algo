#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int result;
    for(int i = 0; i<seoul.size(); i++){
        if(seoul[i] == "Kim")result=i;
    }
    return answer = "김서방은 " + to_string(result) + "에 있다";
}