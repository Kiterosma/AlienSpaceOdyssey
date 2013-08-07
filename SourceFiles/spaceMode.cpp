#include "spaceMode.h"

SpaceMode::SpaceMode(Application* a):application(a),viewZoom(1.f)
{
	cursor.setTexture(application->Reticle);
	cursor.setOrigin(50.f,50.f);
	cursor.scale(.5f,.5f);

	world = new b2World(b2Vec2(0.f,0.f));
	world->SetContactListener(&contactListener);
}

SpaceMode::~SpaceMode()
{
	delete world;
}

void SpaceMode::initialize(Screen screen)
{
	float ppm = PIXELS_PER_METER;

	view.setViewport(FloatRect(0,0,1,1));
	view.setSize(800.f,600.f);
	view.setCenter(3000.f, 2250.f);
	
	player = new OverheadPlayer(application, world, view.getCenter()/ppm);
	Asteroid* asteroid1 = new Asteroid(application, world, Vector2f(35.f,20.f), Vector2f(0.f,0.f));
	entities.push_back(player);
	entities.push_back(asteroid1);

	objects.push_back(new Background(application, application->Starfield, view, false));
	objects.push_back(asteroid1);
	objects.push_back(player);

}

void SpaceMode::draw()
{
	application->window.setView(view);

	list<GameObject*>::iterator it = objects.begin();
	while(it!=objects.end())
	{
		(*it)->draw();
		it++;
	}
	application->window.draw(cursor);
}

void SpaceMode::handleEvent(const Event & event)
{
	switch(event.type)
	{
	case Event::KeyPressed:
		if(event.key.code == Keyboard::Escape)
			application->removeTop();
		break;
	case Event::MouseWheelMoved:
		zoomView(event.mouseWheel.delta);
	}
}

void SpaceMode::update()
{
	cursor.setPosition(application->localMouseCoords());

	newFrame = application->clock.getElapsedTime();

	float diff = newFrame.asSeconds() - oldFrame.asSeconds();

	world->Step(diff, 10, 10);

	updateEntities(diff);

	Vector2f pos = player->getPositionPixels();
	float yOffset = 300*viewZoom;
	float xOffset = 400*viewZoom;

	if(pos.y < yOffset) pos.y = yOffset;
	if(pos.y > 4500-yOffset) pos.y = 4500-yOffset;
	if(pos.x > 6000-xOffset) pos.x = 6000-xOffset;
	if(pos.x < xOffset) pos.x = xOffset;

	view.setCenter(pos);

	oldFrame = newFrame;
}

/*
Update all entities, delete despawning entities, and store new entities.
*/
void SpaceMode::updateEntities(float diff)
{
	for(list<Entity*>::iterator it1=entities.begin(); it1!=entities.end(); it1++)
	{
		list<Entity*> newObjects= (*it1)->update(diff);

		if((*it1)->despawn)
		{
			objects.remove(*it1);
			delete *it1;
			*it1=NULL;

			list<Entity*>::iterator temp = it1;
			temp++;
			entities.erase(it1);
			it1=temp;

		}
		for(list<Entity*>::iterator it2 = newObjects.begin(); it2!=newObjects.end(); it2++)
			objects.push_back(*it2);
		entities.splice(entities.end(),newObjects);
	}
}

void SpaceMode::zoomView(int mouseWheelTicks)
{
	float targetZoom = -1*((float)mouseWheelTicks)/10 + viewZoom;
	if(targetZoom>4.f) targetZoom = 4.f;
	if(targetZoom<.1f) targetZoom = .1f;
	
	view.zoom(targetZoom/viewZoom);
	viewZoom = targetZoom;
}