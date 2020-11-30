#include "../../include/core/board_data.h"

namespace snakeladder {

BoardData::BoardData() {
    /*for (int i = 0; i < 100; i++) {
        TileData tile_temp;
        board_data.push_back(tile_temp);
    }*/
}

BoardData::BoardData(vector<TileData> TileData) {
    board_data = TileData;
}

vector<TileData> BoardData::GetTileData() {
    return board_data;
}
}   // namespace snakeladder