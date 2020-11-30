#ifndef FINAL_PROJECT_PLAYER_H
#define FINAL_PROJECT_PLAYER_H

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
     * @return player_num
     */
    int GetPlayerNum();

    /**
     * Getter of player's current tile
     * @return tile
     */
    int GetTile();

    /**
     * Sets the player's tile
     * @param new_tile new tile
     */
    void SetTile(int new_tile);

private:
    int player_num;
    int tile;

};
}   // namespace snakeladder

#endif //FINAL_PROJECT_PLAYER_H
