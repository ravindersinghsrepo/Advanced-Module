#include<bits/stdc++.h>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareIntervals(Interval &a , Interval &b){
    return a.start < b.start;
}
// given the intervals are not sorted here 
vector<Interval> mergeOverlappingIntervals(vector<Interval> &A){
    // TC-O(nlogn) , SC-O(N)
    sort(A.begin() , A.end(),compareIntervals); 
    int l = A[0].start , r = A[0].end , n = A.size();
    vector<Interval>ans;
    for(int i = 1 ; i < n ;i++){
        if(r>=A[i].start){ // overlapping
           l = min(l , A[i].start);
           r = max( r , A[i].end);
        }else{ // non-overlapping 
          ans.push_back(Interval(l,r));
          l = A[i].start; 
          r = A[i].end ;
        }
    }
    ans.push_back(Interval(l,r));
    return ans;
}

// given array of intervals is sorted based on the start time 
vector<Interval>mergeWithInterval(vector<Interval>&vec , Interval it){
    int l = it.start , r= it.end ; 
    vector<Interval>ans ;
    for(int i = 0 ; i< vec.size();i++){
        // if the interval lies behind the given interval 
        if(vec[i].end<l){
            ans.push_back(Interval(vec[i].start,vec[i].end));
        }else if(vec[i].start>r){ // if the interval lies beyond the given interval
            ans.push_back(Interval(l,r));
            for(int j = i ; j < vec.size();j++){
                ans.push_back(Interval(vec[j].start,vec[j].end));
            }
            return ans ;
        }else{ // given interval is overlapping with the current one 
            l = min(l , vec[i].start);
            r = max(r , vec[i].end);
        }
    }
    ans.push_back(Interval(l,r));
    return ans ;

}

int findMissingNaturalNumber(vector<int>&A){
    // TC -> O(N) , SC -> O(1) 
    int n = A.size();
    int i = 0 ; 
    while(i< n){
        while(A[i]!=i+1 && A[i]<n+1 && A[i]>0){
            int val = A[i];
            if(A[val-1]== val){
                break;
            }
            A[i] = A[val-1];
            A[val-1] = val;
        }
        i++;
    }
    for(int i = 0 ; i< n ;i++){
        if(A[i]!=i+1){
            return i+1;
        }
    }
    return n+1;
}

int main(){

   // merging overlapping intervals -> intervals are given in array ans are sorted on the basis of start time 
    vector<Interval>interval = {
        Interval(1, 3),
        Interval(4, 6),
        Interval(8, 10),
        Interval(15,18)
    };

   mergeOverlappingIntervals(interval); // this one solves for unsorted intervals , if the intervals are given sorted then no need to do sorting and then tc is O(N)
   
   // merge intervals with the given intervals 
   Interval it = Interval(2, 5);
   mergeWithInterval(interval , it);

   // find first missing +ve positive number (natural number)
   vector<int>vec = {0,-1,1,3,-5,2,4};
   int ans =findMissingNaturalNumber(vec);
   return 1 ;
}
