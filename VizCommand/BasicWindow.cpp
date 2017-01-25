// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "BasicWindow.h"	// ベーシックウィンドウクラス

// ウィンドウクラス登録関数RegisterClass
BOOL CBasicWindow::RegisterClass(HINSTANCE hInstance){

	// ウィンドウクラスの登録
	return CWindow::RegisterClass(hInstance, _T("BasicWindow"));	// CWindow::RegisterClassでウィンドウクラス"BasicWindow"を登録.

}

// コンストラクタCBasicWindow()
CBasicWindow::CBasicWindow() : CWindow(){

	// メンバの初期化
	m_pUserControl = NULL;	// m_pUserControlをNULLで初期化.

}

// デストラクタ~CBasicWindow()
CBasicWindow::~CBasicWindow(){

	// メンバの終了処理.
	if (m_pUserControl != NULL) {
		delete m_pUserControl;	// deleteでm_pUserControlを解放.
		m_pUserControl = NULL;	// m_pUserControlをNULLで埋める.
	}

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CBasicWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){
	
	// ここに来る場合はウィンドウクラス"BasicWindow"のウィンドウとして作成.
	return CWindow::Create(_T("BasicWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// ウィンドウクラスを"BasicWindow"にしてCreateのフルバージョンを呼ぶ.

}

// ウィンドウ作成時のハンドラOnCreate.
int CBasicWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ユーザコントロールの作成.
	m_pUserControl = new CUserControl();	// CUserControlオブジェクトを作成し, ポインタをm_pUserControlに格納.
	m_pUserControl->Create(_T("UserControl"), _T(""), WS_BORDER, 100, 100, 200, 200, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// m_pUserControl->Createでウィンドウクラス名"UserControl"なウィンドウを作成.

	// ウィンドウ作成成功
	return 0;	// 成功なので0を返す.

}