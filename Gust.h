#ifndef GUST_H
#define GUST_H
#include <SFML/Graphics.hpp>
#include <time.h>
class Gust : public sf::Sprite {
public:
    Gust(sf::Vector2f pos, sf::Texture & tex);
    void update();
    void setAlpha(int a);
private:
    int alph;
};
#endif