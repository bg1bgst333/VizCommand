// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "UserControl.h"	// ユーザコントロールクラス

// ウィンドウリストアイテムクラスCWindowListItem
class CWindowListItem : public CUserControl {

	// publicメンバ
	public:

		// publicメンバ変数
		HPEN m_hPen;		// ペンHPEN型m_hPen.
		HBRUSH m_hBrush;	// ブラシHBRUSH型m_hBrush.
		std::map<tstring, CWindow *> m_mapChildMap;	// アイテムの子ウィンドウマップm_mapChildMap.

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass

		// コンストラクタ・デストラクタ
		CWindowListItem();	// コンストラクタCWindowListItem()
		virtual ~CWindowListItem();	// デストラクタ~CWindowListItem()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual void Destroy();	// ウィンドウ破棄関数Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウサイズが変更された時のハンドラOnSize.
		virtual void OnPaint();	// ウィンドウの描画を要求された時のハンドラOnPaint.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ユーザ定義メッセージが発生した時のハンドラ.
		virtual void OnSizeChild(WPARAM wParam, LPARAM lParam);	// 子から親へウィンドウサイズ変更の要求が発生した時の独自ハンドラ.

};