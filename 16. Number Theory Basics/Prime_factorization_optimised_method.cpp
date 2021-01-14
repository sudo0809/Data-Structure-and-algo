#include<iostream>
#include<vector>
using namespace std;

//Naive Approach O(N)
void naivePrimeFactorsarion(int n){

    vector<pair<int, int> > factors;
    int cnt ;
    for(int i=2; i<=n; i++){
        if(n%i==0){
            cnt = 0;
            while(n%i==0){
                n = n / i;
                cnt++;
            }
            factors.push_back(make_pair(i, cnt));
        }
    }

    //Print the factors
    for(auto p : factors){
        cout<<p.first<<"^"<<p.second<<endl;
    }
}

// Optimised Approach O(sqrtN)
void printFactors(int n){

    vector<pair<int, int> > factors;
    int cnt ;
    for(int i=2; i*i<=n; i++){

        if(n % i == 0){
            //keep on dividing till n is not divisible
            cnt =0;
            while(n % i == 0){
                n = n / i;
                cnt++;
            }
            factors.push_back(make_pair(i, cnt));
        }
    }
    if(n != 1){
        factors.push_back(make_pair(n, 1));
    }
    //Print the printFactors
    for(auto p : factors){
        cout<<p.first<<"^"<<p.second<<endl;
    }

    return;
}

int main(){

    int n;
    cin>>n;

    // printFactors(n);
    naivePrimeFactorsarion(n);

    return 0;
}
