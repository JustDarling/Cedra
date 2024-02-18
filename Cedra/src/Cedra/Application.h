#pragma once

#include "Core.h"

namespace Cedra
{
	class CEDRA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//to be defined in CLIENT
	Cedra::Application* CreateApplication();

}