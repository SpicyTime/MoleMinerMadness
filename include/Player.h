#include "files.h"

class Player{
private:
 
Texture playerTexture;
void initVariables();
void initTexture();
void initSprite();
void initPhysics();

//Physics
Vector2f velocity;
float acceleration;
float drag;
float gravity;
float maxVelocity;
float minVelocity;
public:
Sprite playerSprite;
Player();
~Player();
//Accessors
const Vector2f getPosition() const;
const FloatRect getGlobalBounds();

void move(const float, const float);
void resetVelocity();
void resetYPos(int);
void update();
void updatePhysics();
void render(RenderTarget&);

};