#include<iostream>
using namespace std;

int main(){

    int arr[100];
    int n, i, val, diff;

    while(1){
        //taking input for current test case
        int max_load = 0;
        int load = 0;
        cin>>n;
        //brak at input n=-1
        if(n==-1){
            break;
        }

        for(int i=0; i<n; i++){
            cin>>arr[i];
            load+= arr[i];
        }
        if(load%n !=0){
            cout<<-1<<endl;
            continue;
        }

        //find the load that is to be divided equally
        load = load/n;

        diff = 0;
        //greedy step
        for(int i=0; i<n; i++){
            //find the difference between final load to be assigned and current load
            diff += (arr[i] - load);
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }

        cout<<max_load<<endl;
    }
}
