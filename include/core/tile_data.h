#ifndef FINAL_PROJECT_TILE_DATA_H
#define FINAL_PROJECT_TILE_DATA_H

#include <string>

/**
 * This class contains the information of a tile
 */
class tile_data {
public:
    /**
     * Get the tile number
     * @return number
     */
    int GetNum();

    /**
     * Get the tile status
     * @return status of tile
     */
    std::string GetTile();

    /**
     * Get the movement of tile
     * @return movement of tile
     */
    int GetMove();

private:
    int num;
    std::string tile;
    int move;
};


#endif //FINAL_PROJECT_TILE_DATA_H
