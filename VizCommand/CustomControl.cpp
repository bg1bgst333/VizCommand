// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "CustomControl.h"	// カスタムコントロールクラス

// staticメンバ変数の定義.
std::map<tstring, WNDPROC> CCustomControl::m_mapBaseWindowProcMap;	// staticメンバ変数CCustomControl::m_mapBaseWindowProcMapは宣言とは別にここに定義しないといけない.

// 独自のウィンドウプロシージャStaticWindowProc.
LRESULT CCustomControl::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ポインタの宣言
	CWindow *pWindow = NULL;	// CWindowオブジェクトポインタpWindow.

	// hwndでウィンドウオブジェクトポインタが引けたら, pWindowに格納.
	if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()) {	// findで見つかったら.
		pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindowにhwndで引けるCWindowオブジェクトポインタを代入.
	}

	// ウィンドウオブジェクト取得できない場合.
	if (pWindow == NULL) {	// pWindowがNULL.

		// 配列の宣言.
		TCHAR tszClassName[256] = { 0 };	// tszClassNameを0で初期化.

		// ウィンドウハンドルからウィンドウクラス名を取得.
		GetClassName(hwnd, tszClassName, 256);	// GetClassNameでウィンドウクラス名を取得.

		// tszClassNameがm_mapBaseWindowProcMapのキーにあれば.
		if (m_mapBaseWindowProcMap.find(tszClassName) != m_mapBaseWindowProcMap.end()) {	// みつかったら.

			// 既定のプロシージャに任せる.
			return CallWindowProc(m_mapBaseWindowProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProcでこのメッセージをm_mapBaseWindowProcMap[tszClassName]に任せる.

		}
		else {

			// そうでないなら, DefWindowProcに任せる.
			return DefWindowProc(hwnd, uMsg, wParam, lParam);

		}

	}
	else {	// pWindowがあった.

		// そのウィンドウのDynamicWindowProcに渡す.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProcに渡す.

	}

}

// コンストラクタCCustomControl()
CCustomControl::CCustomControl() : CWindow() {

}

// ウィンドウ作成関数Create
BOOL CCustomControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの位置・サイズをセット.
	m_x = x;				// m_xにxを代入.
	m_y = y;				// m_yにyを代入.
	m_iWidth = iWidth;		// m_iWidthにiWidthを代入.
	m_iHeight = iHeight;	// m_iHeight = iHeightを代入.

	// ウィンドウの作成.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, m_x, m_y, m_iWidth, m_iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindowで指定された引数を使ってウィンドウを作成.(lpctszClassNameはOS既定のウィンドウクラス, dwStyleにWS_CHILDとWS_VISIBLEを追加.)
	if (m_hWnd == NULL) {	// m_hWndがNULLなら失敗.

		// 失敗ならFALSE.
		return FALSE;	// FALSEを返す.

	}

	// OnCreateは以降呼ばれないのでここで呼んでおく.
	CREATESTRUCT cs;	// CREATESTRUCTを一応用意.
	cs.hInstance = hInstance;	// hInstanceは要るかもしれないので, これは渡せるようにしておく.
	if (OnCreate(m_hWnd, &cs) != 0) {	// OnCreateにcsを渡す.

		// ウィンドウを破棄する.
		DestroyWindow(m_hWnd);
		m_hWnd = NULL;
		return FALSE;

	}

	// 既定のウィンドウプロシージャを取得し, CCustomControl::StaticWindowProcに差し替える.
	WNDPROC lpfnWndProc;	// 既定のプロシージャlpfnWndProc.
	lpfnWndProc = (WNDPROC)GetWindowLong(m_hWnd, GWL_WNDPROC);	// GetWindowLongでプロシージャlpfnWndProcを取得.
	SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)StaticWindowProc);	// SetWindowLongでプロシージャCCustomControl::StaticWindowProcを設定.

	// マップにウィンドウクラス名がなければ登録.
	if (CCustomControl::m_mapBaseWindowProcMap.find(lpctszClassName) == CCustomControl::m_mapBaseWindowProcMap.end()) {
		CCustomControl::m_mapBaseWindowProcMap.insert(std::pair<tstring, WNDPROC>(lpctszClassName, lpfnWndProc));	// プロシージャを登録.
	}

	// WM_CREATEを通らないのでウィンドウマップの登録も行う.
	if (CWindow::m_mapWindowMap.find(m_hWnd) == CWindow::m_mapWindowMap.end()) {
		CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(m_hWnd, this));
	}

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// StaticWindowProcから各ウィンドウオブジェクトごとに呼び出されるサブウィンドウプロシージャDynamicWindowProc.
LRESULT CCustomControl::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ウィンドウメッセージ処理
	switch (uMsg) {

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// OnCreateに任せる.
				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);	// hwndとlParamをOnCreateに渡し, あとは任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// OnDestroyに任せる.
				OnDestroy();	// OnDestroyを呼ぶ.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// コマンドが処理された時.
		case WM_COMMAND:

			// WM_COMMANDブロック
			{

				// OnCommandに任せる.
				return OnCommand(wParam, lParam) ? 0 : 1;	// wParamとlParamを渡して任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// ウィンドウサイズが変更された時.
		case WM_SIZE:

			// WM_SIZEブロック
			{

				// 変数の初期化.
				UINT nType = wParam;		// nTypeをwParamで初期化.
				int cx = LOWORD(lParam);	// cxをLOWORD(lParam)で初期化.
				int cy = HIWORD(lParam);	// cyをHIWORD(lParam)で初期化.

				// OnSizeに任せる.
				OnSize(nType, cx, cy);	// OnSizeにnType, cx, cyを渡す.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// ウィンドウの描画を要求された時.
		case WM_PAINT:

			// WM_PAINTブロック
			{

				// OnPaintに任せる.
				OnPaint();	// OnPaintを呼ぶ.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// これらのメッセージはDefWindowProcに投げないと, スクロールバーが認識せず動作しない.
		case WM_NCHITTEST:
		case WM_NCLBUTTONDOWN:
		case WM_NCLBUTTONUP:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);

		// 水平方向スクロールバーイベント時.
		case WM_HSCROLL:

			// WM_HSCROLLブロック
			{

				// OnHScrollに任せる.
				OnHScroll(LOWORD(wParam), HIWORD(wParam));	// OnHScrollに任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// 垂直方向スクロールバーイベント時.
		case WM_VSCROLL:

			// WM_VSCROLLブロック
			{

				// OnVScrollに任せる.
				OnVScroll(LOWORD(wParam), HIWORD(wParam));	// OnVScrollに任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// ウィンドウを閉じた時.
		case WM_CLOSE:

			// WM_CLOSEブロック
			{

				// OnCloseに任せる.
				if (OnClose() != 0) {	// 0以外なら
					return 0;	// 0を返す.
				}

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// キーが押された時.
		case WM_KEYDOWN:

			// WM_KEYDOWNブロック
			{

				// OnKeyDownに任せる.
				OnKeyDown(wParam, LOWORD(lParam), HIWORD(lParam));	// OnKeyDownに任せる.

			}
				
			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

	// 配列の宣言.
	TCHAR tszClassName[256] = { 0 };	// tszClassNameを0で初期化.

	// ウィンドウハンドルからウィンドウクラス名を取得.
	GetClassName(hwnd, tszClassName, 256);	// GetClassNameでウィンドウクラス名を取得.

	// tszClassNameがm_mapBaseWindowProcMapのキーにあれば.
	if (m_mapBaseWindowProcMap.find(tszClassName) != m_mapBaseWindowProcMap.end()) {	// みつかったら.

		// 既定のプロシージャに任せる.
		return CallWindowProc(m_mapBaseWindowProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProcでこのメッセージをm_mapBaseWindowProcMap[tszClassName]に任せる.

	}
	else {

		// そうでないなら, DefWindowProcに任せる.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);

	}

}

// ウィンドウ破棄時のハンドラOnDestroy.
void CCustomControl::OnDestroy() {

}