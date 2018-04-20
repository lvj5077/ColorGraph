#include<stdio.h>

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"

using namespace boost;
using namespace std;

int color[100];
bool pass(int k,int c[][100])
{
  int i,j;
  for(i=1;i<k;i++)
  {
    if(c[k][i]==1&&color[i]==color[k])
		return false;
  }
  return true;
}

void graphcolor(int n,int m,int c[][100])
{
	int i,k;
	for(i=1;i<=n;i++)
	  color[i]=0;
	k=1;
	while(k>=1)
	{
		color[k]=color[k]+1;

		color[2]=2;
		color[4]=2;
		color[6]=1;
		color[8]=1;

		while(color[k]<=m)
		   if(pass(k,c)) break;
		   else color[k]=color[k]+1;
		if(color[k]<=m&&k==n)
		{
			for(i=1;i<=n;i++){
				printf("%d ",color[i]);
				if (i%3 ==0)
					printf("\n");
			}
			printf("\n");
			break;
		}
		else if(color[k]<=m&&k<n)
		   k=k+1;
		else
		{
		 color[k]=0;
		 k=k-1;
		}
	}
}


int main(){
    int row=3;
    int col=3;
	int m=3;
	int c[100][100];
    int n = row*col;
    int index = 0;
    int count = 0;

    for (int s =0;s<n;++s){
        int j = floor(s/col);
        int i = s-col*j;
        for (int t=0;t<n;++t){
                if (s>=t){
                    continue;
                }
                if (floor(s/col) != floor(t/col) && (s-col*floor(s/col)) != (t-col*floor(t/col))){
                    continue;
                }
                c[s+1][t+1]=1;   
                c[t+1][s+1]=1; 
                cout <<"(" << s+1  <<", " << t+1 <<")"<<endl;
        }
    }

    cout << endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	graphcolor(n,m,c);
	return 0;
}