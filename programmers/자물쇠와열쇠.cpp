#include <iostream>
#include <vector>
using namespace std;
int n,m;

vector<vector<int>>turn90(vector<vector<int>>key){
    vector<vector<int>> key2;
    for(int i=0;i<m;i++){
        vector<int> a(m);
        key2.push_back(a);
    }
    int n1=m/2;
    int i=0;
    if(m%2==0){
        while(i+1<n1){
            key2[i][i]=key[m-1-i][i];
            key2[i][m-1-i]=key[i][i];
            key2[m-1-i][m-1-i]=key[i][m-1-i];
            key2[m-1-i][i]=key[m-1-i][m-1-i];

            for(int j=i+1;j<m-1;j++)key2[j][i]=key[m-1-i][j];
            for(int j=i+1;j<m-1;j++)key2[i][j]=key[m-1-j][i];
            for(int j=i+1;j<m-1;j++)key2[j][m-1-i]=key[i][j];
            for(int j=i+1;j<m-1;j++)key2[m-1-i][m-1-j]=key[j][m-1-i];
            i++;
        }
        key2[i][i]=key[m-1-i][i];
        key2[i][m-1-i]=key[i][i];
        key2[m-1-i][m-1-i]=key[i][m-1-i];
        key2[m-1-i][i]=key[m-1-i][m-1-i];
    }

    else{
        while(i<n1){

            key2[i][i]=key[m-1-i][i];
            key2[i][m-1-i]=key[i][i];
            key2[m-1-i][m-1-i]=key[i][m-1-i];
            key2[m-1-i][i]=key[m-1-i][m-1-i];

            for(int j=i+1;j<m-1-i;j++)key2[j][i]=key[m-1-i][j];
            for(int j=i+1;j<m-1-i;j++)key2[i][j]=key[m-1-j][i];
            for(int j=i+1;j<m-1-i;j++)key2[j][m-1-i]=key[i][j];
            for(int j=i+1;j<m-1-i;j++)key2[m-1-i][j]=key[m-1-j][m-1-i];
            i++;
        }
        key2[n1][n1]=key[n1][n1];
    }


    return key2;
}

vector<vector<int>> makelock(vector<vector<int>>lock){
    vector<vector<int>>lock2;
    for(int i=0;i<3*n;i++){
        vector<int> a(3*n);
        lock2.push_back(a);
    }

    for(int i=n;i<2*n;i++){
        for(int j=n;j<2*n;j++)
        lock2[i][j]=lock[i-n][j-n];
    }

    return lock2;
}
vector<vector<int>> makekey(vector<vector<int>>key){
    vector<vector<int>>key2;
    for(int i=0;i<3*n;i++){
        vector<int> a(3*n);
        key2.push_back(a);
    }

    for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
            key2[i][j]=key[i][j];
    }

    return key2;
}
bool lockoff(vector<vector<int>>key2,vector<vector<int>>lock2){
    for(int i=n;i<2*n;i++)for(int j=n;j<2*n;j++)if(key2[i][j]+lock2[i][j]!=1)return false;
    return true;
}
bool search(vector<vector<int>>key2,vector<vector<int>>lock2){
    int i,j,si=m,sj=m;
    while(si<3*n){
        for(i=si;i>=si-m+1;i--){
            for(int k=0;k<m;k++)key2[i][k]=key2[i-1][k];
            for(int k=0;k<m;k++)key2[i-1][k]=0;
        }
        vector<vector<int>>key3;
        for(i=0;i<3*n;i++){
            vector<int> a(3*n);
            key3.push_back(a);
        }
        for(i=0;i<3*n;i++)for(j=0;j<3*n;j++)key3[i][j]=key2[i][j];

        sj=m;
        while(sj<3*n){

            for(j=sj;j>=sj-m+1;j--){
                for(int k=m-1;k>=0;k--)key3[si-k][j]=key3[si-k][j-1];
                for(int k=m-1;k>=0;k--)key3[si-k][j-1]=0;
            }
            if(lockoff(key3,lock2))return true;
            sj++;
        }
        si++;
    }
    return false;
}
bool solution(vector<vector<int>>key,vector<vector<int>>lock){
    n=lock.size();
    m=key.size();

    vector<vector<int>>lock2=makelock(lock);
    vector<vector<int>>key2=makekey(key);
    if(search(key2,lock2)) return true;

    vector<vector<int>> key3 = turn90(key);
    vector<vector<int>> key6=makekey(key3);
    if(search(key6,lock2)) return true;

    vector<vector<int>> key4 = turn90(key3);
    vector<vector<int>> key7=makekey(key4);
    if(search(key7,lock2)) return true;

    vector<vector<int>> key5 = turn90(key4);
    vector<vector<int>> key8=makekey(key5);
    if(search(key8,lock2)) return true;


    return false;
}