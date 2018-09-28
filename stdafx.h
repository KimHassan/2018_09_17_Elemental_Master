#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <list>
#include <algorithm>

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "imageManager.h"
#include "soundManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "iniDataManager.h"
#include "sceneManager.h"
#include "utils.h"
#include "txtData.h"
#include "database.h"
#include "tileManager.h"
#include "tile.h"

using namespace OCTA_UTIL;

//=======================================
// ## - �����ι� - ## 18.01.12 ## 
//=======================================

#define WINNAME (LPSTR)(TEXT("Octa API"))
#define WINSTARTX 20
#define WINSTARTY 50
#define WINSIZEX 1280
#define WINSIZEY 720
#define GAMEWINDOWX 160 // Ÿ�ϸ� ������ġ
#define GAMEWINDOWY 40	// Ÿ�ϸ� ������ġ
#define GAMEWINDOWWIDTH  960 // Ÿ�ϸ� ũ��
#define GAMEWINDOWHEIGHT 640 // Ÿ�ϸ� ũ��
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define RND randomFunction::getSingeton()
#define KEYMANAGER keyManager::getSingeton()
#define IMAGEMANAGER imageManager::getSingeton()
#define SOUNDMANAGER soundManager::getSingeton()
#define TIMEMANAGER timeManager::getSingeton()
#define EFFECTMANAGER effectManager::getSingeton()
#define SCENEMANAGER sceneManager::getSingeton()
#define TXTDATA txtData::getSingeton()
#define INIDATA iniDataManager::getSingeton()
#define DATABASE database::getSingeton()
#define TILEMANAGER tileManager::getSingeton()

//=======================================
// ## Macro ## 18.01.31 ## 
//=======================================

#define SAFE_DELETE(p) {if(p) { delete(p); (p) = NULL; }} 
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p) = NULL;}}

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;