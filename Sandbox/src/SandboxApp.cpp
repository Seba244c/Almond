#include <Almond.h>

class Sandbox : public Almond::Application {
	public:
	Sandbox() {

	}

	 ~Sandbox() {

	}
};

Almond::Application* Almond::CreateApplication() {
	return new Sandbox();
}
