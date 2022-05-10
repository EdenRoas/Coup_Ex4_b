#include "Ambassador.hpp"
namespace coup{
    Ambassador::Ambassador(Game &game, string name) : Player(game,move(name))
    {
    }
    
    Ambassador::~Ambassador()
    {
    }
    string Ambassador::role(){
        return "Ambassador";
    }
    void Ambassador::transfer(Player &p_a, Player &p_b){// the ammbasador can transfer 1 coin from one player to another
        confirm_your_turn();
        if (p_a.numOfcoins <= 0)
        {
            throw runtime_error("p_a do not have enough coins");
        }
        p_a.numOfcoins--;
        p_b.numOfcoins++;
        endOfaction("transfer");
    }
    

    void Ambassador::block(Player &p){// check if the captain steal 2 coins or one and block his action
        int stealTwoCoins = p.previousAction.compare("stealTwo");
        int stealOneCoin =p.previousAction.compare("stealOne");
        int steal = p.previousAction.compare("steal");
        if ( stealTwoCoins== 0 || stealOneCoin == 0 || steal == 0){
            p.iBeenBlocked();
        }
        else{
            throw invalid_argument("you cantt block this action");  
        }
    }
}