#include "Player.hpp"

using namespace std;
namespace coup{
    class Captain : public Player
    {
    private:
    
    Player *steal_from;
    public:
        Captain(Game &game, string name);//constructor
        ~Captain();//des
        string role();//print the role of the player
        static void block(Player &p); // captain can block another player
        void iBeenBlocked();//update that i was blocked 
        void steal(Player &p); //the captain can steal one to two coins
    };


}