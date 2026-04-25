#ifndef _BOARD_
#define _BOARD_
#include "blocks.h"

#define BOARD_LINE_WIDTH 12
#define BLOCK_SIZE 20
#define BOARD_POSITION 320
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define MIN_VERTICAL_MARGIN 20
#define MIN_HORIZONTAL_MARGIN 20
#define PIECE_BLOCKS 5

class board{
    public:
        board(blocks *m_blocks, int screen_height);
        int get_x_pos_pixel(int pos);
        int get_y_pos_pixel(int pos);
        bool is_block_free(int p_x, int p_y);
        void store_piece(int p_x, int p_y, int p_block, int p_rotation);
        void delete_possible_line();
        bool game_over();
        bool is_impossible_move(int p_x, int p_y, int p_block, int p_rotation);
    private:
        enum {POS_FREE, POS_FILLED};
        int m_board[BOARD_WIDTH][BOARD_HEIGHT];
        blocks *m_blocks;
        int screen_height;
        void init_board();
        void delete_line(int p_y);
};

#endif
