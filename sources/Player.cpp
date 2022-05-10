#include "Player.hpp"
#include "Game.hpp"
using namespace std;
const int six = 6;
const int limit = 10;
const int coup_cost = 7;

namespace coup
{
    Player::Player(Game &game, string name)
    {
        this->name = move(name);
        this->game = &game;
        if (this->game->startGame == 1)
        {
            throw runtime_error("the game already start");
        }
        if (this->game->numOfPlayers == six)
        {
            throw runtime_error("too many players");
        }
        this->isPlay = true;
        this->game->newPlyer(this);
        this->numOfcoins = 0;
    }
    Player::~Player()
    {
    }
    string Player::role()
    {
        return "player";
    }
    void Player::income()
    {
        confirm_your_turn();
        this->numOfcoins++;
        this->endOfaction("income");
    }
    void Player::foreign_aid()
    {
        confirm_your_turn();
        if (this->numOfcoins > limit) // check the limit coins
        {
            throw runtime_error("you have too much coins you must coup someone!");
        }
        this->numOfcoins += 2;
        
        this->endOfaction("foreign_aid");
    }
    void Player::coup(Player &player){
        confirm_your_turn();
        if (!player.isPlay)
        {
            throw invalid_argument("this player is already dead!!");
        }
        
        if (this->numOfcoins < coup_cost)
        {
            throw runtime_error("this Player havn't enough numOfcoins");
        }
        player.isPlay = false;
        numOfcoins -= coup_cost;
        this->endOfaction("coup");

    }
    
    int Player::coins() const{
        return this->numOfcoins;
    }

    void Player::confirm_your_turn(){
        int turn_check = this->name.compare(game->turn());
        if (turn_check != 0)
        {
            throw runtime_error(this->name + " is not your turn!");
        }
        
    }
    void Player::iBeenBlocked(){
        int foreigncheck = this->previousAction.compare("foreign_aid");
        if (foreigncheck == 0)
        {
            this->numOfcoins -= 2;
        }
        else{
            throw invalid_argument("cannot block this action!!");
        }
    }
    void Player::endOfaction(string last){
        this->previousAction = move(last);
        this->game->nextTurn();
    }
    
}