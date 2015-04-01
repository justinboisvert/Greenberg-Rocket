#include "Menu.h"

Menu::Menu(){
    title_transition = true;
    play_transition = false;
    title = new sf::Sprite();
    play = new sf::Sprite();
    play_texture.loadFromFile(resourcePath()+"play_spec.png");
    play->setTexture(play_texture);
    play->setPosition(300.f - play->getTextureRect().width/2.f,345.f);
    //set play to alpha 0
    sf::Color c = play->getColor();
    play->setColor(sf::Color(c.r,c.g,c.b,0));
    title_texture.loadFromFile(resourcePath()+"title_spec.png");
    title->setTexture(title_texture);
    title->setPosition(0,600.f / 4.f);
    title_tween = new SpriteTween(&CDBTweener::TWEQ_EXPONENTIAL,CDBTweener::TWEA_INOUT,title,1.f);
    play_tween = new SpriteTween(&CDBTweener::TWEQ_QUADRATIC,CDBTweener::TWEA_INOUT,play,2.f);
    title_tween->addPos((float)-title->getTextureRect().width, (850.f / 2.f) - title->getTextureRect().width/2.f, X_AXIS);
   // title_tween->addAlpha(0.f,255.f);
    play_tween->addAlpha(0.f,255.f);
 
}

void Menu::update(float time){
    clear(sf::Color(255,255,255));
    if(title_transition){
        title_tween->step(1.f / 60.f);
        if(title_tween->isFinished()){
            title_transition = false;
            play_transition = true;
        }
    }
    if(play_transition){
        play_tween->step(1.f / 60.f);
        if(play_tween->isFinished()){
            Scenes::setScene("game");
        }
    }
   
    draw(*title);
    
}

