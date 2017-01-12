// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
// 独自のヘッダ
#include "Window.h"	// ウィンドウクラス

// アプリケーションクラスCApplication
class CApplication {

	// publicメンバ
	public:

		// publicメンバ変数
		// メンバ変数
		CWindow *m_pMainWindow;	// CWindow *型ウィンドウオブジェクトポインタm_pMainWindow.

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CApplication();	// コンストラクタCApplication()
		~CApplication();	// デストラクタ~CApplication()

		// メンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// アプリケーション初期化関数InitInstance
		virtual int Run();	// メッセージループ関数Run
		virtual int ExitInstance();	// アプリケーション終了処理関数ExitInstance

};