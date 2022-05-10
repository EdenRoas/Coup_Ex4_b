#include "Captain.hpp"
namespace coup
{
    Captain::Captain(Game &game, string name) : Player(game,move(name))
    {
        this->steal_from = NULL;
    }

    Captain::~Captain()
    {
    }
    string Captain::role(){
        return "Captain";
    }
    void Captain::block(Player &p){//we check if another captain are stealing and block him
        int check_steal = p.previousAction.compare("steal");
        if (check_steal == 0)
        {
            p.iBeenBlocked();//update that player p been blocked
        }
        else{
            throw invalid_argument("you can't block this action");  
        }
        
    }
    void Captain::iBeenBlocked(){
        int steal = this->previousAction.compare("steal");
        int stealOneCoin = this->previousAction.compare("stealOne");
        int stealTwoCoins = this->previousAction.compare("stealTwo");
        int foreign = this->previousAction.compare("foreign_aid");
        if (stealTwoCoins == 0)
        {
            this->numOfcoins -=2;
            this->steal_from->numOfcoins += 2;
        }
        else if ( stealOneCoin == 0)
        {
            this->numOfcoins -=1;
            this->steal_from->numOfcoins += 1;
        }
        else if (steal == 0)
        {

        }
        else if (foreign == 0)
        {
            this->numOfcoins -= 2;
        }
        else{
            throw invalid_argument("you cant block this action");
        }
    }
    void Captain::steal(Player &p){
        confirm_your_turn();
        if (p.numOfcoins >= 2)
        {   
            this->numOfcoins += 2;
            p.numOfcoins -= 2;
            this->steal_from = &p;
            endOfaction("stealTwo");
        }
        else if (p.numOfcoins == 1)
        {
            this->numOfcoins += 1;
            p.numOfcoins -= 1;
            this->steal_from = &p;
            endOfaction("stealOne");
        }
        else{
            this->steal_from = &p;
            endOfaction("steal");
        }
    }

    
}