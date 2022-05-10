#include "Game.hpp"
const int sup = 6;
const int inf = 2;
const int ten = 10;

namespace coup
{
    Game::Game() // const
    {
        this->i = 0;
        this->numOfPlayers = 0;
        this->startGame = 0;
    }

    Game::~Game() // des
    {
    }
    //  void Game::checklimit(Player &player)
    // {
    //     if (this->playersList.size() == 1){throw invalid_argument ("Only one player!!");}
    //     if (this->turn() != player.name){throw invalid_argument ("Not your turn -> GO BACK!");}
    //     if (player.numOfcoins == ten){throw invalid_argument ("you have too much coins you must coup someone!");}
    // }
    vector<string> Game::players() // return list of the names players
    {
        vector<string> the_names;
        for (Player *player : playersList)
        {
            if (player->isPlay)
            {
                the_names.push_back(player->name); // add the new player
            }
        }
        return the_names;
    }
    string Game::turn() // return the name of who play right now
    {
        return this->playersList[i]->name;
    }
    string Game::winner() // return the winner of this game
    {
        if (this->players().size() != 1)
        {
            throw invalid_argument("No winner yet!");
        }
        if (!(this->startGame == 1))
        {
            throw invalid_argument(" The game not started !");
        }

        return this->players().at(0);
    }
    void Game::newPlyer(Player *player)
    {
        if (this->startGame == 1)
        {
            throw invalid_argument("Can't add player -> game is already running");
        }
        if (this->playersList.size() == sup)
        {
            throw invalid_argument("Max players in the game!");
        }
        this->playersList.push_back(player);
        this->numOfPlayers++;
    }
    void Game::playGame(){
        if (startGame == 0)
        {
            startGame = 1;
        }
    }
    void Game::nextTurn()
    {
        do
        {
            this->i = (this->i + 1) % this->playersList.size();
        } 
        while (!this->playersList.at(i)->isPlay);
        if (this->numOfPlayers < inf || this->numOfPlayers > sup)
        {
            throw runtime_error("the game cant start -> The number of players is invalid");
        }
        playGame();
        
    }


}