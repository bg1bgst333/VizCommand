// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "UserControl.h"	// ユーザコントロールクラス
#include "ScalableEditBoxPanel.h"	// スカラブルエディットボックスパネルクラス
#include "ConsoleCore.h"	// コンソールコアクラス

// コンソールクラスCConsole
class CConsole : public CScalableEditBoxPanel {

	// publicメンバ
	public:

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass

		// コンストラクタ・デストラクタ
		CConsole();	// コンストラクタCCConsole()
		virtual ~CConsole();	// デストラクタ~CCConsole()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ユーザ定義メッセージが発生した時のハンドラ.
		virtual int OnConsoleCoreCommand(WPARAM wParam, LPARAM lParam);	// CConsoleCoreから送られたメッセージを処理する独自ハンドラ.
		virtual void OnHello(HWND hSrc);		// "Hello, world!"を出力する独自ハンドラ.
		virtual void OnErrorCommandNotFound(HWND hSrc);	// コマンドが見つからない時のエラー用独自ハンドラ.

};