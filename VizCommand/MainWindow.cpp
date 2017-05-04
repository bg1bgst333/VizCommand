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

// ウィンドウクラス登録関数RegisterClass(背景ブラシ指定)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, HBRUSH hBrush) {

	// ウィンドウクラスの登録
	return CWindow::RegisterClass(hInstance, _T("MainWindow"), hBrush);	// CWindow::RegisterClass(背景ブラシ指定)でウィンドウクラス"MainWindow"を登録.

}

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() : CBasicWindow() {

	// メンバの初期化
	//m_pWindowListControl = NULL;	// m_pWindowListControlをNULLで初期化.
	//m_pScalableEditBox = NULL;	// m_pScalableEditBoxをNULLにセット.
	//m_pScalableEditBoxPanel = NULL;	// m_pScalableEditBoxPanelをNULLにセット.
	m_pStreamConsole = NULL;	// m_pStreamConsoleをNULLで初期化.
	m_pConsole = NULL;	// m_pConsoleをNULLにセット.
	m_pListControlPanel = NULL;	// m_pListControlPanelをNULLにセット.

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
	if (m_pListControlPanel != NULL) {
		m_pListControlPanel->Destroy();
		delete m_pListControlPanel;
		m_pListControlPanel = NULL;
	}
	if (m_pConsole != NULL) {
		m_pConsole->Destroy();
		delete m_pConsole;
		m_pConsole = NULL;
	}
	if (m_pStreamConsole != NULL) {
		m_pStreamConsole->Destroy();
		delete m_pStreamConsole;
		m_pStreamConsole = NULL;
	}
	/*
	if (m_pScalableEditBoxPanel != NULL) {
	m_pScalableEditBoxPanel->Destroy();
	delete m_pScalableEditBoxPanel;
	m_pScalableEditBoxPanel = NULL;
	}
	*/
	/*
	if (m_pScalableEditBox != NULL) {
	m_pScalableEditBox->Destroy();
	delete m_pScalableEditBox;
	m_pScalableEditBox = NULL;
	}
	*/
	/*
	if (m_pWindowListControl != NULL) {
	m_pWindowListControl->Destroy();	// m_pWindowListControlのウィンドウを破棄.
	delete m_pWindowListControl;		// m_pWindowListControlを解放.
	m_pWindowListControl = NULL;		// m_pWindowListControlをNULLで埋める.
	}
	*/

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// ウィンドウ作成時のハンドラOnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ストリームコンソールの作成.
	//m_pStreamConsole = new CStreamConsole();	// CStreamConsoleオブジェクトを作成し, ポインタをm_pStreamConsoleに格納.
	//m_pStreamConsole->Create(_T(""), WS_VSCROLL, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_STREAMCONSOLE, lpCreateStruct->hInstance);	// m_pStreamConsole->Createでストリームコンソールを作成.

	// ウィンドウリストコントロールの作成.
	//m_pWindowListControl = new CWindowListControl();	// CWindowListControlオブジェクトを作成し, ポインタをm_pWindowListControlに格納.
	//m_pWindowListControl->Create(_T(""), WS_VSCROLL, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Createでウィンドウリストコントロールを作成.

	// リストコントロールの作成.
	m_pListControlPanel = new CListControlPanel();	// CListControlPanelオブジェクトを作成し, m_pListControlPanelに格納.
	m_pListControlPanel->Create(_T(""), 0, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, lpCreateStruct->hInstance);	// m_pListControlPanel->Createでリストコントロールパネルを作成.

#if 0

	// アイテムを挿入.
	m_pWindowListControl->Insert(_T("0"), 0, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで0番目にウィンドウを挿入.
	m_pWindowListControl->Insert(_T("1"), 1, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで1番目にウィンドウを挿入.
	m_pWindowListControl->Insert(_T("2"), 2, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで2番目にウィンドウを挿入
	m_pWindowListControl->Insert(_T("3"), 3, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで3番目にウィンドウを挿入.
	m_pWindowListControl->Insert(_T("4"), 4, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで4番目にウィンドウを挿入

	// 子ウィンドウを挿入.
	CWindowListItem * pItem1 = m_pWindowListControl->Get(0);	// m_pWindowListControl->Getで0番目を取得.
	CScalableEditBoxPanel *pScalableEditBoxPanel1 = new CScalableEditBoxPanel();	// スカラブルエディットボックスパネルの生成.
	pScalableEditBoxPanel1->Create(_T(""), 0, 0, 0, pItem1->m_iWidth, pItem1->m_iHeight, pItem1->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, lpCreateStruct->hInstance);	// Createで生成.
	pItem1->m_mapChildMap.insert(std::make_pair(_T("ScalableEditBoxPanel"), pScalableEditBoxPanel1));	// pItem->m_mapChildMap.insertでマップ登録.

	// 子ウィンドウを挿入.
	CWindowListItem * pItem2 = m_pWindowListControl->Get(1);	// m_pWindowListControl->Getで1番目を取得.
	CScalableEditBoxPanel *pScalableEditBoxPanel2 = new CScalableEditBoxPanel();	// スカラブルエディットボックスパネルの生成.
	pScalableEditBoxPanel2->Create(_T(""), 0, 0, 0, pItem2->m_iWidth, pItem2->m_iHeight, pItem2->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + 1, lpCreateStruct->hInstance);	// Createで生成.
	pItem2->m_mapChildMap.insert(std::make_pair(_T("ScalableEditBoxPanel"), pScalableEditBoxPanel2));	// pItem->m_mapChildMap.insertでマップ登録.

	// 子ウィンドウを挿入.
	CWindowListItem * pItem3 = m_pWindowListControl->Get(3);	// m_pWindowListControl->Getで3番目を取得.
	CScalableEditBoxPanel *pScalableEditBoxPanel3 = new CScalableEditBoxPanel();	// スカラブルエディットボックスパネルの生成.
	pScalableEditBoxPanel3->Create(_T(""), 0, 0, 0, pItem3->m_iWidth, pItem3->m_iHeight, pItem3->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + 2, lpCreateStruct->hInstance);	// Createで生成.
	pItem3->m_mapChildMap.insert(std::make_pair(_T("ScalableEditBoxPanel"), pScalableEditBoxPanel3));	// pItem->m_mapChildMap.insertでマップ登録.

#if 1

	//m_pScalableEditBox = new CScalableEditBox();
	//m_pScalableEditBox->Create(_T(""), ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 50, 50, 300, 200, hwnd, (HMENU)IDC_SCALABLEEDIT1, lpCreateStruct->hInstance);

	//m_pScalableEditBoxPanel = new CScalableEditBoxPanel();
	//m_pScalableEditBoxPanel->Create(_T(""), 0, 50, 50, 300, 200, hwnd, (HMENU)IDC_SCALABLEEDIT1, lpCreateStruct->hInstance);

#else

#if 1

	// ウィンドウリストコントロールの作成.
	m_pWindowListControl = new CWindowListControl();	// CWindowListControlオブジェクトを作成し, ポインタをm_pWindowListControlに格納.
	//m_pWindowListControl->Create(_T(""), 0, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Createでウィンドウリストコントロールを作成.
	m_pWindowListControl->Create(_T(""), WS_VSCROLL, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Createでウィンドウリストコントロールを作成.

	// アイテムを挿入.
	m_pWindowListControl->Insert(_T("0"), 0, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで0番目にウィンドウを挿入.
	m_pWindowListControl->Insert(_T("1"), 1, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで1番目にウィンドウを挿入.
	m_pWindowListControl->Insert(_T("2"), 2, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで2番目にウィンドウを挿入.
	//m_pWindowListControl->Insert(_T("3"), 3, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで3番目にウィンドウを挿入.
	//m_pWindowListControl->Insert(_T("4"), 4, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで4番目にウィンドウを挿入.
	//m_pWindowListControl->Insert(_T("5"), 5, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで5番目にウィンドウを挿入.
	//m_pWindowListControl->Insert(_T("6"), 6, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで6番目にウィンドウを挿入.

#if 1
	// 子ウィンドウを挿入.
	CWindowListItem * pItem1 = m_pWindowListControl->Get(0);	// m_pWindowListControl->Getで0番目を取得.
	CEditBoxPanel *pEditBoxPanel1 = new CEditBoxPanel();	// エディットボックスパネルの生成.
	pEditBoxPanel1->Create(_T(""), 0, PADDING + 50, PADDING, pItem1->m_iWidth - (PADDING * 2), pItem1->m_iHeight - (PADDING * 2), pItem1->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, lpCreateStruct->hInstance);	// Createで生成.
	pItem1->m_mapChildMap.insert(std::make_pair(_T("EditBoxPanel"), pEditBoxPanel1));	// pItem->m_mapChildMap.insertでマップ登録.

	// 子ウィンドウを挿入.
	CWindowListItem * pItem2 = m_pWindowListControl->Get(1);	// m_pWindowListControl->Getで1番目を取得.
	CEditBoxPanel *pEditBoxPanel2 = new CEditBoxPanel();	// エディットボックスパネルの生成.
	pEditBoxPanel2->Create(_T(""), 0, PADDING + 50, PADDING, pItem2->m_iWidth - (PADDING * 2), pItem2->m_iHeight - (PADDING * 2), pItem2->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + 1, lpCreateStruct->hInstance);	// Createで生成.
	pItem2->m_mapChildMap.insert(std::make_pair(_T("EditBoxPanel"), pEditBoxPanel2));	// pItem->m_mapChildMap.insertでマップ登録.

	// 子ウィンドウを挿入.
	CWindowListItem * pItem3 = m_pWindowListControl->Get(2);	// m_pWindowListControl->Getで2番目を取得.
	CEditBoxPanel *pEditBoxPanel3 = new CEditBoxPanel();	// エディットボックスパネルの生成.
	pEditBoxPanel3->Create(_T(""), 0, PADDING + 50, PADDING, pItem3->m_iWidth - (PADDING * 2), pItem3->m_iHeight - (PADDING * 2), pItem3->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + 2, lpCreateStruct->hInstance);	// Createで生成.
	pItem3->m_mapChildMap.insert(std::make_pair(_T("EditBoxPanel"), pEditBoxPanel3));	// pItem->m_mapChildMap.insertでマップ登録.
#endif
	// 削除
	m_pWindowListControl->Remove(1);
	//m_pWindowListControl->Remove(1);
	//m_pWindowListControl->Remove(0);
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

#endif

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
	//if (m_pWindowListControl != NULL) {
	//	m_pWindowListControl->MoveWindow(PADDING, PADDING, cx - (PADDING * 2), cy - (PADDING * 2));	// 3pxなら2倍の6pxサイズが小さくならなければならない.
	//}
	if (m_pStreamConsole != NULL) {
		m_pStreamConsole->MoveWindow(PADDING, PADDING, cx - (PADDING * 2), cy - (PADDING * 2));	// 3pxなら2倍の6pxサイズが小さくならなければならない.
	}
	if (m_pListControlPanel != NULL) {
		m_pListControlPanel->MoveWindow(PADDING, PADDING, cx - (PADDING * 2), cy - (PADDING * 2));	// 3pxなら2倍の6pxサイズが小さくならなければならない.
	}

}