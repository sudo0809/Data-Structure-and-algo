#include<iostream>
#include<vector>
using namespace std;

//Complexity O(log(log(N)))
vector<int> prime_sieve(int *p, int n){

    p[2] = 1;
    p[1] = p[0] = 0;
    //first mark all odd as 1
    for(int i=3; i<=n; i+=2){
        p[i] = 1;
    }

    // Sieve
    for(int i=3; i<=n; i+= 2){
        //if the current number is marked 1 (it is prime)
        if(p[i]==1){
            //mark all the multiple of i as not prime
            for(int j = i*i; j <= n; j = j+i){
                p[j] = 0;
            }
        }
    }
    vector<int> primes;
    primes.push_back(2);

    for(int i=3; i<=n; i+=2){
        if(p[i]==1){
            primes.push_back(i);
        }
    }
    return primes;
}

//Compelxity O(lon(N))
int noOfDivisor(int m, vector<int> &primes){

    int i=0;
    int p = primes[0];
    int ans = 1;

    int cnt;
    while(p*p<=m){

        if(m%p==0){
            cnt=0;
            while(m%p==0){
                cnt++;
                m = m/p;
            }
            ans = ans * (cnt + 1);
        }
        //go to the next position of primes
        i++;
        p = primes[i];
    }
    if(m != 1){
        ans = ans * 2;
    }
    return ans;
}

int main(){
    int n = 1000;
    // cin>>n;

    int p[n] = {0};
    vector<int>prime = prime_sieve(p,1000);

    int q;
    cin>>q;
    while(q--){
        int no;
        cin>>no;

        int divisor = noOfDivisor(no, prime);
        cout<< divisor << endl;

    }

}
