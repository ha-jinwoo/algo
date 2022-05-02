#include <bits/stdc++.h>

using namespace std;

int isexist(vector<string> v,string city){
  for(int i = 0; i<v.size(); i++)if(v[i]==city)return i;
  return -1;
}

int solution(int cacheSize, vector<string> cities) {
  int answer = 0, count = 0, hits = 0;
  vector<string> c(cacheSize);
  vector<int> g(cacheSize);
  for(string city : cities){
    transform(city.begin(), city.end(), city.begin(), ::tolower);
    int index = isexist(c,city);
    if(index != -1) {
      answer+=1;
      for(int i = 0; i<g.size(); i++)if(g[index]<g[i])g[i]--;
      g[index] = cacheSize;
      hits++;
    } 
    else if(count < cacheSize){
      answer+=5;
      c[count] = city; 
      for(int i = 1; i<=cacheSize; i++){
        bool f = false;
        for(int j : g){
          if(j == i)f = true;
        }
        if(!f){
          g[count] = i;
          break;
        }
      }
      count++;
    }  
    else{
      answer+=5;
      for(int i = 0; i<g.size(); i++)
        if(g[i]==1){
          c[i]=city;
          for(int j = 0; j<g.size(); j++)g[j]--;
          g[i] = cacheSize;
          break;
        }
    }
  }
  return answer;
}