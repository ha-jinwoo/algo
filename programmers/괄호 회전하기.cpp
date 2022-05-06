#include <string>
#include <vector>
#include <map>
#include <stack>
using namespace std;

void Mapping(map<char, int> &MAP)
{
    MAP['('] = 1;
    MAP[')'] = 1;
    MAP['{'] = 2;
    MAP['}'] = 2;
    MAP['['] = 3;
    MAP[']'] = 3;
}

bool Check(string Str, map<char, int> GwalHo)
{
    stack<int> Stack;
    for (int i = 0; i < Str.length(); i++)
    {
        if (Str[i] == '(' || Str[i] == '{' || Str[i] == '[') Stack.push(GwalHo[Str[i]]);
        else
        {
            if (Stack.empty() == true) return false;
            if (Stack.top() != GwalHo[Str[i]]) return false;
            Stack.pop();
        }
    }
    if (Stack.empty() == true) return true;
    return false;
}

string Rotate(string Str)
{
    string R_Str = Str;
    R_Str += Str[0];
    return R_Str.substr(1);
}

int solution(string s) 
{
    if (s.length() % 2 != 0) return 0;

    map<char, int> GwalHo;
    Mapping(GwalHo);
    int answer = 0;
    if (Check(s, GwalHo) == true) answer++;
    string Str = s;
    for (int i = 1; i < s.length(); i++)
    {
        Str = Rotate(Str);
        if (Check(Str, GwalHo) == true) answer++;
    }
    return answer;
}