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
    ci::gl::drawStringCentered("Snakes and Ladders", glm::vec2(400, 70), ci::Color("black"), kTitleFont);
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
    ci::gl::color(ci::Color8u(215, 10, 111));
    ci::gl::drawSolidCircle(kCircle1, (float) kRadius);
    ci::gl::color(ci::Color8u(11, 190, 214));
    ci::gl::drawSolidCircle(kCircle2, (float) kRadius);
    ci::gl::color(ci::Color8u(150, 217, 11));
    ci::gl::drawSolidCircle(kCircle3, (float) kRadius);
    ci::gl::color(ci::Color8u(243, 239, 10));
    ci::gl::drawSolidCircle(kCircle4, (float) kRadius);

    ci::gl::drawStringCentered("Start Game", glm::vec2(400, 170), ci::Color("black"), ci::Font("Arial", 60));
    ci::gl::drawStringCentered("1p", glm::vec2(100, 300), ci::Color("black"), kChoiceFont);
    ci::gl::drawStringCentered("2p", glm::vec2(300, 300), ci::Color("black"), kChoiceFont);
    ci::gl::drawStringCentered("3p", glm::vec2(500, 300), ci::Color("black"), kChoiceFont);
    ci::gl::drawStringCentered("4p", glm::vec2(700, 300), ci::Color("black"), kChoiceFont);
}

void Board::DrawLoadMenu() {
    glm::vec2 box_top_left(250, 75);
    glm::vec2 box_bottom_right(550, 175);
    glm::vec2 spacing(0, 150);
    ci::Rectf outline(box_top_left, box_bottom_right);
    for (int i = 0; i < 4; i++) {
        ci::gl::color(ci::Color("grey"));
        ci::gl::drawSolidRect(outline);
        ci::gl::color(ci::Color("black"));
        ci::gl::drawStrokedRect(outline);
        box_top_left += spacing;
        box_bottom_right += spacing;
        outline = ci::Rectf(box_top_left, box_bottom_right);
    }
}


int Board::Click(const glm::vec2 &mouse_coords) {
    if (state == 0) {
        if (mouse_coords.x >= 285 && mouse_coords.x <= 515 && mouse_coords.y >= 180 && mouse_coords.y <= 250) {
            state = 1;
        }
        else if (mouse_coords.x >= 285 && mouse_coords.x <= 515 && mouse_coords.y >= 380 && mouse_coords.y <= 450) {
            state = 2;
        }
        return 0;
    }
    else if (state == 1) {
        if (glm::distance(mouse_coords, kCircle1) <= kRadius) {
            state = 3;
            return 1;
        }
        else if (glm::distance(mouse_coords, kCircle2) <= kRadius) {
            state = 3;
            return 2;
        }
        else if (glm::distance(mouse_coords, kCircle3) <= kRadius) {
            state = 3;
            return 3;
        }
        else if (glm::distance(mouse_coords, kCircle4) <= kRadius) {
            state = 3;
            return 4;
        }
        return 0;
    }
    return 0;
}

int Board::GetState() const {
    return state;
}

void Board::SetState(int new_state) {
    state = new_state;
}

}   // namespace snakeladder

}   // namespace visualizer