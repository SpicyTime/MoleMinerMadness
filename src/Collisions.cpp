#include "Collisions.h"

Collision::Collision()
{
}

bool Collision::checkCollision(Sprite sprite1, Sprite sprite2)
{
    if(sprite1.getPosition().x < sprite2.getPosition().x + sprite2.getGlobalBounds().width && sprite1.getPosition().x + sprite1.getGlobalBounds().width > sprite2.getPosition().x && sprite1.getPosition().y < sprite2.getPosition().y + sprite2.getGlobalBounds().height && sprite1.getGlobalBounds().height + sprite1.getPosition().y > sprite2.getPosition().y){
        return true;
    }
    return false;
}
