// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "UserControl.h"	// ユーザコントロールクラス
#include "WindowListControl.h"	// ウィンドウリストコントロールクラス

// ストリームコンソールクラスCStreamConsole
class CStreamConsole : public CWindowListControl {

	// publicメンバ
	public:

		// publicメンバ変数
		UINT m_nId;	// リソースID

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass

		// コンストラクタ・デストラクタ
		CStreamConsole();	// コンストラクタCStreamConsole
		virtual ~CStreamConsole();	// デストラクタ~CStreamConsole()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ユーザ定義メッセージが発生した時のハンドラ.
		virtual void OnRequestScrollBottom(UINT uMsg, WPARAM wParam, LPARAM lParam);	// 下へのスクロール要求.
		virtual int OnStreamCommand(WPARAM wParam, LPARAM lParam);	// CConsoleからStreamConsole向けコマンドが送られた時の独自ハンドラ.
		virtual int OnList(WPARAM wParam, LPARAM lParam);	// "list"コマンドの独自ハンドラ.
		virtual int OnView(WPARAM wParam, LPARAM lParam);	// "view"コマンドの独自ハンドラ.

};