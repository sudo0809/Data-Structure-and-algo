#include<iostream>
using namespace std;

int cnt=0;

bool wayOutOfMaze(char maze[][10], int row, int col, int i, int j){
    //base case
    if(cnt==1){
        return false;
    }
    if(i==row-1 and j==col){
        //print the path
        cnt++;
        for(int x=0; x<row; x++){
            for(int y=0; y<col; y++){
                if(maze[x][y]=='1'){
                    cout<<"1"<<" ";
                }
                else{
                    cout<<"0"<<" ";
                }
            }
            cout<<endl;
        }

        cout<<endl;
        return true;
    }

    //Rec case
    if(maze[i][j]=='X'){
        return false;
    }
    if(i>row-1 || j>col-1){
        return false;
    }
    maze[i][j]='1';

    bool right_possible = wayOutOfMaze(maze, row,col, i, j+1);
    bool down_possible = wayOutOfMaze(maze, row, col, i+1, j);

    if(right_possible || down_possible){
        return true;
    }

    maze[i][j]='O';

    return false;
}

int main(){
    int row, col;
    cin>>row>>col;

    char maze[10][10];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>maze[i][j];
        }
    }

    wayOutOfMaze(maze, row, col, 0, 0);
}
