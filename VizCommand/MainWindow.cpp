// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "MainWindow.h"		// メニューウィンドウクラス
#include "EditBox.h"		// エディットボックスクラス
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

	// ウィンドウリストコントロールの作成.
	m_pWindowListControl = new CWindowListControl();	// // CWindowListControlオブジェクトを作成し, ポインタをm_pWindowListControlに格納.
	m_pWindowListControl->Create(_T(""), WS_HSCROLL | WS_VSCROLL, 50, 50, 400, 300, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Createでウィンドウリストコントロールを作成.(この時点では, まだWS_BORDERを付けている.)

	// 1つ目のアイテムを挿入.
	m_pWindowListControl->Insert(_T("0"), 0, 50, lpCreateStruct->hInstance);	// m_pWindowListControl->Insertで0番目にウィンドウを挿入.
	CWindowListItem * pItem = m_pWindowListControl->Get(0);	// m_pWindowListControl->Getで0番目を取得.
	CEditBox *pEditBox = new CEditBox();	// エディットボックス作成.
	pEditBox->Create(_T(""), WS_BORDER, 30, 10, 100, 30, pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, lpCreateStruct->hInstance);	// Createで生成.
	pItem->m_mapChildMap.insert(std::make_pair(_T("EditBox"), pEditBox));	// pItem->m_mapChildMap.insertでマップ登録.

	// 成功.
	return 0;	// 成功なので0を返す.

}

// ウィンドウサイズが変更された時のハンドラOnSize.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

}