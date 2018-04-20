#include "colorGraph.h"

using namespace boost;
using namespace std;

bool pass(int k,vector< vector<int> > adj_mat, vector<int> color)
{
  for(int i=1;i<k;++i)
  {
    if(adj_mat.at(k).at(i) ==1&&color.at(i)==color.at(k))
		return false;
  }
  return true;
}


void graphcolor(int nodes_num,int colors_num,vector< vector<int> > adj_mat,vector<int> pre_color)
{
	cout << "Start: \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	vector <int> color (nodes_num,1);
	int k=1;
	while(k>=1)
	{
		color.at(k)=color.at(k)+1;
		int top_pre_color = 1;
	   	for (int i=0;i<nodes_num;++i){
	   		if (pre_color.at(i)>0){
				color.at(i) = pre_color.at(i);
				if (top_pre_color < pre_color.at(i)) {
					top_pre_color = pre_color.at(i);
				}
	   		}
		}

		while(color.at(k)<=colors_num)
			if(pass(k,adj_mat,color)) 
				break;
		   else 
				color.at(k)=color.at(k)+1;
		if(color.at(k)<=colors_num&& k==(nodes_num-1) )
		{
			int top_post_color = 1;
		   	for (int i=0;i<nodes_num;++i){
				if (top_post_color < color.at(i)) {
					top_post_color = color.at(i);
				}
			}

			ofstream tsfile;
			tsfile.open("result.txt");
			cout << "Result:"<< endl;

			tsfile << top_post_color - top_pre_color <<"\n";	
			cout << "Extra " <<  top_post_color - top_pre_color << " colors used"<<endl;
		   	for (int i=0;i<nodes_num;++i){
				cout << color.at(i)  <<" ";
        		tsfile << color.at(i) <<" ";
			}
			cout << endl;
			tsfile.close();
			break;
		}
		else if(color.at(k)<=colors_num&&k<nodes_num)
		   k=k+1;
		else
		{
		 color.at(k)=0;
		 k=k-1;
		}
	}
}

