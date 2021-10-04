#include <string>
#include <vector>

using namespace std;
int a[35];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    for(int i : lost) a[i]--;
    for(int i : reserve) a[i]++;
    for(int i=1;i<=n;i++){
        if(a[i]==-1){
            if(a[i-1]==1){
                a[i]=a[i-1]=0;
            }
            else if(a[i+1]==1){
                a[i]=a[i+1]=0;
            }
        }
    }
    for(int i : a)if(i == -1)answer--;
    return answer;
}