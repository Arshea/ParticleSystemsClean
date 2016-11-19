#ifndef __PYENGINE_2_0_PARTICLESYSTEM_H__
#define __PYENGINE_2_0_PARTICLESYSTEM_H__

#include "PrimeEngine/Math/Vector3.h"
#include "PrimeEngine/Scene/Particle.h"

struct ParticleSystem {
	Particle particles[1000];
	int initialLife[2] = { 50,100 };
	float initialSize[2] = { 0.1f,1.0f }, initialSpeed[2] = { 1.0f,15.0f }, gravityF = 0.35f;
	Vector3 initialDirection[2] = { Vector3(-0.3f, 0.7f, -0.3f), Vector3(0.3f, 1.0f, 0.3f) };
	bool gravity = true;

	ParticleSystem::ParticleSystem(/*Vector3 pos, */Vector3 _initialDirection[2], int _initialLife[2], float _initialSize[2], float _initialSpeed[2]) {
		setParameters(_initialDirection, _initialLife, _initialSize, _initialSpeed);
		// Add loop for max num particles
		setUpSystem();
	}

	ParticleSystem::ParticleSystem() {
		// Add loop for max num particles
		setUpSystem();
	}

	void setParameters(/*Vector3 pos, */Vector3 _initialDirection[2], int _initialLife[2], float _initialSize[2], float _initialSpeed[2]) {
		for (int i = 0; i < 2; i++) {
			initialLife[i] = _initialLife[i];
			initialDirection[i] = _initialDirection[i];
			initialSize[i] = _initialSize[i];
			initialSpeed[i] = _initialSpeed[i];
		}
	}

	void setUpSystem() {
		int numParticles = 2;// change later ofc
		for (int i = 0; i < numParticles; i++) {
			particles[i] = makeNewParticle();
		}
	}

	Particle makeNewParticle() {
		Vector3 pInitialDirection = randomDirection(initialDirection[0], initialDirection[1]);
		pInitialDirection.normalize();
		float pInitialSpeed = randomBetweenNumbers(initialSpeed[0], initialSpeed[1]);
		Vector3 pVelocity = pInitialSpeed * pInitialDirection;
		float pInitialSize = randomBetweenNumbers(initialSize[0], initialSize[1]);
		float pInitialLife = randomBetweenNumbers(initialLife[0], initialLife[1]);

		return Particle(pVelocity, pInitialLife, pInitialSize);
	}


	// Update interface ----------------------------------------------------------------------------------------------------------------------

	void update() {
		int numParticles = 1000;// change later ofc
		for (int i = 0; i < numParticles; i++) {
			// Gravity
			if (gravity) particles[i].velocity += Vector3(0, -gravityF, 0);
			// Change its velocity and other things here
			if (!particles[i].update() /*|| /* or if y < 0 -- change later because local only particles[i].position.getY() < 0.0f*/) { // If dead make new
				OutputDebugStringA("Particle dead. Making new./n");
				particles[i] = makeNewParticle();
			}
		}
	}

	Particle *getParticles() {
		return particles;
	}


	// Utility -------------------------------------------------------------------------------------------------------------------------------

	Vector3 randomDirection(Vector3 min, Vector3 max) {
		Vector3 randomV;
		randomV.m_x = randomBetweenNumbers(min.getX(), max.getX());
		randomV.m_y = randomBetweenNumbers(min.getY(), max.getY());
		randomV.m_z = randomBetweenNumbers(min.getZ(), max.getZ());

		randomV.normalize(); // Might not need this
		return randomV;
	}

	// Random float between min and max
	float randomBetweenNumbers(float min, float max) {
		if (min >= max) {
			return max;
			OutputDebugStringA("Check upper/lower bounds for ParticleSystem::randomBetweenNumbers function call.\n");
		}
		float random = min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
		return random;
	}

	// Random int between min and max
	int randomBetweenNumbers(int min, int max) {
		if (min >= max) {
			return min;
			OutputDebugStringA("Check upper/lower bounds for ParticleSystem::randomBetweenNumbers function call.\n");
		}		int random = min + ((rand()) % (max - min));
		return random;
	}

};

#endif
