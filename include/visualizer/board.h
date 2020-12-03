#ifndef FINAL_PROJECT_BOARD_H
#define FINAL_PROJECT_BOARD_H

#include "cinder/gl/gl.h"

using namespace std;

namespace snakeladder {

namespace visualizer {

/**
 * Windows instances: main menu, pick players, load menu, game
 * will be displayed using cinders
 */
class Board {
public :
    /**
     * Creates the window board
     * @param height height of window
     * @param width width of window
     */
    Board(double height, double width);

    /**
     * Displays current state
     */
    void Draw() const;

    /**
     * Make certain parts of window clickable depending on screen instance
     * @param mouse_coords the screen coordinates of mouse
     */
    void Click(const glm::vec2& mouse_coords);

    /**
     * Getter for screen's state
     * @return state of screen
     */
    int GetState();

private:
    /**
     * Draws main menu on screen
     */
    void DrawMainMenu() const;

    /**
     * Draw player choices
     */
    void DrawPlayerPick() const;

    /**
     * Draws load menu on screen
     */
    void DrawLoadMenu() const;

    double kWindowWidth;
    double kWindowHeight;

    /**
     * State = 0 -> Main Menu
     * State = 1 -> Pick Players
     * State = 2 -> Load Menu
     * State = 3 -> Game
     */
    int state = 0;
    const ci::Font kUiFont = ci::Font("Arial", 40);
};

}   // namespace snakeladder

}   // namespace visualizer

#endif //FINAL_PROJECT_BOARD_H
