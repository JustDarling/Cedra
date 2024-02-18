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