// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型

// ウィンドウクラスCWindow
class CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		// メンバ変数
		HWND m_hWnd;	// HWND型ウィンドウハンドルm_hWnd
		int m_x;		// ウィンドウの位置x座標m_x
		int m_y;		// ウィンドウの位置y座標m_y
		int m_iWidth;	// ウィンドウの幅m_iWidth
		int m_iHeight;	// ウィンドウの高さm_iHeight

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CWindow();	// コンストラクタCWindow()
		~CWindow();	// デストラクタ~CWindow()

		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// ウィンドウクラス登録関数RegisterClass
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// 独自のウィンドウプロシージャStaticWindowProc.

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual BOOL ShowWindow(int nCmdShow);	// ウィンドウ表示関数ShowWindow

};