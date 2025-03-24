#include<iostream>
#include<vector>
using namespace std ;

int peek(vector<vector<int>> grid)
{
    int leftcol = 0 ; 
    int rightcol = grid[0].size() - 1 ; 

    int midcol = leftcol + (rightcol-leftcol)/2 ; 
    int maxrow = 0 ; 

    for(int i=0;i<grid.size();i++)
    {
        if(grid[i][midcol] > grid[maxrow][midcol])
        {
            maxrow = i ;
        }
    }

    bool leftbig = (midcol > 0) && (grid[maxrow][midcol-1] > grid[maxrow][midcol]) ;
    bool rightbig = (midcol < grid[maxrow][rightcol]) && (grid[maxrow][midcol+1] > grid[maxrow][midcol]) ; 

    if(!leftbig && !rightbig) 
    {
        return grid[maxrow][midcol] ;
    }
    if(rightbig)
    {
        leftcol = midcol+1 ; 
    }
    else{
        rightcol = midcol-1 ; 
    }
}

int main() {
    vector<vector<int>> arr = {{9, 8}, {2, 6}} ;

    int result = peek(arr) ;
    cout << "Peak element found : " << result << endl ;
    return 0 ;
}