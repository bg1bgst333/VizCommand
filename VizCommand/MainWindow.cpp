// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "MainWindow.h"		// メニューウィンドウクラス
#include "EditBoxPanel.h"	// エディットボックスパネルクラス
//#include "MainMenuBar.h"	// メインメニューバークラス

// ウィンドウクラス登録関数RegisterClass
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録
	return CWindow::RegisterClass(hInstance, _T("MainWindow"));	// CWindow::RegisterClassでウィンドウクラス"MainWindow"を登録.

}

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() : CBasicWindow() {

	// メンバの初期化
	m_pWindowListControl = NULL;	// m_pWindowListControlをNULLで初期化.

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow() {

	// メンバの終了処理.
	Destroy();	// Destroyで破棄.

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ここに来る場合はウィンドウクラス"MainWindow"のウィンドウとして作成.
	return CWindow::Create(_T("MainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// ウィンドウクラスを"MainWindow"にしてCreateのフルバージョンを呼ぶ.

}

// ウィンドウ破棄関数Destroy
void CMainWindow::Destroy() {

	// 子ウィンドウの破棄.
	if (m_pWindowListControl != NULL) {
		m_pWindowListControl->Destroy();	// m_pWindowListControlのウィンドウを破棄.
		delete m_pWindowListControl;		// m_pWindowListControlを解放.
		m_pWindowListControl = NULL;		// m_pWindowListControlをNULLで埋める.
	}

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// ウィンドウ作成時のハンドラOnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

#if 1

	// ウィンドウリストコントロールの作成.
	m_pWindowListControl = new CWindowListControl();	// CWindowListControlオブジェクトを作成し, ポインタをm_pWindowListControlに格納.
	//m_pWindowListControl->Create(_T(""), 0, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Createでウィンドウリストコントロールを作成.
	m_pWindowListControl->Create(_T(""), WS_VSCROLL, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Createでウィンドウリストコントロールを作成.

	// アイテムを挿入.
	m_pWindowListControl->Insert(_T("0"), 0, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで0番目にウィンドウを挿入.
	m_pWindowListControl->Insert(_T("1"), 1, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで1番目にウィンドウを挿入.
	m_pWindowListControl->Insert(_T("2"), 2, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで2番目にウィンドウを挿入.
	m_pWindowListControl->Insert(_T("3"), 3, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで3番目にウィンドウを挿入.
	m_pWindowListControl->Insert(_T("4"), 4, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで4番目にウィンドウを挿入.
	m_pWindowListControl->Insert(_T("5"), 5, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで5番目にウィンドウを挿入.
	m_pWindowListControl->Insert(_T("6"), 6, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで6番目にウィンドウを挿入.

	// 子ウィンドウを挿入.
	CWindowListItem * pItem = m_pWindowListControl->Get(0);	// m_pWindowListControl->Getで0番目を取得.
	CEditBoxPanel *pEditBoxPanel = new CEditBoxPanel();	// エディットボックスパネルの生成.
	pEditBoxPanel->Create(_T(""), 0, 3, 3, pItem->m_iWidth - (3 * 2), pItem->m_iHeight - (3 * 2), pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, lpCreateStruct->hInstance);	// Createで生成.
	pItem->m_mapChildMap.insert(std::make_pair(_T("EditBoxPanel"), pEditBoxPanel));	// pItem->m_mapChildMap.insertでマップ登録.

#else

	// ウィンドウリストコントロールの作成.
	m_pWindowListControl = new CWindowListControl();	// CWindowListControlオブジェクトを作成し, ポインタをm_pWindowListControlに格納.
	m_pWindowListControl->Create(_T(""), WS_HSCROLL | WS_VSCROLL, 3, 3, m_iWidth - 3, m_iHeight - 3, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Createでウィンドウリストコントロールを作成.(この時点では, まだWS_BORDERを付けている.)

	// 1つ目のアイテムを挿入.
	m_pWindowListControl->Insert(_T("0"), 0, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで0番目にウィンドウを挿入.
	CWindowListItem * pItem = m_pWindowListControl->Get(0);	// m_pWindowListControl->Getで0番目を取得.
	CEditBoxPanel *pEditBoxPanel = new CEditBoxPanel();
	pEditBoxPanel->Create(_T(""), WS_BORDER, 3, 3, pItem->m_iWidth - 6, pItem->m_iHeight - 6, pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, lpCreateStruct->hInstance);	// Createで生成.
	pItem->m_mapChildMap.insert(std::make_pair(_T("EditBoxPanel"), pEditBoxPanel));	// pItem->m_mapChildMap.insertでマップ登録.

#endif

	// 成功.
	return 0;	// 成功なので0を返す.

}

// ウィンドウサイズが変更された時のハンドラOnSize.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

	// 実際のウィンドウサイズを格納.
	RECT rcWindow;
	GetWindowRect(m_hWnd, &rcWindow);	// GetWindowRectでウィンドウ全体のサイズを取得.
	m_iWidth = rcWindow.right - rcWindow.left;	// m_iWidthにrcWindow.right - rcWindow.leftをセット.
	m_iHeight = rcWindow.bottom - rcWindow.top;	// m_iHeightにrcWindow.bottom - rcWindow.topをセット.

	// 引数のクライアント領域のサイズを使って子ウィンドウをリサイズ.
	//m_pWindowListControl->MoveWindow(1, 1, cx - (1 * 2), cy - (1 * 2));	// 1周り小さいとなると, 1pxなら2倍の2pxサイズが小さくならなければならない.
	m_pWindowListControl->MoveWindow(3, 3, cx - (3 * 2), cy - (3 * 2));	// 3pxなら2倍の6pxサイズが小さくならなければならない.

}