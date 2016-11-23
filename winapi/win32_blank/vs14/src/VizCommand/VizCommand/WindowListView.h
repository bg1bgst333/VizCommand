// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"		// ウィンドウクラス
#include "WindowListItemsPanel.h"	// ウィンドウリストアイテムズパネルクラス

// リソースIDの定義.
#define IDC_WINDOW_LIST_VIEW WM_APP + 100

// ウィンドウリストビュークラス
class CWindowListView : public CWindow {	// CWindowの派生クラス

	// publicメンバ
	public:

		// publicメンバ変数
		// メンバ変数
		CWindowListItemsPanel *m_pWindowListItemsPanel;	// アイテムズパネル.

		// publicメンバ関数
		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(このウィンドウ専用にカスタマイズされたもの.)
		virtual void Destroy();	// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
		virtual BOOL Insert(int index, int height, HINSTANCE hInstance);	// ウィンドウリストアイテムを挿入するメンバ関数Insert.
		virtual void Delete(int index);	// ウィンドウリストアイテムを削除するメンバ関数Delete.
		virtual CWindowListItem * Get(int index);	// ウィンドウリストアイテムを取得するメンバ関数Get.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時のハンドラOnSize.
		virtual int OnClose();	// ウィンドウを閉じる時のハンドラOnClose.
		virtual void OnVScroll(UINT nSBCode, UINT nPos, HWND hScroll);	// 垂直スクロール時のハンドラOnVScroll.

};