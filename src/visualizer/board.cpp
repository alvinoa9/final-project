#include "../../include/visualizer/board.h"

namespace snakeladder {

namespace visualizer {

Board::Board(double height, double width)
    : kWindowHeight(height),
      kWindowWidth(width) {}

void Board::Draw() const {
    if (state == 0) {
        DrawMainMenu();
    }
    else if (state == 1) {
        DrawPlayerPick();
    }
    else if (state == 2) {
        DrawLoadMenu();
    }
}

void Board::DrawMainMenu() const {
    ci::gl::drawStringCentered("New Game", glm::vec2(400, 200), ci::Color("black"), kUiFont);
    ci::gl::drawStringCentered("Load Game", glm::vec2(400, 400), ci::Color("black"), kUiFont);
    ci::Rectf outline1(glm::vec2(285, 180), glm::vec2(515, 250));
    ci::gl::color(ci::Color("black"));
    ci::gl::drawStrokedRect(outline1);
    ci::Rectf outline2(glm::vec2(285, 380), glm::vec2(515, 450));
    ci::gl::color(ci::Color("black"));
    ci::gl::drawStrokedRect(outline2);
}

void Board::DrawPlayerPick() const {

}

void Board::DrawLoadMenu() const{

}


void Board::Click(const glm::vec2 &mouse_coords) {
    if (state == 0) {
        if (mouse_coords.x >= 285 && mouse_coords.x <= 515 && mouse_coords.y >= 180 && mouse_coords.y <= 250) {
            state = 1;
        }
        else if (mouse_coords.x >= 285 && mouse_coords.x <= 515 && mouse_coords.y >= 285 && mouse_coords.y <= 450) {
            state = 2;
        }
    }
    else if (state = 1) {

    }
    else if (state = 2) {

    }
}

int Board::GetState() {
    return state;
}

}   // namespace snakeladder

}   // namespace visualizer