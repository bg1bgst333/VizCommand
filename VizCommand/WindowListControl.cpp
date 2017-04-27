// ヘッダのインクルード
// 独自のヘッダ
#include "WindowListControl.h"	// ウィンドウリストコントロールクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CWindowListControl::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウリストアイテムズパネルを登録.
	CWindowListItemsPanel::RegisterClass(hInstance);	// 子ウィンドウを登録.

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("WindowListControl"));	// CUserControl::RegisterClassでウィンドウクラス"WindowListControl"を登録.

}

// コンストラクタCWindowListControl()
CWindowListControl::CWindowListControl() : CUserControl() {

	// メンバの初期化
	m_pWindowListItemsPanel = NULL;	// m_pWindowListItemsPanelをNULLで初期化.

}

// デストラクタ~CWindowListControl()
CWindowListControl::~CWindowListControl() {

	// メンバの終了処理.
	Destroy();	// Destroyで破棄.

}

// ウィンドウ作成関数Create
BOOL CWindowListControl::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	return CUserControl::Create(_T("WindowListControl"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Createでウィンドウクラス"WindowListControl"なウィンドウを作成.

}

// ウィンドウ破棄関数Destroy
void CWindowListControl::Destroy() {

	// 子ウィンドウの破棄.
	if (m_pWindowListItemsPanel != NULL) {
		m_pWindowListItemsPanel->Destroy();	// m_pWindowListItemsPanelのウィンドウを破棄.
		delete m_pWindowListItemsPanel;		// m_pWindowListItemsPanelを解放.
		m_pWindowListItemsPanel = NULL;		// m_pWindowListItemsPanelをNULLで埋める.
	}

	// ペンとブラシの破棄.
	DeleteObject(m_hBrush);	// ブラシの破棄.
	DeleteObject(m_hPen);	// ペンの破棄.

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// アイテム挿入関数Insert
BOOL CWindowListControl::Insert(LPCTSTR lpctszWindowName, int iIndex, int iHeight, HINSTANCE hInstance) {

	// アイテムズパネルのInsertを呼ぶ.
	return m_pWindowListItemsPanel->Insert(lpctszWindowName, iIndex, iHeight, hInstance);	// m_pWindowListItemsPanel->Insertで挿入.

}

// アイテム削除関数Remove
BOOL CWindowListControl::Remove(int iIndex) {

	// アイテムズパネルのRemoveを呼ぶ.
	return m_pWindowListItemsPanel->Remove(iIndex);	// m_pWindowListItemsPanel->Removeで削除.

}

// アイテム取得関数Get
CWindowListItem * CWindowListControl::Get(int iIndex) {

	// iIndex番目を返す.
	return m_pWindowListItemsPanel->Get(iIndex);	// m_pWindowListItemsPanel->GetでiIndex番目を返す.

}

// ウィンドウ作成時のハンドラOnCreate.
int CWindowListControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ペンとブラシの作成.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0x7f, 0));		// 緑(濃)のペンを作成.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0xff, 0));		// 緑(淡)のブラシを作成.

	// ウィンドウリストアイテムズパネルクラスの作成.
	m_pWindowListItemsPanel = new CWindowListItemsPanel();	// CWindowListItemsPanelオブジェクトを作成し, ポインタをm_pWindowListItemsPanelに格納.
	m_pWindowListItemsPanel->Create(_T(""), 0, 30, 0, 300, 10, hwnd, (HMENU)IDC_WINDOWLISTITEMSPANEL1, lpCreateStruct->hInstance);	// m_pWindowListItemsPanel->Createでウィンドウリストアイテムズパネルを作成.(親ウィンドウより小さめ.)

	// 成功なので0を返す.
	return 0;

}

// ウィンドウの描画を要求された時のハンドラOnPaint.
void CWindowListControl::OnPaint() {

	// 変数の宣言
	HDC hDC;			// デバイスコンテキストハンドルHDC型hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT構造体変数ps.

	// 矩形を描画.(クライアント領域はスクロールバーを含まない.)
	RECT rc;
	GetClientRect(m_hWnd, &rc);	// GetClientRectでクライアント領域の矩形を取得.

	// スクロールバー設定.
	// 横
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// サイズをセット.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// フラグをセット.
	m_ScrollInfo.nPage = rc.right - rc.left;	// クライアント領域の幅をセット.
	m_ScrollInfo.nMin = 0;	// 最小値をセット.
	m_ScrollInfo.nMax = m_pWindowListItemsPanel->m_iWidth;	// 子ウィンドウの幅をセット.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, TRUE);	// SetScrollInfoでセット.

	// 縦
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// サイズをセット.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// フラグをセット.
	m_ScrollInfo.nPage = rc.bottom - rc.top;	// クライアント領域の高さをセット.
	m_ScrollInfo.nMin = 0;	// 最小値をセット.
	m_ScrollInfo.nMax = m_pWindowListItemsPanel->m_iHeight;	// 子ウィンドウの高さをセット.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);	// SetScrollInfoでセット.

	// 描画開始.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaintで描画開始.

	// ペンとブラシの選択.
	HPEN hOldPen = (HPEN)SelectObject(hDC, m_hPen);		// 緑のペンを選択.
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, m_hBrush);	// 緑のブラシを選択.
	// 矩形描画.
	Rectangle(hDC, 0, 0, rc.right - rc.left, rc.bottom - rc.top);	// Rectangleで矩形を描画.
	// ペンとブラシの復元
	SelectObject(hDC, hOldBrush);		// 古いブラシを選択.
	SelectObject(hDC, hOldPen);		// 古いペンを選択.

	// 描画終了.
	EndPaint(m_hWnd, &ps);	// EndPaintで描画終了.

}

// 水平方向スクロールバーイベント時のハンドラOnHScroll.
void CWindowListControl::OnHScroll(UINT nSBCode, UINT nPos) {

	// スクロール情報取得.
	m_ScrollInfo.fMask = SIF_POS;	// 位置だけ変更モード(これがないと, スクロールバーが元の位置に戻ってしまうので注意!こっちが前!)
	GetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo);	// マスクを設定してからGetScrollInfo.(こっちが後!)

	// スクロールバー処理.
	switch (nSBCode) {	// nSBCodeごとに振り分け.

		// 一番左
		case SB_LEFT:

			// 位置を最小値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// 一番右
		case SB_RIGHT:

			// 位置を最大値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1列左
		case SB_LINELEFT:

			// nPosが0でなければデクリメント.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1列右
		case SB_LINERIGHT:

			// nPosが最大値-1でなければインクリメント.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1ページ左
		case SB_PAGELEFT:

			// nPage分減らす.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1ページ右
		case SB_PAGERIGHT:

			// nPage分増やす.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// つまみをドラッグ中.
		case SB_THUMBTRACK:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// つまみをドラッグ後.
		case SB_THUMBPOSITION:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// それ以外.
		default:

			break;

	}

	// スクロール情報設定.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, TRUE);

	// アイテムズパネルの移動.
	m_pWindowListItemsPanel->MoveWindow(0, -m_ScrollInfo.nPos);	// m_pWindowListItemsPanel->MoveWindowでx軸だけ変更.

}

// 垂直方向スクロールバーイベント時のハンドラOnVScroll.
void CWindowListControl::OnVScroll(UINT nSBCode, UINT nPos) {

	// スクロール情報取得.
	m_ScrollInfo.fMask = SIF_POS;	// 位置だけ変更モード(これがないと, スクロールバーが元の位置に戻ってしまうので注意!こっちが前!)
	GetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo);	// マスクを設定してからGetScrollInfo.(こっちが後!)

	// スクロールバー処理.
	switch (nSBCode) {	// nSBCodeごとに振り分け.

		// 一番上
		case SB_TOP:

			// 位置を最小値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// 一番下
		case SB_BOTTOM:

			// 位置を最大値に.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1行上
		case SB_LINEUP:

			// nPosが0でなければデクリメント.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1行下
		case SB_LINEDOWN:

			// nPosが最大値-1でなければインクリメント.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1ページ上
		case SB_PAGEUP:

			// nPage分減らす.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1ページ下
		case SB_PAGEDOWN:

			// nPage分増やす.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// つまみをドラッグ中.
		case SB_THUMBTRACK:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// つまみをドラッグ後.
		case SB_THUMBPOSITION:

			// 引数のnPosをセット
			m_ScrollInfo.nPos = nPos;
			break;

		// それ以外.
		default:

			break;

	}

	// スクロール情報設定.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);

	// アイテムズパネルの移動.
	m_pWindowListItemsPanel->MoveWindow(1, -m_ScrollInfo.nPos);	// m_pWindowListItemsPanel->MoveWindowでy軸だけ変更.

}