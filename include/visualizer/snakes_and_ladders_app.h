#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "board.h"
#include <core/game_engine.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <random>
#include "../../include/core/tile_data.h"
#include "../../include/core/board_data.h"
#include "../../include/visualizer/board.h"

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
    void mouseDown(ci::app::MouseEvent event) override;

    const size_t kWindowSize = 700;
    const double kWindowWidth = 800;
    const double kWindowHeight = 700;
    const size_t kMargin = 50;
    const ci::Font kUiFont = ci::Font("Arial", 22);

private:
    /**
     * Random number generator from 1 to 6
     * @return roll number
     */
    static int RollDice();

    /**
     * Resets game
     */
    void reset();

    /**
     * Draws dice
     * @param dice number rolled
     */
    void DrawDice(int dice);

    /**
     * Draws players
     * @param players
     */
    void DrawGamePiece(vector<Player> players);

    Board board_;
    int state = 0;
    GameEngine game;
    string status = "";
    string kImagePath = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\snlboard2.png";
    string kFilePath = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\BoardInfo.json";
    ci::gl::Texture2dRef texture;
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
    string kPlayer1 = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\player1.png";
    string kPlayer2 = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\player2.png";
    string kPlayer3 = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\player3.png";
    string kPlayer4 = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\player4.png";
    ci::gl::Texture2dRef player1;
    ci::gl::Texture2dRef player2;
    ci::gl::Texture2dRef player3;
    ci::gl::Texture2dRef player4;
};

}  // namespace visualizer

}  // namespace snakeladder
