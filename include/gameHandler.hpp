#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include<control.hpp>
#include<elements.hpp>
#include<matrix.hpp>

class GameHandler
{
private:
    GameHandler();
    GameHandler(const GameHandler &);
public:
    static GameHandler& getInstance()
    {
        static GameHandler instance;
        return instance;
    }
    
};

#endif