#include "colorGraph.h"

using namespace boost;
using namespace std;

bool pass(int k,vector< vector<int> > adj_mat, vector<int> pre_color, vector<int> post_color)
{
	for(int i=0;i<k;++i)
	{
		if(adj_mat.at(k).at(i) ==1&&post_color.at(i)==post_color.at(k)){
			return false;
		}
		if(post_color.at(i)==0){
			return false;
		}
		if(post_color.at(i)!=pre_color.at(i) && pre_color.at(i)!=0){
			return false;
		}
	}

	// for(int i=0;i<k;++i)
	// {
	// 	cout << post_color.at(i) << " ";
	// }
	return true;
}


bool graphcolorOPT(int currNode, int nodes_num,int colors_num,vector< vector<int> > adj_mat,vector<int> pre_color, vector<int> &post_color){
	bool result = false;
	cout << "Start: \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	for (int c = 1; c<colors_num;++c){
		int temp = post_color.at(currNode);
		post_color.at(currNode) = c;
		if (pass(currNode,adj_mat, pre_color, post_color)){
			post_color.at(currNode) = c;
			if (currNode<(nodes_num-1)){
				graphcolorOPT(currNode+1,nodes_num,colors_num,adj_mat,pre_color,post_color);
			}
			else{
				result = true;
				cout << "ok"<<endl;
				for (int n =0;n<currNode;++n){
					cout << post_color.at(n)<<" ";
				}

				return result;
			}
		}
		else{
			post_color.at(currNode) = temp;
		}

	}
	if (!result){
		cout << "No result by using "<<colors_num<<" color(s)"<<endl;	
	}

	return result;
}


bool graphcolor(int nodes_num,int colors_num,vector< vector<int> > adj_mat,vector<int> pre_color,vector<int> &post_color)
{
	cout << "Start: \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	int top_pre_color = 1;
   	for (int i=0;i<nodes_num;++i){
   		if (pre_color.at(i)>0){
			if (top_pre_color < pre_color.at(i)) {
				top_pre_color = pre_color.at(i);
			}
   		}
	}

	int k=0;
	bool result = false;

	for (int c = 1;c<colors_num;++c){
		int colors_used = c;

		cout << "colors_used: "<< c<<endl;

		int k = 0;
		while(!result)
		{
			post_color.at(k)=post_color.at(k)+1;

			while(post_color.at(k)<=colors_used){
				if(pass(k,adj_mat,pre_color,post_color)) 
					break;
			   else 
					post_color.at(k)=post_color.at(k)+1;
			}
			if(post_color.at(k)<=colors_used&& k==(nodes_num-1) )
			{
				int top_post_color = 1;
			   	for (int i=0;i<nodes_num;++i){
					if (top_post_color < post_color.at(i)) {
						top_post_color = post_color.at(i);
					}
				}

				ofstream tsfile;
				tsfile.open("result.txt");
				cout << "Find result!"<< endl;

				tsfile << top_post_color - top_pre_color <<"\n";	
				cout << "Extra " <<  top_post_color - top_pre_color << " colors used"<<endl;
			   	for (int i=0;i<nodes_num;++i){
					// cout << post_color.at(i)  <<" ";
	        		tsfile << post_color.at(i) <<" ";
				}
				cout << endl;
				tsfile.close();

				result = true;
				return result;
			}
			else if(post_color.at(k)<=colors_used&&k<nodes_num){
			   k=k+1;
			}
			else
			{
				post_color.at(k)=0;
				k=k-1;
				if (k<0){
					cout << "No solution by using "<< colors_used << " color(s)" <<endl<<endl;
					break;
				}
			}
		}

		if (result){
			break;
		}

	}

	return result;
}

