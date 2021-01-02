#ifndef PLAYER_HH
#define PLAYER_HH

#include <map>

#include "core/playerbase.h"

namespace student {

/**
 * @brief The Player class is the subclass of Course::PlayerBase
 * includes some adds like startingresources
 */
class Player : public Course::PlayerBase
{
public:

    /**
      * @brief Player constructor
      * @param name
      * @param objects owned by this
      * @param startresources
      */
    Player(const std::string& name,
           const std::vector<std::shared_ptr<Course::GameObject> > objects={},
           int money = 200,
           int food = 200,
           int wood = 100,
           int stone = 100,
           int ore = 50);

    virtual ~Player() = default;

    /**
     * @brief addStartResources to player
     * @param money
     * @param food
     * @param wood
     * @param stone
     * @param ore
     */
    void addStartResources(int money, int food, int wood, int stone, int ore);

    /**
     * @brief addResources to player in the game
     * @param type
     * @param count
     */
    void addResources(int type, int count);

    /**
     * @brief deleteResources from player in the game
     * @param type
     * @param count
     */
    void deleteResources(int type, int count);

    /**
     * @brief emptyResources clears player resources
     */
    void emptyResources();

    /**
     * @brief isBuildable checks if there's enough resources
     * @param type
     * @param count
     * @return
     */
    bool isBuildable(int type, int count);

    /**
     * @brief getResource functions for checking
     * @return exact resoure amout
     */
    int getMoneyResource();
    int getFoodResource();
    int getWoodResource();
    int getStoneResource();
    int getOreResources();
    /**
     * @brief HQDestroied sets HQ_ to false
     * Player loses if HQ_ is false
     */
    void HQDestroied();

    /**
     * @brief returnHQsituation
     * @return bool HQ_
     */
    bool returnHQsituation();

private:
    bool HQ_;
    int money_;
    int food_;
    int wood_;
    int stone_;
    int ore_;

};


}
#endif // PLAYER_HH
