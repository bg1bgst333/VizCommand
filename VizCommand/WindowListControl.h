// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "UserControl.h"	// ユーザコントロールクラス
#include "WindowListItemsPanel.h"	// ウィンドウリストアイテムズパネルクラス
#include "resource.h"			// リソース

// ウィンドウリストコントロールクラスCWindowListControl
class CWindowListControl : public CUserControl {

	// publicメンバ
	public:

		// publicメンバ変数
		HPEN m_hPen;		// ペンHPEN型m_hPen.
		HBRUSH m_hBrush;	// ブラシHBRUSH型m_hBrush.
		CWindowListItemsPanel *m_pWindowListItemsPanel;	// CWindowListItemsPanel *型ウィンドウリストアイテムズパネルオブジェクトポインタm_pWindowListItemsPanel
		SCROLLINFO m_ScrollInfo;	// スクロール情報m_ScrollInfo.

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass

		// コンストラクタ・デストラクタ
		CWindowListControl();	// コンストラクタCWindowListControl()
		virtual ~CWindowListControl();	// デストラクタ~CWindowListControl()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual void Destroy();	// ウィンドウ破棄関数Destroy
		virtual BOOL Insert(LPCTSTR lpctszWindowName, int iIndex, int iHeight, HINSTANCE hInstance);	// アイテム挿入関数Insert
		virtual BOOL Remove(int iIndex);	// アイテム削除関数Remove
		virtual CWindowListItem *Get(int iIndex);	// アイテム取得関数Get
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnPaint();	// ウィンドウの描画を要求された時のハンドラOnPaint.
		virtual void OnHScroll(UINT nSBCode, UINT nPos);	// 水平方向スクロールバーイベント時のハンドラOnHScroll.
		virtual void OnVScroll(UINT nSBCode, UINT nPos);	// 垂直方向スクロールバーイベント時のハンドラOnVScroll.

};