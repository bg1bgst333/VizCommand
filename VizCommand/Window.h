// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <map>			// std::map

// マクロの定義
// UNICODE切り替え
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// ウィンドウクラスCWindow
class CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		// staticメンバ変数
		static std::map<HWND, CWindow *> m_mapWindowMap;	// ウィンドウハンドルからCWindowオブジェクトポインタを引くマップm_mapWindowMap.

		// メンバ変数
		HWND m_hWnd;	// HWND型ウィンドウハンドルm_hWnd
		int m_x;		// ウィンドウの位置x座標m_x
		int m_y;		// ウィンドウの位置y座標m_y
		int m_iWidth;	// ウィンドウの幅m_iWidth
		int m_iHeight;	// ウィンドウの高さm_iHeight

		// publicメンバ関数
		// コンストラクタ・デストラクタ
		CWindow();	// コンストラクタCWindow()
		virtual ~CWindow();	// デストラクタ~CWindow()

		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// ウィンドウクラス登録関数RegisterClass
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, UINT nID);	// ウィンドウクラス登録関数RegisterClass(メニュー指定)
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// 独自のウィンドウプロシージャStaticWindowProc.

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)
		virtual BOOL ShowWindow(int nCmdShow);	// ウィンドウ表示関数ShowWindow
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// StaticWindowProcから各ウィンドウオブジェクトごとに呼び出されるサブウィンドウプロシージャDynamicWindowProc.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// ウィンドウ作成時のハンドラOnCreate.
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// コマンド処理時のハンドラOnCommand.

};