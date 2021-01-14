#include<iostream>
#include<climits>
using namespace std;

bool CheckBestTime(int rank[], int p, int s, int curr_time){

    int total_p = 0;
    int count_p = 1;
    int chef_p_time = 0;

    for(int i=0; i<s; i++){

        while(chef_p_time +(rank[i]*count_p) <= curr_time){
            chef_p_time += rank[i] * count_p;
            count_p++;
        }
        total_p += count_p-1;
        chef_p_time = 0;
        count_p = 1;
    }
    if(total_p>=p){
        return true;
    }
    else{
        return false;
    }
}

int main() {

    int t;
    cin>>t;
    for(int i=0; i<t; i++){

        int p, s; // p = parathas to make and s = no.of chefs
        cin>>p>>s;
        int rank[s];

        int fastest_cook = INT_MAX;
        for(int j=0; j<s; j++){
            cin>>rank[j];
            fastest_cook = min(rank[i], fastest_cook);
        }

        int min_time = 0;
        int count = 1;
        int max_time = 0;
        //max_time taken by the fastest fastest_cook
        while(count<=p){
            max_time = max_time + fastest_cook * count;
            count++;
        }

        int ans = max_time;
        while(min_time <= max_time){

            int best_time = (min_time + max_time)/2;
            bool PrathaOnTime = CheckBestTime(rank, p, s, best_time);
            if(PrathaOnTime){
                ans = best_time;
                max_time = best_time - 1;
            }
            else{
                min_time = best_time + 1;
            }
        }

        cout<<ans<<endl;

    }



    return 0;
}
