#include "board.h"

board::board(blocks *p_blocks, int p_screen_height)
{
    m_blocks = p_blocks;
    screen_height = p_screen_height;
    init_board();
}

void board::init_board(){
    for(int i = 0; i < BOARD_WIDTH; i++){
        for(int j = 0; j < BOARD_HEIGHT; j++){
            m_board[i][j] = POS_FREE;
        }
    }
}

void board::store_piece(int p_x, int p_y, int p_blocks, int p_rotation){
    for(int i1 = p_x, i2 = 0; i1 < p_x + PIECE_BLOCKS; i1++, i2++){
        for(int j1 = p_y, j2 = 0; j1 < p_y + PIECE_BLOCKS; j1++, j2++){
            if(m_blocks->get_block_type(p_blocks, p_rotation, i2, j2) != 0){
                m_board[i1][j1] = POS_FILLED;
            }
        }
    }
}

bool board::game_over(){
    for(int i = 0; i < BOARD_WIDTH; i++){
        if(m_board[i][0] == POS_FILLED){
            return true;
        }
    }
    return false;
}

void board::delete_line(int p_y){
    for(int j = p_y; j > 0; j--){
        for(int i = 0; i < BOARD_WIDTH; i++){
            m_board[i][j] = m_board[i][j-1];
        }
    }
}

void board::delete_possible_line(){
    for(int j = 0; j < BOARD_HEIGHT; j++){
        int i = 0;
        while(i < BOARD_WIDTH){
            if(m_board[i][j] != POS_FILLED){
                break;
            }
            i++;
        }
        if(i == BOARD_WIDTH){
            delete_line(j);
        }
    }
}

bool board::is_block_free(int p_x, int p_y){
    if(m_board[p_x][p_y] == POS_FREE){
        return true;
    }else{
        return false;
    }
}

int board::get_x_pos_pixel(int pos){
    return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pos * BLOCK_SIZE));
}

int board::get_y_pos_pixel(int pos){
    return ((screen_height - (BLOCK_SIZE * BOARD_HEIGHT)) + (pos * BLOCK_SIZE));
}

bool board::is_impossible_move(int p_x, int p_y, int block, int rotation){
    for(int i1 = p_x, i2 = 0; i1 < p_x + PIECE_BLOCKS; i1++, i2++){
        for(int j1 = p_y, j2 = 0; j1 < p_y + PIECE_BLOCKS; j1++, j2++){

            if(m_blocks->get_block_type(block, rotation, i2, j2) != 0){

                if(i1 < 0 || i1 >= BOARD_WIDTH || j1 >= BOARD_HEIGHT){
                    return true;
                }

                if(j1 >= 0 && !is_block_free(i1, j1)){
                    return true;
                }

            }
        }
    }
    return false;
}