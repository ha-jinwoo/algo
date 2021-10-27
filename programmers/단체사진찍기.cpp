#include <bits/stdc++.h>

using namespace std;

inline void get_indexes(int (*index)[26], const char* str)
{   
    for (int i = 0; str[i] != '\0'; i++)
    {
        (*index)[(int)str[i]] = i;
    }   
}

int solution(int n, vector<string> data)
{
    char str[] = "ACFJMNRT";
    int index[26] = { 0, };
    get_indexes(&index, str);

    int perm[] = {(int)'A',(int)'C',(int)'F',(int)'J',(int)'M',(int)'N',(int)'R',(int)'T'};

    int answer = 0;
    do
    {
        bool flag = true;

        for (string& cond : data)
        {
            const int name1 = int(cond[0]);
            const int name2 = int(cond[2]);
            const int num = cond[4]-'0';
            const char op = cond[3];

            const int dist = abs(perm[index[name1]] - perm[index[name2]]) - 1;

            if (op == '>' && !(dist > num)) flag = false;
            if (op == '=' && !(dist == num)) flag = false;
            if (op == '<' && !(dist < num)) flag = false;

            if (flag == false)
            {
                break;
            }
        }
        if (flag)
        {
            answer++;
        }
    } while (next_permutation(perm, perm + 8));

    return answer;
}