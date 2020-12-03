#ifndef FINAL_PROJECT_GAME_ENGINE_H
#define FINAL_PROJECT_GAME_ENGINE_H

#include "../../include/core/board_data.h"
#include "../../include/core/tile_data.h"
#include "../../include/core/player.h"
#include <algorithm>
#include <math.h>
#include <string>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

namespace snakeladder {

class GameEngine {
public:
    /**
     * Default constructor
     */
    GameEngine();

    /**
     * Constructor with parameter number of players
     * @param num_players number of players
     */
    GameEngine(int num_players);

    /**
     * Runs the game
     * @param dice moves of player
     * @return string of player's move
     */
    string run(int dice);

private:
    /**
     * Deserialize json file
     */
    void JSONDeserialize();
    int total_player;
    vector<TileData> tile_data;
    vector<Player> player_list;
    int curr_player = 1;
    BoardData board_data;
    string kFilePath = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\BoardInfo.json";
    json board;
};
}   // namespace snakeladder

#endif //FINAL_PROJECT_GAME_ENGINE_H
