/**
 * @file Duke.hpp ->Role
 */

#include "Player.hpp"
using namespace std;
namespace coup
{
    class Duke : public Player
    {
    private:

    public:
        Duke(Game &game, string name);//constructor
        ~Duke();                       // des
        string role();                // pront the role of the player
        void tax();                   // the duke can take  coins
        static void block(Player &p); // duck can block player who take foreign_aid
    };
}