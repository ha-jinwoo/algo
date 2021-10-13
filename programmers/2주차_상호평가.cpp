#include <bits/stdc++.h>

using namespace std;

string solution(vector<vector<int>> scores)
{
  string answer = "";

  vector<int> maxes;
  vector<int> mines;
  vector<int> maxcnt(scores.size(), 0);
  vector<int> mincnt(scores.size(), 0);

  for (int i = 0; i < scores.size(); i++)
  {
    int max2 = scores[0][i];
    int min2 = scores[0][i];
    maxcnt[i]++;
    mincnt[i]++;
    for (int j = 1; j < scores.size(); j++)
    {
      if (max2 < scores[j][i])
      {
        max2 = scores[j][i];
        maxcnt[i] = 1;
      }
      else if (max2 == scores[j][i])
        maxcnt[i]++;
      if (min2 > scores[j][i])
      {
        min2 = scores[j][i];
        mincnt[i] = 1;
      }
      else if (min2 == scores[j][i])
        mincnt[i]++;
    }
    maxes.push_back(max2);
    mines.push_back(min2);
  }
vector<bool> cnt(scores.size(),false);
  for (int i = 0; i < scores.size(); i++)
  {
    if (scores[i][i] == maxes[i] && maxcnt[i] == 1) {scores[i][i] = 0;cnt[i]=true;}
    if (scores[i][i] == mines[i] && mincnt[i] == 1) {scores[i][i] = 0;cnt[i]=true;}
  }
  

  vector <double> avr;
  for (int i = 0; i < scores.size(); i++)
  {
    double sum = scores[0][i];
    for (int j = 1; j < scores.size(); j++)
    {
      sum+=scores[j][i];
    }
    if(cnt[i])avr.push_back(sum/(scores.size()-1));
    else avr.push_back(sum/scores.size());
  }
  for(int i = 0; i<avr.size(); i++){
    if(avr[i] >=90)answer+='A';
    else if(avr[i] >=80)answer+='B';
    else if(avr[i] >=70)answer+='C';
    else if(avr[i] >=50)answer+='D';
    else answer+='F';
  }
  
  return answer;
}