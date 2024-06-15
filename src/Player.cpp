#include "Player.h"

Player::Player()
{
    initTexture();
    initSprite();
    initPhysics();
}

Player::~Player()
{
}

void Player::move(const float x, const float y)
{
    velocity.x += x * acceleration;

    //limit acceleration
    if(std::abs(velocity.x) > maxVelocity){
        velocity.x = maxVelocity * ((velocity.x < 0.f) ? -1.f: 1.f);
    }
}

void Player::resetVelocity()
{
    velocity.y = 0;
}

void Player::resetYPos(int newY)
{
    playerSprite.setPosition(Vector2f(playerSprite.getPosition().x, newY));
}

void Player::initTexture()
{
    string source_dir = RESOURCE_PATH;
  
    if(!playerTexture.loadFromFile(source_dir + "Player1.png")){
        cout << "ERROR::PLAYER::COULD NOT LOAD FROM FILE" << '\n';
    }  
}
void Player::initSprite()
{
    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(IntRect(0, 0, 76, 90));
   
}

void Player::initPhysics()
{
    acceleration = 2.f;
    drag = 0.98f;
    gravity = 1.f;
    maxVelocity = 5.f;
    minVelocity = 1.f;
}

void Player::update()
{
    updatePhysics();
}

void Player::updatePhysics()
{
    velocity *= drag;
    velocity.y += 1.f * gravity;

    //limit deceleration
    if(std::abs(velocity.x) < minVelocity){
        velocity.x = 0.f;
    }
    playerSprite.move(velocity);
}

void Player::render(RenderTarget& target)
{
    target.draw(playerSprite);
}
