#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i<s.size(); i++){
        if(s[i] == ' ')answer+=' ';
        else if(islower(s[i])&&s[i]+n>'z')answer+=s[i]+n-26;
        else if(isupper(s[i])&&s[i]+n>'Z')answer+=s[i]+n-26;
        else answer+=s[i]+n;
    }
    return answer;
}