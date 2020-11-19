#include <visualizer/snakes_and_ladders_app.h>

using snakeladder::visualizer::SnakesAndLaddersApp;

void prepareSettings(SnakesAndLaddersApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(SnakesAndLaddersApp, ci::app::RendererGl, prepareSettings);
