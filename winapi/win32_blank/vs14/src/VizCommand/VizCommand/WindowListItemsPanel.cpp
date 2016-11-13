// ヘッダのインクルード
#include "WindowListItemsPanel.h"	// ウィンドウリストアイテムズパネルクラス

// ウィンドウ作成関数Create.
BOOL CWindowListItemsPanel::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// メンバにセット.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	m_iWidth = iWidth;	// m_iWidthにiWidthをセット.
	m_iHeight = iHeight;	// m_iHeightにiHeightをセット.

	// クラス名"WindowListItemsPanel"の子ウィンドウを作成.
	return CWindow::Create(_T("WindowListItemsPanel"), _T(""), WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createでクラス名"WindowListItemsPanel"の子ウィンドウを作成.

}

// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
void CWindowListItemsPanel::Destroy() {

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
BOOL CWindowListItemsPanel::Insert(int index, int height, HINSTANCE hInstance) {

	// アイテムの生成.
	CWindowListItem *pItem = new CWindowListItem();	// CWindowListItemオブジェクトpItemを生成.
	// 挿入位置がサイズより大きい場合は一番最後に追加.
	if (index > (int)m_vecpWindowList.size()) {
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

	// アイテムズパネルのサイズを変更.
	m_iHeight = m_iHeight + height;
	::MoveWindow(m_hWnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);

	// TRUEを返す.
	return TRUE;	// TRUEを返す.

}

// ウィンドウリストアイテムを削除するメンバ関数Delete.
void CWindowListItemsPanel::Delete(int index) {

	// サイズが0なら何もしない.
	if (m_vecpWindowList.size() == 0) {
		return;
	}
	else {
		// サイズ以上なら末尾の削除.
		if (index >= (int)m_vecpWindowList.size()) {
			int height;
			CWindowListItem *pItem = m_vecpWindowList.at(m_vecpWindowList.size() - 1);	// m_vecpWindowList.atで取出し.
			height = pItem->m_iHeight;
			pItem->Destroy();	// pItem->Destroyでウィンドウの破棄.
			delete pItem;	// deleteでpItemを解放.
			m_vecpWindowList.erase(m_vecpWindowList.begin() + m_vecpWindowList.size() - 1);	// m_vecpWindowList.size() - 1番目をeraseで削除.
			// アイテムズパネルのサイズを変更.
			m_iHeight = m_iHeight - height;
			::MoveWindow(m_hWnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);
			return;
		}
		if (index < 0) {	// マイナスなら0の取出し.
			int height = m_vecpWindowList[0]->m_iHeight;	// 0番目のm_iHeightを保存.
			CWindowListItem *pItem = m_vecpWindowList.at(0);	// 0を削除..
			pItem->Destroy();	// pItem->Destroyでウィンドウの破棄.
			delete pItem;	// deleteでpItemを解放.
			m_vecpWindowList.erase(m_vecpWindowList.begin() + 0);	// 0番目をeraseで削除.
			// 後ろはheight分ずれる.
			for (int i = 0; i <= (int)m_vecpWindowList.size() - 1; i++) {
				m_vecpWindowList[i]->MoveWindow(m_vecpWindowList[i]->m_x, m_vecpWindowList[i]->m_y - height, m_vecpWindowList[i]->m_iWidth, m_vecpWindowList[i]->m_iHeight);
			}
			// アイテムズパネルのサイズを変更.
			m_iHeight = m_iHeight - height;
			::MoveWindow(m_hWnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);
			return;
		}
		// index番目の削除.
		CWindowListItem *pItem = m_vecpWindowList.at(index);	// m_vecpWindowList.atで取出し.
		int delHeight = pItem->m_iHeight;	// delHeightに保存.
		pItem->Destroy();	// pItem->Destroyでウィンドウの破棄.
		delete pItem;	// deleteでpItemを解放.
		m_vecpWindowList.erase(m_vecpWindowList.begin() + index);	// index番目をeraseで削除.
		// 後ろはheight分ずれる.
		for (int i = index; i <= (int)m_vecpWindowList.size() - 1; i++) {
			m_vecpWindowList[i]->MoveWindow(m_vecpWindowList[i]->m_x, m_vecpWindowList[i]->m_y - delHeight, m_vecpWindowList[i]->m_iWidth, m_vecpWindowList[i]->m_iHeight);
		}
		// アイテムズパネルのサイズを変更.
		m_iHeight = m_iHeight - delHeight;
		::MoveWindow(m_hWnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);
	}

}

// ウィンドウリストアイテムを取得するメンバ関数Get.
CWindowListItem * CWindowListItemsPanel::Get(int index){

	// index番目のアイテムを返す.
	return m_vecpWindowList[index];

}

// ウィンドウ作成時のハンドラOnCreate.
int CWindowListItemsPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ウィンドウ作成成功
	return 0;	// 成功なら0を返す.

}

// ウィンドウ破棄時のハンドラOnDestroy
void CWindowListItemsPanel::OnDestroy() {

}

// ウィンドウが移動された時のハンドラOnMove.
void CWindowListItemsPanel::OnMove(int x, int y){

	::InvalidateRect(m_hWnd, NULL, TRUE);

}

// ウィンドウのサイズが変更された時のハンドラOnSize.
void CWindowListItemsPanel::OnSize(UINT nType, int cx, int cy) {

	// アイテムズパネルの位置サイズ情報を変更.
	m_iWidth = cx;
	m_iHeight = cy;

	// 全ての子ウィンドウの横幅を合わせる.
	for (std::vector<CWindowListItem *>::iterator it = m_vecpWindowList.begin(); it != m_vecpWindowList.end(); it++) {

		// 子ウィンドウのサイズも変更.
		(*it)->m_iWidth = cx;	// 横幅はcxに合わせる.
		// 高さはそのまま.
		::MoveWindow((*it)->m_hWnd, 0, (*it)->m_y, (*it)->m_iWidth, (*it)->m_iHeight, TRUE);	// MoveWindowで子ウィンドウのサイズもこのウィンドウの横幅に合わせる.

	}

}

// 画面描画の更新を要求された時.
void CWindowListItemsPanel::OnPaint(){

	// 変数の宣言
	HDC hDC;
	PAINTSTRUCT ps;

	// 描画の開始.
	hDC = ::BeginPaint(m_hWnd, &ps);

	// アイテムズパネルの領域を矩形で描画.
	HPEN hOldPen;
	HBRUSH hOldBrush;
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
	hOldPen = (HPEN)SelectObject(hDC, hGreenPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hWhiteBrush);
	Rectangle(hDC, m_x, m_y, m_iWidth, m_iHeight);
	SelectObject(hDC, hOldBrush);
	SelectObject(hDC, hOldPen);
	DeleteObject(hWhiteBrush);
	DeleteObject(hGreenPen);

	// 描画の終了.
	::EndPaint(m_hWnd, &ps);

}

// ウィンドウを閉じる時のハンドラOnClose.
int CWindowListItemsPanel::OnClose() {

	// 0を返す.
	return 0;	// 0を返してウィンドウを閉じる.

}