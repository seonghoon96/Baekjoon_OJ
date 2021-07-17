#include <iostream>
using namespace std;
#define MAX 1001
int r,c;
int matrix[MAX][MAX];


int main()
{
    memset(matrix, false, sizeof(matrix));
    cin >>r >> c;
    int minhap = 1000;
    if()
    int xpos, ypos;
    for(int i=1; i<=r; i++)
    {
        for (int j=1; j<=c; j++)
        {
            cin >> matrix[MAX][MAX];
            if(matrix[i][j] < minhap && i!=1 && j !=1 && i!=r &&j!=c)
            {
                minhap = matrix[i][j];
                xpos = i;
                ypos = j;
            }
        }
    }    

}




