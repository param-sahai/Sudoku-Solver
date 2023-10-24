class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char dig){
        
        //Check 1: Rowise
        for(int i=0;i<9;i++){
            if(board[row][i]==dig)
                return false;
        }
        
        //Check 2: Column
        for(int i=0;i<9;i++){
            if(board[i][col]==dig)
                return false;
        }
        
        //Check 3: Sub boxes
        int gr = 0, gc = 0;
        if(row<=2) gr = 0;
        else if(row<=5) gr = 3;
        else gr = 6;
        
        if(col<=2) gc = 0;
        else if(col<=5) gc = 3;
        else gc = 6;
        
        for(int i = gr; i<gr+3; i++){
            for(int j = gc; j<gc+3; j++){
                if(board[i][j]==dig)
                    return false;
            }
        }
        
        
        
        return true;
    }
    
    bool helper(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                {
                    for(char dig = '1'; dig<='9'; dig++){
                        if(isValid(board, i, j, dig)){ //Checking for the three conditions
                            board[i][j] = dig; //Replacing i.e Adding digit
                            if(helper(board)) return true; //if in future, it gives true, then its correct
                            else
                                board[i][j] = '.'; //Undoing changes
                        }

                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};