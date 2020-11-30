#include "../../include/core/tile_data.h"

namespace snakeladder {

TileData::TileData() {
    num = 0;
    tile = "";
    move = 0;
}

TileData::TileData(int num, std::string tile, int move) {
    this->num = num;
    this->tile = tile;
    this->move = move;
}

int TileData::GetNum() {
    return num;
}

std::string TileData::GetTile() {
    return tile;
}

int TileData::GetMove() {
    return move;
}

}   // namespace snakeladder