#include "../../include/core/board_data.h"

namespace snakeladder {

BoardData::BoardData() {}

BoardData::BoardData(vector<TileData> TileData) {
    board_data = TileData;
}

vector<TileData> BoardData::GetTileData() {
    return board_data;
}
}