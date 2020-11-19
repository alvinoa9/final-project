#pragma once
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
//#include "cinder/ImageIo.h"
//#include "cinder/gl/Texture.h"
#include "gameplay.h"
#include <core/game_engine.h>
#include <algorithm>
#include <math.h>
#include <string>

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
    //void keyDown(ci::app::KeyEvent event) override;

    const size_t kWindowSize = 700;
    const size_t kWindowWidth = 700;
    const size_t kWindowHeight = 700;
    const size_t kMargin = 50;
    const ci::Font kUiFont = ci::Font("Arial", 22);
    const int kHistogramInterval = 20;
private:
    std::string kFilePath = "C:\\Users\\alvin\\CLionProjects\\~Cinder\\my-projects\\final-project\\data\\snlboard2.png";
    ci::gl::Texture2dRef texture;
};

}  // namespace visualizer

}  // namespace snakeladder
