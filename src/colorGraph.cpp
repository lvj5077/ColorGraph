#include "colorGraph.h"
#include "utilities.h"

using namespace boost;
using namespace std;

bool pass(int k,vector< vector<int> > adj_mat, vector<int> pre_color, vector<int> post_color)
{
	// cout << "test: "<<endl;
	// printVecSQ(pre_color);
	// printVecSQ(post_color);
	for(int i=0;i<k;++i)
	{
		if (post_color.at(i)!=0){
			for (int j=0;j<k;++j){
				if(adj_mat.at(i).at(j) ==1){
					if ( post_color.at(j)!=0 && post_color.at(i)==post_color.at(j) )
						return false;
					if (pre_color.at(j)!=0 && post_color.at(i)==pre_color.at(j))
						return false;
				}
			}
			if(post_color.at(i)!=pre_color.at(i) && pre_color.at(i)!=0 ){
				return false;
			}
		}
	}
	return true;
}




bool graphcolor(int nodes_num,int colors_used,vector< vector<int> > adj_mat,vector<int> pre_color,vector<int> &post_color)
{
	cout << "Using "<< colors_used << " colors"<<endl;

	bool result = false;

	int k = 0;
	while(!result)
	{
		// cout << "k: "<< k+1<<endl;
		if (pre_color.at(k)!=0){
			post_color.at(k)=pre_color.at(k);
			// if(!pass(nodes_num,adj_mat,pre_color,post_color)) {
			// 	k = k-1;
			// 	if (k<0){
			// 		cout << "No solution by using "<< colors_used << " color(s)" <<endl<<endl;
			// 		break;
			// 	}
			// }
		}
		else{
			post_color.at(k)=post_color.at(k)+1;

			while(post_color.at(k)<=colors_used){
				if(pass(nodes_num,adj_mat,pre_color,post_color)) 
					break;
			    else 
					post_color.at(k)=post_color.at(k)+1;
			}
		}

		// printVecSQ(post_color);

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


			int top_pre_color = 1;
		   	for (int i=0;i<nodes_num;++i){
		   		if (pre_color.at(i)>0){
					if (top_pre_color < pre_color.at(i)) {
						top_pre_color = pre_color.at(i);
					}
		   		}
			}

			tsfile << top_post_color - top_pre_color <<"\n";	
			cout << top_post_color - top_pre_color << " extra colors used"<<endl;
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
			// cout << "roll back"<<endl;
			if (k<0){
				cout << "No solution by using "<< colors_used << " color(s)" <<endl<<endl;
				break;
			}


			while ( pre_color.at(k)!=0 ){
				k = k-1;
				if (k<0){
					cout << "No solution by using "<< colors_used << " color(s)" <<endl<<endl;
					break;
				}
				// cout << "jump to last non-zero"<<endl;
			}

			// cout << endl;

		}
	}

	return result;
}


bool graphcolorOPT(int nodes_num,vector< vector<int> > adj_mat,vector<int> pre_color,vector<int> &post_color){
	int colors_used = 1;
   	for (int i=0;i<nodes_num;++i){
		if (colors_used < pre_color.at(i)) {
			colors_used = pre_color.at(i);
		}
	}
	bool result = false;
	while(!result && colors_used<=nodes_num){
		result = graphcolor(nodes_num,colors_used,adj_mat,pre_color, post_color); 
		colors_used = colors_used+1;
	}

	return result;
}
