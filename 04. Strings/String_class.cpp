#include<iostream>
#include<string>
using namespace std;

int main() {

  //String INit
  string s0;
  string s1("Hello");
  string s2(s1);
  string s3 = "Hello World!!!";

  string s4 = s3;

  char a[] = {'a', 'b', 'c', '\0'};
  string s5(a);

  cout<<s0<<endl;
  cout<<s1<<endl;
  cout<<s2<<endl;
  cout<<s3<<endl;
  cout<<s4<<endl;
  cout<<s5<<endl;

  //to check whether a string is empty or not
  if(s0.empty()){
    cout<<"s0 is empty"<<endl;
  }//s0.empty() is a boolian value

  //Append
  s0.append("I love python");
  cout<<s0<<endl;
  s0 += " and learning c++";
  cout<<s0<<endl;

  //Remove
  cout<<s0.length()<<endl;
  s0.clear();
  cout<<s0.length()<<endl;

  //Compare two strings
  s0 = "Mango";
  s1 = "Apple";
  cout<<s1.compare(s0)<<endl;// comapring s1 with s0
  //Reaturnes an integer == 0 if equal,  >0 or <0

  if(s1 < s0){
    cout<<"Apple is smaller than Mango"<<endl;
  }

  //find substring
  string s = "I want apple juice";
  int idx = s.find("apple");
  cout<<idx<<endl;

  //Remove a word from a string
  string word = "apple";
  int len = word.length();
  cout<<s<<endl;
  s.erase(idx, len+1);
  cout<<s<<endl;

  //Iterate over all the character in a string
  for(int i=0; i<s1.length(); i++){
    cout<<s1[i]<<";";
  }
  cout<<endl;
   //Iterators
   for(auto it = s.begin(); it<=s.end(); it++){
     cout<<(*it)<<",";
   }
   cout<<endl;

   //for each loop
   for(auto c:s1){
     cout<<c<<",";
   }

}
