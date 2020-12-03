#include "../../include/core/game_engine.h"

namespace snakeladder {

GameEngine::GameEngine() {
    JSONDeserialize();
    total_player = 0;
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

    // Checks if move is out of board
    if (move > 100) {
        move = 100 - (move - 100);
    }

    TileData tile_landed = tile_data[move - 1];
    string tile_type = tile_landed.GetTile();
    string status;

    // If tile is snake
    if (tile_type == "snake") {
        move = tile_landed.GetMove();
        status = "Player " + to_string(curr_player + 1) + " have landed on a snake, move to tile " + to_string(move) + "!";
        position = MoveDown(tile, move, position);
    }
    // If tile is a ladder
    else if (tile_type == "ladder") {
        move = tile_landed.GetMove();
        status = "Player " + to_string(curr_player + 1) + " have landed on a ladder, move to tile " + to_string(move) + "!";
        position = MoveUp(tile, move, position);
    }
    // Move normally
    else {
        if (move > tile) {
            position = MoveUp(tile, move, position);
        }
        else {
            position = MoveDown(tile, move, position);
        }
        status = "Player " + to_string(curr_player + 1) + " have landed on tile " + to_string(move) + "!";

    }

    if (move == 100) {
        status = "Player " + to_string(curr_player + 1) + " reached tile 100 and WON!";
    }

    current.SetTile(move);
    current.SetPosition(position);
    player_list[curr_player] = current;
    curr_player = (curr_player + 1) % total_player;
    return status;
}

vector<Player> GameEngine::GetPlayerList() {
    return player_list;
}

glm::vec2 GameEngine::MoveDown(int tile, int move, glm::vec2 position) {
    for (int i = tile - 1; i >= move; --i) {
        if (i % 10 == 0) {
            position += glm::vec2(0, 70);
        } else if (i % 20 > 10){
            position += glm::vec2(70, 0);
        } else {
            position -= glm::vec2(70, 0);
        }
    }
    return position;
}

glm::vec2 GameEngine::MoveUp(int tile, int move, glm::vec2 position) {
    for (int i = tile; i < move; i++) {
        if (i % 10 == 0) {
            position -= glm::vec2(0, 70);
        } else if (i % 20 > 10){
            position -= glm::vec2(70, 0);
        } else {
            position += glm::vec2(70, 0);
        }
    }
    return position;
}

}   // namespace snakeladder