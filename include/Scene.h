#include "files.h"
class Scene{
private:
void initSprites();
void initTextures();
Sprite bar;
Sprite floor;
Sprite top;
Texture barTexture;
Texture floorTexture;
Texture topTexture;
public:
Scene();
~Scene();
void render(RenderTarget&);
void update();
Sprite getBar();

};