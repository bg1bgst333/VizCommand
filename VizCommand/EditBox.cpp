// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "EditBox.h"	// エディットボックスクラス

// コンストラクタCEditBox()
CEditBox::CEditBox() : CCustomControl() {

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CEditBox::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){
	
	// ウィンドウの作成.
	return CCustomControl::Create(_T("Edit"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Createでウィンドウを作成し, その戻り値をreturnで返す.

}