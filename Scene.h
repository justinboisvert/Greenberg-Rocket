#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics.hpp>
#include "SpriteTween.h"
#include <vector>
#include "ResourcePath.hpp"
class Scene : public sf::RenderTexture {
public:
    Scene();
    virtual void update(float time) {};
    virtual void pollEvent(sf::Event& event) {};
    sf::Vector2<int> mouseCoords;
};

#endif