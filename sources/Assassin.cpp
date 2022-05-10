#include "Assassin.hpp"
namespace coup
{
    Assassin::Assassin(Game &game, string name) : Player(game, move(name))
    {
        this->assassinTarget = NULL;
    }

    Assassin::~Assassin()
    {
    }
    string Assassin::role(){
        return "Assassin";
    }
    void Assassin::iBeenBlocked(){
        int foreigncheck = this->previousAction.compare("foreign_aid");
        int killcheck = this->previousAction.compare("kill");
        if (killcheck == 0)
        {
            this->assassinTarget->isPlay = true;
        }
        else if (foreigncheck == 0)
        {
            this->numOfcoins -= 2;
        }
        else{
            throw runtime_error("you can't block me!");
        }
    }
    void Assassin::coup(Player &Player){
        confirm_your_turn();
        const int sevenCoins = 7;
        if (!Player.isPlay) //check if he can coup this player 
        {
            throw runtime_error("This player already eliminated!!");
        }
        if (this->numOfcoins < 3) // check if he have enough coins
        {
            throw runtime_error("Assassin-you don't have enough numOfcoins");
        }
        Player.isPlay = false; //else -> coup the player target
        this->assassinTarget = &Player;
        if (this->numOfcoins >= sevenCoins)
        {
            numOfcoins -= sevenCoins;
            this->endOfaction("coup");
        }
        else{
            numOfcoins -= 3;
            this->endOfaction("kill");
        }
    }
        

}