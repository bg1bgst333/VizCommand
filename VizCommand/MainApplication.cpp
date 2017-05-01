// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// メインアプリケーションクラス
#include "MainWindow.h"			// メインウィンドウクラス

// コンストラクタCMainApplication()
CMainApplication::CMainApplication() : CStandardApplication() {

}

// アプリケーション初期化関数InitInstance
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 初期化
	CStandardApplication::InitInstance(hInstance, lpCmdLine, nShowCmd);	// CStandardApplication::InitInstanceを呼ぶ.

	// メインウィンドウクラスの登録
	CMainWindow::RegisterClass(hInstance, (HBRUSH)GetStockObject(GRAY_BRUSH));	// CMainWindow::RegisterClassで背景ブラシがGRAY_BRUSHなウィンドウクラス"MainWindow"を登録.

	// ウィンドウリストコントロールクラスの登録
	CWindowListControl::RegisterClass(hInstance);	// CWindowListControl::RegisterClassでウィンドウリストコントロールクラスの登録.

	// エディットボックスパネルクラスの登録
	//CEditBoxPanel::RegisterClass(hInstance);			// CEditBoxPanel::RegisterClassでエディットボックスパネルクラスの登録.
	CScalableEditBoxPanel::RegisterClass(hInstance, (HBRUSH)GetStockObject(LTGRAY_BRUSH));	// CScalableEditBoxPanel::RegisterClassで背景ブラシがLTGRAY_BRUSHなスカラブルエディットボックスパネルクラスの登録.

	// メインウィンドウオブジェクトの生成
	m_pMainWindow = new CMainWindow();	// CMainWindowオブジェクトを作成し, アドレスをm_pMainWindowに格納.

	// ウィンドウ作成
	if (!m_pMainWindow->Create(_T("VizCommand"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWindow->Createでの作成が失敗なら.
		return FALSE;	// FALSEを返す.
	}

	// ウィンドウ表示
	m_pMainWindow->ShowWindow(SW_SHOW);	// m_pMainWindow->ShowWindowで表示.

	// 成功なのでTRUEを返す.
	return TRUE;	// TRUEを返す.

}