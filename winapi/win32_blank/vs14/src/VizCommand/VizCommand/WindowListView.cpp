// ヘッダのインクルード
#include "WindowListView.h"	// ウィンドウリストビュークラス

// ウィンドウ作成関数Create.
BOOL CWindowListView::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// クラス名"WindowListView"の子ウィンドウを作成.
	return CWindow::Create(_T("WindowListView"), _T(""), WS_CHILD | WS_VISIBLE | WS_VSCROLL, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createでクラス名"WindowListView"の子ウィンドウを作成.

}

// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
void CWindowListView::Destroy() {

	// アイテムズの破棄.
	m_pWindowListItemsPanel->Destroy();
	delete m_pWindowListItemsPanel;
	m_pWindowListItemsPanel = NULL;

	// 破棄.
	DestroyWindow(m_hWnd);	// DestroyWindowでm_hWndを破棄.
	m_hWnd = NULL;	// m_hWndをNULLにする.

}

// ウィンドウリストアイテムを挿入するメンバ関数Insert.
BOOL CWindowListView::Insert(int index, int height, HINSTANCE hInstance){

	return m_pWindowListItemsPanel->Insert(index, height, hInstance);

}

// ウィンドウリストアイテムを削除するメンバ関数Delete.
void CWindowListView::Delete(int index){

	m_pWindowListItemsPanel->Delete(index);

}

// ウィンドウ作成時のハンドラOnCreate.
int CWindowListView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 子ウィンドウとなるウィンドウリストアイテムズパネルオブジェクトの作成.
	m_pWindowListItemsPanel = new CWindowListItemsPanel();	// CWindowListItemsPanelオブジェクトm_pWindowListItemsPanelの作成.

	// ウィンドウリストアイテムズパネルの作成.
	m_pWindowListItemsPanel->Create(0, 0, 0, 0, hwnd, (HMENU)IDC_WINDOW_LIST_ITEMS_PANEL, lpCreateStruct->hInstance);	// m_pWindowListItemsPanel->Createでウィンドウリストアイテムズパネルを作成.

	// スクロールバーの初期化.
	// 変数の宣言
	SCROLLINFO scrinfo = {0};	// SCROLLINFO構造体変数scrinfo.
	// scrinfoの初期化
	scrinfo.cbSize = sizeof(SCROLLINFO);	// SCROLLINFO構造体のサイズ.
	scrinfo.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// 設定する項目のマスク.(SIF_PAGEはページサイズ, SIF_RANGEはページ範囲, SIF_POSは現在位置.)
	scrinfo.nMin = 0;	// ページ範囲最小値を0にセット.
	scrinfo.nMax = 0;	// ページ範囲最大値を0にセット.
	scrinfo.nPage = 0;	// ページサイズを0にセット.
	scrinfo.nPos = 0;	// 現在の位置を0にセット.
	SetScrollInfo(hwnd, SB_VERT, &scrinfo, TRUE);	// SetScrollInfoでscrinfoをセット.(CTLじゃなくてVERTだった.)

	// ウィンドウ作成成功
	return 0;	// 成功なら0を返す.

}

// ウィンドウ破棄時のハンドラOnDestroy
void CWindowListView::OnDestroy() {

}

// ウィンドウのサイズが変更された時のハンドラOnSize.
void CWindowListView::OnSize(UINT nType, int cx, int cy){

	// 子ウィンドウのウィンドウリストアイテムズパネルのサイズも変更.
	::MoveWindow(m_pWindowListItemsPanel->m_hWnd, m_pWindowListItemsPanel->m_x, m_pWindowListItemsPanel->m_y, cx, m_pWindowListItemsPanel->m_iHeight, TRUE);	// MoveWindowで子ウィンドウm_pWindowListItemsPanelの横のサイズだけこのウィンドウに合わせる.

	// 変数の宣言
	SCROLLINFO scrinfo = { 0 };	// SCROLLINFO構造体変数scrinfo.
	// scrinfoの更新.
	// SCROLLINFO構造体の情報を取得.
	scrinfo.cbSize = sizeof(SCROLLINFO);		// サイズをセット.
	scrinfo.fMask = SIF_ALL;					// マスクはすべての項目をセット.
	GetScrollInfo(m_hWnd, SB_VERT, &scrinfo);	// GetScrollInfoでSCROLLINFO構造体の情報を取得.(CTLじゃなくてVERTだった.)

	//scrinfo.cbSize = sizeof(SCROLLINFO);	// SCROLLINFO構造体のサイズ.
	scrinfo.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;	// 設定する項目のマスク.(SIF_PAGEはページサイズ, SIF_RANGEはページ範囲, SIF_POSは現在位置.)
	scrinfo.nMin = 0;	// ページ範囲最小値を0にセット.
	scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;	// ページ範囲最大値をm_pWindowListItemsPanel->m_iHeightにセット.
	int temp = cy - (m_pWindowListItemsPanel->m_iHeight - scrinfo.nPos);
	if (temp >= 0) {
		scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight + temp;
	}
	else {
		scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;
	}
	scrinfo.nPage = cy;	// ページサイズをcyにセット.

	//scrinfo.nPos = 0;	// 現在の位置を0にセット.
	SetScrollInfo(m_hWnd, SB_VERT, &scrinfo, TRUE);	// SetScrollInfoでscrinfoをセット.(CTLじゃなくてVERTだった.)

}

// ウィンドウを閉じる時のハンドラOnClose.
int CWindowListView::OnClose() {

	// 0を返す.
	return 0;	// 0を返してウィンドウを閉じる.

}

// 垂直スクロール時のハンドラOnVScroll.
void CWindowListView::OnVScroll(UINT nSBCode, UINT nPos, HWND hScroll) {

	// 変数の宣言
	SCROLLINFO scrinfo = { 0 };	// SCROLLINFO構造体変数scrinfo.(" = {0}"することで中身を0で埋める.)

	// SCROLLINFO構造体の情報を取得.
	scrinfo.cbSize = sizeof(SCROLLINFO);		// サイズをセット.
	scrinfo.fMask = SIF_ALL;					// マスクはすべての項目をセット.
	GetScrollInfo(m_hWnd, SB_VERT, &scrinfo);	// GetScrollInfoでSCROLLINFO構造体の情報を取得.(CTLじゃなくてVERTだった.)

	scrinfo.fMask = SIF_PAGE | SIF_RANGE | SIF_POS;

	// 通知コード処理
	switch (nSBCode) {	// nSBCodeに行われた操作の通知コードが格納されているので, それで判定する.

		// 1番上
		case SB_TOP:

			{
				int temp = scrinfo.nPage - (m_pWindowListItemsPanel->m_iHeight - scrinfo.nPos);
				if (temp >= 0) {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight + temp;
				}
				else {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;
				}

				// 1番上にセット.
				scrinfo.nPos = scrinfo.nMin;	// 現在位置を1番上にセット.
				break;	// 抜ける.
			}

		// 1番下
		case SB_BOTTOM:

			// 1番下にセット.
			scrinfo.nPos = scrinfo.nMax;	// 現在位置を1番下にセット.
			break;	// 抜ける.

		// 1行上
		case SB_LINEUP:

			{
				int temp = scrinfo.nPage - (m_pWindowListItemsPanel->m_iHeight - scrinfo.nPos);
				if (temp >= 0) {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight + temp;
				}
				else {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;
				}

				// 1行上に戻す.
				if (scrinfo.nPos > 0) {	// scrinfo.nPosが1以上なら.	
					scrinfo.nPos--;	// scrinfo.nPosを減らす.
					m_pWindowListItemsPanel->m_y++;
				}
				break;	// 抜ける.
			}

		// 1行下
		case SB_LINEDOWN:

			// 1行下に進める.
			if (scrinfo.nPos < scrinfo.nMax - (int)scrinfo.nPage + 1) {	// scrinfo.nPosが最後の位置より前なら.
				scrinfo.nPos++;	// scrinfo.nPosを増やす.
				m_pWindowListItemsPanel->m_y--;
			}
			break;	// 抜ける.

		// 1ページ上
		case SB_PAGEUP:
	
			{
				int temp = scrinfo.nPage - (m_pWindowListItemsPanel->m_iHeight - scrinfo.nPos);
				if (temp >= 0) {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight + temp;
				}
				else {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;
				}

				// 1ページ戻す.
				scrinfo.nPos -= scrinfo.nPage;	// 現在位置を1ページ戻す.
				m_pWindowListItemsPanel->m_y = m_pWindowListItemsPanel->m_y + scrinfo.nPage;
				if (scrinfo.nPos <= scrinfo.nMin) {
					scrinfo.nPos = scrinfo.nMin;
					m_pWindowListItemsPanel->m_y = 0;
				}

				break;	// 抜ける.
			}

		// 1ページ下
		case SB_PAGEDOWN:
			
			// 1ページ進む.
			scrinfo.nPos += scrinfo.nPage;	// 現在位置を1ページ進める.
			m_pWindowListItemsPanel->m_y = m_pWindowListItemsPanel->m_y - scrinfo.nPage;
			if (scrinfo.nPos + (int)scrinfo.nPage >= scrinfo.nMax) {
				scrinfo.nPos = scrinfo.nMax - scrinfo.nPage;
				m_pWindowListItemsPanel->m_y = 0 - scrinfo.nPos;
			}
			
			break;	// 抜ける.

		
		// スクロールつまみが離された時.
		case SB_THUMBTRACK:
		case SB_THUMBPOSITION:
		
			{

				int temp = scrinfo.nPage - (m_pWindowListItemsPanel->m_iHeight - scrinfo.nPos);
				if (temp >= 0) {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight + temp;
				}
				else {
					scrinfo.nMax = m_pWindowListItemsPanel->m_iHeight;
				}

				// 離された位置をセット.
				scrinfo.nPos = nPos;	// nPosに離された位置が格納されているのでscrinfo.nPosにセット.
				m_pWindowListItemsPanel->m_y = 0 - scrinfo.nPos;
				break;	// 抜ける.

			}

		// それ以外.
		default:

			// 抜ける.
			break;	// 抜ける.

	}

	// scrinfo.nPosをhScrollにセット.
	SetScrollInfo(m_hWnd, SB_VERT, &scrinfo, TRUE);	// SetScrollInfoで現在のscrinfo.nPosをhScrollにセット.(CTLじゃなくてVERTだった.)
	::MoveWindow(m_pWindowListItemsPanel->m_hWnd, m_pWindowListItemsPanel->m_x, m_pWindowListItemsPanel->m_y, m_pWindowListItemsPanel->m_iWidth, m_pWindowListItemsPanel->m_iHeight, TRUE);

}
