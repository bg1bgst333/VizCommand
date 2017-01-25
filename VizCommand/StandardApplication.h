// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "BasicApplication.h"	// ベーシックアプリケーションクラス

// スタンダードアプリケーションクラスCStandardApplication
class CStandardApplication : public CBasicApplication {

	// publicメンバ
	public:

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CStandardApplication();	// コンストラクタCStandardApplication()

		// メンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// アプリケーション初期化関数InitInstance

};