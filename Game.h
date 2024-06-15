#include "Player.h"
#include "Scene.h"
#include "Collisions.h"
#include "files.h"
class Game{
private:
RenderWindow window;
Event event;
Collision collisionChecker;
void initWindow();
void initPlayer();
void initScene();
Scene* scene;
Player* player;
public:
Game();
~Game();
const RenderWindow& getWindow();

void renderPlayer();
void renderScene();
void render();
void updateMovement();
void updateCollisions();
void updatePlayer();
void update();



};