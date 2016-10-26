// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Application.h"	// アプリケーションクラス

// メインアプリケーションクラス
class CMainApplication : public CApplication {	// CApplicationの派生クラス

	// publicメンバ
	public:

		// publicメンバ関数
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// インスタンス初期化関数InitInstance

};