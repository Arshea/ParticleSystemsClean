#ifndef __PYENGINE_2_0_PARTICLESYSTEM_H__
#define __PYENGINE_2_0_PARTICLESYSTEM_H__

#include "PrimeEngine/Math/Vector3.h"
#include "PrimeEngine/Scene/Particle.h"

struct ParticleSystem {
	Particle particles[2];
	int initialLife = 10;
	float initialSize = 1.0f, initialSpeed = 0.01f;
	Vector3 initialDirection = Vector3(0, 1.0f, 0); 

	ParticleSystem::ParticleSystem(/*Vector3 pos, */Vector3 _initialDirection, int _initialLife, float _initialSize, float _initialSpeed) {
		setParameters(_initialDirection, _initialLife, _initialSize, _initialSpeed);
		// Add loop for max num particles
		setUpSystem();
	}

	ParticleSystem::ParticleSystem() {
		// Add loop for max num particles
		setUpSystem();
	}

	void setUpSystem() {
		int numParticles = 2;// change later ofc
		initialDirection.normalize(); // Change to random ofc
		for (int i = 0; i < numParticles; i++) {
			Vector3 pVelocity = initialSpeed * initialDirection;
			Vector3 pPos = Vector3(0, 0, 0);
			particles[i] = Particle(pVelocity, initialLife, initialSize);
		}
	}

	void setParameters(/*Vector3 pos, */Vector3 _initialDirection, int _initialLife, float _initialSize, float _initialSpeed) {
		initialLife = _initialLife;
		initialDirection = _initialDirection;
		initialSize = _initialSize;
		initialSpeed = _initialSpeed;
	}

	bool update() {

	}
};

#endif
