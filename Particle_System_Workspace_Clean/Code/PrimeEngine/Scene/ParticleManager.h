#ifndef __PYENGINE_2_0_PARTICLEMANAGER_H__
#define __PYENGINE_2_0_PARTICLEMANAGER_H__

#define NOMINMAX
// API Abstraction
#include "PrimeEngine/APIAbstraction/APIAbstractionDefines.h"

// Outer-Engine includes
#include <assert.h>

// Inter-Engine includes
#include "PrimeEngine/MemoryManagement/Handle.h"
#include "PrimeEngine/PrimitiveTypes/PrimitiveTypes.h"
#include "../Utils/Array/Array.h"
#include "../Math/Matrix4x4.h"

#include "PrimeEngine/Scene/PSysSceneNode.h"
#include "PrimeEngine/Scene/ParticleSystem.h"
#include "PrimeEngine/Scene/ParticleRenderer.h"

// Sibling/Children includes

namespace PE {
	namespace Components {

		struct ParticleManager : Component
		{
			ParticleSystem pSysTest; // Change to array

			PE_DECLARE_CLASS(ParticleManager);
			ParticleManager(PE::GameContext &context, PE::MemoryArena arena, Handle hMyself);

			void updateSystems(int &threadOwnershipMask);

			//ParticleManager::ParticleManager() {};
			void print(int &threadOwnershipMask);

		};

	}; // namespace Components
}; // namespace PE
#endif
