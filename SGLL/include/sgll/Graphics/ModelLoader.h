#pragma once

#include <vector>

#include "RawModel.h"

namespace SGLL
{
	class ModelLoader
	{
	public:

		static RawModel loadModel(const std::vector<float>& vertices, const std::vector<float>& uv, const std::vector<unsigned int> indices);

		static RawModel loadModel(const std::vector<float>& vertices, const std::vector<float>& uv);

		static RawModel loadModel(const std::vector<float>& vertices, const std::vector<unsigned int> indices);

		static RawModel loadModel(const std::vector<float>& vertices);


		static std::vector<unsigned int> getVaos()
		{
			return mVaos;
		}
		
		static std::vector<unsigned int> getVbos()
		{
			return mVbos;
		}

		static std::vector<unsigned int> getIbos()
		{
			return mIbos;
		}

		static void cleanUp();

	private:
		static unsigned int createVao();

		static unsigned int createVbo(const std::vector<float>& data, unsigned int dimension);

		static unsigned int createIbo(const std::vector<unsigned int>& data);

		static std::vector<unsigned int> mVaos;
		static std::vector<unsigned int> mVbos;
		static std::vector<unsigned int> mIbos;
	};

}