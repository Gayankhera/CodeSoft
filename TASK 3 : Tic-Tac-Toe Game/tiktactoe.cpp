#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board(3, vector<char>(3, ' '));

void display_board() 
{
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----\n";
    }
}

pair<int, int> get_player_move(char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> row >> col;
        
        // Check for valid input
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            return make_pair(row, col);
        }
        cout << "Invalid move, try again!" << endl;
    }
}

void update_board(char player, pair<int, int> move) {
    board[move.first][move.second] = player;
}

bool check_win(char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool check_draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    char players[] = {'X', 'O'}; 
    int turn = 0; 
    while (true) {
        display_board();
        pair<int, int> move = get_player_move(players[turn]);
        update_board(players[turn], move);
        
        if (check_win(players[turn])) {
            display_board();
            cout << "Player " << players[turn] << " wins!" << endl;
            break;
        }
        
        if (check_draw()) {
            display_board();
            cout << "It's a draw!" << endl;
            break;
        }
        
        turn = (turn + 1) % 2;
    }
    return 0;
}