// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "Window.h"			// ウィンドウクラス
#include "UserControl.h"	// ユーザコントロールクラス

// ベーシックウィンドウクラスCBasicWindow
class CBasicWindow : public CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		CUserControl *m_pUserControl;	// CUserControl *型ユーザコントロールオブジェクトポインタm_pUserControl

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance);	// ウィンドウクラス登録関数RegisterClass

		// コンストラクタ・デストラクタ
		CBasicWindow();	// コンストラクタCBasicWindow()
		virtual ~CBasicWindow();	// デストラクタ~CBasicWindow()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.

};