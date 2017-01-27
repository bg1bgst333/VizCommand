// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "StandardApplication.h"	// スタンダードアプリケーションクラス
//#include "StandardWindow.h"			// スタンダードウィンドウクラス

// コンストラクタCStandardApplication()
CStandardApplication::CStandardApplication() : CBasicApplication() {

}

// アプリケーション初期化関数InitInstance
BOOL CStandardApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 初期化
	CBasicApplication::InitInstance(hInstance, lpCmdLine, nShowCmd);	// CBasicApplication::InitInstanceを呼ぶ.

	// スタンダードウィンドウクラスの登録
	//CStandardWindow::RegisterClass(hInstance, IDR_MAINMENU);	// CStandardWindow::RegisterClassでメニューIDがIDR_MAINMENUなウィンドウクラス"StandardWindow"を登録.

	// 成功なのでTRUEを返す.
	return TRUE;	// TRUEを返す.

}