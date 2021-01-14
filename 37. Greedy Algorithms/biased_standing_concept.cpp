#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

/*
1
7
noobz 1
llamas 2
winxx 2
wheels 1
coder 5
stangecas 7
error 7
*/

int main(){

    int t;
    cin>>t;
    string s;
    int n, rank;
    vector<pair<string, int> > v;

    while(t--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>s>>rank;
            v.push_back(make_pair(s, rank));
        }
        //using counting sort for keeping Time Complexity O(N)
        int *arr = new int[n+1];
        // memset(arr, 0, sizeof(arr));
        for(int i=0; i<=n; i++){
            arr[i] = 0;
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        //count the ranks
        for(int i=0; i<n; i++){
            int desired_rank = v[i].second;
            arr[desired_rank]++;
        }

        for(int i=0; i<=n; i++){
            cout<<arr[i]<<" ";
        }


        int badness=0;
        int original_rank = 1;
        int i=0;
        ///oterloop is for original ranking possible
        while(original_rank<=n){
            cout<<"here"<<endl;
            while(arr[i]!=0){
                badness += abs(i - original_rank);
                arr[i]--;
                original_rank++;
            }
            i++;
        }
        cout<<badness<<endl;
        delete [] arr;
        v.clear();
    }




    return 0;
}
