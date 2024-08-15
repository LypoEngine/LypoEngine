//
// Created by GuillaumeIsCoding on 7/28/2024.
//
#pragma once

#include "core/mouse.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace hive
{
	/**
	 * Windows concrete class of core::Mouse
	 */
	class GlfwMouse : public hive::Mouse
	{
	public:
		GlfwMouse(void* window, const hive::MouseStates& configuration = hive::MouseStates::DEFAULT) noexcept;
		virtual ~GlfwMouse() noexcept override = default;

		void setSensitivity(const float& sensitivity) override;
		void setConfiguration(const hive::MouseStates& configuration) override;
		
		void getPosition(double& x_position, double& y_position) override;

		bool isButtonPressed(const hive::ButtonValue& value) const override;
	private:
		void initialize(void* window, const hive::MouseStates& configuration) noexcept;

		static void positionCallback(GLFWwindow* window, double x_position, double y_position) noexcept;
		static void scrollCallback(GLFWwindow* window, double x_offset, double y_offset) noexcept;
		static void buttonCallback(GLFWwindow* window, int button, int action, int mods) noexcept;
	private:
		struct DataImpl;
		static std::unique_ptr<DataImpl> p_data_impl_;
	};
}
