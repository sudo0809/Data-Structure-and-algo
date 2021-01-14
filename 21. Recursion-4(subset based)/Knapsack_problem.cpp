#include<iostream>
using namespace std;

int profit(int N, int C, int *wt, int *wt_cost){

    //base case
    if(N==0||C==0){
        return 0;
    }
    //rec case
    //Including the last item
    int ans = 0;
    int inc, exc;
    inc = exc = 0;
    if(wt[N-1]<=C){
        inc = wt_cost[N-1] + profit(N-1, C-wt[N-1], wt, wt_cost);
    }
    //excluding the last item
    exc = profit(N-1, C, wt, wt_cost);

    ans = max(inc, exc);
    return ans;

}

int main(){
    // int capacity;
    // cin>>capacity;

    int wt[] = {1,2,3,5};
    int wt_cost[] = {40, 20, 35, 100};

    int N = 4;
    int C = 7;

    cout<<profit(N, C, wt, wt_cost)<<endl;


    return 0;
}
