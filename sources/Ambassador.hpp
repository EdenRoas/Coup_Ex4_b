/**
 * @file Ambassador.hpp
 *
 */
#include "Player.hpp"

using namespace std;
namespace coup
{
    class Ambassador : public Player
    {
    private:
        string name;
        Game game;

    public:
        Ambassador(Game &game, string name);//defult constructor
        ~Ambassador();// des
        string role();// return the role of the players
        void transfer(Player &p_a, Player &p_b);// the ammbasador can transfer 1 coin from one player to another
        static void block(Player &p);// the ambassador can block captain's steal
       
    };
    
    
    


}