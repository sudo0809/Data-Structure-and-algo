// t test case
// every test case will give you length of string
// string will comprise of character 'a' and 'b'
// no two 'b' are consecative

#include<iostream>
using namespace std;

int makeStrings(int n, char temp[], int i, char prev){
    if(i==n){
        return 1;
    }

    if(prev == 'b'){
        temp[i] = 'a';
        int count_ba = makeStrings(n, temp, i+1, 'a');

        return count_ba;
    }
    if(prev == 'a'){
        temp[i] = 'a';
        int count_aa = makeStrings(n, temp, i+1, 'a');
        temp[i] = 'b';
        int count_ab = makeStrings(n, temp, i+1, 'b');

        return count_aa + count_ab;
    }

    return 0;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        char temp[25];
        temp[0] = 'a';
        int cnt_a = makeStrings(n, temp, 1, 'a');
        temp[0] = 'b';
        int cnt_b = makeStrings(n, temp, 1, 'b');

        int cnt_total = cnt_a + cnt_b;

        cout<<"#"<<n<<" : "<<cnt_total<<endl;
    }
}
