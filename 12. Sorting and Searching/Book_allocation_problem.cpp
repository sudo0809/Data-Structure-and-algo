#include<iostream>
using namespace std;

int possibility(int books[], int n, int m, int pages ){

    int student_count = 1;
    int student_pages_count = 0;
    int i=0;
    // cout<<pages<<endl;
    while(student_count<=m){
        if(i==n){
            return 1;
        }
        else if(student_pages_count + books[i]<=pages){
            student_pages_count += books[i];
            i++;
        }
        else{
            student_count ++;
            student_pages_count = 0;
        }
    }
    return 0;
}

int main(){

    int t;
    cin>>t;
    while(t){

        int n, m; //nummber of book = n and students = m
        cin>>n>>m;
        int books[n];
        int total_sum_pages =0; //this is the end i.e all the books are read by
        // 1 student
        for(int i=0; i<n; i++){
            cin>>books[i];
            total_sum_pages += books[i];
        }
        int max_pages = books[n-1]; //this is the start like for k books there
        //are k students to max paseges read by a student in the last book pages
        int s = max_pages;
        int e = total_sum_pages;
        int max_pages_assigned = 0;
        cout<<s<<" "<<e<<endl;
        while(s<=e){
            int mid = (s+e)/2;
            int canStudentsRead = possibility(books, n, m, mid);
            if(canStudentsRead){
                max_pages_assigned =mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        cout<<max_pages_assigned<<endl;
        t--;
    }
    return 0;
}
