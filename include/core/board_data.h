#ifndef FINAL_PROJECT_BOARD_DATA_H
#define FINAL_PROJECT_BOARD_DATA_H

#include <vector>
#include "../../include/core/tile_data.h"
using namespace std;

namespace snakeladder {

/**
 * This class contains the board information
 */
class BoardData {
public:
    /**
     * Default constructor
     */
    BoardData();

    /**
     * Construct class with given vector
     * @param TileData
     */
    BoardData(vector<TileData> TileData);

    /**
     * Getter for tile vector
     * @return board_data
     */
    vector<TileData> GetTileData();

private:
    vector<TileData> board_data;
};
}   // namespace snakeladder

#endif //FINAL_PROJECT_BOARD_DATA_H