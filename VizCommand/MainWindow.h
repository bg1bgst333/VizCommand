// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "BasicWindow.h"		// ベーシックウィンドウクラス
#include "WindowListControl.h"	// ウィンドウリストコントロールクラス
#include "EditBoxPanel.h"		// エディットボックスパネルクラス
#include "ScalableEditBox.h"	// スカラブルエディットボックスクラス
#include "resource.h"			// リソース

// メインウィンドウクラスCMainWindow
class CMainWindow : public CBasicWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		CWindowListControl *m_pWindowListControl;	// CWindowListControl *型ウィンドウリストコントロールオブジェクトポインタm_pWindowListControl
		CScalableEditBox *m_pScalableEditBox;	// CScalableEditBox *型スカラブルエディットボックスオブジェクトポインタm_pScalableEditBox

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, HBRUSH hBrush);	// ウィンドウクラス登録関数RegisterClass(背景ブラシ指定)

		// コンストラクタ・デストラクタ
		CMainWindow();			// コンストラクタCMainWindow()
		virtual ~CMainWindow();	// デストラクタ~CMainWindow()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)
		virtual void Destroy();	// ウィンドウ破棄関数Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウサイズが変更された時のハンドラOnSize.

};