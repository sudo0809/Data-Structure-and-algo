#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<char> q;
    int freq[27] = {0};

    //running stream until you get a '.'
    char ch;
    cin>>ch;

    while(ch != '.'){
        //insert in the q and f table
        q.push(ch);
        freq[ch-'a']++;

        //query
        while(!q.empty()){
            int front_element_idx = q.front() - 'a';
            if(freq[front_element_idx] > 1){
                q.pop();
            }
            else{
                cout<<q.front()<<endl;
                break;
            }
        }
        //q is empty
        if(q.empty()){
            cout<<"-1"<<endl;
        }
        cin>>ch;
    }
    return 0;
}
