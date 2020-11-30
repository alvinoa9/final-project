#ifndef FINAL_PROJECT_GAME_ENGINE_H
#define FINAL_PROJECT_GAME_ENGINE_H

#include "../../include/core/board_data.h"
#include "../../include/core/tile_data.h"
#include "../../include/core/player.h"

namespace snakeladder {

class GameEngine {
public:
    GameEngine();
    GameEngine(int num_players, BoardData board_data);

private:
    BoardData board_data;
    vector<Player>
};
}   // namespace snakeladder

#endif //FINAL_PROJECT_GAME_ENGINE_H
