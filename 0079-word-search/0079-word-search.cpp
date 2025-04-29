class Solution {
public:
    bool rec(int rs, int ct, int m, int n, int ind, vector<vector<char>>& board, string& word) {
        if (ind == word.size()) return true;
        if (rs<0 || ct< 0 || rs >=m || ct >=n || board[rs][ct] != word[ind]) return false;

        char temp = board[rs][ct];
        board[rs][ct] = '#'; 

        bool down = rec(rs + 1,ct, m, n,ind + 1,board, word);
        bool up = rec(rs - 1,ct, m,n, ind + 1,board, word);
        bool left = rec(rs,ct - 1,m, n,ind + 1,board, word);
        bool right = rec(rs, ct + 1,m, n, ind + 1,board, word);

        board[rs][ct] = temp; 
        return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (board[i][j] == word[0]) {
                    if (rec(i, j, m, n, 0, board, word))
                        return true;
                }
            }
        }
        return false;
    }
};