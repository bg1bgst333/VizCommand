// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "StandardApplication.h"	// スタンダードアプリケーションクラス

// メインアプリケーションクラスCMainApplication
class CMainApplication : public CStandardApplication {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CMainApplication();	// コンストラクタCMainApplication()

		// メンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// アプリケーション初期化関数InitInstance

};