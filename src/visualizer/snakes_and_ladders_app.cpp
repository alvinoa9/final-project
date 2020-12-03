#include "../../include/visualizer/snakes_and_ladders_app.h"

namespace snakeladder{

namespace visualizer {

SnakesAndLaddersApp::SnakesAndLaddersApp()
{
    ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
    // Deserialize json file
    //ifstream file(kFilePath);
    //file >> board;
    GameEngine temp_game(4);
    game = temp_game;
    //game.LoadPlayer(player);
}

void SnakesAndLaddersApp::setup() {
    ci::gl::enableAlphaBlending();
    // Load board image
    ci::fs::path path = ci::fs::path(kImagePath);
    texture = ci::gl::Texture::create(ci::loadImage(path));

    // Load dice images
    ci::fs::path dice_path1 = ci::fs::path(kDice1);
    dice1 = ci::gl::Texture::create(ci::loadImage(dice_path1));
    ci::fs::path dice_path2 = ci::fs::path(kDice2);
    dice2 = ci::gl::Texture::create(ci::loadImage(dice_path2));
    ci::fs::path dice_path3 = ci::fs::path(kDice3);
    dice3 = ci::gl::Texture::create(ci::loadImage(dice_path3));
    ci::fs::path dice_path4 = ci::fs::path(kDice4);
    dice4 = ci::gl::Texture::create(ci::loadImage(dice_path4));
    ci::fs::path dice_path5 = ci::fs::path(kDice5);
    dice5 = ci::gl::Texture::create(ci::loadImage(dice_path5));
    ci::fs::path dice_path6 = ci::fs::path(kDice6);
    dice6 = ci::gl::Texture::create(ci::loadImage(dice_path6));

    // Load Player models
    ci::fs::path player1_path = ci::fs::path(kPlayer1);
    player1 = ci::gl::Texture::create(ci::loadImage(player1_path));
    ci::fs::path player2_path = ci::fs::path(kPlayer2);
    player2 = ci::gl::Texture::create(ci::loadImage(player2_path));
    ci::fs::path player3_path = ci::fs::path(kPlayer3);
    player3 = ci::gl::Texture::create(ci::loadImage(player3_path));
    ci::fs::path player4_path = ci::fs::path(kPlayer4);
    player4 = ci::gl::Texture::create(ci::loadImage(player4_path));

    // Insert json data to class
    /*vector<TileData> vector_temp;

    for (const auto& data : board["board"]) {
        TileData temp_tile(data["num"], data["tile"], data["move"]);
        vector_temp.push_back(temp_tile);
    }
    BoardData board_temp(vector_temp);
    board_data = board_temp;*/
}

void SnakesAndLaddersApp::draw() {
    // Draw Background
    ci::Color background_color("white");
    ci::gl::clear(background_color);

    // Draw board
    ci::gl::color(ci::Color("white"));
    ci::gl::draw(texture);
    //ci::gl::drawStringCentered(to_string(board.size()), glm::vec2(1, 1), ci::Color("black"));

    // Draw initial pieces
    if (!start) {
        for (size_t i = 0; i < player_list.size(); i++) {
            if (i == 0) {
                ci::gl::draw(player1, player_list[i].GetPosition());
            }
            else if (i == 1) {
                ci::gl::draw(player2, player_list[i].GetPosition());
            }
            else if (i == 2) {
                ci::gl::draw(player3, player_list[i].GetPosition());
            }
            else if (i == 3) {
                ci::gl::draw(player4, player_list[i].GetPosition());
            }
        }
    }

    // Draw dice
    ci::gl::color(ci::Color("white"));
    if (dice == 1) {
        ci::gl::draw(dice1, glm::vec2(700, 600));
    }
    else if (dice == 2) {
        ci::gl::draw(dice2, glm::vec2(700, 600));
    }
    else if (dice == 3) {
        ci::gl::draw(dice3, glm::vec2(700, 600));
    }
    else if (dice == 4) {
        ci::gl::draw(dice4, glm::vec2(700, 600));
    }
    else if (dice == 5) {
        ci::gl::draw(dice5, glm::vec2(700, 600));
    }
    else if (dice == 6) {
        ci::gl::draw(dice6, glm::vec2(700, 600));
    }
    string status;
    if (start) {
        ci::gl::drawStringCentered("You rolled " + to_string(dice) + "!", glm::vec2(750, 580), ci::Color("black"), kUiFont);
        //status = game.run(dice);
    }
    ci::Rectf dice_outline(glm::vec2(700, 600), glm::vec2(800, 700));
    ci::gl::color(ci::Color("black"));
    ci::gl::drawStrokedRect(dice_outline);

    vector<Player> player_list = game.GetPlayerList();
    ci::gl::color(ci::Color("white"));
    for (size_t i = 0; i < player_list.size(); i++) {
        if (i == 0) {
            ci::gl::draw(player1, player_list[i].GetPosition());
        }
        else if (i == 1) {
            ci::gl::draw(player2, player_list[i].GetPosition());
        }
        else if (i == 2) {
            ci::gl::draw(player3, player_list[i].GetPosition());
        }
        else if (i == 3) {
            ci::gl::draw(player4, player_list[i].GetPosition());
        }
    }
}

int SnakesAndLaddersApp::RollDice() {
    //Generate number between 1 and 6
    int roll = rand() % 6 + 1;
    return roll;
}

void SnakesAndLaddersApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
        // Roll dice
        case ci::app::KeyEvent::KEY_r:
            start = true;
            dice = RollDice();
            break;

        case ci::app::KeyEvent::KEY_DOWN:
            break;
    }
}

}  // namespace visualizer

}  // namespace snakeladder