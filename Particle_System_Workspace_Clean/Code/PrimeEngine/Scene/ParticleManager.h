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
#include "../Events/Component.h"
#include "../Utils/Array/Array.h"
#include "../Geometry/MeshCPU/MeshCPU.h"
#include "../Math/Matrix4x4.h"

#include "PrimeEngine/APIAbstraction/GPUBuffers/VertexBufferGPU.h"
#include "PrimeEngine/APIAbstraction/GPUBuffers/IndexBufferGPU.h"

#include "PrimeEngine/APIAbstraction/Effect/Effect.h"

#include "PrimeEngine/Scene/PSysSceneNode.h"

// Sibling/Children includes

namespace PE {
	namespace Components {

		struct ParticleManager : Component
		{
			PSysSceneNode *pSysTest; // Change to array

			PE_DECLARE_CLASS(ParticleManager);
			ParticleManager(PE::GameContext &context, PE::MemoryArena arena, Handle hMyself);

			void startTestSystem();

		};

	}; // namespace Components
}; // namespace PE
#endif
