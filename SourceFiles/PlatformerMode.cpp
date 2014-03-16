#include "PlatformerMode.h"
#include <iostream>

PlatformerMode::PlatformerMode(Application* a):GameMode(a,b2Vec2(0.f,9))
{
	cursor.setTexture(application->Reticle);
	cursor.setOrigin(50.f,50.f);
	cursor.scale(.5f,.5f);
}

PlatformerMode::~PlatformerMode()
{
	
}

void PlatformerMode::initialize(Screen screen)
{
	float ppm = PIXELS_PER_METER;

	//Define terrain
	b2BodyDef terrainDef;
	terrainDef.type = b2_staticBody;
	terrainDef.position.Set(0, 232/ppm);
	terrain = world->CreateBody(&terrainDef);
	terrain->SetUserData(this);

	b2PolygonShape shape1;
	shape1.SetAsBox(552.5f/ppm, 8/ppm, b2Vec2(552.5f/ppm, -8/ppm), 0);

	b2FixtureDef fixture1;
	fixture1.shape = &shape1;

	terrain->CreateFixture(&fixture1);

	view.setViewport(FloatRect(0,0,1,1));
	view.reset(FloatRect(0,0,800*232/600,232));
	
	player = new PlatformerPlayer(application, world, Vector2f(100/ppm, 199/ppm));
	entities.push_back(player);

	objects.push_back(new Background(application, application->World1_1, view));
	objects.push_back(player);
}

void PlatformerMode::handleEvent(const Event & event)
{
	switch(event.type)
	{
	case Event::KeyPressed:
		if(event.key.code == Keyboard::Escape && !paused)
			application->removeTop();
		break;
	case Event::MouseWheelMoved:
		//if(!paused) zoomView(event.mouseWheel.delta);
	case Event::LostFocus:
		paused = true;
	case Event::GainedFocus:
		paused = false;
	}
}

void PlatformerMode::preUpdate()
{
	
}

void PlatformerMode::postUpdate()
{
	Vector2f pos = player->getPositionPixels();
	//float yOffset = 300*viewZoom;
	float xOffset = 400*viewZoom*232/600;

	//if(pos.y < yOffset) pos.y = yOffset;
	//if(pos.y > 232-yOffset) pos.y = 232-yOffset;
	if(pos.x > 3392-xOffset) pos.x = 3392-xOffset;
	if(pos.x < xOffset) pos.x = xOffset;

	pos.y = 232/2;

	view.setCenter(pos);
}