// ヘッダのインクルード
#include "MainWindow.h"	// メインウィンドウクラス
#include "EditPanel.h"	// エディットパネルクラス
#include "WindowListItem.h"	// ウィンドウリストアイテムクラス

// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
void CMainWindow::Destroy() {


	// 孫ウィンドウ(ウィンドウリストアイテムの子ウィンドウ)の破棄.
	CChildMapItem *pItem = m_pChildMap->Get(_T("0"));
	pItem->m_pWindow->Destroy();
	delete pItem->m_pWindow;
	delete pItem;
	m_pChildMap->Remove(_T("0"));
	delete m_pChildMap;

	// アイテムの破棄.
	m_pWindowListView->Delete(0);

	// 子ウィンドウ(ウィンドウリストアイテム)の破棄.
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

	// ウィンドウリストアイテムの子ウィンドウを管理するマップの作製.
	m_pChildMap = new CChildMap;

	// ウィンドウリストビューの作成.
	m_pWindowListView->Create(0, 0, 200, 200, hwnd, (HMENU)IDC_WINDOW_LIST_VIEW, lpCreateStruct->hInstance);	// m_pWindowListView->Createでウィンドウリストビューを作成.

	// ウィンドウリストアイテムの追加.
	m_pWindowListView->Insert(0, 200, lpCreateStruct->hInstance);	// 高さ200のウィンドウリストアイテムをInsert.

	// エディットパネルのセット.
	CWindowListItem *m_pWindowListItem = m_pWindowListView->Get(0);	// 0番目のアイテムを取得.
	CEditPanel *pEditPanel = new CEditPanel();	// pEditPanelオブジェクトの作成.
	pEditPanel->Create(50, 50, 50, 50, m_pWindowListItem->m_hWnd, (HMENU)IDC_EDIT_PANEL, lpCreateStruct->hInstance);	// pEditPanel->Createで生成.
	m_pChildMap->Add(_T("0"), new CChildMapItem(0, pEditPanel));	// チャイルドマップに追加.

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