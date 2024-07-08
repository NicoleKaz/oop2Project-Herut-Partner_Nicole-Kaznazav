#include "Controller.h"
#include <iostream>
#include <thread>
#include <chrono>


int main()
{
    try
    {
        Controller game;
        game.run();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}
