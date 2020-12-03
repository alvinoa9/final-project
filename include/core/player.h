#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H
#include "cinder/gl/gl.h"
namespace snakeladder {

/**
 * This class contains the information of a player
 */
class Player {
public:
    /**
     * Default class constructor
     */
    Player();

    /**
     * Constructor that sets a player's number
     * @param num player's number
     */
    Player(int num);

    /**
     * Getter of player's number
     * @return player_num player's number
     */
    int GetPlayerNum();

    /**
     * Getter of player's current tile
     * @return tile player's current tile
     */
    int GetTile();

    /**
     * Getter of player's current position
     * @return tile player's current position
     */
    glm::vec2 GetPosition();

    /**
     * Sets the player's tile
     * @param new_tile new tile
     */
    void SetTile(int new_tile);

    /**
     * Sets player's position
     * @param new_position new position
     */
    void SetPosition(glm::vec2 new_position);

private:
    int player_num;
    int tile;
    glm::vec2 position;
};
}   // namespace snakeladder

#endif //FINAL_PROJECT_PLAYER_H
