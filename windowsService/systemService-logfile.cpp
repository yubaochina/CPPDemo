// systemServiceExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>  
#include <stdio.h>  
#include <time.h>  


#define SLEEP_TIME 3000  
#define LOGFILE "D:\\test.txt"  
#define SERVICENAME L"testNTService"  


SERVICE_STATUS g_ServiceStatus;
SERVICE_STATUS_HANDLE g_hStatus;


int WriteLog(const char* str)
{
	FILE* log;

	//log = fopen(LOGFILE, "a+");
	fopen_s(&log, LOGFILE, "a+");
	if (log == NULL)
		return -1;

	fprintf(log, "%s\n", str);

	fclose(log);

	return 0;
}


void ControlHandler(DWORD request)
{
	switch (request)
	{
	case SERVICE_CONTROL_PAUSE:
		WriteLog("Pause.");
		g_ServiceStatus.dwWin32ExitCode = 0;
		g_ServiceStatus.dwCurrentState = SERVICE_PAUSED;
		break;
	case SERVICE_CONTROL_CONTINUE:
		WriteLog("Continue.");
		g_ServiceStatus.dwWin32ExitCode = 0;
		g_ServiceStatus.dwCurrentState = SERVICE_RUNNING;
		break;
	case SERVICE_CONTROL_STOP:
		WriteLog("Stop.");
		g_ServiceStatus.dwWin32ExitCode = 0;
		g_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
		break;
	case SERVICE_CONTROL_SHUTDOWN:
		WriteLog("Shutdown.");
		g_ServiceStatus.dwWin32ExitCode = 0;
		g_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
		break;
	default:
		break;
	}

	SetServiceStatus(g_hStatus, &g_ServiceStatus);

	return;
}



void ServiceMain(int argc, char** argv)
{
	g_ServiceStatus.dwServiceType = SERVICE_WIN32;
	g_ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
	g_ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_PAUSE_CONTINUE;
	g_ServiceStatus.dwWin32ExitCode = 0;
	g_ServiceStatus.dwServiceSpecificExitCode = 0;
	g_ServiceStatus.dwCheckPoint = 0;
	g_ServiceStatus.dwWaitHint = 0;

	g_hStatus = RegisterServiceCtrlHandler(SERVICENAME, (LPHANDLER_FUNCTION)ControlHandler);
	if (g_hStatus == (SERVICE_STATUS_HANDLE)0)
	{
		return;
	}

	g_ServiceStatus.dwCurrentState = SERVICE_RUNNING;
	SetServiceStatus(g_hStatus, &g_ServiceStatus);

	char buf[256];
	time_t ltime;

	while (1)
	{
		if (g_ServiceStatus.dwCurrentState == SERVICE_RUNNING)
		{

			time(&ltime);
			ctime_s(buf, sizeof(buf), &ltime);

			if (WriteLog(buf))
			{
				g_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
				g_ServiceStatus.dwWin32ExitCode = -1;
				SetServiceStatus(g_hStatus, &g_ServiceStatus);
				return;
			}
		}
		else if (g_ServiceStatus.dwCurrentState != SERVICE_PAUSED)
		{
			break;
		}

		Sleep(SLEEP_TIME);
	}

	return;
}



int main()
{
	SERVICE_TABLE_ENTRY ServiceTable[2];
	ServiceTable[0].lpServiceName = SERVICENAME;
	ServiceTable[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTION)ServiceMain;

	ServiceTable[1].lpServiceName = NULL;
	ServiceTable[1].lpServiceProc = NULL;

	StartServiceCtrlDispatcher(ServiceTable);

	return 0;
}
