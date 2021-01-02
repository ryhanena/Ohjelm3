#ifndef BOMB_HH
#define BOMB_HH

#include "buildings/buildingbase.h"

namespace student {
/**
 * @brief The Bomb class represents bomb in the game
 *
 * Can be used to destroy buildings and workers surrounding
 */

class Bomb : public Course::BuildingBase
{
public:

    Bomb() = delete;

    /**
     * @brief Bomb constructor
     * @param eventhandler points to student GE-Handler
     * @param objectmanager points to student ObjManager
     * @param owner points to owner
     * @param tilespaces
     */
    explicit Bomb(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1
            );

    virtual ~Bomb() = default;

    /**
     * @brief getType
     * @return type of bomb "Bomb"
     */

    virtual std::string getType() const override;

    /**
     * @brief Explode check if ready to explode
     * @param turn recent turn
     * @return boolean true if ready
     */

    bool Explode(int turn);

    /**
     * @brief setTimer sets timer for bomb
     * @param turn recent turn
     */
    void setTimer(int turn);

private:

    int explosionTurn_;

}; //class Bomb

} //namespace
#endif // BOMB_HH
