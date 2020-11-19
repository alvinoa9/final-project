#include "../../include/visualizer/snakes_and_ladders_app.h"

namespace snakeladder{

namespace visualizer {

SnakesAndLaddersApp::SnakesAndLaddersApp()
{
    ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);

}

void SnakesAndLaddersApp::setup() {
    ci::fs::path path = ci::fs::path(kFilePath);
    texture = ci::gl::Texture::create(ci::loadImage(path));
}

void SnakesAndLaddersApp::draw() {
    ci::Color background_color("white");
    ci::gl::clear(background_color);
    ci::gl::draw(texture);
}


/*void IdealGasApp::keyDown(ci::app::KeyEvent event) {
switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_UP:
        scale *= 0.5;
        break;

    case ci::app::KeyEvent::KEY_DOWN:
        break;
}
}*/


}  // namespace visualizer

}  // namespace snakeladder