/**
 * turn -> return the name of the player who needs to play right now
 * winner -> return the name of the winner / error during the game
 * players -> return the names of the players that are still play
 */
#include <iostream>
#include <vector>
#include <stdexcept>
#pragma once
#include <string>
#include <algorithm>
#include "Player.hpp"
using namespace std;

namespace coup
{
    class Player;
    class Game
    {
    private:
        vector<Player *> playersList;

    public:
        Game();                   // constructor
        ~Game();                  // des
        unsigned int i;
        unsigned int numOfPlayers;
        unsigned int startGame;
       // void checklimit(Player &player);
        void playGame();
        vector<string> players(); // return list of the players name
        void newPlyer(Player *p); // auxiliary function for adding a new player
        string turn();            // returns the name of the player whose turn it is now
        string winner();          // return the name of the winner / error-> the game is still playing
        void nextTurn();          // if no one play-> start the game else->move the turn to the next player
    };

}
