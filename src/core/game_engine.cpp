#include "../../include/core/game_engine.h"

namespace snakeladder {

GameEngine::GameEngine() {
    JSONDeserialize();
}

GameEngine::GameEngine(int num_players) {
    JSONDeserialize();
    total_player = num_players;
    for (int i = 0; i < num_players; i++) {
        Player player_temp(i + 1);
        player_list.push_back(player_temp);
    }
}

void GameEngine::JSONDeserialize() {
    // Deserialize json file
    ifstream file(kFilePath);
    file >> board;

    // Insert json data to class
    vector<TileData> vector_temp;

    for (const auto& data : board["board"]) {
        TileData temp_tile(data["num"], data["tile"], data["move"]);
        vector_temp.push_back(temp_tile);
    }
    tile_data = vector_temp;
    BoardData board_temp(vector_temp);
    board_data = board_temp;
}

string GameEngine::run(int dice) {
    Player current = player_list[curr_player];
    glm::vec2 position = current.GetPosition();
    int tile = current.GetTile();
    int move = tile + dice;
    TileData tile_landed = tile_data[dice + tile - 1];
    string tile_type = tile_landed.GetTile();
    string status = "";
    // If tile landed is a snake
    if (tile_type == "snake") {
        move = tile_landed.GetMove();
        status = "Player " + to_string(curr_player) + " have landed on a snake, move to tile " + to_string(move) + "!";
        for (int i = tile; i >= move; i--) {
            if (i % 10 == 0) {
                position -= glm::vec2(0, 70);
            } else if (i % 20 > 10){
                position += glm::vec2(70, 0);
            } else {
                position -= glm::vec2(70, 0);
            }
        }
    }
    else {
        // If tile landed is ladder
        if (tile_type == "ladder") {
            move = tile_landed.GetMove();
            status = "Player " + to_string(curr_player) + " have landed on a ladder, move to tile " + to_string(move) + "!";
        } else {
            status = "Player " + to_string(curr_player) + " have landed on tile " + to_string(move) + "!";
        }
        for (int i = tile; i <= move; i++) {
            if (i % 10 == 0) {
                position += glm::vec2(0, 70);
            } else if (i % 20 > 10){
                position -= glm::vec2(70, 0);
            } else {
                position += glm::vec2(70, 0);
            }
        }
    }

    current.SetPosition(position);
    current.SetTile(dice + tile);
    player_list[curr_player] = current;
    curr_player++;
    if (curr_player >= total_player + 1) {
        curr_player = 1;
    }
    return status;
}

}   // namespace snakeladder