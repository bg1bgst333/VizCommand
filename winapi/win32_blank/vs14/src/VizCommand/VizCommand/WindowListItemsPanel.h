// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 既定のヘッダ
#include <vector>	// std::vector
// 独自のヘッダ
#include "Window.h"		// ウィンドウクラス
#include "WindowListItem.h"	// ウィンドウリストアイテムクラス

// リソースIDの定義.
#define IDC_WINDOW_LIST_ITEMS_PANEL WM_USER + 200

// ウィンドウリストアイテムズパネルクラス
class CWindowListItemsPanel : public CWindow {	// CWindowの派生クラス

	// publicメンバ
	public:

		// publicメンバ変数
		// メンバ変数
		std::vector<CWindowListItem *> m_vecpWindowList;	// ウィンドウリストm_vecpWindowList.
		int m_x;	// 位置m_x.
		int m_y;	// 位置m_y.
		int m_iWidth;	// 幅m_iWidth.
		int m_iHeight;	// 高さm_iHeight.

		// publicメンバ関数
		// メンバ関数
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(このウィンドウ専用にカスタマイズされたもの.)
		virtual void Destroy();	// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
		virtual BOOL Insert(int index, int height, HINSTANCE hInstance);	// ウィンドウリストアイテムを挿入するメンバ関数Insert.
		virtual void Delete(int index);	// ウィンドウリストアイテムを削除するメンバ関数Delete.
		virtual CWindowListItem * Get(int index);	// ウィンドウリストアイテムを取得するメンバ関数Get.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.
		virtual void OnMove(int x, int y);	// ウィンドウが移動された時のハンドラOnMove.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時のハンドラOnSize.
		virtual void OnPaint();	// 画面描画の更新を要求された時.
		virtual int OnClose();	// ウィンドウを閉じる時のハンドラOnClose.

};