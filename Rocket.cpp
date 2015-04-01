#include "Rocket.h"

Rocket::Rocket(sf::Texture& tex){
    setTexture(tex);
    setOrigin(getTexture()->getSize().x/2.f, getTexture()->getSize().y/2.f);
    angle_rotation = 90;
    oil_mass = oil_current = 100.f;
    oil_speed = 1.f;
    derivOil = -.1f;
    velocity.y = 0.f;
    velocity.x = 0.f;
    acceleration = 20.f / 5.f;
    vel_res = 0.f;
    start_ = false;
}

void Rocket::update(){
    if(start_){
    //oil cap
    if(oil_current <= 0.f){
        oil_current = 0.f;
        vel_res = 0.f;
    }
    else {
        oil_current += derivOil;
    }
    //decreasing oil
    
    vel_res += thrustVelocity();
    velocity.y = vel_res*sinf((angle_rotation*(float)M_PI)/180.f);
    velocity.x = -vel_res*cosf((angle_rotation*(float)M_PI/180.f));

    velocity.y += acceleration;

    move(velocity);
    //std::cout << velocity.y << "\n";
   // std::cout << velocity.x << "\n";
    if(velocity.y >= 0.f && thrustVelocity() == 0.f && freefall != true){
        freefall = true;
        falltime.restart();
    }
    
    if(getPosition().y >= 540.f){
        setPosition(getPosition().x,540.f);
        freefall = false;
        velocity.y = 0;
    }
    
    if(freefall){
        move(0,.5f*acceleration*powf((falltime.getElapsedTime().asSeconds()*acceleration),2));
        
    }

    }
    
    setRotation(90.f - angle_rotation);
    
}

void Rocket::setRotationAngle(float a){
    angle_rotation = 90.f + a;
}

void Rocket::start(){
    start_ = true;
}

bool Rocket::hasStarted(){
    return start_;
}

void Rocket::setExhaustspeed(float v){
    oil_speed = v;
}

void Rocket::reset(){
    //refuel, essentially
    oil_current = oil_mass;
}

float Rocket::thrustVelocity(){
    if(oil_current <= 0.f){
        return 0.f;
    }
    else {
    return -oil_speed*logf(oil_mass/oil_current) / 5.f;
    }
}

bool Rocket::hasGas(){
    return oil_current > 0.f;
}
