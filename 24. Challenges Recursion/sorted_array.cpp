#include<iostream>
using namespace std;

bool check_sorted(int a[], int n, int type){

    //base case
    if(n==0){
        return true;
    }

    //rec case
    int current_type;
    if(a[n] < a[n-1]){
        current_type = 21;
    }
    else if(a[n] > a[n-1]){
        current_type = 12;
    }
    else{
        current_type = 0;
    }

    if(current_type!=0 and type!=0 and current_type!=type){
        return false;
    }
    else{
        type = current_type;
        if(check_sorted(a, n-1, type)){
            return true;
        }
        return false;
    }

}

int main(){

    int n;
    cin>>n;
    int arr[1000];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int current_type;
    if(arr[n-1] < arr[n-2]){
        current_type = 21;
    }
    else if(arr[n-1] > arr[n-2]){
        current_type = 12;
    }
    else{
        current_type = 0;
    }
    if(n>2){
    		if(check_sorted(arr, n-1, current_type)){
    			cout<<"true"<<endl;
    		}
    		else{
    			cout<<"false"<<endl;
    		}
    	}
	else{
		cout<<"true"<<endl;
	}
}


//as accepted by the CB (only decreasing oreder sorting)
/*
int arraySortedOrNot(int long long arr[], int n)
{
    // Array has one or no element or the
    // rest are already checked and approved.
    if (n == 1 || n == 0)
        return 1;

    // Unsorted pair found (Equal values allowed)
    if (arr[n - 1] < arr[n - 2])
        return 0;

    // Last pair was sorted
    // Keep on checking
    return arraySortedOrNot(arr, n - 1);
}
int main(){

    int n;
    cin>>n;
    int long long arr[1000];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

	if(n>2){
		if(arraySortedOrNot(arr, n)){
			cout<<"true"<<endl;
		}
		else{
			cout<<"false"<<endl;
		}
	}
	else{
		cout<<"true"<<endl;
	}

}
*/
