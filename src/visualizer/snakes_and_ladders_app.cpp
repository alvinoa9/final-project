#include "../../include/visualizer/snakes_and_ladders_app.h"

namespace snakeladder{

namespace visualizer {

SnakesAndLaddersApp::SnakesAndLaddersApp()
{
    ci::app::setWindowSize((int) kWindowWidth, (int) kWindowHeight);
    // Deserialize json file
    ifstream file(kFilePath);
    file >> board;
}

void SnakesAndLaddersApp::setup() {
    ci::fs::path path = ci::fs::path(kImagePath);
    texture = ci::gl::Texture::create(ci::loadImage(path));

    // Insert json data to class
    vector<TileData> vector_temp;

    for (const auto& data : board["board"]) {
        TileData temp_tile(data["num"], data["tile"], data["move"]);
        vector_temp.push_back(temp_tile);
    }
    BoardData board_temp(vector_temp);
    board_data = board_temp;

    // Initialize players

    for (int i = 1; i < 5; i++) {

    }
}

void SnakesAndLaddersApp::draw() {
    ci::Color background_color("white");
    ci::gl::clear(background_color);
    ci::gl::draw(texture);
    ci::gl::drawStringCentered(to_string(board.size()), glm::vec2(1, 1), ci::Color("black"));
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