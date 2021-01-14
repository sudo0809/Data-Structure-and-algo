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
vector<int> factorize(int m, vector<int> &primes){

    vector<int> factors;
    factors.clear();

    int i=0;
    int p = primes[0];

    while(p*p<=m){
        if(m%p==0){
            factors.push_back(p);
            while(m%p==0){
                m = m/p;
            }
        }
        //go to the next position of primes
        i++;
        p = primes[i];
    }
    if(m != 1){
        factors.push_back(m);
    }
    return factors;
}

int main(){
    int n;
    cin>>n;

    int p[n] = {0};
    vector<int>prime = prime_sieve(p,n);
    //
    // int q;
    // cin>>q;
    // while(q--){
    //     int no;
    //     cin>>no;
    //
    //     vector<int>factors = factorize(no, prime);
    //
    //     for(auto a : factors){
    //         cout<<a<<" ";
    //     }
    // }
    cout<<prime[7]<<endl;

}
