#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Almond {

	class ALMOND_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}