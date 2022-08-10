#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100005

int T,N,S,ax,ay,bx,by,ans;
vector <int> X;

struct Z{
	int x,y;
	bool operator < (const Z &ot)const{
		return x<ot.x;
	}
} A[MAXN];

bool proc(int w)
{
	int i;
	X.clear(); X.push_back(-1e9);
	for (i=1;i<=N;i++) if (ay+w < A[i].y && A[i].y < by-w) X.push_back(A[i].x);
	X.push_back(1e9);
	//if (X.back()-X.front() <= w) return 1;
	int s=(S-w-w)/2,l=bx-S/2,r=ax+S/2;
	for (i=1;i<X.size();i++){
		if (X[i]-X[i-1] >= S-w-w && !(X[i-1]+s > r || X[i]-s < l)) return 1;
	}
	return 0;
}

int main()
{
	int i;
	for (scanf("%d",&T);T--;){
		scanf("%d",&N);
		for (i=1;i<=N;i++) scanf("%d%d",&A[i].x,&A[i].y), A[i].x <<= 1, A[i].y <<= 1;
		ax = bx = A[1].x;
		ay = by = A[1].y;
		for (i=1;i<=N;i++){
			ax = min(ax,A[i].x), ay = min(ay,A[i].y);
			bx = max(bx,A[i].x), by = max(by,A[i].y);
		}
		S = max(bx-ax,by-ay);
		if (bx-ax > by-ay){
			for (i=1;i<=N;i++) swap(A[i].x,A[i].y);
			swap(ax,ay);
			swap(bx,by);
		}
		sort(A+1,A+N+1);
		//for(int i=1;i<=N;i++)printf("%d %d\n",A[i].x,A[i].y);
		int s=0,e=S>>1,m;
		while (s <= e){
			m = (s+e)>>1;
			if (proc(m)) e = m-1, ans = m;
			else s = m+1;
		}
		printf("%d.%d\n",ans>>1,ans&1?5:0);
	}
}
