#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
void printVecPT( vector<int> *vec){
    for(int i=0; i<vec->size(); ++i)                 
    {                                        
        cout << setw( 4 )<< vec->at(i) << " ";
    }
    cout << endl;
}

void printVec( vector<int> vec){
    for(int i=0; i<vec.size(); ++i)                 
    {                                        
        cout << setw( 4 )<< vec.at(i) << " ";
    }
    cout << endl;
}


void printMat(vector< vector<int> > mat)
{
    for(int i=0; i<mat.size(); ++i)                 
    {                                        
        for(int j=0; j<mat[i].size(); ++j)             
        {    
            cout << setw( 4 )<< mat.at(i).at(j) << " ";
        }
        cout << endl;
    } 
}   

int main(int argc, char *argv[])
{   
    int row,col;
    row = 3;
    col = 4;

    vector< vector<int> >   mat( row , vector<int>(col,0) );

    int count = 0;

    for(int i=0; i<row; ++i)                 
    {                                        
        for(int j=0; j<col; ++j)             
        {          
            ++count;   
            mat.at(i).at(j) = count;
        }
    }

    printMat(mat);

    for(int i=1;i<5;++i)
    {
        cout << i<<" ";
    }
    cout <<endl;


    for(int i=1;i<5;i++)
    {
        cout << i<<" ";
    }
    cout <<endl;
    


    vector<int> *pre_color;

    pre_color = new vector<int> (5,1);
    for(int i=0; i<pre_color->size(); ++i)                 
    {                                        
        cout << setw( 4 )<< pre_color->at(i) << " ";
    }
    cout << endl;

    printVecPT(pre_color);

    printVec(*pre_color);

    return 0;
}