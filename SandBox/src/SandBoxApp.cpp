#include "Cedra.h"

class SandBox : public Cedra::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{
		
	}
};

Cedra::Application* Cedra::CreateApplication()
{
	return new SandBox();
}

int main(int argc, char** argv)
{
	Cedra::Log::Init();

	auto app = Cedra::CreateApplication();
	app->Run();
	delete app;
}
