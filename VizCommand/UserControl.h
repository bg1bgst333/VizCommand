// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "Window.h"	// ウィンドウクラス

// ユーザコントロールクラスCUserControl
class CUserControl : public CWindow {

	// publicメンバ
	public:

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// ウィンドウクラス登録関数RegisterClass(ウィンドウクラス名指定)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, HBRUSH hBrush);	// ウィンドウクラス登録関数RegisterClass(背景ブラシ指定)

		// コンストラクタ・デストラクタ
		CUserControl();	// コンストラクタCUserControl()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.

};
