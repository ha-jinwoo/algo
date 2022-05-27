#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    cout<<*min_element(arr.begin(), arr.end());
    if (arr.size() == 1) {
        return { -1 };
    }   
    arr.erase(min_element(arr.begin(), arr.end()));
    return arr;
}