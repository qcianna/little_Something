#include <iostream>
#include "board.h"

int main()
{
    std::cout << "\n\tHello!\n" << std::endl;
    
    board::how_to_play();

    board::set_tab();

    while(board::end('O') == false && board::end('X') == false && board::tie() == false)
    {
        std::cout << "Player 1" << std::endl;
        board::move(1);
        if(board::end('O') == true)
        {
            std::cout << "\n\tPlayer 1 wins!!\n" << std::endl;
        }
        if (board::end('O') == false && board::end('X') == false && board::tie() == false)
        {
            std::cout << "Player 2" << std::endl;
            board::move(2);
            if(board::end('X') == true)
            {
                std::cout << "\n\tPlayer 2 wins!!\n" << std::endl;
            }
        }
        if(board::tie() == true)
        {
            std::cout << "\n\tTIE!!!\n" << std::endl;
        }
    }
}