// ヘッダのインクルード
#include "WindowListView.h"	// ウィンドウリストビュークラス

// ウィンドウ作成関数Create.
BOOL CWindowListView::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// クラス名"WindowListView"の子ウィンドウを作成.
	return CWindow::Create(_T("WindowListView"), _T(""), WS_CHILD | WS_VISIBLE | WS_VSCROLL, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createでクラス名"WindowListView"の子ウィンドウを作成.

}

// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
void CWindowListView::Destroy() {

	// アイテムをすべて削除.
	int c = m_vecpWindowList.size();
	for (int i = 0; i < c; i++) {
		Delete(0);	// Deleteで削除.
	}

	// 破棄.
	DestroyWindow(m_hWnd);	// DestroyWindowでm_hWndを破棄.
	m_hWnd = NULL;	// m_hWndをNULLにする.

}

// ウィンドウリストアイテムを挿入するメンバ関数Insert.
BOOL CWindowListView::Insert(int index, int height, HINSTANCE hInstance){

	// アイテムの生成.
	CWindowListItem *pItem = new CWindowListItem();	// CWindowListItemオブジェクトpItemを生成.
	// 挿入位置がサイズより大きい場合は一番最後に追加.
	if ( index > (int)m_vecpWindowList.size()) {
		int position = 0;
		int idx = m_vecpWindowList.size();	// idxをm_vecpWindowList.size()に初期化.
		if (idx == 0) {
			position = 0;
		}
		else {
			position = m_vecpWindowList[idx - 1]->m_y + m_vecpWindowList[idx - 1]->m_iHeight;
		}
		pItem->Create(0, position, 200, height, m_hWnd, (HMENU)(IDC_WINDOW_LISTITEM + idx), hInstance);	// ウィンドウ生成.
		TCHAR tszText[256];
		_stprintf_s(tszText, _T("%d"), idx);
		pItem->SetWindowText(tszText);
		m_vecpWindowList.push_back(pItem);	// 追加
	}
	else {
		int idx;	// idxを用意.
		int position = 0;
		if (index < 0) {	// indexがマイナス.
			idx = 0;	// idxを0にセット.
		}
		else {
			idx = index;	// idxをindexにセット.
		}
		if (idx == 0) {
			position = 0;
		}
		else {
			position = m_vecpWindowList[idx - 1]->m_y + m_vecpWindowList[idx - 1]->m_iHeight;
		}
		pItem->Create(0, position, 200, height, m_hWnd, (HMENU)(IDC_WINDOW_LISTITEM + m_vecpWindowList.size()), hInstance);	// ウィンドウ生成.
		TCHAR tszText[256];
		_stprintf_s(tszText, _T("%d"), idx);
		pItem->SetWindowText(tszText);
		m_vecpWindowList.insert(m_vecpWindowList.begin() + idx, pItem);	// 追加
		// 後ろはheight分ずれる.
		for (int i = idx + 1; i <= (int)m_vecpWindowList.size() - 1; i++) {
			m_vecpWindowList[i]->MoveWindow(m_vecpWindowList[i]->m_x, m_vecpWindowList[i]->m_y + height, m_vecpWindowList[i]->m_iWidth, m_vecpWindowList[i]->m_iHeight);
		}
	}
	
	// TRUEを返す.
	return TRUE;	// TRUEを返す.

}

// ウィンドウリストアイテムを削除するメンバ関数Delete.
void CWindowListView::Delete(int index){

	// サイズが0なら何もしない.
	if (m_vecpWindowList.size() == 0) {
		return;
	}
	else {
		// サイズ以上なら末尾の削除.
		if (index >= (int)m_vecpWindowList.size()) {
			CWindowListItem *pItem = m_vecpWindowList.at(m_vecpWindowList.size() - 1);	// m_vecpWindowList.atで取出し.
			pItem->Destroy();	// pItem->Destroyでウィンドウの破棄.
			delete pItem;	// deleteでpItemを解放.
			m_vecpWindowList.erase(m_vecpWindowList.begin() + m_vecpWindowList.size() - 1);	// m_vecpWindowList.size() - 1番目をeraseで削除.
			return;
		}
		if (index < -1) {	// マイナスなら0の取出し.
			CWindowListItem *pItem = m_vecpWindowList.at(0);	// 0を削除..
			pItem->Destroy();	// pItem->Destroyでウィンドウの破棄.
			delete pItem;	// deleteでpItemを解放.
			m_vecpWindowList.erase(m_vecpWindowList.begin() + 0);	// 0番目をeraseで削除.
			return;
		}
		// index番目の削除.
		CWindowListItem *pItem = m_vecpWindowList.at(index);	// m_vecpWindowList.atで取出し.
		pItem->Destroy();	// pItem->Destroyでウィンドウの破棄.
		delete pItem;	// deleteでpItemを解放.
		m_vecpWindowList.erase(m_vecpWindowList.begin() + index);	// index番目をeraseで削除.
	}

}

// ウィンドウ作成時のハンドラOnCreate.
int CWindowListView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ウィンドウ作成成功
	return 0;	// 成功なら0を返す.

}

// ウィンドウ破棄時のハンドラOnDestroy
void CWindowListView::OnDestroy() {

}

// ウィンドウのサイズが変更された時のハンドラOnSize.
void CWindowListView::OnSize(UINT nType, int cx, int cy){

	// 全ての子ウィンドウの横幅を合わせる.
	for (std::vector<CWindowListItem *>::iterator it = m_vecpWindowList.begin(); it != m_vecpWindowList.end(); it++) {

		// 子ウィンドウのウィンドウリストビューのサイズも変更.
		(*it)->m_iWidth = cx;	// 横幅はcxに合わせる.
		// 高さはそのまま.
		::MoveWindow((*it)->m_hWnd, 0, (*it)->m_y, (*it)->m_iWidth, (*it)->m_iHeight, TRUE);	// MoveWindowで子ウィンドウのサイズもこのウィンドウの横幅に合わせる.

	}

}

// ウィンドウを閉じる時のハンドラOnClose.
int CWindowListView::OnClose() {

	// 0を返す.
	return 0;	// 0を返してウィンドウを閉じる.

}