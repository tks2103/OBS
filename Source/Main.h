/********************************************************************************
 Copyright (C) 2012 Hugh Bailey <obs.jim@gmail.com>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
********************************************************************************/


#pragma once

#define WINVER         0x0600
#define _WIN32_WINDOWS 0x0600
#define _WIN32_WINNT   0x0600
#define NTDDI_VERSION  NTDDI_VISTASP1
#define WIN32_LEAN_AND_MEAN
#define ISOLATION_AWARE_ENABLED 1
#include <windows.h>
#include <commctrl.h>
#include <shellapi.h>
#include <commdlg.h>
#include <math.h>

#include <xmmintrin.h>
#include <emmintrin.h>

#define USE_AAC 1

#pragma warning(default : 4265)

//-------------------------------------------
// direct3d 10.1

#include <D3D10_1.h>
#include <D3DX10.h>
#include <DXGI.h>

#define USE_DXGI1_2 1

#ifdef USE_DXGI1_2
#include <dxgi1_2.h>
#endif


//-------------------------------------------
// API DLL

#include "OBSApi.h"


//-------------------------------------------
// application globals

class OBS;

extern HWND         hwndMain;
extern HWND         hwndRenderFrame;
extern HINSTANCE    hinstMain;
extern ConfigFile   *GlobalConfig;
extern ConfigFile   *AppConfig;
extern OBS          *App;
extern bool         bIsPortable;
extern TCHAR        lpAppPath[MAX_PATH];
extern TCHAR        lpAppDataPath[MAX_PATH];

#define OBS_VERSION             0x005206 //version number is 0xMMmmtt (Major.minor.test - yes I know it's hex)
#define OBS_VERSION_STRING_ANSI "Open Broadcaster Software v0.52.07b aquaman build"
#define OBS_VERSION_STRING      TEXT(OBS_VERSION_STRING_ANSI)
#define OBS_TEST_BUILD          1 //define this if releasing a test build to disable the auto updater

#ifdef _DEBUG
#define OBS_DISABLE_AUTOUPDATE 1
#endif

#if OBS_TEST_BUILD
#define OBS_DISABLE_AUTOUPDATE 1
#endif

#define OBS_WINDOW_CLASS      TEXT("OBSWindowClass")
#define OBS_RENDERFRAME_CLASS TEXT("RenderFrame")

inline UINT ConvertMSTo100NanoSec(UINT ms)
{
    return ms*1000*10; //1000 microseconds, then 10 "100nanosecond" segments
}

void WINAPI ProcessEvents();

//-------------------------------------------
// application headers

#include "../resource.h"
#include "VolumeControl.h"
#include "VolumeMeter.h"
#include "OBS.h"
#include "WindowStuff.h"
#include "CodeTokenizer.h"
#include "D3D10System.h"
#include "HTTPClient.h"
#include "Updater.h"

