#include "../../include/core/player.h"

namespace snakeladder {

Player::Player() {
    player_num = 0;
    tile = 1;
}

Player::Player(int num) {
    player_num = num;
    tile = 1;
}

int Player::GetPlayerNum() {
    return player_num;
}

int Player::GetTile() {
    return tile;
}

void Player::SetTile(int new_tile) {
    tile = new_tile;
}

}   // namespace snakeladder