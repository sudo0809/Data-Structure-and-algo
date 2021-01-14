//There are N students  and total of M coupons initially
// X coupouns are required to get scholarship
// Y coupouns will be added in total which student is not able to get sccholarship
//Find max students getting scholarship

#include<iostream>
using namespace std;

bool checkForStudents(int n, int m, int x, int y, int mid){

    //total coupouns
    int total_c = m + (n-mid)*y;
    //total student getting scholarship
    int total_scholarships_coupouns_required = x*mid;

    if(total_scholarships_coupouns_required <= total_c){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    int n, m, x, y;
    cin>>n>>m>>x>>y;

    int s = 0;
    int e = n;
    int ans = 0;
    while(s<=e){

        int mid = (s+e)/2;
        bool possibility = checkForStudents(n, m , x, y, mid);
        if(possibility){
            s = mid+1;
            ans = mid;
        }
        else{
            e = mid-1;
        }
    }

    cout<<ans<<endl;


    return 0;
}
