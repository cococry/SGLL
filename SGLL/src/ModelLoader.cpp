#include "sgll/Graphics/ModelLoader.h"

#include <glad/glad.h>

std::vector<unsigned int> SGLL::ModelLoader::mVaos;
std::vector<unsigned int> SGLL::ModelLoader::mVbos;
std::vector<unsigned int> SGLL::ModelLoader::mIbos;

namespace SGLL
{
    RawModel ModelLoader::loadModel(const std::vector<float>& vertices, const std::vector<float>& uv, const std::vector<unsigned int> indices)
    {
        unsigned int vao = createVao();

        createVbo(vertices, 3);
        createVbo(uv, 2);
        createIbo(indices);

        return RawModel(vao, indices.size());

    }

    RawModel ModelLoader::loadModel(const std::vector<float>& vertices, const std::vector<float>& uv)
    {
        unsigned int vao = createVao();

        createVbo(vertices, 3);
        createVbo(uv, 2);

        return RawModel(vao, vertices.size());
    }
    RawModel ModelLoader::loadModel(const std::vector<float>& vertices, const std::vector<unsigned int> indices)
    {
        unsigned int vao = createVao();

        createVbo(vertices, 3);
        createIbo(indices);

        return RawModel(vao, indices.size());
    }
    RawModel ModelLoader::loadModel(const std::vector<float>& vertices)
    {
        unsigned int vao = createVao();

        createVbo(vertices, 3);

        return RawModel(vao, vertices.size());
    }
    void ModelLoader::cleanUp()
    {
        for (unsigned int vao : mVaos)
        {
            glDeleteVertexArrays(1, &vao);
        }
        for (unsigned int vbo : mVbos)
        {
            glDeleteVertexArrays(1, &vbo);
        }
        for (unsigned int ibo : mIbos)
        {
            glDeleteVertexArrays(1, &ibo);
        }
    }
    unsigned int ModelLoader::createVao()
    {
        unsigned int vao;

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        return vao;
    }
    unsigned int ModelLoader::createVbo(const std::vector<float>& data, unsigned int dimension)
    {
        unsigned int vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER,
            data.size() * sizeof(GLfloat),
            data.data(),
            GL_STATIC_DRAW);

        mVbos.push_back(vbo);

        glVertexAttribPointer(mVbos.size() - 1,
            dimension,
            GL_FLOAT,
            GL_FALSE,
            0,
            (GLvoid*)0);

        glEnableVertexAttribArray(mVbos.size() - 1);

        
        return vbo;
    }
    unsigned int ModelLoader::createIbo(const std::vector<unsigned int>& data)
    {

        unsigned int ibo;
        glGenBuffers(1, &ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
            data.size() * sizeof(GLuint),
            data.data(),
            GL_STATIC_DRAW);

        return ibo;
    }
}

