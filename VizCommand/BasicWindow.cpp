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

}

// デストラクタ~CBasicWindow()
CBasicWindow::~CBasicWindow(){

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CBasicWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){
	
	// ここに来る場合はウィンドウクラス"BasicWindow"のウィンドウとして作成.
	return CWindow::Create(_T("BasicWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// ウィンドウクラスを"BasicWindow"にしてCreateのフルバージョンを呼ぶ.

}

// ウィンドウ作成時のハンドラOnCreate.
int CBasicWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ウィンドウ作成成功
	return 0;	// 成功なので0を返す.

}