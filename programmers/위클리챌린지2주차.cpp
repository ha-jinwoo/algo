#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores)
{
    int n = (int)scores.size();
    string answer = "";

    for (int i = 0; i < n; ++i)
    {
        int sum = 0, t = n;
        int max_count = 0, min_count = 0;

        for (int j = 0; j < n; ++j)
        {
            if (scores[j][i] < scores[i][i]) max_count++;
            if (scores[j][i] > scores[i][i]) min_count++;

            sum += scores[j][i];
        }

        if ((max_count == n - 1) || (min_count == n - 1))
        {
            sum -= scores[i][i];
            t--;
        }

        double avg = (double)sum / (double)t;

        if (avg >= 90.0f) answer += "A";
        else if (avg >= 80.0f) answer += "B";
        else if (avg >= 70.0f) answer += "C";
        else if (avg >= 50.0f) answer += "D";
        else answer += "F";
    }

    return answer;
}