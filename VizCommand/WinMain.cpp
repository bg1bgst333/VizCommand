// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
// ヘッダのインクルード
// 独自のヘッダ
#include "BasicApplication.h"	// ベーシックアプリケーションクラス

// _tWinMain関数
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数の宣言
	CApplication *pApp;	// CApplicationオブジェクトポインタpApp

	// CBasicApplicationオブジェクトの初期化
	pApp = new CBasicApplication();	// CBasicApplicationオブジェクトを作成し, pAppにアドレスを格納.
	if (!pApp->InitInstance(hInstance, lpCmdLine, nShowCmd)){	// pApp->InitInstanceで初期化処理が失敗なら.

		// エラー処理
		MessageBox(NULL, _T("アプリケーションの初期化に失敗しました."), _T("VizCommand"), MB_OK | MB_ICONHAND);	// MessageBoxで"アプリケーションの初期化に失敗しました."と表示.
		pApp->ExitInstance();	// pApp->ExitInstanceで終了処理.
		delete pApp;	// deleteでpAppを解放.
		return -1;	// 異常終了(-1)を返す.

	}

	// メッセージループ処理
	pApp->Run();

	// プログラムの終了
	delete pApp;	// deleteでpAppを解放.
	return 0;		// 正常終了(0)を返す.

}