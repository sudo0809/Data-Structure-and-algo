#include<iostream>
using namespace std;

bool CheckPainter(int board[], int n, int k, int t, int mid_time){

    int P_time = 0; //Indivisual Painter's time
    int count_p = 1; // no. of painter used;
    int i = 0; // i'th board to be painted
    while(i<n){
        if(P_time + board[i]*t <= mid_time){
            P_time += board[i]*t;
            i++;
        }
        else{
            count_p++;
            if(count_p>k){
                // cout<<"returning false"<<endl;
                return false;
            }
            P_time = 0;
        }
    }
    // cout<<"returning true"<<endl;
    return true;
}


int main() {

    int k,n,t;
    cin>>k>>n>>t;

    int board[n];
    // for(int i=0; i<n; i++){
        // cin>>board[i];
    // }

    int s_time = 0;
    int e_time = 0;
    for(int j=0; j<n;j++){
        cin>>board[j];
        e_time += board[j]*t;
        s_time = max(s_time, board[j]*t);
    }


    int ans = e_time;
    while(s_time<=e_time){
        int mid_time = (s_time+e_time)/2;
        bool PaintPossibility = CheckPainter(board, n, k, t, mid_time);
        if(PaintPossibility){
            ans = mid_time;
            e_time = mid_time - 1;
        }
        else{
            s_time = mid_time + 1;
        }
    }

    cout<<ans<<endl;

    return 0;
}
