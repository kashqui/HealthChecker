#include <time.h>
#include <Windows.h>
#include "TP.cpp"

// Check span
const int REPEAT_SECOND = 5;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	TP tp;
	tp.getHeartBeat();
	time_t origin_time = time(NULL);
	// Repeat calling method.
	while (true)
	{
		time_t present_time = time(NULL);
		// If time is right?
		if (difftime(present_time, origin_time) < REPEAT_SECOND)
		{
			// Sleep during span.
			Sleep(1000 * REPEAT_SECOND);
		}
		else
		{
			// Get heartbeat from each device.
			tp.getHeartBeat();
			origin_time = time(NULL);
		}
	}
}