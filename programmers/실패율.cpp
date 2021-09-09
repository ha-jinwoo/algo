#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct h{
  double d;
    int index;
};
bool comp(struct h &a,struct h &b){
    if(a.d==b.d)return a.index<b.index;
    return a.d>b.d;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int stage=1;
    vector<struct h>a;
    double sum=0;
    double delay=0;
    while(stage<N+1){
        sum=0;
        delay=0;
        for(int i=0;i<stages.size();i++){
            if(stage<=stages[i])sum++;
            if(stage==stages[i])delay++;
        }
        
        if(sum!=0){
            struct h h1;
            h1.d=delay/sum;
            h1.index=stage;
            a.push_back(h1);
        }
        else{
                        struct h h1;
            h1.d=0;
            h1.index=stage;
            a.push_back(h1);
        }
        stage++;
    }
    sort(a.begin(),a.end(),comp);
    for(int i=0;i<a.size();i++)cout<<a[i].d<<" ";
    for(int i=0;i<a.size();i++)answer.push_back(a[i].index);
    return answer;
}