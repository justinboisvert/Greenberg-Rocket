#ifndef MENU_H
#define MENU_H
#include "Scenes.h"
#include "Scene.h"
#include "ResourcePath.hpp"
#include <iostream>
#include <math.h>
#include "SpriteTween.h"
class Menu : public Scene {
public:
    Menu();
    void update(float time);
private:
    sf::Sprite* title;
    sf::Sprite* play;
    sf::Texture title_texture;
    sf::Texture play_texture;
    SpriteTween* title_tween;
    SpriteTween* play_tween;
    bool title_transition;
    bool play_transition;
};
#endif