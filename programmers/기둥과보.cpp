#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int bx[1000];
int by[1000];
int gx[1000];
int gy[1000];
int bi=0;
int gi=0;

bool makecolumn(int x,int y){
    if(y==0)return true;
    for(int i=0;i<1000;i++){
        if(bx[i]==x&&by[i]==y)return true;
        else if(bx[i]+1==x&&y==by[i]) return true;
    }
    for(int i=0;i<1000;i++){
        if(gx[i]==x&&gy[i]+1==y)return true;
    }
    return false;
}
bool makebo(int x,int y){
    for(int i=0;i<1000;i++){
        if(gx[i]==x&&gy[i]+1==y)return true;
        if(gx[i]-1==x&&gy[i]+1==y)return true;
    }
    for(int i=0;i<1000;i++){
        if(bx[i]+1==x&&by[i]==y){
            for(int j=0;j<1000;j++){
                if(bx[j]-1==x&&by[j]==y)
                    return true;
            }
        }
        if(bx[i]-1==x&&by[i]==y){
            for(int j=0;j<1000;j++){
                if(bx[j]+1==x&&by[j]==y)
                    return true;
            }
        }
    }
    return false;
}
void makeframe(int x,int y,int a){
    if(a==0){
        if(makecolumn(x,y)){
            gx[gi]=x;
            gy[gi]=y;
            gi++;
        }
    }
    else{
        if(makebo(x,y)){
            bx[bi]=x;
            by[bi]=y;
            bi++;
        }
    }
}
bool pdb(int x,int y,int k){

    for(int i=0;i<1000;i++){
    	if(gx[i]==x&&gy[i]==y){
    		int tempa=bx[k];
    		int tempb=by[k];
    		bx[k]=-3;
    		by[k]=-3;
    		if(!makecolumn(gx[i],gy[i])){
        		bx[k]=tempa;
        		by[k]=tempb;
    			return false;
    		}
    		bx[k]=tempa;
    		by[k]=tempb;
    	}
    	if(gx[i]-1==x&&gy[i]==y){
    		int tempa=bx[k];
    		int tempb=by[k];
    		bx[k]=-3;
    		by[k]=-3;
    		if(!makecolumn(gx[i],gy[i])){
        		bx[k]=tempa;
        		by[k]=tempb;
    			return false;
    		}
    		bx[k]=tempa;
    		by[k]=tempb;
    	}
    	if(bx[i]+1==x&&by[i]==y){

            		int tempa=bx[k];
            		int tempb=by[k];
            		bx[k]=-3;
            		by[k]=-3;
            		if(!makebo(bx[i],by[i])){
                		bx[k]=tempa;
                		by[k]=tempb;
            			return false;
            		}
            		bx[k]=tempa;
            		by[k]=tempb;

    	}
    	if(bx[i]+1==x&&by[i]==y){
            for(int j=0;j<1000;j++){
                if(bx[j]-1==x&&by[j]==y){
            		int tempa=bx[k];
            		int tempb=by[k];
            		bx[k]=-3;
            		by[k]=-3;
            		if(!makebo(bx[i],by[i])||!makebo(bx[j],by[j])){
                		bx[k]=tempa;
                		by[k]=tempb;
            			return false;
            		}
            		bx[k]=tempa;
            		by[k]=tempb;
                }
            }
    	}
    	if(bx[i]-1==x&&by[i]==y){

            		int tempa=bx[k];
            		int tempb=by[k];
            		bx[k]=-3;
            		by[k]=-3;
            		if(!makebo(bx[i],by[i])){
                		bx[k]=tempa;
                		by[k]=tempb;
            			return false;
            		}
            		bx[k]=tempa;
            		by[k]=tempb;

    	}
    	if(bx[i]-1==x&&by[i]==y){
            for(int j=0;j<1000;j++){
                if(bx[j]+1==x&&by[j]==y){
            		int tempa=bx[k];
            		int tempb=by[k];
            		bx[k]=-3;
            		by[k]=-3;
            		if(!makebo(bx[i],by[i])||!makebo(bx[j],by[j])){
                		bx[k]=tempa;
                		by[k]=tempb;
            			return false;
            		}
            		bx[k]=tempa;
            		by[k]=tempb;
                }
            }
    	}
    	
    }
    return true;
}

bool pdg(int x,int y,int k){
    for(int i=0;i<1000;i++){
        if(gx[i]==x&&gy[i]-1==y){
            int tempa=gx[k];
            int tempb=gy[k];
            gx[k]=-3;
            gy[k]=-3;
            if(!makecolumn(gx[i],gy[i])){
                gx[k]=tempa;
                gy[k]=tempb;
                return false;
            }
            gx[k]=tempa;
            gy[k]=tempb;
        }
        if(bx[i]+1==x&&by[i]-1==y){
            int tempa=gx[k];
            int tempb=gy[k];
            gx[k]=-3;
            gy[k]=-3;
            if(!makebo(bx[i],by[i])){
                gx[k]=tempa;
                gy[k]=tempb;
                return false;
            }
            gx[k]=tempa;
            gy[k]=tempb;
        }
        if(bx[i]==x&&by[i]-1==y){
            int tempa=gx[k];
            int tempb=gy[k];
            gx[k]=-3;
            gy[k]=-3;
            if(!makebo(bx[i],by[i])){
                gx[k]=tempa;
                gy[k]=tempb;
                return false;
            }
            gx[k]=tempa;
            gy[k]=tempb;
        }
    }
    return true;
}
void deleteframe(int x,int y,int a,int i){
    if(a==0){
        if(pdg(x,y,i)){
            gx[i]=-3;
            gy[i]=-3;
        }
    }
    else{
        if(pdb(x,y,i)){
            bx[i]=-3;
            by[i]=-3;
        }
    }
}
bool comp(const vector<int> &a,const vector<int> &b){
	if(a[0]==b[0]){
		if(a[1]==b[1])return a[2]<b[2];
		return a[1]<b[1];
	}
	return a[0]<b[0];
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(int i=0;i<1000;i++){
        gx[i]=-3;
        gy[i]=-3;
        bx[i]=-3;
        by[i]=-3;
    }

    for(int i=0;i<build_frame.size();i++){
        int x=build_frame[i][0];
        int y=build_frame[i][1];
        int a=build_frame[i][2];
        int b=build_frame[i][3];
        if(b==1){
            makeframe(x,y,a);
        }
        else{
            for(int j=0;j<1000;j++){
                if(a==1&&bx[j]==x&&by[j]==y){
                    deleteframe(x,y,1,j);
                }
                else if(a==0&&gx[j]==x&&gy[j]==y){
                    deleteframe(x,y,0,j);
                }
            }
        }
    }

    for(int i=0;i<1000;i++){

        if(gx[i]!=-3){
            vector<int> h1;
            h1.push_back(gx[i]);
            h1.push_back(gy[i]);
            h1.push_back(0);
            answer.push_back(h1);
        }
        if(bx[i]!=-3){
        	vector<int> h1;
        	h1.push_back(bx[i]);
        	h1.push_back(by[i]);
        	h1.push_back(1);
        	answer.push_back(h1);
       }
    }
    sort(answer.begin(),answer.end(),comp);
    for(int i=0;i<answer.size();i++){
        cout<<answer[i][0]<<" "<<answer[i][1]<<" "<<answer[i][2]<<endl;
    }
    return answer;
}
int main(){
	vector<vector<int>> build_frame ={

	};
	vector<vector<int>> answer = solution(1,build_frame);

	return 0;
}