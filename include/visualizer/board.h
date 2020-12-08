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
     * @return number of players
     */
    int Click(const glm::vec2& mouse_coords);

    /**
     * Getter for screen's state
     * @return state of screen
     */
    int GetState() const;

    /**
     * Set screen's state
     */
    void SetState(int new_state);

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
    static void DrawLoadMenu() ;

private:
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
    const ci::Font kChoiceFont = ci::Font("Arial", 50);
    const ci::Font kTitleFont = ci::Font("Arial", 60);
    const int kRadius = 75;
    glm::vec2 kCircle1 = glm::vec2(100, 320);
    glm::vec2 kCircle2 = glm::vec2(300, 320);
    glm::vec2 kCircle3 = glm::vec2(500, 320);
    glm::vec2 kCircle4 = glm::vec2(700, 320);
};

}   // namespace snakeladder

}   // namespace visualizer

#endif //FINAL_PROJECT_BOARD_H
