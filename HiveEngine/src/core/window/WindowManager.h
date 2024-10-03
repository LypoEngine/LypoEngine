//
// Created by samuel on 10/2/24.
//

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H


namespace hive
{
	class Window;
}

namespace hive
{
	class WindowManager
	{

	public:
		static std::shared_ptr<Window> getCurrentWindow();
		static void setCurrentWindow(const std::shared_ptr<Window>& window);

	private:
		static std::shared_ptr<Window> m_window;
	};

}



#endif //WINDOWMANAGER_H
