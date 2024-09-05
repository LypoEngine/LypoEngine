#include "Renderer.hpp"

namespace hive {
	void Renderer::beginScene()
    {
        beginScene(0.1f, 0.1f, 0.1f, 1.0f);
    }

    void Renderer::beginScene(float r, float g, float b, float a)
    {
        //TODO: take a vector for the color in parameter when glm is implemented
        RenderCommand::setClearColor(r, g, b, a);
        RenderCommand::clear();

        //TODO: in the future we will take in parameters info on camera, light and environment to render the scene
    }

    void Renderer::endScene()
    {
    }

    void Renderer::submitGeometryToDraw(const std::shared_ptr<VertexArray>& vertexArray)
    {
        vertexArray->bind();
        RenderCommand::drawVertexArray(vertexArray);
        //TODO : in the future we will sudmit the geometry to a draw queue to be rendered in the correct order
    }

    void Renderer::submitGeometryToDraw(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader)
    {
        shader->bind();
        submitGeometryToDraw(vertexArray);
    }
}