#include "sgll/Graphics/Primitves/RenderablePrimitiv.h"
#include "sgll/DeltaTime.h"
#include "sgll/Graphics/ModelLoader.h"

namespace SGLL
{
	RenderablePrimitiv::RenderablePrimitiv(const glm::vec3& position, const glm::vec3& scale, const glm::vec3& color, const glm::vec3& rotation, const std::vector<float>& vertexPositions, 
		const std::vector<unsigned int>& indices, bool loadModel)
		: Position(position), Scale(scale), Color(color), Rotation(rotation), mVertexPositions(vertexPositions), mIndices(indices)
	{
		if (loadModel) 
		{
			mModel = ModelLoader::loadModel(vertexPositions, indices);
		}
	}
	void RenderablePrimitiv::increasePositon(float x, float y, float z)
	{
		Position.x += x * DeltaTime::get();
		Position.y += y * DeltaTime::get();
		Position.z += z * DeltaTime::get();
	}

	void RenderablePrimitiv::decreasePosition(float x, float y, float z)
	{
		Position.x -= x * DeltaTime::get();
		Position.y -= y * DeltaTime::get();
		Position.z -= z * DeltaTime::get();
	}

	void RenderablePrimitiv::increaseScale(float x, float y, float z)
	{
		Scale.x += x * DeltaTime::get();
		Scale.y += y * DeltaTime::get();
		Scale.z += z * DeltaTime::get();
	}

	void RenderablePrimitiv::decreaseScale(float x, float y, float z)
	{
		Scale.x -= x * DeltaTime::get();
		Scale.y -= y * DeltaTime::get();
		Scale.z -= z * DeltaTime::get();
	}

	void RenderablePrimitiv::increaseRotation(float x, float y, float z)
	{
		Rotation.x += x * DeltaTime::get();
		Rotation.y += y * DeltaTime::get();
		Rotation.z += z * DeltaTime::get();
	}

	void RenderablePrimitiv::decreaseRotation(float x, float y, float z)
	{
		Rotation.x -= x * DeltaTime::get();
		Rotation.y -= y * DeltaTime::get();
		Rotation.z -= z * DeltaTime::get();
	}

}