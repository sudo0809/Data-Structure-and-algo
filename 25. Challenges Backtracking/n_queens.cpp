#include<iostream>
using namespace std;

int cnt=0;

bool queenRakhPayege(int board[][12], int i, int j, int n){

    //check for rows
    for(int row=0; row<i; row++){
        if(board[row][j]==1 ){
            return false;
        }
    }
    //check for diagonals
    int left_ptr_x = i;
    int left_ptr_y = j;
    while(left_ptr_x>=0 and left_ptr_y>=0){
        if(board[left_ptr_x][left_ptr_y] == 1){
            return false;
        }
        left_ptr_x--;
        left_ptr_y--;
    }

    int right_ptr_x = i;
    int right_ptr_y = j;
    while(right_ptr_x>=0 and right_ptr_y<n){
        if(board[right_ptr_x][right_ptr_y]==1){
            return false;
        }
        right_ptr_x--;
        right_ptr_y++;
    }

    return true;
}

bool QueenPossible(int board[][12], int i, int n){
    if(i==n){
        cnt++;
        // Printing the board
        // for(int x=0; x<n; x++){
        //     for(int y=0; y<n; y++){
        //         cout<<board[x][y]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return false;
    }


    for(int j=0; j<n; j++){

        if(queenRakhPayege(board, i, j, n)){
            board[i][j] = 1;
            //iss row me possible hai then check for next row
            bool checkingForNextRow = QueenPossible(board, i+1, n);
            if(checkingForNextRow){
                return true;
            }
            board[i][j] = 0; // backtracking
        }
    }
    return false;

}

int main(){
    int n;
    int board[12][12] = {0};
    cin>>n;

    QueenPossible(board, 0, n);

    cout<<cnt<<endl;
    return 0;
}
