#ifndef ROCKET_H
#define ROCKET_H
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "ResourcePath.hpp"
#define _USE_MATH_DEFINES
class Rocket : public sf::Sprite {
public:
    Rocket(sf::Texture& tex);
    void update();
    float thrustVelocity();
    void pollEvent(sf::Event& event);
    void reset();
    void start();
    void setRotationAngle(float a);
    bool hasStarted();
    void setExhaustspeed(float v);
    bool hasGas();
private:
    sf::Texture r_t;
    float angle_rotation;
    float oil_mass, oil_current;
    float oil_speed;
    float derivOil;
    float vel_res;
    float acceleration;
    bool freefall;
    sf::Vector2f velocity;
    sf::Clock falltime;
    bool start_;
    
};
#endif