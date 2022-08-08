#pragma once


namespace SGLL
{
	class RawModel
	{
	public:
		RawModel() = default;

		RawModel(unsigned int vaoID, unsigned int vertexCount);

		unsigned int getVertexCount() const
		{
			return mVertexCount;
		}

		unsigned int getVaoID() const
		{
			return mVaoID;
		}
	private:
		unsigned int mVertexCount;
		unsigned int mVaoID;
	};
}