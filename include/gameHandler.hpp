#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

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