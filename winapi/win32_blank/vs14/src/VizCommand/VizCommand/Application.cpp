// ヘッダのインクルード
#include "Application.h"	// アプリケーションクラス

// メッセージループ関数Run
int CApplication::Run() {

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

// インスタンス終了処理関数ExitInstance
int CApplication::ExitInstance() {

	// メインウィンドウオブジェクトがあれば解放.
	if (m_pMainWindow != NULL) {	// m_pMainWindowがNULLじゃなければ.

		// 解放.
		delete m_pMainWindow;	// deleteでm_pMainWindowを解放.
		m_pMainWindow = NULL;	// NULLをセット.

	}

	// 成功なら0.
	return 0;	// 0を返す.

}