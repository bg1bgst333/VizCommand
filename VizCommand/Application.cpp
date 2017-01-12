// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "Application.h"	// アプリケーションクラス

// コンストラクタCApplication()
CApplication::CApplication(){

	// メンバ変数の初期化
	m_pMainWindow = NULL;	// m_pMainWindowをNULLに初期化.

}

// デストラクタ~CApplication()
CApplication::~CApplication(){

	// メンバ変数の終了処理
	if (m_pMainWindow != NULL) {	// m_pMainWindowがNULLでなければ.
		delete m_pMainWindow;	// deleteでm_pMainWindowを解放.
		m_pMainWindow = NULL;	// m_pMainWindowにNULLを代入.
	}

}

// アプリケーション初期化関数InitInstance
BOOL CApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ウィンドウクラスの登録
	CWindow::RegisterClass(hInstance, _T("Window"));	// CWindow::RegisterClassでウィンドウクラス"Window"を登録.
	
	// ウィンドウオブジェクトの生成
	m_pMainWindow = new CWindow();	// CWindowオブジェクトを作成し, アドレスをm_pMainWindowに格納.

	// ウィンドウ作成
	if (!m_pMainWindow->Create(_T("Window"), _T("VizCommand"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWindow->Createでの作成が失敗なら.
		return FALSE;	// FALSEを返す.
	}

	// ウィンドウ表示
	m_pMainWindow->ShowWindow(SW_SHOW);	// m_pMainWindow->ShowWindowで表示.

	// 成功なのでTRUEを返す.
	return TRUE;	// TRUEを返す.

}

// メッセージループ関数Run
int CApplication::Run(){

	// 変数の宣言
	MSG msg;	// メッセージ情報msg

	// メッセージ取得
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessageでメッセージ取得.

		// ウィンドウメッセージの送出
		DispatchMessage(&msg);	// DispatchMessageでウィンドウプロシージャに送出.
		TranslateMessage(&msg);	// TranslateMessageで仮想キーメッセージを文字へ変換.

	}

	// 終了処理
	return ExitInstance();	// ExitInstanceの値を返す.

}

// アプリケーション終了処理関数ExitInstance
int CApplication::ExitInstance(){

	// メインウィンドウオブジェクトがあれば解放.
	if (m_pMainWindow != NULL) {	// m_pMainWindowがNULLじゃなければ.

		// 解放.
		delete m_pMainWindow;	// deleteでm_pMainWindowを解放.
		m_pMainWindow = NULL;	// NULLをセット.

	}

	// 0を返す.
	return 0;

}