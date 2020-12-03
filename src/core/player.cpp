#include "../../include/core/player.h"

namespace snakeladder {

Player::Player() {
    player_num = 0;
    tile = 1;
    position = glm::vec2(0, 0);
}

Player::Player(int num) {
    player_num = num;
    tile = 1;
    if (num == 1) {
        position = glm::vec2(35, 70);
    }
    else if (num == 2) {
        position = glm::vec2(35, 35);
    }
    else if (num == 3) {
        position = glm::vec2(0, 70);
    }
    else if (num == 4) {
        position = glm::vec2(0, 0);
    }
}

int Player::GetPlayerNum() {
    return player_num;
}

int Player::GetTile() {
    return tile;
}

glm::vec2 Player::GetPosition() {
    return position;
}

void Player::SetTile(int new_tile) {
    tile = new_tile;
}

void Player::SetPosition(glm::vec2 new_position) {
    position = new_position;
}

}   // namespace snakeladder