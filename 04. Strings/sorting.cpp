#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string a, string b){
  if(a.length() == b.length()){
    return a<b;//lexo calculation
  }
  return a.length() < b.length();//Returns True for len(a)< len(b)
  //i.e. this is for ascending order small len to greater len
}


int main() {

  int n;
  cin>>n;
  cin.get();

  string s[100];

  for(int i=0; i<n; i++){
    getline(cin, s[i]);
  }

  sort(s,s+n, compare);

  for(int i=0; i<n; i++){
    cout<<s[i]<<endl;
  }

}
