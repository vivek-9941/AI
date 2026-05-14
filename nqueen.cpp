#include <iostream>
#include <vector>
using namespace std;

// Print the chessboard
void printBoard(vector<vector<char>>& board) {
    int n =board.size();
    cout << "\nOne possible solution:\n";
    for (int i = 0; i < n; i++) {
        for(int j  = 0;  j < board[0].size();j++){

            cout << board[i][j] <<" ";
        }
        cout<<endl;
    }
}
bool issafe(vector<vector<char>>& grid, int r, int c) {
    int n = grid.size();

    // Check left side of current row
    for (int j = 0; j < c; j++) {
        if (grid[r][j] == 'Q') return false;
    }

    // Check upper-left diagonal
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (grid[i][j] == 'Q') return false;
    }

    // Check lower-left diagonal
    for (int i = r + 1, j = c - 1; i < n && j >= 0; i++, j--) {
        if (grid[i][j] == 'Q') return false;
    }

    return true;
}
bool solve(vector<vector<char>>& grid , int c){
    if(c == grid[0].size()){
        printBoard(grid );
        return true;
    }
    for(int row  = 0 ; row < grid.size();row++){
        if(issafe(grid , row,c) ){
            grid[row][c] = 'Q';
            if(solve(grid , c+ 1 ))return true;
            grid[row][c] = '.';
        }
    }
    return false;
}
int main(){
     int n;
    cout << "Enter value of N: ";
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n,'.'));
    if(!solve(grid, 0)){
        cout<<"NO SOL EXIST"<<endl;
    }
}