#include "Game.h"
Game::Game()
{
    initWindow();
    initPlayer();
    initScene();
}

Game::~Game()
{
    delete player;
    delete scene;
}
void Game::initWindow()
{
    window.create(VideoMode( 1280, 700), "GAME ");
    window.setFramerateLimit(60);
}
void Game::initPlayer()
{
    player = new Player();
}
void Game::initScene()
{
   scene = new Scene();
}
const RenderWindow &Game::getWindow()
{
    // TODO: insert return statement here
    return window;
}

 


void Game::renderPlayer()
{
    player->render(window);
}

void Game::renderScene()
{
    scene->render(window);
}

void Game::render( )
{
    window.clear();
    renderScene();
    renderPlayer();
     
    window.display();
}
void Game::updatePlayer()
{
    player->update();
}
void Game::updateMovement()
{
    if( Keyboard::isKeyPressed(Keyboard::Key::A)){
        player->move(-1.f, 0.f);
    }
    else if( Keyboard::isKeyPressed(Keyboard::Key::D)){
        player->move(1.f, 0.f);
    }
    if( Keyboard::isKeyPressed(Keyboard::Key::W)){
        player->move(0.f, -1.f);
    }
    else if( Keyboard::isKeyPressed(Keyboard::Key::S)){
        player->move(0.f, 1.f);
    }
}
void Game::updateCollisions()
{
    if(collisionChecker.checkCollision(player->playerSprite, scene->getBar())){
        cout << "COLLISION DETECTED" << '\n';
        player->resetVelocity();
        int place = scene->getBar().getPosition().y - player->playerSprite.getGlobalBounds().height;
         
        player->resetYPos(place);
    }
    
}
void Game::update()
{
    while(window.pollEvent(event)){
        if(event.type == Event::Closed){
            window.close();
        }
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Key::Escape){
            window.close();
        }
         
    }
    updateCollisions();
    updatePlayer();
    updateMovement();
}
