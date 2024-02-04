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

void printBoundary2(vector<vector<int>>&A){
    int N = A.size(); // n is the length of the array 
    // 1 starting point i.e 0,0 :.
    int i = 0 , j = 0 ; 
    // printing the first N-1 elements of 1st row
    for(int idx = 1 ; idx <N ;idx++){
        cout<<A[i][j]<<" ";
        j++;
    }
    // printing the first N-1 element of the last colm 
    for(int idx = 1 ; idx < N ;idx++){
        cout<<A[i][j]<<" ";
        i++;
    }
    // printing the N-1 element of the last row 
    for(int idx = 1 ; idx<N ;idx++){
        cout<<A[i][j]<<" ";
        j--;
    }
    //printing the N-1 element of the first col

    for(int idx = 1 ; idx <N ;idx++){
        cout<<A[i][j]<<" ";;
        i--;
    }
}

void printSpiral(vector<vector<int>>&A){
    int N = A.size(); // size of the array
    // we will just print the N-1 array elements on each boundary after that shift to inner boundary to be printed
    int i = 0 , j = 0 ; // starting point 
    while(N>1){
        for(int idx = 1 ; idx < N ;i++){
            cout<< A[i][j]<<",";
            j++;
        }
        for(int idx = 1 ; idx < N ;i++){
            cout<< A[i][j]<<",";
            i++;
        }
        for(int idx = 1 ; idx < N ;i++){
            cout<< A[i][j]<<",";
            j--;
        }
        for(int idx = 1 ; idx < N ;i++){
            cout<< A[i][j]<<",";
            i--;
        }
        i++;j++; // shifting to the inner boundary 
        N= N-2 ;
    }
    if(N==1){
        cout<<A[i][j];
    }

}
int main(){

    // in a sorted 2D array (left to right and top to bot sorted) , determine the presence of a element 

    // in a left to right sorted 2D array (0s & 1s only) determine the row that has maximum number of ones
    vector<vector<int>>A;
    int row = getRowWithMaxOne(A);

    // print all the boundary elements of a 2D array 
    printBoundary(A);

    // another way of writing the code 
    printBoundary2(A);

    printSpiral(A);
    
    cout<<row;
}
/*
[[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80],
[316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,81],
[315,624,625,626,627,628,629,630,631,632,633,634,635,636,637,638,639,640,641,642,643,644,645,646,647,648,649,650,651,652,653,654,655,656,657,658,659,660,661,662,663,664,665,666,667,668,669,670,671,672,673,674,675,676,677,678,679,680,681,682,683,684,685,686,687,688,689,690,691,692,693,694,695,696,697,698,699,700,395,82]]
*/