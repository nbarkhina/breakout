#include "PADDLE.H"
#include "CONF.H"
#include "RENDERER.H"

#define PADDLE_SPEED 2.0
#define PADDLE_WIDTH 30
#define PADDLE_HEIGHT 5

Paddle::Paddle(float x, float y, char color) {
    pos.x = x;
    pos.y = y;
    width = PADDLE_WIDTH;
    height = PADDLE_HEIGHT;
    velocity.x = PADDLE_SPEED;
    _color = color;
}

void Paddle::move(int direction) {
    if (direction == LEFT) {
        if (pos.x > 0) {
            pos.x -= velocity.x;
        }
    } else if (direction == RIGHT) {
        if (pos.x < SCREEN_WIDTH - width) {
                pos.x += velocity.x;
        }
    }
}

void Paddle::draw(Renderer* renderer) {
    renderer->rectangle(pos.x, pos.y, width, height, _color);
}