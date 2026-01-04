#include "Form1.h"
#include <Windows.h>
using namespace Form; // Your Project Name

void Main(void)
{
//Application::EnableVisualStyles();
Application::SetCompatibleTextRenderingDefault(false);
Application::Run(gcnew Form1); // Your Form Name
Application::Exit();
}