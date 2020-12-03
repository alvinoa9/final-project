#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "gameplay.h"
#include <core/game_engine.h>
#include <algorithm>
#include <math.h>
#include <string>
#include "json.hpp"
#include <iostream>
#include <stdlib.h>
#include "../../include/core/tile_data.h"
#include "../../include/core/board_data.h"

using json = nlohmann::json;
using namespace std;

namespace snakeladder {

namespace visualizer {

/**
* Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
* classify it.
*/
class SnakesAndLaddersApp : public ci::app::App {
public:
    SnakesAndLaddersApp();

    void draw() override;
    void setup() override;
    void keyDown(ci::app::KeyEvent event) override;

    const size_t kWindowSize = 700;
    const size_t kWindowWidth = 800;
    const size_t kWindowHeight = 700;
    const size_t kMargin = 50;
    const ci::Font kUiFont = ci::Font("Arial", 22);

private:
    int RollDice();

    GameEngine game;
    string kImagePath = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\snlboard2.png";
    string kFilePath = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\BoardInfo.json";
    ci::gl::Texture2dRef texture;
    json board;
    BoardData board_data;
    bool start = false;
    int player = 1;
    int dice = 1;
    string kDice1 = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\dice1.jpg";
    string kDice2 = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\dice2.jpg";
    string kDice3 = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\dice3.jpg";
    string kDice4 = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\dice4.jpg";
    string kDice5 = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\dice5.jpg";
    string kDice6 = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\dice6.jpg";
    ci::gl::Texture2dRef dice1;
    ci::gl::Texture2dRef dice2;
    ci::gl::Texture2dRef dice3;
    ci::gl::Texture2dRef dice4;
    ci::gl::Texture2dRef dice5;
    ci::gl::Texture2dRef dice6;
};

}  // namespace visualizer

}  // namespace snakeladder
