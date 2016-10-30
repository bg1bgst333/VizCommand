// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"		// ウィンドウクラス
// リソースIDの定義.
#define IDC_WINDOW_LISTVIEW WM_USER + 100

// ウィンドウリストビュークラス
class CWindowListView : public CWindow {	// CWindowの派生クラス

	// publicメンバ
	public:

		// publicメンバ関数
		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(このウィンドウ専用にカスタマイズされたもの.)
		virtual void Destroy();	// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.
		virtual int OnClose();	// ウィンドウを閉じる時のハンドラOnClose.

};