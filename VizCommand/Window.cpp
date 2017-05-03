// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// ウィンドウクラス

// staticメンバ変数の定義.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// staticメンバ変数CWindow::m_mapWindowMapは宣言とは別にここに定義しないといけない.

// コンストラクタCWindow()
CWindow::CWindow(){

	// メンバ変数の初期化
	m_hWnd = NULL;	// m_hWndをNULLで初期化.
	m_x = 0;		// m_xを0で初期化.
	m_y = 0;		// m_yを0で初期化.
	m_iWidth = 0;	// m_iWidthを0で初期化.
	m_iHeight = 0;	// m_iHeightを0で初期化.

}

// デストラクタ~CWindow()
CWindow::~CWindow() {

	// メンバ変数の終了処理
	Destroy();		// Destroyでウィンドウを破棄.
	m_x = 0;		// m_xに0を代入.
	m_y = 0;		// m_yに0を代入.
	m_iWidth = 0;	// m_iWidthに0を代入.
	m_iHeight = 0;	// m_iHeightに0を代入.

}

// ウィンドウクラス登録関数RegisterClass
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName) {

	// 変数の宣言
	WNDCLASS wc;	// ウィンドウクラスwc

	// ウィンドウクラスの設定
	wc.lpszClassName = lpctszClassName;						// ウィンドウクラス名はlpctszClassName.
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはとりあえずCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = StaticWindowProc;						// ウィンドウプロシージャにStaticWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは引数のhInstanceをセット.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アプリケーション既定アイコンIDI_APPLICATION.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);			// システム既定の矢印カーソルIDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白(WHITE_BRUSH).
	wc.lpszMenuName = NULL;									// とりあえず現時点ではNULL.
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

// ウィンドウクラス登録関数RegisterClass(メニュー指定)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, UINT nID) {

	// 変数の宣言
	WNDCLASS wc;	// ウィンドウクラスwc

	// ウィンドウクラスの設定
	wc.lpszClassName = lpctszClassName;						// ウィンドウクラス名はlpctszClassName.
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはとりあえずCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = StaticWindowProc;						// ウィンドウプロシージャにStaticWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは引数のhInstanceをセット.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アプリケーション既定アイコンIDI_APPLICATION.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);			// システム既定の矢印カーソルIDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// 背景は白(WHITE_BRUSH).
	wc.lpszMenuName = MAKEINTRESOURCE(nID);					// メニューにはnIDをMAKEINTRESOURCEで変換したもの.
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

// ウィンドウクラス登録関数RegisterClass(背景ブラシ指定)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, HBRUSH hBrush) {

	// 変数の宣言
	WNDCLASS wc;	// ウィンドウクラスwc

	// ウィンドウクラスの設定
	wc.lpszClassName = lpctszClassName;						// ウィンドウクラス名はlpctszClassName.
	wc.style = CS_HREDRAW | CS_VREDRAW;						// スタイルはとりあえずCS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = StaticWindowProc;						// ウィンドウプロシージャにStaticWindowProc.
	wc.hInstance = hInstance;								// インスタンスハンドルは引数のhInstanceをセット.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// アプリケーション既定アイコンIDI_APPLICATION.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);			// システム既定の矢印カーソルIDC_ARROW.
	wc.hbrBackground = hBrush;								// 背景は引数のhBrushを指定.
	wc.lpszMenuName = NULL;									// とりあえず現時点ではNULL.
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
LRESULT CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// ポインタの初期化
	CWindow *pWindow = NULL;	// CWindowオブジェクトポインタpWIndowをNULLに初期化.

	// ウィンドウメッセージ処理
	switch (uMsg) {

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ポインタの初期化
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCT構造体へのポインタlpCreateStructをNULL.
				// lParamからlpCreateStructを取り出す.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParamをLPCREATESTRUCT型にキャストしてlpCreateStructに格納.
				if (lpCreateStruct != NULL) {	// lpCreateStructがNULLでなければ.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParamsはCWindow *型にキャストし, pWindowに格納.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// CWindow::m_mapWindowMapにhwndとpWindowのペアを登録.
				}

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外の時.
		default:

			// defaultブロック
			{

				// hwndでCWindowオブジェクトポインタが引けたら, pWindowに格納.
				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()) {	// findでキーをhwndとするCWindowオブジェクトポインタが見つかったら.
					pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindowにhwndで引けるCWindowオブジェクトポインタを格納.
				}

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

	// CWindowオブジェクトポインタが取得できなかった場合, 取得できた場合で分ける.
	if (pWindow == NULL) {	// pWindowがNULL

		// DefWindowProcに任せる.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcにそのまま引数を渡して, その値を戻り値とする.

	}
	else {	// pWindowがNULLでない.

		// そのCWindowオブジェクトのDynamicWindowProcに渡す.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProcにそのまま引数を渡して, その値を戻り値とする.

	}

}

// ウィンドウ作成関数Create
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの位置・サイズをセット.
	m_x = x;				// m_xにxを代入.
	m_y = y;				// m_yにyを代入.
	m_iWidth = iWidth;		// m_iWidthにiWidthを代入.
	m_iHeight = iHeight;	// m_iHeight = iHeightを代入.

	// ウィンドウの作成.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, m_x, m_y, m_iWidth, m_iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindowで指定された引数を使ってウィンドウを作成.
	if (m_hWnd == NULL) {	// m_hWndがNULLなら失敗.

		// 失敗ならFALSE.
		return FALSE;	// FALSEを返す.

	}

	// 成功ならTRUE.
	return TRUE;	// TRUEを返す.

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ここに来る場合はウィンドウクラス"Window"のウィンドウとして作成.
	return Create(_T("Window"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// ウィンドウクラスを"Window"にしてCreateのフルバージョンを呼ぶ.

}

// ウィンドウ破棄関数Destroy
void CWindow::Destroy() {

	// メンバ変数の終了処理
	if (m_hWnd != NULL) {	// m_hWndがNULLでなければ.
		DestroyWindow(m_hWnd);	// m_hWndを破棄.
		m_hWnd = NULL;	// m_hWndにNULLを代入.
	}

}

// ウィンドウ表示関数ShowWindow
BOOL CWindow::ShowWindow(int nCmdShow) {

	// ウィンドウの表示
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPIのShowWindowでm_hWndを表示.

}

// 位置とサイズを変更する関数MoveWindow.
BOOL CWindow::MoveWindow(int x, int y, int iWidth, int iHeight) {

	// エディットボックスのサイズを変更する.
	m_x = x;				// m_xにxをセット.
	m_y = y;				// m_yにyをセット.
	m_iWidth = iWidth;		// m_iWidthにiWidthをセット.
	m_iHeight = iHeight;	// m_iHeightにiHeightをセット.	
	return ::MoveWindow(m_hWnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);	// WindowsAPIのMoveWindowで位置とサイズを変更.

}

// 相対座標リサイズor移動関数MoveWindow.
BOOL CWindow::MoveWindow(BOOL bResize, int iRelativeHorizontal, int iRelativeVertical) {

	// リサイズか移動かを決定.
	if (bResize) {	// リサイズ
		m_iWidth = m_iWidth + iRelativeHorizontal;	// 幅の増加.
		m_iHeight = m_iHeight + iRelativeVertical;	// 高さの増加.
	}
	else {	// 移動.
		m_x = m_x + iRelativeHorizontal;	// 右に移動.
		m_y = m_y + iRelativeVertical;		// 下に移動.
	}
	return ::MoveWindow(m_hWnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);	// WindowsAPIのMoveWindowで位置とサイズを変更.

}

// 絶対座標で指定(xywhのどれか.)の値だけ変更する関数MoveWindow.
BOOL CWindow::MoveWindow(int xywh, int value) {

	// xywhのどれかを決定.
	if (xywh == 0) {	// x
		m_x = value;
	}
	else if (xywh == 1) {	// y
		m_y = value;
	}
	else if (xywh == 2) {	// w
		m_iWidth = value;
	}
	else if (xywh == 3) {	// h
		m_iHeight = value;
	}
	return ::MoveWindow(m_hWnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);	// WindowsAPIのMoveWindowで位置とサイズを変更.

}

// ウィンドウ名の長さ取得関数GetWindowTextLength.
int CWindow::GetWindowTextLength() {

	// ウィンドウ名の長さを取得.
	return ::GetWindowTextLength(m_hWnd);	// WindowsAPIのGetWindowTextLengthでm_hWndのウィンドウ名の長さを取得し, returnで戻り値として返す.

}

// ウィンドウ名取得関数GetWindowText.
int CWindow::GetWindowText(LPTSTR lpszStringBuf, int nMaxCount) {

	// ウィンドウ名を取得.
	return ::GetWindowText(m_hWnd, lpszStringBuf, nMaxCount);	// WindowsAPIのGetWindowTextでm_hWndのウィンドウ名を取得し, returnで戻り値として返す.

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
				if (OnKeyDown(wParam, LOWORD(lParam), HIWORD(lParam)) == -1) {	// -1の時は入力をキャンセル.

					// 入力キャンセル.
					return 0;	// 0をここで返すと入力キャンセルとなる.

				}

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// 文字キーが押された時.
		case WM_CHAR:

			// WM_CHARブロック
			{

				// OnCharに任せる.
				if (OnChar(wParam, LOWORD(lParam), HIWORD(lParam)) == -1) {	// -1の時は入力をキャンセル.

					// 入力キャンセル.
					return 0;	// 0をここで返すと入力キャンセルとなる.

				}

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// マウス左ボタンが離された時.
		case WM_LBUTTONUP:

			// WM_LBUTTONUPブロック
			{

				// 変数の宣言
				POINT pt;	// POINT構造体変数pt.

				// 座標の取り出し.
				pt.x = LOWORD(lParam);	// lParamの下位ワードが座標x.
				pt.y = HIWORD(lParam);	// lParamの上位ワードが座標y.

				// OnLButtonUpに任せる.
				if (OnLButtonUp(wParam, pt) == -1) {	// -1の時は入力をキャンセル.

					// 入力キャンセル.
					return 0;	// 0をここで返すと入力キャンセルとなる.

				}

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外の時.
		default:

			// defaultブロック
			{

				// OnUserMessageに任せる.
				OnUserMessage(uMsg, wParam, lParam);	// OnUserMessageに任せる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

	// DefWindowProcに任せる.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcにそのまま引数を渡して, その値を戻り値とする.

}

// ウィンドウ作成時のハンドラOnCreate.
int CWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ウィンドウ作成成功
	return 0;	// 成功なら0を返す.

}

// ウィンドウ破棄時のハンドラOnDestroy.
void CWindow::OnDestroy() {

	// メッセージループ終了.
	PostQuitMessage(0);	// PostQuitMessageでメッセージループを抜けさせる.

}

// コマンド処理時のハンドラOnCommand.
BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam) {

	// とりあえずTRUEを返す.
	return TRUE;	// TRUEを返す.

}

// ウィンドウサイズが変更された時のハンドラOnSize.
void CWindow::OnSize(UINT nType, int cx, int cy) {

	// 特に何もしない.

}

// ウィンドウの描画を要求された時のハンドラOnPaint.
void CWindow::OnPaint() {

}

// 水平方向スクロールバーイベント時のハンドラOnHScroll.
void CWindow::OnHScroll(UINT nSBCode, UINT nPos) {

}

// 垂直方向スクロールバーイベント時のハンドラOnVScroll.
void CWindow::OnVScroll(UINT nSBCode, UINT nPos) {

}

// ウィンドウを閉じる時のハンドラOnClose.
int CWindow::OnClose() {

	// このウィンドウを破棄.
	Destroy();	// Destroyでこのウィンドウを破棄.

	// 0を返す.
	return 0;	// 0を返してウィンドウを閉じる.

}

// キーが押された時のハンドラOnKeyDown.
int CWindow::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {

	// 成功なら0を返す.
	return 0;

}

// 文字キーが押された時のハンドラOnChar.
int CWindow::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {

	// 成功なら0を返す.
	return 0;

}

// マウス左ボタンが離された時のハンドラOnLButtonUp.
int CWindow::OnLButtonUp(UINT nFlags, POINT pt) {

	// 成功なら0を返す.
	return 0;

}

// ユーザ定義メッセージが発生した時のハンドラ.
void CWindow::OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {

}