/*
bishop ba9i makmel car fih 4 cas normalement
input not checked yet
*/
#include "check_mate.h"

int     ft_piece(char c) {
    return (c == 'P' || c == 'B' || c == 'P' || c == 'Q');
}

int     ft_pawn(char **board, int x, int y) {
    if ((x-1 >= 0) && (y-1 >= 0)) { 
        if ((board[y-1][x-1] == 'K') || (board[y-1][x+1] == 'K'))
            return (1);
    }
    return (0);
}

int     ft_rook(char **board, int x, int y) {
    int i = x, j = 0;
    while (board[j]) {
        if (ft_piece(board[j][i]))
            return (0);
        if (board[j][i] == 'K')
            return(1);
        j++;
    }
    i = 0;
    j = y;
    while (board[j][i]) {
        if (ft_piece(board[j][i]))
            return (0);
        if (board[j][i] == 'K')
            return(1);
        i++;
    }
    return (0);
}

int     ft_bishop(char **board, int x, int y) {
    int i = x, j = y;

    while (board[j] && j > -1) {
        while (board[j][i] && i > -1) {
            if (ft_piece(board[j][i]))
                return (0);
            if (board[j][i] == 'K')
                return(1);
            i++;
        }
        j++;
    }
    while (board[j] && j > -1) {
        while (board[j][i] && i > -1) {
            if (ft_piece(board[j][i]))
                return (0);
            if (board[j][i] == 'K')
                return(1);
            i--;
        }
        j--;
    }
    i = 0;
    while (board[--j]) { 
        while (board[j][i]){
            if (ft_piece(board[j][i]))
                return (0);
            if (board[j][i] == 'K')
                return(1);
            i++;
        }
        j--;
    }
    return (0);
}

void    ft_checkmate(char **board) {
    int i, j = 0;

    while (board[j]) {
        i = 0;
        while (board[j][i]) {
            if((board[j][i] == 'P') && (ft_pawn(board,i,j))) {
                write(1,"Success",7);
                return ;
            } else if ((board[j][i] == 'B') && (ft_bishop(board,i,j))) {
                write(1,"Success",7);
                return ;
            } else if ((board[j][i] == 'R') && (ft_rook(board,i,j))) {
                write(1,"Success",7);
                return ;
            } else if ((board[j][i] == 'Q') && (ft_bishop(board,i,j) || ft_rook(board,i,j))) {
                write(1,"Success",7);
                return ;
            } else
                i++;
        }
        j++;
    }
    write(1,"Fail",4);
}
int main (int ac, char **av) {
    if (ac > 1) {
        ft_checkmate(&av[1]);
    }
    write(1,"\n",1);
    return (0);
}