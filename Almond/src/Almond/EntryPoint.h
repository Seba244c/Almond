#pragma once

#ifdef AM_PLATFORM_WINDOWS

extern Almond::Application* Almond::CreateApplication();

int main(int argc, char** argv) {
	printf("Almond Engine\n");
	auto app = Almond::CreateApplication();
	app->Run();
	delete app;
}

#endif