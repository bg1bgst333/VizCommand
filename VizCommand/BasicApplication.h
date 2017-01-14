// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "Application.h"	// アプリケーションクラス

// ベーシックアプリケーションクラスCBasicApplication
class CBasicApplication : public CApplication {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CBasicApplication();	// コンストラクタCBasicApplication()

		// メンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// アプリケーション初期化関数InitInstance

};