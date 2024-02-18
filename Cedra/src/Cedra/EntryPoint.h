#pragma once

#ifdef  CD_PLATFORM_WINDOWS

extern Cedra::Application* Cedra::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Cedra::CreateApplication();
	app->Run();
	delete app;
}
 
#endif
