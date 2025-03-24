#include<iostream>
#include<vector>
using namespace std ;

void generateTF(vector<bool> &com, int n, int index)
{
   if(index == n)
   {
    for(bool i : com)
    {
        cout<<i<<" " ;  
    }
    cout<<endl ;
    return ;
   }
 
   com[index] = false ;
   generateTF(com,n,index+1) ;

   com[index] = true ;
   generateTF(com,n,index+1) ;
}

int main()
{
    int n ;
    cout<<"Enter the number of elements : ";
    cin>>n ;

    vector<bool> com(n) ;
    generateTF(com,n,0) ;

    return 0 ;
}