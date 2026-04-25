#ifndef _BLOCKS_
#define _BLOCKS_

class blocks{
    public:
        int get_block_type(int p_block, int p_rotation, int p_x, int p_y);
        int get_x_inital_pos(int p_block, int p_rotation);
        int get_y_inital_pos(int p_block, int p_rotation);
};

#endif