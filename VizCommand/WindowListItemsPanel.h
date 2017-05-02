// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 既定のヘッダ
#include <list>	// std::list
// 独自のヘッダ
#include "UserControl.h"	// ユーザコントロールクラス
#include "WindowListItem.h"	// ウィンドウリストアイテムクラス
#include "resource.h"			// リソース

// ウィンドウリストアイテムズパネルクラスCWindowListItemsPanel
class CWindowListItemsPanel : public CUserControl {

	// publicメンバ
	public:

		// publicメンバ変数
		HPEN m_hPen;		// ペンHPEN型m_hPen.
		HBRUSH m_hBrush;	// ブラシHBRUSH型m_hBrush.
		std::list<CWindowListItem *> m_lstWindowList;	// ウィンドウリストm_vecWindowList.
		int m_nId;	// ウィンドウリストアイテムのリソースID, int型m_nId.

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass

		// コンストラクタ・デストラクタ
		CWindowListItemsPanel();	// コンストラクタCWindowListItemsPanel()
		virtual ~CWindowListItemsPanel();	// デストラクタ~CWindowListItemsPanel()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual void Destroy();	// ウィンドウ破棄関数Destroy
		virtual BOOL Insert(LPCTSTR lpctszWindowName, int iIndex, int iHeight, HINSTANCE hInstance);	// アイテム挿入関数Insert
		virtual BOOL Remove(int iIndex);	// アイテム削除関数Remove
		virtual CWindowListItem *Get(int iIndex);	// アイテム取得関数Get
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウサイズが変更された時のハンドラOnSize.
		virtual void OnPaint();	// ウィンドウの描画を要求された時のハンドラOnPaint.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ユーザ定義メッセージが発生した時のハンドラ.
		virtual void OnSizeChild(WPARAM wParam, LPARAM lParam);	// 子から親へウィンドウサイズ変更の要求が発生した時の独自ハンドラ.

};