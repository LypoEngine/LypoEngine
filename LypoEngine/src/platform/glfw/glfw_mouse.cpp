//
// Created by GuillaumeIsCoding on 7/28/2024.
//
#include "glfw_mouse.h"

namespace hive
{
	struct GlfwMouse::DataImpl
	{
		DataImpl() : x_position(0.0), y_position(0.0), x_offset(0.0), y_offset(0.0), sensitivity(1.0f) {}
		
		double x_position, y_position;
		double x_offset, y_offset;
		float sensitivity;
		bool buttons[8] = {false};
		GLFWwindow* window;
	};

	std::unique_ptr<GlfwMouse::DataImpl> GlfwMouse::p_data_impl_ = std::make_unique<GlfwMouse::DataImpl>();

	GlfwMouse::GlfwMouse(void* window, const hive::MouseStates& configuration) noexcept
	{
		initialize(window, configuration);
	}

	void GlfwMouse::initialize(void* window, const hive::MouseStates& configuration) noexcept
	{
		p_data_impl_->window = static_cast<GLFWwindow*>(window);

		setConfiguration(configuration);

		glfwSetCursorPosCallback(p_data_impl_->window, GlfwMouse::positionCallback);
		glfwSetMouseButtonCallback(p_data_impl_->window, GlfwMouse::buttonCallback);
		glfwSetScrollCallback(p_data_impl_->window, GlfwMouse::scrollCallback);
	}

	void GlfwMouse::positionCallback(GLFWwindow* window, double x_position, double y_position) noexcept
	{
		GlfwMouse::p_data_impl_->x_position = x_position * GlfwMouse::p_data_impl_->sensitivity;
		GlfwMouse::p_data_impl_->y_position = y_position * GlfwMouse::p_data_impl_->sensitivity;
	}

	void GlfwMouse::scrollCallback(GLFWwindow* window, double x_offset, double y_offset) noexcept
	{
		GlfwMouse::p_data_impl_->x_offset += x_offset * GlfwMouse::p_data_impl_->sensitivity;
		GlfwMouse::p_data_impl_->y_offset += y_offset * GlfwMouse::p_data_impl_->sensitivity;
	}

	void GlfwMouse::buttonCallback(GLFWwindow* window, int button_value, int action, int mods) noexcept
	{
		if (button_value >= static_cast<int>(hive::ButtonValue::BUTTON_1) && button_value < static_cast<int>(hive::ButtonValue::BUTTON_8)) GlfwMouse::p_data_impl_->buttons[button_value] = (action == GLFW_PRESS);
	}

	void GlfwMouse::setSensitivity(const float& sensitivity)
	{
		GlfwMouse::p_data_impl_->sensitivity = (GlfwMouse::p_data_impl_->sensitivity != sensitivity) ? sensitivity : GlfwMouse::p_data_impl_->sensitivity;
	}

	void GlfwMouse::setConfiguration(const hive::MouseStates& configuration)
	{
		switch (configuration)
		{
		case hive::MouseStates::LOCK:
			glfwSetInputMode(p_data_impl_->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			break;
		case hive::MouseStates::HIDDEN:
			glfwSetInputMode(p_data_impl_->window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
			break;
		default:
			glfwSetInputMode(p_data_impl_->window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			break;
		}
	}

	void GlfwMouse::getPosition(double& x_position, double& y_position)
	{
		x_position = GlfwMouse::p_data_impl_->x_position;
		y_position = GlfwMouse::p_data_impl_->y_position;
	}

	bool GlfwMouse::isButtonPressed(const hive::ButtonValue& button_value) const
	{
		return GlfwMouse::p_data_impl_->buttons[static_cast<int>(button_value)];
	}
}