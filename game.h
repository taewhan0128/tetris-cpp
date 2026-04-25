#ifndef _GAME_
#define _GAME_

#include "board.h"
#include "blocks.h"
#include "IO.h"
#include <time.h>

#define WAIT_TIME 700

class game{
    public:
        game(board *p_board, blocks *p_block, IO *p_io, int screen_height);
        void draw_screen();
        void create_new_piece();
        int m_pos_x, m_pos_y;
        int m_piece, m_rotation;
    private:
        int screen_height;
        int next_pos_x, next_pos_y;
        int next_piece, next_rotation;
        board *m_board;
        blocks *m_block;
        IO *m_IO;
        color m_block_color;
        color m_next_block_color;
        int get_rand(int p_A, int p_B);
        void init_game();
        void draw_block(int p_x, int p_y, int p_block, int p_rotation, color p_color);
        void draw_board();
};

#endif