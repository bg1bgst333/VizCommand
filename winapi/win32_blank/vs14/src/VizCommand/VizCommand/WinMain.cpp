// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
// 独自のヘッダ
#include "MainApplication.h"	// メインアプリケーションクラス

// _tWinMain関数
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// 変数・ポインタの宣言
	CApplication *pApplication;	// CApplicationポインタpApplication.
	int iRet;	// int型変数iRet.

	// オブジェクトの作成.
	pApplication = new CMainApplication();	// CMainApplicationオブジェクトを作成し, CApplicationオブジェクトポインタのpApplicationに格納.

	// インスタンス初期化.
	if (!pApplication->InitInstance(hInstance, lpCmdLine, nShowCmd)) {	// pApplication->InitInstanceでアプリケーションインスタンス初期化.

		// 終了処理.
		iRet = pApplication->ExitInstance();	// pApplication->ExitInstanceで終了処理.
		delete pApplication;	// pApplicationを解放.
		return iRet;	// iRetを戻り値とする.

	}

	// メッセージループ処理.
	iRet = pApplication->Run();	// pApplication->Runでメッセージループ処理.

	// pApplicationの解放.
	delete pApplication;	// deleteでpApplicationの解放.

	// プログラムの終了.
	return iRet;

}