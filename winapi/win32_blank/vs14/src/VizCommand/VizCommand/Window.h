// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止

// ヘッダのインクルード
// 既定のヘッダ
#include <windows.h>	// 標準WindowsAPI
#include <tchar.h>		// TCHAR型
#include <map>			// std::map

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
		static std::map<HWND, CWindow *> m_mapWindowMap;	// ウィンドウハンドルからウィンドウオブジェクトを引くマップm_mapWindowMap.
		static std::map<tstring, WNDPROC> m_mapBaseWndProcMap;	// 既定のウィンドウクラス名から既定のウィンドウプロシージャを引くマップm_mapBaseWndProcMap.

		// メンバ変数
		HWND m_hWnd;	// HWND型ウィンドウハンドルm_hWnd

		// publicメンバ関数
		// staticメンバ関数
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName = _T("CWindow"));	// ウィンドウクラス登録関数RegisterClass
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// 独自のウィンドウプロシージャStaticWindowProc.

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(CW_USEDEFAULT可)
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, BOOL bProcChange);	// ウィンドウ作成関数Create(既存のウィンドウクラスのウィンドウプロシージャを差し替える場合.)
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(RECT指定)
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, HINSTANCE hInstance);	// ウィンドウ作成関数Create(省略版)
		virtual BOOL ShowWindow(int nCmdShow);	// ウィンドウ表示関数ShowWindow
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// WindowProcから各ウィンドウオブジェクトごとに呼び出されるサブウィンドウプロシージャDynamicWindowProc
		virtual void Destroy() = 0;	// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.(純粋仮想関数)
		virtual void SetWindowText(LPCTSTR lpctszString);	// ウィンドウにテキストをセットするメンバ関数SetWindowText.
		virtual void MoveWindow(int x, int y, int iWidth, int iHeight);	// ウィンドウのサイズや位置を変更するメンバ関数MoveWindow.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) = 0;	// ウィンドウ作成時のハンドラOnCreate.(純粋仮想関数)
		virtual void OnDestroy() = 0;	// ウィンドウ破棄時のハンドラOnDestroy.(純粋仮想関数)
		virtual void OnMove(int x, int y);	// ウィンドウが移動された時のハンドラOnMove.
		virtual void OnSize(UINT nType, int cx, int cy);	// ウィンドウのサイズが変更された時のハンドラOnSize.
		virtual void OnPaint();	// 画面描画の更新を要求された時.
		virtual int OnClose() = 0;		// ウィンドウを閉じる時のハンドラOnClose.(純粋仮想関数)
		virtual int OnKeyDown(WPARAM wParam, LPARAM lParam);	// キーが押された時.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// コマンド処理時のハンドラOnCommand.
		virtual void OnVScroll(UINT nSBCode, UINT nPos, HWND hScroll);	// 垂直スクロール時のハンドラOnVScroll.

};