#include "game.h"
#include <iostream>
#ifndef LINUX
#endif

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
#else
int main(int argc, char* argv[])
#endif
{
    IO m_IO;
    int m_screen_height = m_IO.GetScreenHeight();
    blocks m_block;
    board m_board(&m_block, m_screen_height);
    game m_game(&m_board, &m_block, &m_IO, m_screen_height);
    unsigned long m_time1 = SDL_GetTicks();
    while(!m_IO.IsKeyDown(SDLK_ESCAPE)){
        m_IO.ClearScreen();
        m_game.draw_screen();
        m_IO.UpdateScreen();
        int m_key = m_IO.Pollkey();
        if(m_key == SDLK_RIGHT)
            std::cout << "RIGHT pressed\n";

        if(m_key == SDLK_LEFT)
            std::cout << "LEFT pressed\n";

        switch (m_key){
        case (SDLK_RIGHT):
        {
            if (!m_board.is_impossible_move(m_game.m_pos_x + 1, m_game.m_pos_y, m_game.m_piece, m_game.m_rotation)){
                m_game.m_pos_x++;
            }
            break;
        }
        case(SDLK_LEFT):
        {
            if (!m_board.is_impossible_move(m_game.m_pos_x - 1, m_game.m_pos_y, m_game.m_piece, m_game.m_rotation)){
                m_game.m_pos_x--;
            }  
            break; 
        }
        case (SDLK_x):
        {
            while (!m_board.is_impossible_move(m_game.m_pos_x, m_game.m_pos_y+1, m_game.m_piece, m_game.m_rotation)){
                m_game.m_pos_y++; 
            }
            m_board.store_piece(m_game.m_pos_x, m_game.m_pos_y, m_game.m_piece, m_game.m_rotation);
            m_board.delete_possible_line ();
            if (m_board.game_over()){
                m_IO.Getkey();
                exit(0);
            }
            m_game.create_new_piece();
            break;
        }
        case (SDLK_UP):
        {
            if (!m_board.is_impossible_move(m_game.m_pos_x, m_game.m_pos_y, m_game.m_piece, (m_game.m_rotation + 1) % 4)){
                m_game.m_rotation = (m_game.m_rotation + 1) % 4;
            }
            break;
        }
        }
        unsigned long m_time2 = SDL_GetTicks();
        if ((m_time2 - m_time1) > WAIT_TIME)
        {
            if (!m_board.is_impossible_move(
                    m_game.m_pos_x,
                    m_game.m_pos_y + 1,
                    m_game.m_piece,
                    m_game.m_rotation))
            {
                m_game.m_pos_y++; 
            }
            else{
                m_board.store_piece(
                    m_game.m_pos_x,
                    m_game.m_pos_y,
                    m_game.m_piece,
                    m_game.m_rotation);

                m_board.delete_possible_line();

                if (m_board.game_over())
                {
                    m_IO.Getkey();
                    exit(0);
                }

                m_game.create_new_piece();
            }

            m_time1 = SDL_GetTicks();
        }
        SDL_Delay(16);
    }
    return 0;
}