// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "MainWindow.h"		// メインウィンドウクラス	

// ウィンドウクラス登録関数RegisterClass
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// ウィンドウクラスの登録
	return CWindow::RegisterClass(hInstance, _T("MainWindow"));	// CWindow::RegisterClassでウィンドウクラス"MainWindow"を登録.

}

// コンストラクタCMainWindow()
CMainWindow::CMainWindow() : CBasicWindow() {

	// メンバの初期化
	m_pUserControl = NULL;		// m_pUserControlをNULLで初期化.
	m_pCustomControl = NULL;	// m_pCustomControlをNULLで初期化.

}

// デストラクタ~CMainWindow()
CMainWindow::~CMainWindow() {

	// メンバの終了処理.
	if (m_pCustomControl != NULL) {
		delete m_pCustomControl;	// deleteでm_pCustomControlを解放.
		m_pCustomControl = NULL;	// m_pCustomControlをNULLで埋める.
	}
	if (m_pUserControl != NULL) {
		delete m_pUserControl;	// deleteでm_pUserControlを解放.
		m_pUserControl = NULL;	// m_pUserControlをNULLで埋める.
	}

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ここに来る場合はウィンドウクラス"MainWindow"のウィンドウとして作成.
	return CWindow::Create(_T("MainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// ウィンドウクラスを"MainWindow"にしてCreateのフルバージョンを呼ぶ.

}

// ウィンドウ作成時のハンドラOnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ユーザコントロールの作成.
	m_pUserControl = new CUserControl();	// CUserControlオブジェクトを作成し, ポインタをm_pUserControlに格納.
	m_pUserControl->Create(_T("UserControl"), _T(""), WS_BORDER, 50, 50, 100, 100, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// m_pUserControl->Createでウィンドウクラス名"UserControl"なウィンドウを作成.

	// カスタムコントロールの作成.
	m_pCustomControl = new CCustomControl();	// CCustomControlオブジェクトを作成し, ポインタをm_pCustomControlに格納.
	m_pCustomControl->Create(_T("Edit"), _T(""), WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 150, 150, 200, 50, hwnd, (HMENU)(WM_APP + 2), lpCreateStruct->hInstance);	// m_pCustomControl->Createでウィンドウクラス名"Edit"なウィンドウを作成.

	// 成功.
	return 0;	// 成功なので0を返す.

}