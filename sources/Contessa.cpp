#include "Contessa.hpp"
namespace coup{
    Contessa::Contessa(Game &game, string name) : Player(game, move(name))
    {
    }
    
    Contessa::~Contessa()
    {
    }
    string Contessa::role(){
        return "Contessa";
    }
    void Contessa::block(Player &player){
        int check_kill = player.previousAction.compare("kill"); // check if the assasin last action was to kill another player
        if ( check_kill == 0)
        {
            player.iBeenBlocked(); // update that the assassin been blocked 
        }
        else{
            throw invalid_argument("this action cannot be block!!");  
        }
    }
    
}