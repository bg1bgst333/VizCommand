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
	
	// TRUEを返す.
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