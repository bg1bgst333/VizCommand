// ヘッダのインクルード
// 独自のヘッダ
#include "EditBoxPanel.h"	// エディットボックスパネルクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CEditBoxPanel::RegisterClass(HINSTANCE hInstance) {

	// ユーザコントロールとして登録.
	return CUserControl::RegisterClass(hInstance, _T("EditBoxPanel"));	// CUserControl::RegisterClassでウィンドウクラス"EditBoxPanel"を登録.

}

// コンストラクタCEditBoxPanel
CEditBoxPanel::CEditBoxPanel() : CUserControl() {

	// メンバの初期化
	m_pEditBox = NULL;	// m_pEditBoxをNULLで初期化.

}

// デストラクタ~CEditBoxPanel()
CEditBoxPanel::~CEditBoxPanel() {

	// メンバの終了処理.
	Destroy();	// Destroyで破棄.

}

// ウィンドウ作成関数Create
BOOL CEditBoxPanel::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ユーザコントロールで作成.
	m_nId = hMenu;
	return CUserControl::Create(_T("EditBoxPanel"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, m_nId, hInstance);	// CUserControl::Createでウィンドウクラス"EditBoxPanel"なウィンドウを作成.

}

// ウィンドウ破棄関数Destroy
void CEditBoxPanel::Destroy() {

	// 子ウィンドウの破棄.
	if (m_pEditBox != NULL) {
		m_pEditBox->Destroy();	// m_pEditBoxのウィンドウを破棄.
		delete m_pEditBox;	// deleteで解放.
		m_pEditBox = NULL;	// NULLで埋める.
	}

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// ウィンドウ作成時のハンドラOnCreate.
int CEditBoxPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// 子エディットボックスの生成.
	m_pEditBox = new CEditBox();	// CEditBoxオブジェクトを作成し, ポインタをm_pEditBoxに格納.
	m_pEditBox->Create(_T(""), WS_BORDER | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 3, 3, m_iWidth - (3 * 2), m_iHeight - (3 * 2), hwnd, m_nId + 100, lpCreateStruct->hInstance);	// m_pEditBox->Createでエディットボックス作成.

	// 成功なので0を返す.
	return 0;

}

// ウィンドウサイズが変更された時のハンドラOnSize.
void CEditBoxPanel::OnSize(UINT nType, int cx, int cy) {

	// 実際のウィンドウサイズを格納.
	m_iWidth = cx;	// m_iWidthにcxをセット.
	m_iHeight = cy;	// m_iHeightにcyをセット.

	// 子ウィンドウのリサイズ
	if (m_pEditBox != NULL) {
		m_pEditBox->MoveWindow(3, 3, m_iWidth - (3 * 2), m_iHeight - (3 * 2));
	}

}