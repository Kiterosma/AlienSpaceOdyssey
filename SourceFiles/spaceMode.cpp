#include "SpaceMode.h"

SpaceMode::SpaceMode(Application* a):GameMode(a,b2Vec2(0.f,0.f))
{
	cursor.setTexture(application->Reticle);
	cursor.setOrigin(50.f,50.f);
	cursor.scale(.5f,.5f);
}

SpaceMode::~SpaceMode()
{
	
}

void SpaceMode::initialize(Screen screen)
{
	float ppm = PIXELS_PER_METER;

	view.setViewport(FloatRect(0,0,1,1));
	view.setSize(800.f,600.f); //replace with appropriate resolution
	view.setCenter(3000.f, 2250.f);
	
	player = new OverheadPlayer(application, world, view.getCenter()/ppm);
	Asteroid* asteroid1 = new Asteroid(application, world, Vector2f(35.f,20.f), Vector2f(0.f,0.f));
	entities.push_back(player);
	entities.push_back(asteroid1);

	objects.push_back(new Background(application, application->Starfield, view));
	objects.push_back(asteroid1);
	objects.push_back(player);
}

void SpaceMode::handleEvent(const Event & event)
{
	switch(event.type)
	{
	case Event::KeyPressed:
		if(event.key.code == Keyboard::Escape && !paused)
			application->removeTop();
		break;
	case Event::MouseWheelMoved:
		if(!paused) zoomView(event.mouseWheel.delta);
	case Event::LostFocus:
		paused = true;
	case Event::GainedFocus:
		paused = false;
	}
}

void SpaceMode::preUpdate()
{

}

void SpaceMode::postUpdate()
{
	Vector2f pos = player->getPositionPixels();
	float yOffset = 300*viewZoom;
	float xOffset = 400*viewZoom;

	if(pos.y < yOffset) pos.y = yOffset;
	if(pos.y > 4500-yOffset) pos.y = 4500-yOffset;
	if(pos.x > 6000-xOffset) pos.x = 6000-xOffset;
	if(pos.x < xOffset) pos.x = xOffset;

	view.setCenter(pos);
}