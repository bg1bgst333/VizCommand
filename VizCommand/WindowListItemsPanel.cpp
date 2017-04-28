// ヘッダのインクルード
// 独自のヘッダ
#include "WindowListItemsPanel.h"	// ウィンドウリストアイテムズパネルクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CWindowListItemsPanel::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウリストアイテムを登録.
	CWindowListItem::RegisterClass(hInstance);	// 子ウィンドウを登録.

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("WindowListItemsPanel"));	// CUserControl::RegisterClassでウィンドウクラス"WindowListItemsPanel"を登録.

}

// コンストラクタCWindowListItemsPanel()
CWindowListItemsPanel::CWindowListItemsPanel() : CUserControl() {

	// メンバの初期化.
	m_nId = 0;	// m_nIdを0に初期化.

}

// デストラクタ~CWindowListItemsPanel()
CWindowListItemsPanel::~CWindowListItemsPanel() {

	// メンバの終了処理.
	Destroy();	// Destroyで破棄.
	m_nId = 0;	// m_nIdを0にセット.

}

// ウィンドウ作成関数Create
BOOL CWindowListItemsPanel::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	return CUserControl::Create(_T("WindowListItemsPanel"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createでウィンドウクラス"WindowListItemsPanel"なウィンドウを作成.

}

// ウィンドウ破棄関数Destroy
void CWindowListItemsPanel::Destroy() {

	// アイテムの一斉削除.
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// イテレータ.
	while (itor != m_lstWindowList.end()) {
		(*itor)->Destroy();
		delete (*itor);
		(*itor) = NULL;
		itor++;
	}
	m_lstWindowList.clear();

	// ペンとブラシの破棄.
	if (m_hBrush) {
		DeleteObject(m_hBrush);	// ブラシの破棄.
		m_hBrush = NULL;
	}
	if (m_hPen) {
		DeleteObject(m_hPen);	// ペンの破棄.
		m_hPen = NULL;
	}
	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// アイテム挿入関数Insert
BOOL CWindowListItemsPanel::Insert(LPCTSTR lpctszWindowName, int iIndex, int iHeight, HINSTANCE hInstance) {

	// 変数の宣言.
	int iIdx;	// 値のチェック後のインデックスint型iIdx.
	CWindowListItem *pItem;	// ウィンドウリストアイテムポインタpItem.
	int iTotalHeight = 0;	// パネル全体の高さiTotalHeightを0に初期化.

	// インデックスの値で振り分け.
	if (iIndex < 0) {	// 負の値
		iIdx = 0;	// 0をセット.
	}
	else if (iIndex >(int)m_lstWindowList.size()) {	// サイズより大きい.
		iIdx = m_lstWindowList.size();	// サイズをセット.
	}
	else {
		iIdx = iIndex;	// iIndexをセット.
	}
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// イテレータ.
	int y = 0;
	for (int i = 0; i < (int)m_lstWindowList.size() + 1; i++) {
		if (i == iIdx) {
			pItem = new CWindowListItem();	// 生成.
			pItem->Create(lpctszWindowName, 0, 3, iTotalHeight + 3, m_iWidth - (3 * 2), iHeight - (3 * 2), m_hWnd, (HMENU)(IDC_WINDOWLISTITEM_ID_START + m_nId), hInstance);	// ウィンドウ生成.
			iTotalHeight = iTotalHeight + iHeight;	// 挿入するウィンドウの高さを足す.
			m_lstWindowList.insert(itor, pItem);	// 挿入.
			m_nId++;
			itor = m_lstWindowList.begin();
			for (int j = 0; j < iIdx; j++) {
				itor++;
			}
		}
		else if (i < iIdx) {
			y = y + (*itor)->m_iHeight;	// 位置計算.
			y = y + (3 * 2);	// 余白の大きさ
			iTotalHeight = y;
		}
		else if (i > iIdx) {
			if (itor != m_lstWindowList.end()) {
				iTotalHeight = iTotalHeight + (*itor)->m_iHeight;
				iTotalHeight = iTotalHeight + (3 * 2);
				(*itor)->MoveWindow(false, 0, iHeight);	// iHeight分ずらす.
			}
			else {
				break;
			}
		}
		if (itor != m_lstWindowList.end()) {
			itor++;
		}
		else {
			break;
		}
	}

	//アイテムズパネルの大きさを拡張する.
	MoveWindow(3, iTotalHeight);	// 高さをiTotalHeightにする.

	// とりあえず成功にしておく.
	return TRUE;

}

// アイテム削除Remove
BOOL CWindowListItemsPanel::Remove(int iIndex) {

	// 変数の宣言.
	int iIdx;		// 値のチェック後のインデックスint型iIdx.
	int iHeight = 0;	// 削除されたアイテムの高さiHeightを0に初期化.
	int iTotalHeight = 0;	// パネル全体の高さiTotalHeightを0に初期化.

	// インデックスの値で振り分け.
	if (iIndex < 0) {	// 負の値
		iIdx = 0;	// 0をセット.
	}
	else if (iIndex >(int)m_lstWindowList.size() - 1) {	// 最後尾より大きい.
		iIdx = m_lstWindowList.size() - 1;	// 最後尾をセット.
	}
	else {
		iIdx = iIndex;	// iIndexをセット.
	}
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// イテレータ.
	for (int i = 0; i < (int)m_lstWindowList.size(); i++) {
		if (i == iIdx) {
			iHeight = (*itor)->m_iHeight;	// 高さを保存.
			(*itor)->Destroy();
			delete (*itor);
			m_lstWindowList.remove((*itor));
			itor = m_lstWindowList.begin();
			for (int j = 0; j < iIdx; j++) {
				itor++;
			}
			if (itor != m_lstWindowList.end()) {
				iTotalHeight = iTotalHeight + (*itor)->m_iHeight;
				(*itor)->MoveWindow(false, 0, -iHeight);	// iHeight分ずらす.
			}
			else {
				break;
			}
		}
		else if (i > iIdx) {
			if (itor != m_lstWindowList.end()) {
				iTotalHeight = iTotalHeight + (*itor)->m_iHeight;
				(*itor)->MoveWindow(false, 0, -iHeight);	// iHeight分ずらす.
			}
			else {
				break;
			}
		}
		else {
			iTotalHeight = iTotalHeight + (*itor)->m_iHeight;
		}
		if (itor != m_lstWindowList.end()) {
			itor++;
		}
		else {
			break;
		}
	}

	//アイテムズパネルの大きさを縮小する.
	MoveWindow(3, iTotalHeight);	// 高さをiTotalHeightにする.

	// とりあえず成功にしておく.
	return TRUE;

}

// アイテム取得関数Get
CWindowListItem * CWindowListItemsPanel::Get(int iIndex) {

	// iIndex番目の要素を返す.
	int i = 0;	// iを0に初期化.
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// イテレータ.
	while (itor != m_lstWindowList.end()) {
		if (i == iIndex) {
			return (*itor);
		}
		i++;
		itor++;
	}
	return NULL;

}

// ウィンドウ作成時のハンドラOnCreate.
int CWindowListItemsPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ペンとブラシの作成.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 0xff));		// 青(濃)のペンを作成.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0x9d, 0xcc, 0xe0));		// 青(淡)のブラシを作成.

	// 成功なので0を返す.
	return 0;

}

// ウィンドウサイズが変更された時のハンドラOnSize.
void CWindowListItemsPanel::OnSize(UINT nType, int cx, int cy) {

	// 実際のウィンドウサイズを格納.
	m_iWidth = cx;	// m_iWidthにcxをセット.
	m_iHeight = cy;	// m_iHeightにcyをセット.

	// アイテムの一斉リサイズ.
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// イテレータ.
	while (itor != m_lstWindowList.end()) {
		(*itor)->MoveWindow(2, m_iWidth - (3 * 2));	// 親ウィンドウの幅に合わせる.
		itor++;
	}

}

// ウィンドウの描画を要求された時のハンドラOnPaint.
void CWindowListItemsPanel::OnPaint() {

	// 変数の宣言
	HDC hDC;			// デバイスコンテキストハンドルHDC型hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT構造体変数ps.

	// 描画開始.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaintで描画開始.
	// ペンとブラシの選択.
	HPEN hOldPen = (HPEN)SelectObject(hDC, m_hPen);		// 青のペンを選択.
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, m_hBrush);	// 青のブラシを選択.
	// 矩形を描画.(クライアント領域はスクロールバーを含まない.)
	RECT rc;
	GetClientRect(m_hWnd, &rc);	// GetClientRectでクライアント領域の矩形を取得.
	Rectangle(hDC, 0, 0, rc.right - rc.left, rc.bottom - rc.top);	// Rectangleで矩形を描画.
	// ペンとブラシの復元
	SelectObject(hDC, hOldBrush);		// 古いブラシを選択.
	SelectObject(hDC, hOldPen);		// 古いペンを選択.
	// 描画終了.
	EndPaint(m_hWnd, &ps);	// EndPaintで描画終了.

}