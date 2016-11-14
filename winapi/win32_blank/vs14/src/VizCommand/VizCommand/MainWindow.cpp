// ヘッダのインクルード
#include "MainWindow.h"	// メインウィンドウクラス
#include "EditPanel.h"	// エディットパネルクラス
#include "WindowListItem.h"	// ウィンドウリストアイテムクラス

// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
void CMainWindow::Destroy() {

	// エディットボックスの破棄.
	DeleteEdit(0);

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

// 指定のindexのウィンドウリストアイテムにエディットボックスを追加するメンバ関数AddEdit.
void CMainWindow::AddEdit(int index, int x, int y, int w, int h, HINSTANCE hInstance){

	// エディットパネルの設置.
	CWindowListItem *m_pWindowListItem = m_pWindowListView->Get(index);	// index番目のアイテムを取得.
	CEditPanel *pEditPanel = new CEditPanel();	// pEditPanelオブジェクトの作成.
	pEditPanel->Create(x, y, w, h, m_pWindowListItem->m_hWnd, (HMENU)IDC_EDIT_PANEL + index, hInstance);	// pEditPanel->Createで生成.
	TCHAR tszTemp[256] = { 0 };
	_stprintf_s(tszTemp, _T("WindowListItem[%d].Edit"), index);	// インデックスをタグ名に変換.
	m_pChildMap->Add(tszTemp, new CChildMapItem(index, pEditPanel));	// チャイルドマップに追加.

}

// 指定のウィンドウリストアイテムのエディットボックスを削除するメンバ関数DeleteEdit.
void CMainWindow::DeleteEdit(int index){

	// エディットパネルの削除.
	TCHAR tszTemp[256] = { 0 };
	_stprintf_s(tszTemp, _T("WindowListItem[%d].Edit"), index);	// インデックスをタグ名に変換.
	CChildMapItem *pItem = m_pChildMap->Get(tszTemp);
	pItem->m_pWindow->Destroy();
	delete pItem->m_pWindow;
	delete pItem;
	m_pChildMap->Remove(tszTemp);
	delete m_pChildMap;

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

	// エディットボックス追加
	AddEdit(0, 50, 50, 200, 50, lpCreateStruct->hInstance);

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

	// リサイズ
	TCHAR tszTemp[256] = { 0 };
	_stprintf_s(tszTemp, _T("WindowListItem[%d].Edit"), 0);	// インデックスをタグ名に変換.
	CChildMapItem *pItem = m_pChildMap->Get(tszTemp);
	::MoveWindow(pItem->m_pWindow->m_hWnd, 50, 50, m_pWindowListView->m_pWindowListItemsPanel->Get(0)->m_iWidth - 100/*cx - 17*/, m_pWindowListView->m_pWindowListItemsPanel->Get(0)->m_iHeight - 100, TRUE);	// ウィンドウリストアイテムよりひとまわり小さい子ウィンドウ.

}

// ウィンドウを閉じる時のハンドラOnClose.
int CMainWindow::OnClose() {

	// 子ウィンドウの破棄.
	Destroy();	// Destroyで子ウィンドウの破棄.
	return 0;	// 0を返すと閉じる.

}