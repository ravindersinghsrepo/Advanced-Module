#include<bits/stdc++.h>
using namespace std;

// important 
int getRowWithMaxOne(vector<vector<int>>&vec){
    int n = vec.size() , m = vec[0].size() ; 
    int row = 0 , col = m-1 ;
    int ans = - 1;
    while(row<n && col>=0){
        // move left till we reach 0 or till we col ptr goes out of bound
        // also update ans(that stores row)
        while(col>=0 && vec[row][col]==1){
            ans = row;
            col--;
        }
        // if we reach 0               -----  then go down
        // if out of bound we come out -----  no harm in going down
        row++;
        // in nect iteration we will check if we are 1 then follow same thing 

    }
    return ans;
}

/* input :
    1  2  3  4  5
    6  7  8  9  10
    11 12 13 14 15
    16 17 18 19 20
    21 22 23 24 25 
    output : 1 2 3 4 5 10 15 20 25 24 21 16 11 6 
    */
void printBoundary(vector<vector<int>>&arr){
    int n = arr.size();
    int m = arr[0].size();
    int i = 0 , j = 0 ; 

    // print first row (0,0 to 0,m-2)
    while(j<m-1){
        cout<<arr[i][j]<<" ";
        j++;
    }

    // print the last column till 2nd last element only 
    while(i<n-1){
        cout<<arr[i][j]<<" ";
        i++;
    }

    // print the last row till 2nd element only
    while(j>=1){
        cout<<arr[i][j]<<" ";
        j--;
    }
    // print the first col till 2nd element only  
    while(i>0){
        cout<<arr[i][j]<<" ";
        i--;
    }
    return ;
}

int main(){

    // in a sorted 2D array (left to right and top to bot sorted) , determine the presence of a element 

    // in a left to right sorted 2D array (0s & 1s only) determine the row that has maximum number of ones
    vector<vector<int>>A;
    int row = getRowWithMaxOne(A);

    // print all the boundary elements of a 2D array 
    printBoundary(A);

    
    cout<<row;
}