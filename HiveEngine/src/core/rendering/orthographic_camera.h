//
// Created by mathe on 05/09/2024.
//
#pragma once
#include "lypch.h"
#include <glm/glm.hpp>

namespace hive
{
    class OrthographicCamera
    {
    public:
        OrthographicCamera(float left, float right, float bottom, float top);

        const glm::vec3& getPosition() const { return position_; }
        void setPosition(const glm::vec3& position) { position_ = position; RecomputeViewMatrix(); }

        float getRotation() const { return rotation_; }
        void setRotation(float rotation) { rotation_ = rotation; RecomputeViewMatrix(); }

        const glm::mat4& getProjectionMatrix() const { return projectionMatrix_; }
        const glm::mat4& getViewMatrix() const { return viewMatrix_; }
        const glm::mat4& getViewProjectionMatrix() const { return viewProjectionMatrix_; }
    private:
        void RecomputeViewMatrix();
    private:
        glm::mat4 projectionMatrix_;
        glm::mat4 viewMatrix_;
        glm::mat4 viewProjectionMatrix_;

        glm::vec3 position_ = { 0.0f, 0.0f, 0.0f };
        float rotation_ = 0.0f;
    };
}