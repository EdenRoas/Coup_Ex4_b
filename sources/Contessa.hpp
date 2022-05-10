#include "Player.hpp"
namespace coup
{
    class Contessa : public Player
    {
    private:

    public:
        Contessa(Game &game, string name);//constructor
        ~Contessa(); // des
        string role(); // print the role player
        static void block(Player &p);//contessa can block assassin action
    };
}