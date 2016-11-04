// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"		// ウィンドウクラス
// リソースIDの定義.
#define IDC_WINDOW_LISTITEM WM_USER + 200

// ウィンドウリストアイテムクラス
class CWindowListItem : public CWindow {	// CWindowの派生クラス

	// publicメンバ
	public:

		// publicメンバ変数
		// メンバ変数
		int m_x;	// 位置m_x.
		int m_y;	// 位置m_y.
		int m_iWidth;	// 幅m_iWidth.
		int m_iHeight;	// 高さm_iHeight.
		TCHAR m_tszText[256];	// テキストm_tszText

		// publicメンバ関数
		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(このウィンドウ専用にカスタマイズされたもの.)
		virtual void Destroy();	// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
		virtual void SetWindowText(LPCTSTR lpctszString);	// ウィンドウにテキストをセットするメンバ関数SetWindowText.
		virtual void MoveWindow(int x, int y, int iWidth, int iHeight);	// ウィンドウのサイズや位置を変更するメンバ関数MoveWindow.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.
		virtual void OnPaint();	// 画面描画の更新を要求された時.
		virtual int OnClose();	// ウィンドウを閉じる時のハンドラOnClose.

};