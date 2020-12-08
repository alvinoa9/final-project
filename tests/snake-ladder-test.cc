#include "include/core/game_engine.h"
#include "include/core/board_data.h"
#include "include/core/tile_data.h"
#include "include/core/player.h"

#include <catch2/catch.hpp>

using namespace snakeladder;

TEST_CASE("Test Game Engine") {
    GameEngine game(2);
    vector<Player> player_list = game.GetPlayerList();
    vector<TileData> tile_data = game.GetTileData();

    SECTION("JSON Deserializer") {
        REQUIRE(tile_data.size() == 100);

        TileData test_tile = tile_data[3];
        REQUIRE(test_tile.GetNum() == 4);
        REQUIRE(test_tile.GetTile() == "ladder");
        REQUIRE(test_tile.GetMove() == 56);
    }

    SECTION("Game Engine construction") {
        REQUIRE(player_list.size() == 2);
    }

    SECTION("Initial player construction") {
        Player player1 = player_list[0];
        Player player2 = player_list[1];

        REQUIRE(player1.GetTile() == 1);
        REQUIRE(player1.GetPlayerNum() == 1);
        REQUIRE(player1.GetPosition() == glm::vec2(37, 601));

        REQUIRE(player2.GetTile() == 1);
        REQUIRE(player2.GetPlayerNum() == 2);
        REQUIRE(player2.GetPosition() == glm::vec2(37, 636));
    }

    SECTION("Test movement") {
        game.run(3);
        game.run(2);

        player_list = game.GetPlayerList();
        Player player1 = player_list[0];
        Player player2 = player_list[1];

        REQUIRE(player1.GetTile() == 56);
        REQUIRE(player1.GetPlayerNum() == 1);
        REQUIRE(player1.GetPosition() == glm::vec2(317, 251));

        REQUIRE(player2.GetTile() == 3);
        REQUIRE(player2.GetPlayerNum() == 2);
        REQUIRE(player2.GetPosition() == glm::vec2(177, 636));
    }
}