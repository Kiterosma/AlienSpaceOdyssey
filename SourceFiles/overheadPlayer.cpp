#include "overheadPlayer.h"

OverheadPlayer::OverheadPlayer(Application* a, b2World* w, Vector2f pos):Entity(a, w, a->UFO, IntRect(2,3,45,45), pos, Vector2f(0,0)),speedLimit(4),cooldown(0.f)
{
	sprite.setOrigin(22.5f,21.5f);

	b2CircleShape circle;
	circle.m_p.Set(0,0);
	circle.m_radius = 30.f/PIXELS_PER_METER;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circle;
	fixtureDef.density = 1.f; //density subject to change
	body->CreateFixture(&fixtureDef);
	body->SetUserData(this);
}

list<Entity*> OverheadPlayer::update(float diff)
{
	list<Entity*> result;

	orientPlayer();

	Entity::update(diff);

	cooldown -= diff;
	if(cooldown<0) cooldown = 0;

	bool xflag = false;
	bool yflag = false;

	if(Keyboard::isKeyPressed(application->controls.getKey("Move Up")))
	{
		yflag = true;
		accelerateCenter(b2Vec2(0, -5.f));
	}
	if(Keyboard::isKeyPressed(application->controls.getKey("Move Down")))
	{
		yflag = true;
		accelerateCenter(b2Vec2(0, 5.f));
	}
	if(Keyboard::isKeyPressed(application->controls.getKey("Move Right")))
	{
		xflag = true;
		accelerateCenter(b2Vec2(5.f, 0.f));
	}
	if(Keyboard::isKeyPressed(application->controls.getKey("Move Left")))
	{
		accelerateCenter(b2Vec2(-5.f, 0.f));
		xflag = true;
	}
	if(Mouse::isButtonPressed(application->controls.getMouseButton("Shoot")))
	{
		if(cooldown==0)
			result.push_back(shoot());
	}

	if(!xflag && !yflag)
	{
		idle();
	}
	
	if(!xflag) decelerateX();
	if(!yflag) decelerateY();

	return result;
}

void OverheadPlayer::idle()
{
	//idle animations
}

void OverheadPlayer::accelerateCenter(b2Vec2 force)
{
	b2Vec2 velocity = getVelocity();

	if(velocity.x > speedLimit)
	{
		setVelocity(b2Vec2(speedLimit, velocity.y));
		if(force.x > 0.f) force.x = 0.f;
	}
	else if(velocity.x < speedLimit*-1)
	{
		setVelocity(b2Vec2(speedLimit*-1, velocity.y));
		if(force.x < 0.f) force.x = 0.f;
	}

	if(velocity.y > speedLimit)
	{
		setVelocity(b2Vec2(velocity.x, speedLimit));
		if(force.y > 0.f) force.y = 0.f;
	}
	else if(velocity.y < speedLimit*-1)
	{
		setVelocity(b2Vec2(velocity.x, speedLimit*-1));
		if(force.y < 0.f) force.y = 0.f;
	}

	Entity::accelerateCenter(force);
}

void OverheadPlayer::decelerateX()
{
	b2Vec2 velocity = body->GetLinearVelocity();

	int xDir = (velocity.x > 0)? 1:-1;

	if(velocity.x==0) xDir = 0;

	if(velocity.x > -.15f && velocity.x < .15f) setVelocity(b2Vec2(0.f,velocity.y));

	accelerateCenter(b2Vec2((float)(xDir*-1), 0.f)); //adjust value if necessary
}

void OverheadPlayer::decelerateY()
{
	b2Vec2 velocity = body->GetLinearVelocity();

	int yDir = (velocity.y > 0)? 1:-1;

	if(velocity.y==0) yDir = 0;

	if(velocity.y > -.15f && velocity.y < .15f) setVelocity(b2Vec2(velocity.x, 0.f));

	accelerateCenter(b2Vec2(0.f, (float)(yDir*-1)));
}

Projectile* OverheadPlayer::shoot()
{
	float angle = angleToMouse();
	Vector2f offset(.6f*cosf(angle),.6f*sinf(angle)); //laser appears to the side of the player, not on top.

	cooldown += .1f;

	return new Projectile(application, body->GetWorld(), sfmlb2d::B2TOSFVec2f(body->GetPosition())+offset, sfmlb2d::B2TOSFVec2f(body->GetLinearVelocity()),angle, Projectile::Laser);
}

float OverheadPlayer::angleToMouse()
{
	Vector2f mouse = application->localMouseCoords();
	Vector2f direction = mouse - getPositionPixels();
	return std::atan2f(direction.y,direction.x);
}

void OverheadPlayer::orientPlayer()
{
	float angle = angleToMouse();
	rotate((angle/(2*3.1416f))*360);
}

Entity::ID OverheadPlayer::getID()
{
	return Entity::overheadplayer;
}

void OverheadPlayer::beginContact(void* other)
{

}

void OverheadPlayer::endContact(void* other)
{

}