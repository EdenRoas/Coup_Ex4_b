#include "Player.hpp"
using namespace std;
namespace coup{
    class Assassin : public Player
    {
    private:
        Player *assassinTarget;
    public:
        Assassin(Game &game, string name); // constructor
        ~Assassin();                        // des
        string role();  // print the role player
        void coup(Player &p);//can eliminate another player -> cost 3 coins
        void iBeenBlocked(); //update the 
    };
}