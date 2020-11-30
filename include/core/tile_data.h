#ifndef FINAL_PROJECT_TILE_DATA_H
#define FINAL_PROJECT_TILE_DATA_H

#include <string>

namespace snakeladder {

/**
 * This class contains the information of a tile
 */
class TileData {
public:
    /**
     * Default constructor
     */
    TileData();

    /**
     * Class constructor with given number, tile type and move
     * @param num tile number
     * @param tile tile type
     * @param move move tile
     */
    TileData(int num, std::string tile, int move);

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
}   // namespace snakeladder

#endif //FINAL_PROJECT_TILE_DATA_H
