#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> a (10,false);
    
    for(int i : numbers){
        a[i] = true;
    }
    
    for(int i = 0; i<10; i++) if(!a[i])answer+=i;
    
    
    return answer;
}