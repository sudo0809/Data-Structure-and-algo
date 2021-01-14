#include<iostream>
#include<algorithm>
using namespace std;
int main() {

	int t;
	cin>>t;

	for(int i=0; i<t; i++){

		int n;
		cin>>n;

		int * a = new int[n];
        for(int j=0; j<n; j++){
            cin>>a[j];
        }

        next_permutation(a, a+n);
        for(int j=0; j<n; j++){
            cout<<a[j]<<" ";
        }
        cout<<endl;

        delete [] a;

	}

	return 0;
}
