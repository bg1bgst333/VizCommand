// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "BasicWindow.h"	// ベーシックウィンドウクラス
#include "CustomControl.h"	// カスタムコントロールクラス
#include "UserControl.h"	// ユーザコントロールクラス

// メインウィンドウクラスCMainWindow
class CMainWindow : public CBasicWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		CUserControl *m_pUserControl;		// CUserControl *型ユーザコントロールオブジェクトポインタm_pUserControl
		CCustomControl *m_pCustomControl;	// CCustomControl *型カスタムコントロールオブジェクトポインタm_pCustomControl

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass

		// コンストラクタ・デストラクタ
		CMainWindow();			// コンストラクタCMainWindow()
		virtual ~CMainWindow();	// デストラクタ~CMainWindow()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.

};