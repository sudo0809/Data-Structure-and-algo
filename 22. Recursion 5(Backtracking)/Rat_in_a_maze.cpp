#include<iostream>
using namespace std;

bool rateInMaze(char maze[10][10],int soln[][10], int i, int j, int m, int n){
    if(i==m && j==n){
        soln[m][n] = 1;
        //Print the Path
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //Rat should be inside the grid
    if(i>m || j>n){
        return false;
    }
    if(maze[i][j]=='X'){
        return false;
    }

    //Assume solution exists through current cell
    soln[i][j] = 1;

    //Rec case
    bool rightSuccess = rateInMaze(maze, soln, i, j+1, m, n);
    bool downSuccess = rateInMaze(maze, soln, i+1, j, m, n);

    //Backtracking
    soln[i][j] = 0;

    if(rightSuccess || downSuccess){
        return true;
    }
    return false;
}

int main(){

    char maze[10][10] = {
                        "0000",
                        "00X0",
                        "000X",
                        "0X00",
    };

    int soln[10][10] = {0};
    int m=4, n=4;

    bool ans = rateInMaze(maze, soln, 0, 0, m-1, n-1);

    if(ans==false){
        cout<<"Path doesn't exist !";
    }

    return 0;
}
