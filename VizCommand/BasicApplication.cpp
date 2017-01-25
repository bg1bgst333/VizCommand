// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "BasicApplication.h"	// ベーシックアプリケーションクラス
#include "BasicWindow.h"	// ベーシックウィンドウクラス

// コンストラクタCBasicApplication()
CBasicApplication::CBasicApplication() : CApplication() {

}

// アプリケーション初期化関数InitInstance
BOOL CBasicApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// 初期化
	CApplication::InitInstance(hInstance, lpCmdLine, nShowCmd);	// CApplication::InitInstanceを呼ぶ.

	// ベーシックウィンドウクラスの登録
	CBasicWindow::RegisterClass(hInstance);	// CBasicWindow::RegisterClassでウィンドウクラス"BasicWindow"を登録.

	// TRUEを返す.
	return TRUE;	// TRUEを返す.

}
