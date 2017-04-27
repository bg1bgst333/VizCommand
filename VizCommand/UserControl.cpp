// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "UserControl.h"	// ユーザコントロールクラス

// ウィンドウクラス登録関数RegisterClass(ウィンドウクラス名指定)
BOOL CUserControl::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName) {

	// ウィンドウクラスの登録
	return CWindow::RegisterClass(hInstance, lpctszClassName);	// CWindow::RegisterClassでウィンドウクラスlpctszClassNameを登録.

}

// コンストラクタCUserControl()
CUserControl::CUserControl() : CWindow() {

}

// ウィンドウ作成関数Create
BOOL CUserControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ここに来る場合はウィンドウクラスlpctszClassNameなウィンドウとして作成.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// ウィンドウクラスをlpctszClassNameにして, dwStyleにWS_CHILDとWS_VISIBLEを追加して, Createのフルバージョンを呼ぶ.

}

// ウィンドウ破棄時のハンドラOnDestroy.
void CUserControl::OnDestroy() {

}
