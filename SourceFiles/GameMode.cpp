#include "GameMode.h"

GameMode::GameMode(Application* a, b2Vec2 gravity):Element(a),viewZoom(1.f),paused(false)
{
	world = new b2World(gravity);
	world->SetContactListener(&contactListener);
}

void GameMode::update()
{
	if(!paused)
	{
		preUpdate();

		cursor.setPosition(application->localMouseCoords());

		newFrame = application->clock.getElapsedTime();

		float diff = newFrame.asSeconds() - oldFrame.asSeconds();

		world->Step(diff, 10, 10);

		updateEntities(diff);

		postUpdate();

		oldFrame = newFrame;
	}
}

void GameMode::updateEntities(float diff)
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

void GameMode::zoomView(int mouseWheelTicks)
{
	float targetZoom = -1*((float)mouseWheelTicks)/10 + viewZoom;
	if(targetZoom>4.f) targetZoom = 4.f;
	if(targetZoom<.1f) targetZoom = .1f;
	
	view.zoom(targetZoom/viewZoom);
	viewZoom = targetZoom;
}

void GameMode::pause()
{

}