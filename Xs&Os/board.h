#pragma once
#include <iostream>
#define N 3
#define SIZE 9

namespace board{

    char tab[SIZE];

    void set_tab()
    {
        for(int i=0; i<SIZE; i++)
        {
            tab[i] = ' ';
        }
    }
    
    template <typename T>
    void draw_board(T t[SIZE])
    {
        for(int i=0; i<N; i++)
        {
            std::cout << "   " << t[3*i] << "  |  " << t[3*i+1] << "  |  " << t[3*i+2] << "   " << std::endl;
            if (i!=N-1)
            {
                std::cout << "-------------------" << std::endl;
            }
        } 
    }

    void how_to_play()
    {
        std::cout << "Numers of positions are as on the figure below" << std::endl;
        int positions_tab[SIZE];
        for(int i=0; i<SIZE; i++)
        {
            positions_tab[i] = i;
        }
        draw_board(positions_tab);
        std::cout << std::endl;
    }

    void move(int player)
    {
        std::cout << "Give position number: ";
        int i;
        std::cin >> i;
        if (player == 1)
            tab[i] = 'O';
        else
            tab[i] = 'X';
        draw_board(tab);
    }

    bool tie()
    {
        for(int i=0; i<SIZE; i++)
        {
            if(tab[i] == ' ')
                return false;
        }
        return true;
    }

    bool end(const char c)
    {
        for(int i=0; i<N; i++)
        {
            if(tab[3*i] == c && tab[3*i+1] == c && tab[3*i+2] == c)
                return true;

            if(tab[i] == c && tab[i+3] == c && tab[i+6] == c)
                return true;
        }

        if((tab[0] == c && tab[4] == c && tab[8] == c) || (tab[2] == c && tab[4] == c && tab[6] == c))
            return true;
    
        return false;
    }
}