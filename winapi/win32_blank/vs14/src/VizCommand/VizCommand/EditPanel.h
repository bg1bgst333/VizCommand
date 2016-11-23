// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"		// ウィンドウクラス
#include "Edit.h"		// エディットクラス

// リソースIDの定義.
#define IDC_EDIT_PANEL WM_APP + 400

// エディットパネルクラス
class CEditPanel : public CWindow {	// CWindowの派生クラス

	// publicメンバ
	public:

		// メンバ変数
		CEdit *m_pEdit;	// CEditオブジェクトポインタm_pEdit
		int m_x;	// 位置m_x.
		int m_y;	// 位置m_y.
		int m_iWidth;	// 幅m_iWidth.
		int m_iHeight;	// 高さm_iHeight.
		HMENU m_nID;	// リソースID m_nID.

		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(このウィンドウ専用にカスタマイズされたもの.)
		virtual void Destroy();	// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時のハンドラOnSize.
		virtual int OnClose();	// ウィンドウを閉じる時のハンドラOnClose.

};