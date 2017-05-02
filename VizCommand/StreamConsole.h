// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "UserControl.h"	// ユーザコントロールクラス
#include "WindowListControl.h"	// ウィンドウリストコントロールクラス

// ストリームコンソールクラスCStreamConsole
class CStreamConsole : public CWindowListControl {

	// publicメンバ
	public:

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass

		// コンストラクタ・デストラクタ
		CStreamConsole();	// コンストラクタCStreamConsole
		virtual ~CStreamConsole();	// デストラクタ~CStreamConsole()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.

};