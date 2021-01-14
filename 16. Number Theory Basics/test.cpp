#include<iostream>
#include<vector>
using namespace std;

vector<int> prime_seive(int *p, int n){

	for(int i=3; i<=n; i+=2){
		p[i] = 1;
	}
	for(int i=3; i<=n; i+=2){

		if(p[i]==1){
			for(int j=i*i; j<=n; j+= i){
				p[j] = 0;
			}
		}
	}
	p[0] = p[1] = 0;
	p[2] = 1;

	vector<int> primes;
	primes.push_back(2);
	for(int i=3; i<=n; i+=2){
		if(p[i]==1){
			primes.push_back(i);
		}
	}
    cout<<primes[3]<<endl;
	return primes;

}

int main() {

	int n;
	cin>>n;

	int c = 500000;
	int numbers[c] = {0};
	vector<int> primes = prime_seive(numbers, c);

	cout<<primes[n-1]<<endl;

	return 0;
}
