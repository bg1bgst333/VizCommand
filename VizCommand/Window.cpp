// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "Window.h"	// ウィンドウクラス

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
	if (m_hWnd != NULL) {	// m_hWndがNULLでなければ.
		DestroyWindow(m_hWnd);	// m_hWndを破棄.
		m_hWnd = NULL;	// m_hWndにNULLを代入.
	}
	m_x = 0;		// m_xに0を代入.
	m_y = 0;		// m_yに0を代入.
	m_iWidth = 0;	// m_iWidthに0を代入.
	m_iHeight = 0;	// m_iHeightに0を代入.

}

// ウィンドウクラス登録関数RegisterClass
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

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

// 独自のウィンドウプロシージャStaticWindowProc関
LRESULT CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// ウィンドウメッセージ処理
	switch (uMsg) {

		// ウィンドウの作成が開始された時.
		case WM_CREATE:

			// WM_CREATEブロック
			{

				// ウィンドウ作成成功
				return 0;	// 成功なら0を返す.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// ウィンドウが破棄された時.
		case WM_DESTROY:

			// WM_DESTROYブロック
			{

				// メッセージループ終了.
				PostQuitMessage(0);	// PostQuitMessageでメッセージループを抜けさせる.

			}

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

		// それ以外の時.
		default:

			// 既定の処理へ向かう.
			break;	// 抜けてDefWindowProcに向かう.

	}

	// 既定の処理
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProcに任せる.

}

// ウィンドウ作成関数Create
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

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

// ウィンドウ表示関数ShowWindow
BOOL CWindow::ShowWindow(int nCmdShow){

	// ウィンドウの表示
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPIのShowWindowでm_hWndを表示.

}