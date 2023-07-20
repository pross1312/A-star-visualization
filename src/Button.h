#pragma once
#include "vec2.h"
#include <string>
#include <SDL2/SDL_ttf.h>
#include <functional>
#define BUTTON_NORMAL_COLOR 0x333333ff
#define BUTTON_ON_HOVER_COLOR 0x777777ff
#define BUTTON_TEXT_COLOR 0xffffffff
#define BUTTON_CLICKED_COLOR 0x999999ff
#define BUTTON_PADDING 10

class Button {
public:
    Button(const char* msg, TTF_Font* font, SDL_Renderer* renderer, int x, int y, std::function<void()> onClickedEvent);
    bool isInBound(Vec2i position);
    void draw(SDL_Renderer* renderer);
    void update(SDL_Event& event, Vec2i mousePos);
private:
    std::string text;
    uint32_t currentColor;
    std::function<void()> onClickedEvent;
    SDL_Rect bound;
    SDL_Texture* texture;
};
