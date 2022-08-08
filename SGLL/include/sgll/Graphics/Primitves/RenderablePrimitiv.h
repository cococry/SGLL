#pragma once

#include "../TexturedModel.h"
#include <glm/glm.hpp>
#include <vector>

namespace SGLL
{
	class RenderablePrimitiv
	{
	public:
		RenderablePrimitiv(const glm::vec3& position, const glm::vec3& scale, const glm::vec3& color, const glm::vec3& rotation, 
			const std::vector<float>& vertexPositions, const std::vector<unsigned int>& indices, bool loadModel = true);


		glm::vec3 Position;
		glm::vec3 Scale;
		glm::vec3 Color;
		glm::vec3 Rotation;

		void increasePositon(float x, float y, float z);

		void decreasePosition(float x, float y, float z);

		void increaseScale(float x, float y, float z);

		void decreaseScale(float x, float y, float z);

		void increaseRotation(float x, float y, float z);

		void decreaseRotation(float x, float y, float z);



		virtual void render() = 0;

		const std::vector<float>& getVertexPositions() const
		{
			return mVertexPositions;
		}

		const std::vector<unsigned int>& getIndices() const
		{
			return mIndices;
		}

		const RawModel& getModel() const
		{
			return mModel;
		}

	protected:
		std::vector<float> mVertexPositions;
		std::vector<unsigned int> mIndices;


		RawModel mModel;
	};
}