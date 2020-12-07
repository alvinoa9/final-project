#include "../../include/visualizer/snakes_and_ladders_app.h"

namespace snakeladder{

namespace visualizer {

SnakesAndLaddersApp::SnakesAndLaddersApp()
    : board_(kWindowWidth, kWindowHeight)
{
    ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
    GameEngine temp_game(player);
    game = temp_game;
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
}

void SnakesAndLaddersApp::draw() {
    // Draw Background
    ci::Color background_color("white");
    ci::gl::clear(background_color);

    // Draw Main Menu and Save button
    if (state != 0) {
        DrawButton();
    }

    if (state < 3) {
        board_.Draw();
        if (state == 2) {
            DrawInstances();
        }
    }
    else {
        // Draw board
        ci::gl::color(ci::Color("white"));
        ci::gl::draw(texture);

        // Draw dice
        DrawDice(dice);

        // Draw Players
        DrawGamePiece(game.GetPlayerList());
    }

    state = board_.GetState();
}

int SnakesAndLaddersApp::RollDice() {
    random_device generator;
    uniform_int_distribution<int> distribution(1,6);
    int roll = distribution(generator);
    return roll;
}

void SnakesAndLaddersApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
        // Reset game
        case ci::app::KeyEvent::KEY_r:
            reset();
            break;
    }
}

void SnakesAndLaddersApp::mouseDown(ci::app::MouseEvent event) {
    if (player == 0) {
        player = board_.Click(event.getPos());
        if (player > 0) {
            game_instance++;
            game.LoadPlayer(player);
        }
    }
    // Roll dice
    if (event.getPos().x >= 700 && event.getPos().y >= 600 && state == 3) {
        start = true;
        dice = RollDice();
        status = game.run(dice);
    }
    // Main menu
    if (event.getPos().x >= 700 && event.getPos().x <= 800 &&
        event.getPos().y >= 0 && event.getPos().y < 40 && state != 0) {
        state = 0;
        player = 0;
        reset();
        ingame_status = false;
        board_.SetState(state);
    }
    // Save Game
    if (event.getPos().x >= 700 && event.getPos().x <= 800 &&
        event.getPos().y >= 40 && event.getPos().y < 80 && state == 3) {
        if (instance.size() + 1 > 4 && !ingame_status) {
            overwrite = true;
            state = 2;
            board_.SetState(2);
        }
        else {
            SaveGame();
        }
    }
    // Load Game
    if (state == 2) {
        glm::vec2 box_top_left(250, 75);
        glm::vec2 box_bottom_right(550, 175);
        glm::vec2 spacing(0, 150);
        int save = -1;

        for (size_t i = 0; i < 4; i++) {
            if (event.getPos().x >= box_top_left.x && event.getPos().x <= box_bottom_right.x &&
                event.getPos().y >= box_top_left.y && event.getPos().y <= box_bottom_right.y) {
                save = i;
            }
            box_top_left += spacing;
            box_bottom_right += spacing;
        }
        if (save != -1) {
            game_instance = save;
            if (overwrite) {
                instance[save] = game;
                overwrite = false;
            }
            LoadGame(save);
        }
    }

}

void SnakesAndLaddersApp::reset() {
    GameEngine temp_game(player);
    game = temp_game;
}

void SnakesAndLaddersApp::DrawDice(int roll) {
    ci::gl::color(ci::Color("white"));
    if (roll == 1) {
        ci::gl::draw(dice1, glm::vec2(700, 600));
    }
    else if (roll == 2) {
        ci::gl::draw(dice2, glm::vec2(700, 600));
    }
    else if (roll == 3) {
        ci::gl::draw(dice3, glm::vec2(700, 600));
    }
    else if (roll == 4) {
        ci::gl::draw(dice4, glm::vec2(700, 600));
    }
    else if (roll == 5) {
        ci::gl::draw(dice5, glm::vec2(700, 600));
    }
    else if (roll == 6) {
        ci::gl::draw(dice6, glm::vec2(700, 600));
    }

    if (start) {
        ci::gl::drawStringCentered("You rolled " + to_string(dice) + "!", glm::vec2(750, 580), ci::Color("black"), kUiFont);
    }
    ci::Rectf dice_outline(glm::vec2(700, 600), glm::vec2(800, 700));
    ci::gl::color(ci::Color("black"));
    ci::gl::drawStrokedRect(dice_outline);
}

void SnakesAndLaddersApp::DrawGamePiece(vector<Player> player_list) {
    ci::gl::color(ci::Color("white"));
    for (size_t i = 0; i < player_list.size(); i++) {
        if (i == 0) {
            ci::gl::draw(player1, player_list[0].GetPosition());
        }
        else if (i == 1) {
            ci::gl::draw(player2, player_list[1].GetPosition());
        }
        else if (i == 2) {
            ci::gl::draw(player3, player_list[2].GetPosition());
        }
        else if (i == 3) {
            ci::gl::draw(player4, player_list[3].GetPosition());
        }
    }
}

void SnakesAndLaddersApp::DrawButton() {
    glm::vec2 box_top_left(700, 0);
    glm::vec2 box_bottom_right(800, 40);
    glm::vec2 spacing(0, 40);
    ci::Rectf outline(box_top_left, box_bottom_right);
    ci::gl::color(ci::Color("black"));
    ci::gl::drawStrokedRect(outline, 2);
    ci::gl::drawStringCentered("Main Menu", glm::vec2(750, 15), ci::Color("black"), kUiFont);

    if (state == 3) {
        box_top_left += spacing;
        box_bottom_right += spacing;
        outline = ci::Rectf(box_top_left, box_bottom_right);
        ci::gl::color(ci::Color("black"));
        ci::gl::drawStrokedRect(outline, 2);
        ci::gl::drawStringCentered("Save Game", glm::vec2(750, 55), ci::Color("black"), kUiFont);
    }
}

void SnakesAndLaddersApp::SaveGame() {
    if (ingame_status) {
        instance[game_instance] = game;
    }
    else {
        instance.push_back(game);
        ingame_status = true;
    }
}

void SnakesAndLaddersApp::LoadGame(int save) {
    ingame_status = true;
    game = instance[save];
    state = 3;
    board_.SetState(3);
}

void SnakesAndLaddersApp::DrawInstances() {
    glm::vec2 position(400, 105);
    for (size_t i = 0; i < instance.size(); i++) {
        ci::gl::drawStringCentered("Save " + to_string(i + 1), position, ci::Color("White"), kLoadFont);
        position += glm::vec2(0, 150);
    }
}

}  // namespace visualizer

}  // namespace snakeladder