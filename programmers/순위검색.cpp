#include <bits/stdc++.h>

using namespace std;

pair<vector<string>, int> split(const string &str) {
  int score;
  vector<string> ret(4);

  stringstream ss;	
  ss.str(str);

  // ss >> ret[0];
  // ss >> ret[1];
  // ss >> ret[2];
  // ss >> ret[3];
  // ss >> score;
  ss >> ret[0] >> ret[1] >> ret[2] >> ret[3] >> score;
  
	return make_pair(ret, score);
}
pair<string, int> split2(const string &str) {
  int score;
  string rets, tmp;
  vector<string> ret(4);

  stringstream ss;	
  ss.str(str);

  // ss >> ret[0];
  // ss >> ret[1];
  // ss >> ret[2];
  // ss >> ret[3];
  // ss >> ret[4];
  // ss >> ret[5];
  // ss >> ret[6];
  // ss >> score;

  // if(ret[0]!="-")rets+=ret[0];
  // if(ret[2]!="-")rets+=ret[2];
  // if(ret[4]!="-")rets+=ret[4];
  // if(ret[6]!="-")rets+=ret[6];
  ss >> ret[0] >> tmp >> ret[1] >> tmp >> ret[2] >> tmp >> ret[3] >> score;
  
  if(ret[0]!="-")rets+=ret[0];
  if(ret[1]!="-")rets+=ret[1];
  if(ret[2]!="-")rets+=ret[2];
  if(ret[3]!="-")rets+=ret[3];

	return make_pair(rets, score);
}
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	vector<string> k;
	unordered_map<string, vector<int>> attributes;
	for (string s : info) {
		pair<vector<string>, int> p = split(s);
		vector<string> a = p.first;

		attributes[""].push_back(p.second);

		attributes[a[0]].push_back(p.second);
		attributes[a[1]].push_back(p.second);
		attributes[a[2]].push_back(p.second);
		attributes[a[3]].push_back(p.second);

		attributes[a[0] + a[1]].push_back(p.second);
		attributes[a[0] + a[2]].push_back(p.second);
		attributes[a[0] + a[3]].push_back(p.second);
		attributes[a[1] + a[2]].push_back(p.second);
		attributes[a[1] + a[3]].push_back(p.second);
		attributes[a[2] + a[3]].push_back(p.second);

		attributes[a[0] + a[1] + a[2]].push_back(p.second);
		attributes[a[0] + a[1] + a[3]].push_back(p.second);
		attributes[a[0] + a[2] + a[3]].push_back(p.second);
		attributes[a[1] + a[2] + a[3]].push_back(p.second);

		attributes[a[0] + a[1] + a[2] + a[3]].push_back(p.second);

	}

	for (string s : query) {
		pair<string, int> p = split2(s);
		int count = 0;
		for (int i : attributes[p.first])
			if (i >= p.second)
				count++;
		answer.push_back(count);
	}
	return answer;
}

int main(){

  vector<string> info = {
    "java backend junior pizza 150",
    "python frontend senior chicken 210",
    "python frontend senior chicken 150",
    "cpp backend senior pizza 260",
    "java backend junior chicken 80",
    "python backend senior chicken 50"
  };
  vector <string> query = {
    "java and backend and junior and pizza 100",
    "python and frontend and senior and chicken 200",
    "cpp and - and senior and pizza 250",
    "- and backend and senior and - 150",
    "- and - and - and chicken 100",
    "- and - and - and - 150"
  };

  vector<int> result = solution(info,query);
  for(int i : result) cout<< i <<" ";

  return 0;
}