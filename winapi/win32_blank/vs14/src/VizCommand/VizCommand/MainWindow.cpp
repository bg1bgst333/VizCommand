// ヘッダのインクルード
#include "MainWindow.h"	// メインウィンドウクラス

// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
void CMainWindow::Destroy() {

	// 子ウィンドウの破棄.
	m_pWindowListView->Destroy();	// m_pWindowListView->Destroyで破棄.

	// ウィンドウリストビューの破棄.
	if (m_pWindowListView != NULL) {	// NULLでなければ.

		// m_pWindowListViewの破棄.
		delete m_pWindowListView;	// deleteでm_pWindowListViewを解放.
		m_pWindowListView = NULL;	// m_pWindowListViewをNULLにセット.

	}

}

// ウィンドウ作成時のハンドラOnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 子ウィンドウとなるウィンドウリストビューオブジェクトの作成.
	m_pWindowListView = new CWindowListView();	// CWindowListViewオブジェクトm_pWindowListViewの作成.

	// 子ウィンドウの作成.
	m_pWindowListView->Create(100, 100, 200, 200, hwnd, (HMENU)IDC_WINDOW_LISTVIEW, lpCreateStruct->hInstance);	// m_pWindowListView->Createでウィンドウリストビューを作成.

	// ウィンドウ作成成功
	return 0;	// 成功なら0を返す.

}

// ウィンドウ破棄時のハンドラOnDestroy
void CMainWindow::OnDestroy() {

	// メッセージループ終了.
	PostQuitMessage(0);	// PostQuitMessageでメッセージループを抜けさせる.

}

// ウィンドウを閉じる時のハンドラOnClose.
int CMainWindow::OnClose() {

	// 子ウィンドウの破棄.
	Destroy();	// Destroyで子ウィンドウの破棄.
	return 0;	// 0を返すと閉じる.

}