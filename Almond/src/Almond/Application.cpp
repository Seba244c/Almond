#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Almond {
	Application::Application() {

	};

	Application::~Application() {

	};

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			AM_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AM_TRACE(e);
		}

		while (true);
	}
}