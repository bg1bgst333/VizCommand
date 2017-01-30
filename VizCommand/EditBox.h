// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "CustomControl.h"	// カスタムコントロールクラス

// エディットボックスクラスCEditBox
class CEditBox : public CCustomControl {

	// publicメンバ
	public:

		// コンストラクタ・デストラクタ
		CEditBox();	// コンストラクタCEditBox()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)

};
