#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
int solution(int distance, vector<int> rocks, int n) {

	sort(rocks.begin(),rocks.end());

	int a = 0;
			int b = distance;

			while(a < b) {
				int c = (a+b+1)/2;
				int p = 0;
				int hits = 0;
				for(int i=0;i<rocks.size();i++) {
					if(rocks[i]-p < c) ++hits;
					else p = rocks[i];
				}
				if(hits > n) b = c-1;
				else a = c;
			}
			return a;
}