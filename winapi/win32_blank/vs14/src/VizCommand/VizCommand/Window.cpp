// ヘッダのインクルード
#include "Window.h"		// ウィンドウクラス

// staticメンバ変数の定義.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// staticメンバ変数CWindow::m_mapWindowMapは宣言と別にここに定義しないといけない.
std::map<tstring, WNDPROC> CWindow::m_mapBaseWndProcMap;		// staticメンバ変数CWindow::m_mapBaseWndProcMapは宣言とは別にここに定義しないといけない.

// ウィンドウクラス登録関数RegisterClass.
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName) {

	// 変数の宣言
	WNDCLASS wc;	// ウィンドウクラスwc

	// ウィンドウクラスの設定
	wc.lpszClassName = lpctszClassName;						// ウィンドウクラス名にはlpctszClassNameを指定.
	wc.style = CS_HREDRAW | CS_VREDRAW;						// とりあえずCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = StaticWindowProc;						// 独自に定義したウィンドウプロシージャStaticWindowProc.
	wc.hInstance = hInstance;								// WinMainの引数のインスタンスハンドルhInstanceを指定.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アプリケーション既定アイコンIDI_APPLICATION.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);			// システム既定の矢印カーソルIDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白(WHITE_BRUSH).
	wc.lpszMenuName = NULL;									// とりあえずNULL.
	wc.cbClsExtra = 0;										// とりあえず0でいい.
	wc.cbWndExtra = 0;										// とりあえず0でいい.

	// ウィンドウクラスの登録
	if (!::RegisterClass(&wc)) {	// RegisterClassにwcをセットして登録.

		// エラー処理
		return FALSE;	// 失敗なのでFALSEを返す.

	}

	// 成功ならTRUE.
	return TRUE;	// 成功なのでTRUEを返す.

}

// 独自のウィンドウプロシージャStaticWindowProc関数
LRESULT CALLBACK CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ポインタの宣言
	CWindow *pWindow = NULL;	// CWindowオブジェクトポインタpWindow.

	// ウィンドウメッセージ処理
	switch (uMsg) {	// uMsgごとに振り分ける.

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ポインタの初期化
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCT構造体へのポインタlpCreateStructをNULL.

				// lParamからlpCreateStructを取り出す.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParamを(LPCREATESTRUCT)にキャスト.
				if (lpCreateStruct->lpCreateParams != NULL) {	// NULLでなければ.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParamsは(CWindow *)にキャストしpWindowに入れる.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// CWindow::m_mapWindowMapにhwndとpWindowのペアを登録.
				}

			}

			// 既定処理へ.
			break;	// breakで抜ける.

		// それ以外.
		default:

			// defaultブロック
			{

				// hwndでウィンドウオブジェクトポインタが引けたら, pWindowに格納.
				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()) {	// findで見つかったら.
					pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindowにhwndで引けるCWindowオブジェクトポインタを代入.
				}

			}

			// 既定処理へ.
			break;	// breakで抜ける.

	}

	// ウィンドウオブジェクト取得できない場合.
	if (pWindow == NULL) {	// pWindowがNULL.

		// 配列の宣言.
		TCHAR tszClassName[256] = { 0 };	// tszClassNameを0で初期化.

		// ウィンドウハンドルからウィンドウクラス名を取得.
		GetClassName(hwnd, tszClassName, 256);	// GetClassNameでウィンドウクラス名を取得.

		// tszClassNameがm_mapBaseWndProcMapのキーにあれば.
		if (m_mapBaseWndProcMap.find(tszClassName) != m_mapBaseWndProcMap.end()) {	// みつかったら.

			// 既定ののプロシージャに任せる.
			return CallWindowProc(m_mapBaseWndProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProcでこのメッセージをm_mapBaseWndProcMap[tszClassName]に任せる.

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

// ウィンドウ作成関数Create(CW_USEDEFAULT可)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウの作成.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindowで指定された引数を使ってウィンドウを作成.
	if (m_hWnd == NULL) {	// m_hWndがNULLなら失敗.

		// 失敗ならFALSE.
		return FALSE;	// FALSEを返す.

	}

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// ウィンドウ作成関数Create(既存のウィンドウクラスのウィンドウプロシージャを差し替える場合.)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, BOOL bProcChange){
	
	// ウィンドウの作成.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindowで指定された引数を使ってウィンドウを作成.
	if (m_hWnd == NULL) {	// m_hWndがNULLなら失敗.

		// 失敗ならFALSE.
		return FALSE;	// FALSEを返す.

	}

	// プロシージャを差し替える場合.
	if (bProcChange) {	// bProcChangeがTRUEなら.

		// OnCreateは以降呼ばれないのでここで呼んでおく.
		CREATESTRUCT cs;	// CREATESTRUCTを一応用意.
		cs.hInstance = hInstance;	// hInstanceは要るかもしれないので, これは渡せるようにしておく.
		if (OnCreate(m_hWnd, &cs) != 0) {	// OnCreateにcsを渡す.

			// ウィンドウを破棄する.
			DestroyWindow(m_hWnd);
			m_hWnd = NULL;
			return FALSE;

		}

		// 既定のウィンドウプロシージャを取得し, StaticWindowProcに差し替える.
		WNDPROC lpfnWndProc;	// 既定のプロシージャlpfnWndProc.
		lpfnWndProc = (WNDPROC)GetWindowLong(m_hWnd, GWL_WNDPROC);	// GetWindowLongでプロシージャlpfnWndProc取得.
		SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)StaticWindowProc);	// SetWindowLongでプロシージャStaticWindowProc設定.

		// マップにウィンドウクラス名がなければ登録.
		if (m_mapBaseWndProcMap.find(lpctszClassName) == m_mapBaseWndProcMap.end()) {
			m_mapBaseWndProcMap.insert(std::pair<tstring, WNDPROC>(lpctszClassName, lpfnWndProc));	// プロシージャを登録.
		}

		// WM_CREATEを通らないのでウィンドウマップの登録も行う.
		if (CWindow::m_mapWindowMap.find(m_hWnd) == CWindow::m_mapWindowMap.end()) {
			CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(m_hWnd, this));
		}

	}

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// ウィンドウ作成関数Create(RECT指定)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// ウィンドウの作成.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, hWndParent, hMenu, hInstance, this);	// CreateWindowで指定された引数を使ってウィンドウを作成.
	if (m_hWnd == NULL) {	// m_hWndがNULLなら失敗.

		// 失敗ならFALSE.
		return FALSE;	// FALSEを返す.

	}

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// ウィンドウ作成関数Create(省略版)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, HINSTANCE hInstance){

	// ウィンドウ作成
	return CWindow::Create(lpctszClassName, lpctszWindowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance);	// CWindow::Create(CW_USEDEFAULT可)でウィンドウ作成.

}

// ウィンドウ表示関数ShowWindow.
BOOL CWindow::ShowWindow(int nCmdShow) {

	// ウィンドウの表示
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPIのShowWindowでm_hWndを表示.

}

// StaticWindowProcから各ウィンドウオブジェクトごとに呼び出されるサブウィンドウプロシージャDynamicWindowProc.
LRESULT CWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ウィンドウメッセージ処理
	switch (uMsg) {

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// OnCreateに任せる.
				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);	// hwndとlParamをOnCreateに渡してあとは任せる.

			}

			// 既定の処理へ向かう.
			break;

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// OnDestroyに任せる.
				OnDestroy();	// OnDestroyを呼ぶ.

			}

			// 既定の処理へ向かう.
			break;

		// ウィンドウが移動された時.
		case WM_MOVE:

			// WM_MOVEブロック
			{

				// OnMoveに任せる.
				OnMove(LOWORD(lParam), HIWORD(lParam));

			}

			// 既定の処理へ向かう.
			break;

		// ウィンドウのサイズが変更された時.
		case WM_SIZE:
			
			// WM_SIZEブロック
			{

				// 変数の宣言
				UINT nType;	// サイズ変更のタイプ
				int cx;	// 変更後の幅
				int cy;	// 変更後の高さ

				// 値の取出し.
				nType = wParam;	// nTypeにwParamをセット.
				cx = LOWORD(lParam);	// cxにlParamの下位ワードをセット.
				cy = HIWORD(lParam);	// cyにlParamの上位ワードをセット.

				// OnSizeに任せる.
				OnSize(nType, cx, cy);	// OnSizeを呼ぶ.

			}

			// 既定の処理へ向かう.
			break;

		// 画面描画の更新を要求された時.
		case WM_PAINT:

			// WM_PAINTブロック
			{

				// OnPaintに任せる.
				OnPaint();

			}

			// 既定の処理へ向かう.
			break;

		// ウィンドウが閉じられたとき.
		case WM_CLOSE:

			// WM_CLOSEブロック
			{

				// OnCloseに任せる.
				if (OnClose() != 0) {	// 0以外なら
					return 0;	// 0を返す.
				}

			}

			// 既定の処理へ向かう.
			break;

		// キーが押された時.
		case WM_KEYDOWN:

			// WM_KEYDOWNブロック
			{

				// OnKeyDownに任せる.	
				return OnKeyDown(wParam, lParam);

			}

			// 既定の処理へ向かう.
			break;

		// コマンド処理された時.
		case WM_COMMAND:

			// WM_COMMANDブロック
			{

				// OnCommandに任せる.
				return OnCommand(wParam, lParam) ? 0 : 1;	// wParamとlParamを渡して任せる.

			}

			// 既定の処理へ向かう.
			break;
		
		// スクロールされた時.
		case WM_VSCROLL:

			// WM_VSCROLLブロック
			{

				// 変数の宣言.
				UINT nSBCode;
				UINT nPos;
				HWND hScroll;

				// 取出し.
				nSBCode = LOWORD(wParam);
				nPos = HIWORD(wParam);
				hScroll = (HWND)lParam;

				// OnVScrollに任せる.
				OnVScroll(nSBCode, nPos, hScroll);

			}

			// 既定の処理へ向かう.
			break;

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;

	}

	// 配列の宣言.
	TCHAR tszClassName[256] = { 0 };	// tszClassNameを0で初期化.

	// ウィンドウハンドルからウィンドウクラス名を取得.
	GetClassName(hwnd, tszClassName, 256);	// GetClassNameでウィンドウクラス名を取得.

	// tszClassNameがm_mapBaseWndProcMapのキーにあれば.
	if (m_mapBaseWndProcMap.find(tszClassName) != m_mapBaseWndProcMap.end()) {	// みつかったら.

		// 既定ののプロシージャに任せる.
		return CallWindowProc(m_mapBaseWndProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProcでこのメッセージをm_mapBaseWndProcMap[tszClassName]に任せる.

	}
	else {

		// そうでないなら, DefWindowProcに任せる.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);

	}

}

// ウィンドウにテキストをセットするメンバ関数SetWindowText.
void CWindow::SetWindowText(LPCTSTR lpctszString){

}

// ウィンドウのサイズや位置を変更するメンバ関数MoveWindow.
void CWindow::MoveWindow(int x, int y, int iWidth, int iHeight){

}

// ウィンドウが移動された時のハンドラOnMove.
void CWindow::OnMove(int x, int y){

}

// ウィンドウのサイズが変更された時のハンドラOnSize.
void CWindow::OnSize(UINT nType, int cx, int cy){

}

// 画面描画の更新を要求された時.
void CWindow::OnPaint(){

}

// キーが押された時.
int CWindow::OnKeyDown(WPARAM wParam, LPARAM lParam){

	return 0;

}

// コマンド処理時のハンドラOnCommand.
BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam) {

	// FALSEを返す.
	return FALSE;	// FALSEを返す.

}

// 垂直スクロール時のハンドラOnVScroll.
void CWindow::OnVScroll(UINT nSBCode, UINT nPos, HWND hScroll){

}