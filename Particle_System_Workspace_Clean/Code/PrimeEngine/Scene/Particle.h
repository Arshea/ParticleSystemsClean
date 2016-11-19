#ifndef __PYENGINE_2_0_PARTICLE_H__
#define __PYENGINE_2_0_PARTICLE_H__

#include "PrimeEngine/Math/Vector3.h"

struct Particle {
	Vector3 position = Vector3(0,0,0);
	Vector3 velocity = Vector3(0,0,0);
	int life = 10;
	float size = 1.0f;

	Particle::Particle() {}

	Particle::Particle(/*Vector3 pos, */Vector3 vel, int initialLife, float size) {
		setParameters(/*pos, */vel, initialLife, size);

	}

	void setParameters(/*Vector3 pos, */Vector3 vel, int initialLife, float initialSize) {
		position = /*pos;*/Vector3(0, 0, 0);
		velocity = vel;
		life = initialLife;
		size = initialSize;
	}

	// Return false if dead
	bool update() {
		position += velocity;
		life--;
		if (life <= 0) return false;
		return true;
	}
};

#endif