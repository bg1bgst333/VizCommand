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

	// ウィンドウリストビューの作成.
	m_pWindowListView->Create(100, 100, 200, 200, hwnd, (HMENU)IDC_WINDOW_LISTVIEW, lpCreateStruct->hInstance);	// m_pWindowListView->Createでウィンドウリストビューを作成.

	// ウィンドウリストアイテムの追加.
	m_pWindowListView->Insert(0, 50, lpCreateStruct->hInstance);	// 高さ50のウィンドウリストアイテムをInsert.

	// ウィンドウリストアイテムの追加.
	m_pWindowListView->Insert(1, 50, lpCreateStruct->hInstance);	// 高さ50のウィンドウリストアイテムをInsert.

	// ウィンドウリストアイテムの追加.
	m_pWindowListView->Insert(2, 50, lpCreateStruct->hInstance);	// 高さ50のウィンドウリストアイテムをInsert.

	// ウィンドウリストアイテムの追加.
	m_pWindowListView->Insert(3, 50, lpCreateStruct->hInstance);	// 高さ50のウィンドウリストアイテムをInsert.

	// ウィンドウリストアイテムの追加.
	m_pWindowListView->Insert(4, 50, lpCreateStruct->hInstance);	// 高さ50のウィンドウリストアイテムをInsert.

	// ウィンドウリストアイテムの追加.
	m_pWindowListView->Insert(1, 50, lpCreateStruct->hInstance);	// 高さ50のウィンドウリストアイテムをInsert.

	// ウィンドウリストアイテムの削除
	m_pWindowListView->Delete(-1);	// -1番目(0番目)を削除.

	// ウィンドウリストアイテムの削除
	m_pWindowListView->Delete(10);	// 10番目(4番目)を削除.

	// ウィンドウリストアイテムの削除
	m_pWindowListView->Delete(0);	// 0番目を削除.

	// ウィンドウリストアイテムの削除
	m_pWindowListView->Delete(1);	// 1番目を削除.

	// ウィンドウリストアイテムの削除
	m_pWindowListView->Delete(1);	// 1番目を削除.

	// ウィンドウ作成成功
	return 0;	// 成功なら0を返す.

}

// ウィンドウ破棄時のハンドラOnDestroy
void CMainWindow::OnDestroy() {

	// メッセージループ終了.
	PostQuitMessage(0);	// PostQuitMessageでメッセージループを抜けさせる.

}

// ウィンドウのサイズが変更された時のハンドラOnSize.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {
	
	// 子ウィンドウのウィンドウリストビューのサイズも変更.
	::MoveWindow(m_pWindowListView->m_hWnd, 0, 0, cx, cy, TRUE);	// MoveWindowで子ウィンドウm_pWindowListViewのサイズもこのウィンドウに合わせる.

}

// ウィンドウを閉じる時のハンドラOnClose.
int CMainWindow::OnClose() {

	// 子ウィンドウの破棄.
	Destroy();	// Destroyで子ウィンドウの破棄.
	return 0;	// 0を返すと閉じる.

}