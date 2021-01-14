#include<iostream>
#include<numeric>
#include<climits>
using namespace std;

bool numOfPages(int books[], int n, int m, int min_pages){

    int pages_read = 0;

    int studentUsed = 1; //no. of students read
    for(int i=0; i<n; i++){
        if(pages_read + books[i]> min_pages){
            studentUsed++;

            pages_read = books[i];
            if(studentUsed>m){
                return false;
            }
        }
        else{
            pages_read += books[i];
        }
    }
    return true;
}

int main(){

    int n = 4; // no. of books
    int m = 2; // no.of students
    int books[] = {10, 20, 30, 40};

    int s = books[n-1];
    int initial_sum = 0;
    int e = accumulate(books, books+n, initial_sum);

    int ans = INT_MAX;

    while(s<=e){
        int min_pages = (s+e)/2;
        bool possiblity = numOfPages(books, n, m, min_pages);

        if(possiblity){
            ans = min(min_pages, ans);
            e = min_pages - 1;
        }
        else{
            s = min_pages + 1;
        }

    }

    cout<<ans<<endl;

    return 0;
}
