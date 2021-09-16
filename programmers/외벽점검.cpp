#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int T[100];
int answer=9;
void process(int q,vector<int> weak){
    vector<int> dist;
    for(int i = q-1; i>= 0; i--) dist.push_back(T[i]);
    /*for(int i = q-1; i>= 0; i--) cout<<dist[i]<<" ";
    cout<<endl;*/
    unsigned int s;
    unsigned int i=0;
    for(unsigned int y=0; y<weak.size(); y++){
    	unsigned int j,q,a;
    	q=y;
    	s=0;
    	/*if(dist.size()==2&&dist[0]==4&&dist[1]==3){
    		cout<<"y : "<<y<<" ";
    	}*/
    	while(q<weak.size()){
        	/*if(dist.size()==2&&dist[0]==4&&dist[1]==3){
        		cout<<"ing q : "<<q<<" ";
        	}*/
    		if(s==dist.size())break;
    		int k = weak[q];
    		int flag=0;
    		for(i=s;i<dist.size();i++){
    		    j = dist[i];
    		    k += j;
    		    if(k<weak[y+1]) break;
    		    else {
    		    	flag=1;
    		    	for(a=q;a<weak.size();a++){
    		    		//if(dist.size()==2&&dist[0]==4&&dist[1]==3)cout<< " k: "<<k<<", weak[a]: "<<weak[a];
    		    		if(k<weak[a]){
    		    			break;
    		    		}
    		    	}
    		    	q=a;
    		    	i++;
    		    	break;
    		    }
    		}if(flag==0){
    			q++;
    			s++;
    		}
    		else s=i;

    	}
    	/*if(dist.size()==2&&dist[0]==4&&dist[1]==3){
    		cout<<"end q : "<<q<<endl;
    	}*/

    	if(q-y>=weak.size()/2){
    		if(answer>dist.size())answer=dist.size();
    		break;
    	}
    }

}
void Perm(int n, int r, int q,vector<int> &dist,vector<int> weak){
    if(r == 0){process(q,weak);return;}
    for(int i = n-1; i>=0; i--){
        swap(dist[i], dist[n-1]);
        T[r-1] = dist[n-1];
        Perm(n-1, r-1, q,dist,weak);
        swap(dist[i], dist[n-1]);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    vector<int> weak2;
    for(unsigned int i=0;i<weak.size();i++) weak2.push_back(weak[i]-n);
    for(unsigned int i=0;i<weak.size();i++) weak2.push_back(weak[i]);
    for(unsigned int i=1;i<=dist.size();i++) Perm(dist.size(),i,i,dist,weak2);
    if(answer==9) answer=-1;
    return answer;
}
int main(){
	vector<int> weak={1,5,6,10};
	vector<int> dist={1,2,3,4};
	cout<<solution(12,weak,dist);
}