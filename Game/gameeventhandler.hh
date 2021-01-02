#ifndef GAMEEVENTHANDLER_HH
#define GAMEEVENTHANDLER_HH

#include <vector>
#include <map>

#include "interfaces//igameeventhandler.h"
#include "core/playerbase.h"
#include "mapitem.hh"
#include "player.hh"
#include "bomb.hh"

namespace student {

/**
 * @brief The GameEventHandler class represents GeHandler of the game
 *
 * Handles game changes like resources, players and bombs
 */

class GameEventHandler: public Course::iGameEventHandler
{

public:
    /**
     * @brief GameEventHandler constructor takes no parameters
     */
    GameEventHandler();
    virtual ~GameEventHandler();

    bool modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount);

    /**
     * @brief modifyResources handles resources of the game
     * @param player pointer to player
     * @param resources, amout of resources
     * @return
     */
    bool modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources);

    /**
     * @brief setNewPlayer adds new player to playermap
     * @param player pointer to player
     * @param Flag in the map (MapItem)
     */
    void setNewPlayer(std::shared_ptr<Player> player, MapItem* Flag);

    /**
     * @brief setMaxPLayerCount sets count of players when game starts
     * @param count
     */
    void setMaxPLayerCount(int count);

    int getMaxPlayerCount();

    /**
     * @brief getPlayerCount
     * @return playercount_
     */
    int getPlayerCount();

    /**
     * @brief switchTurn handles turnswitches
     */
    void switchTurn();

    /**
     * @brief movePlayer move players flag to next destination
     * @param coord, destination
     */
    void movePlayer(Course::Coordinate coord);

    /**
     * @brief getRound
     * @return turn in game
     */
    int getRound();

    /**
     * @brief getPlayerTurn is one way to return turn
     * @return
     */
    int getPlayerTurn();

    /**
     * @brief addBomb to bombvector
     * @param bomb pointer
     */
    void addBomb(std::shared_ptr<Bomb> bomb);

    /**
     * @brief getBomb
     * @param i
     * @return bomb
     */
    std::shared_ptr<student::Bomb> getBomb(int i);
    /**
     * @brief getBombCount
     * @return amount of bombs
     */
    int getBombCount();

    /**
     * @brief deleteBomb from bombvector
     * @param bomb pointer
     */
    void deleteBomb(std::shared_ptr<Bomb> bomb);

    /**
     * @brief checkExpolsions checks if there's any
     * @return bomb to explode
     */
    std::shared_ptr<Bomb> checkExpolsions();

    /**
     * @brief getPlayerCoordinate
     * @return coordinate of players flag
     */
    Course::Coordinate getPlayerCoordinate();

    /**
     * @brief getPlayerInTurn
     * @return pointer to player in turn
     */
    std::shared_ptr<Player> getPlayerInTurn();

    /**
     * @brief getPlayer
     * @param i
     * @return pointer to wanted player
     */
    std::shared_ptr<Player> getPlayer(int i);

    /**
     * @brief getPlayers
     * @return vector of players, needed when calculating points
     */
    std::vector<std::shared_ptr<Player>> getPlayers();

    /**
     * @brief deletePlayer deletes player from game
     * @param player
     */
    void deletePlayer(std::shared_ptr<Player> player);

    /**
     * @brief checkIfEnd checks if only one player in game
     * @return that one player (winner)
     */
    std::shared_ptr<Player> checkIfEnd();

private:
    std::shared_ptr<Player> playerInTurn_;
    std::map<std::shared_ptr<Player>, MapItem*> playerMap_;
    std::vector<int> deads_;
    int maxPlayerCount_;
    int turn_;
    int round_;
    std::vector<std::shared_ptr<Bomb>> bombVector_;
};
}
#endif // GAMEEVENTHANDLER_HH
