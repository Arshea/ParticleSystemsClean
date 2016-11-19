#include "PrimeEngine/Math/Vector3.h"

struct Particle {
	Vector3 position;
	Vector3 velocity;
	int life;

	Particle::Particle(Vector3 pos, Vector3 vel, int initialLife) {
		position = pos;
		velocity = vel;
		life = initialLife;
	}

	// Return false if dead
	bool update() {
		if (life <= 0) return false;
		position += velocity;
		life--;
		return true;
	}
};