// ヘッダのインクルード
// 独自のヘッダ
#include "ListControlPanel.h"	// リストコントロールパネルクラス
// 既定のヘッダ
#include <commctrl.h>	// コモンコントロール

// ウィンドウクラス登録関数RegisterClass
BOOL CListControlPanel::RegisterClass(HINSTANCE hInstance) {

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("ListControlPanel"));	// CUserControl::RegisterClassでウィンドウクラス"ListControlPanel"を登録.

}

// コンストラクタCListControlPanel
CListControlPanel::CListControlPanel() : CUserControl() {

	// メンバの初期化
	m_pListControl = NULL;	// m_pListControlをNULLで初期化.

}

// デストラクタ~CListControlPanel()
CListControlPanel::~CListControlPanel() {

	// メンバの終了処理.
	Destroy();	// Destroyで破棄.

}

// ウィンドウ作成関数Create
BOOL CListControlPanel::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	m_nId = hMenu;
	return CUserControl::Create(_T("ListControlPanel"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, m_nId, hInstance);	// CUserControl::Createでウィンドウクラス"ListControlPanel"なウィンドウを作成.

}

// ウィンドウ破棄関数Destroy
void CListControlPanel::Destroy() {

	// 子ウィンドウの破棄.
	if (m_pListControl != NULL) {
		m_pListControl->Destroy();	// m_pListControlのウィンドウを破棄.
		delete m_pListControl;	// deleteで解放.
		m_pListControl = NULL;	// NULLで埋める.
	}

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// ウィンドウ作成時のハンドラOnCreate.
int CListControlPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 子リストコントロールの生成.
	m_pListControl = new CListControl();	// CListControlオブジェクトを作成し, ポインタをm_pListControlに格納.
	m_pListControl->Create(_T(""), WS_BORDER | WS_VSCROLL | WS_HSCROLL | LVS_ICON, PADDING, PADDING, m_iWidth - (PADDING * 2), m_iHeight - (PADDING * 2), hwnd, m_nId + 100, lpCreateStruct->hInstance);	// m_pListControl->Createでリストコントロール作成.

	// 成功なので0を返す.
	return 0;

}

// ウィンドウサイズが変更された時のハンドラOnSize.
void CListControlPanel::OnSize(UINT nType, int cx, int cy) {

	// 実際のウィンドウサイズを格納.
	m_iWidth = cx;	// m_iWidthにcxをセット.
	m_iHeight = cy;	// m_iHeightにcyをセット.

	// 子ウィンドウのリサイズ
	if (m_pListControl != NULL) {
		m_pListControl->MoveWindow(PADDING, PADDING, m_iWidth - (PADDING * 2), m_iHeight - (PADDING * 2));
	}

}