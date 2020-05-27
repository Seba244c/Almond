#pragma once

#ifdef AM_PLATFORM_WINDOWS

extern Almond::Application* Almond::CreateApplication();

int main(int argc, char** argv) {
	Almond::Log::Init();
	AM_CORE_WARN("Initialized Log!");
	AM_INFO("Hello!");

	auto app = Almond::CreateApplication();
	app->Run();
	delete app;
}

#endif