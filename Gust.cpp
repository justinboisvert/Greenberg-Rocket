#include "Gust.h"

Gust::Gust(sf::Vector2f pos, sf::Texture& tex){
    srand(time(NULL));
    sf::Vector2f scale;
    scale.x = (rand() % 2) + 1;
    scale.y = (rand() % 2) + 1;
    setScale(scale);
    setTexture(tex);
    setPosition(pos);
    setOrigin(getTexture()->getSize().x / 2.f, getTexture()->getSize().y / 2.f);
    alph = 255;
    
}

void Gust::update(){
    alph -= 10;
    if(alph < 0){
        alph = 0;
    }
    setAlpha(alph);
}

void Gust::setAlpha(int a){
    sf::Color c = getColor();
    setColor(sf::Color(c.r,c.g,c.b,a));
}