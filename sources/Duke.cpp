#include "Duke.hpp"
namespace coup
{
    Duke::Duke(Game &game, string name) : Player(game, move(name))
    {
    }

    Duke::~Duke()
    {
    }
    string Duke::role()
    {
        return "Duke";
    }
    void Duke::block(Player &player)
    {
        int foreign_check = player.previousAction.compare("foreign_aid");
        if (foreign_check == 0)
        {
            player.iBeenBlocked(); // update that he been blocked
        }
        else
        {
            throw invalid_argument("you cantt block this action");
        }
    }
    void Duke::tax()
    {
        confirm_your_turn();
        this->numOfcoins += 3;
        this->endOfaction("tax");
    }

}