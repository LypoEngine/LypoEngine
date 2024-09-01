//
// Created by mathe on 12/08/2024.
//

#include "RenderCommand.h"
#include "platform/opengl/OpenGlRenderAPI.h"


namespace hive
{
    RenderAPI* getRenderAPI()
    {
        switch(RenderAPI::getAPI())
        {
            case RenderAPI::API::OpenGL:
                return new OpenGlRenderAPI();
            default:
                return nullptr;
        }
    }

    RenderAPI* RenderCommand::renderAPI_ = getRenderAPI();
}