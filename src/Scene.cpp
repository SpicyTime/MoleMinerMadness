#include "Scene.h"

 

void Scene::initTextures()
{
    string source_dir = RESOURCE_PATH;
    if(!barTexture.loadFromFile(source_dir + "SteelBar.png")){
        cout << "ERROR::SCENE::COULD NOT LOAD BAR TEXTURE"<< '\n';
    }
    if(!topTexture.loadFromFile(source_dir + "Roof.png")){
        cout << "ERROR::SCENE::COULD NOT LOAD TOP TEXTURE" << '\n';
    }
    if(!floorTexture.loadFromFile(source_dir + "Ground.png")){
        cout << "ERROR::SCENE::COULD NOT LOAD FLOOR TEXTURE" << '\n';
    }

}
void Scene::initSprites()
{
    bar.setTexture(barTexture);
    bar.setPosition(Vector2f(0, 350));
    bar.setScale(4.f, 4.f);
    floor.setTexture(floorTexture);
    floor.setPosition(Vector2f(0, 600));
    floor.setScale(4.f, 4.f);
    top.setTexture(topTexture);
    top.setPosition(Vector2f(0, 0));
    top.setScale(4.f, 4.f);

}
Scene::Scene()
{
    initTextures();
    initSprites();
}

Scene::~Scene()
{
}

void Scene::render(RenderTarget & target)
{
    target.draw(bar);
    target.draw(floor);
    target.draw(top);
}

void Scene::update()
{
}

Sprite Scene::getBar()
{
    return bar;
}
