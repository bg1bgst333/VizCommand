// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "Window.h"	// ウィンドウクラス

// カスタムコントロールクラスCCustomControl
class CCustomControl : public CWindow {

	// publicメンバ
	public:

		// publicメンバ変数
		// staticメンバ変数
		static std::map<tstring, WNDPROC> m_mapBaseWindowProcMap;	// 既定のウィンドウクラス名から既定のウィンドウプロシージャを引くマップm_mapBaseWindowProcMap.

		// publicメンバ関数
		// staticメンバ関数
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// 独自のウィンドウプロシージャStaticWindowProc.

		// コンストラクタ・デストラクタ
		CCustomControl();	// コンストラクタCCustomControl()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// StaticWindowProcから各ウィンドウオブジェクトごとに呼び出されるサブウィンドウプロシージャDynamicWindowProc.
		virtual void OnDestroy();	// ウィンドウ破棄時のハンドラOnDestroy.

};
