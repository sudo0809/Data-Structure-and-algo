#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.first+p1.second < p2.first+p2.second;
}

int main(){
    int n;
    cin>>n;
    int c,r;
    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
        cin>>c>>r;
        v.push_back(make_pair(c,r));
    }
    //sort according to the centre of the circles
    sort(v.begin(), v.end(), compare);

    int  ptr = 1;
    int ans = 0;
    //right _coordinate is centre + radius
    int right_cor_prev = v[0].first + v[0].second;
    int left_cor_next;

    while(ptr<n){
        int left_cor_next = v[ptr].first - v[ptr].second;
        if(left_cor_next < right_cor_prev){
            ans++; //removing the next circle is posssible
            //update the left_cor_next
        }
        else{
            //update the initial circle
            right_cor_prev = left_cor_next + 2*v[ptr].second;
        }
        ptr++;
    }
    cout<<ans<<endl;

    return 0;
}
