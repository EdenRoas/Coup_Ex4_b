/**
 * @file Player.cpp
 * @author Eden Roas
 * income -> player can take 1 coin from the pile
 * foreign_aid -> take 2 coin from the pile -> will be block by the Duke
 * coup -> depose another player- cost 7 coins
 * role -> return the player role
 * coins -> return how much coins each playre have
 */
#pragma once
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include<string>
using namespace std;


namespace coup{
    class Game;
    class Player
    {   
    protected:
        Game *game;
        
    public:
        int numOfcoins; //money amount 
        string name; // name of player
        bool isPlay; // if the player still in the game
        string previousAction; // save the last action 
        Player(Game& game, string name); // constructor
        ~Player();//des
        virtual string role();//any player already have this function 
        void income();//let the player take 1 coin
        void foreign_aid();//let the player take 2 coins
        void coup(Player &player); // coup ->cost 7 coins
        int coins() const;//return how much coins any players hava
        void confirm_your_turn(); // confirm that the player can play right now
        void endOfaction(string last);//decleration of the end of the turn and what action was taken
        virtual void iBeenBlocked(); //check if i been blocked on foroigin action and update
        
    };
    
}