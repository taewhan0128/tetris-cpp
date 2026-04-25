#include "game.h"

game::game(board *p_board, blocks *p_blocks, IO *p_io, int p_screen_height)
{
    m_board = p_board;
    m_block = p_blocks;
    m_IO = p_io;
    screen_height = p_screen_height;

    init_game();
}

int game::get_rand(int p_A, int p_B){
    return rand() % (p_B - p_A + 1) + p_A;
}

void game::init_game(){
    srand ((unsigned int) time(NULL));
    m_piece = get_rand(0, 6);
    m_rotation = get_rand(0, 3);
    m_block_color = (color)get_rand(GREEN, YELLOW);
    m_next_block_color = (color)get_rand(GREEN, YELLOW);
    m_pos_x = (BOARD_WIDTH / 2) + m_block->get_x_inital_pos (m_piece, m_rotation);
    m_pos_y = m_block->get_y_inital_pos (m_piece, m_rotation);
    next_piece = get_rand(0, 6);
    next_rotation = get_rand(0, 3);
    next_pos_x = BOARD_WIDTH + 5;
    next_pos_y = 5;
}

void game::create_new_piece(){
    m_piece = next_piece;
    m_rotation = next_rotation;
    m_block_color = m_next_block_color;
    m_pos_x = (BOARD_WIDTH / 2) + m_block->get_x_inital_pos(m_piece, m_rotation);
    m_pos_y = m_block->get_y_inital_pos(m_piece, m_rotation);
    next_piece = get_rand(0, 6);
    next_rotation = get_rand(0, 3);
    m_next_block_color = (color)get_rand(GREEN, YELLOW);
}

void game::draw_block(int p_x, int p_y, int p_block, int p_rotation, color p_color){
    int m_pixel_x = m_board->get_x_pos_pixel(p_x);
    int m_pixel_y = m_board->get_y_pos_pixel(p_y);
    for(int i = 0; i < PIECE_BLOCKS; i++){
        for(int j = 0; j < PIECE_BLOCKS; j++){
            int blockType = m_block->get_block_type(p_block, p_rotation, i, j);
            if(blockType != 0)
            {
                m_IO->DrawRectangle(
                    m_pixel_x + i * BLOCK_SIZE,
                    m_pixel_y + j * BLOCK_SIZE,
                    (m_pixel_x + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
                    (m_pixel_y + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
                    p_color
                );
            }
        }
    }
}

void game::draw_board(){
    int m_x1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
    int m_x2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
    int m_y = screen_height - (BLOCK_SIZE * BOARD_HEIGHT);
    m_IO->DrawRectangle(m_x1 - BOARD_LINE_WIDTH, m_y, m_x1, screen_height - 1, WHITE);
    m_IO->DrawRectangle(m_x2, m_y, m_x2 + BOARD_LINE_WIDTH, screen_height - 1, WHITE);
    m_x1 += 1;
    for(int i = 0; i < BOARD_WIDTH; i++){
        for(int j = 0; j < BOARD_HEIGHT; j++){
            if(!m_board->is_block_free(i, j)){
                m_IO->DrawRectangle(m_x1 + i * BLOCK_SIZE,
                    m_y + j * BLOCK_SIZE,
                    (m_x1 + i * BLOCK_SIZE) + BLOCK_SIZE * 1,
                    (m_y + j * BLOCK_SIZE) + BLOCK_SIZE * 1,
                    m_block_color);
            }
        }
    }
    
}

void game::draw_screen(){
    draw_board();
    draw_block(m_pos_x, m_pos_y, m_piece, m_rotation, m_block_color);
    draw_block(next_pos_x, next_pos_y, next_piece, next_rotation, m_next_block_color);
    //m_IO->DrawRectangle(10, 10, 60, 60, RED);
    //m_IO->DrawRectangle(70, 10, 120, 60, GREEN);
    //m_IO->DrawRectangle(130, 10, 180, 60, BLUE);
    //m_IO->DrawRectangle(190, 10, 240, 60, WHITE);
}