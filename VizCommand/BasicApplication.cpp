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

	// ベーシックウィンドウオブジェクトの生成
	m_pMainWindow = new CBasicWindow();	// CBasicWindowオブジェクトを作成し, アドレスをm_pMainWindowに格納.

	// ウィンドウ作成
	if (!m_pMainWindow->Create(_T("VizCommand"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWindow->Createでの作成が失敗なら.
		return FALSE;	// FALSEを返す.
	}

	// ウィンドウ表示
	m_pMainWindow->ShowWindow(SW_SHOW);	// m_pMainWindow->ShowWindowで表示.

	// 成功なのでTRUEを返す.
	return TRUE;	// TRUEを返す.

}
