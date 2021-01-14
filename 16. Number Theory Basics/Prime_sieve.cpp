#include<iostream>
using namespace std;

#define ll long long

//Naice Approach O(N) or O(sqrtN)
bool isPrime(int n){
    if(n==1){
        return false;
    }
    if(n==2){
        return false;
    }
    for(int i=2; i * i <n; i++){ //if we find a multiple less than its sqrt then
        //Its conjugate multiple is greater than sqrt no. which are multiple of
        //the number
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void prime_sieve(int *p, int n){

    //first mark all odd as 1
    for(int i=3; i<=n; i+=2){
        p[i] = 1;
    }

    // Sieve
    for(ll i=3; i<=n; i+= 2){
        //if the current number is marked 1 (it is prime)
        if(p[i]==1){
            //mark all the multiple of i as not prime
            for(ll j = i*i; j <= n; j = j+i){
                p[j] = 0;
            }
        }
    }

    p[2] = 1;
    p[1] = p[0] = 0;

    return ;
}

int main(){
    int n;
    cin>>n;

    // cout<<isPrime(n)<<endl;
    int p[n] = {0};
    prime_sieve(p, n);

    //printing all the prime numbers till n
    for(int i=0; i<=n; i++){
        if(p[i] == 1){
            cout<< i <<" ";
        }
    }

    return 0;
}
