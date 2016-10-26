// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
// 独自のヘッダ
#include "Window.h"		// ウィンドウクラス

// アプリケーションクラス
class CApplication {

	// publicメンバ
	public:

		// publicメンバ変数
		CWindow *m_pMainWindow;	// CWindow *型ウィンドウオブジェクトm_pMainWindow.

		// publicメンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) = 0;	// インスタンス初期化関数InitInstance(純粋仮想関数)
		virtual int Run();	// メッセージループ関数Run
		virtual int ExitInstance();	// インスタンス終了処理関数ExitInstance

};