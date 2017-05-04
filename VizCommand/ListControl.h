// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// 独自のヘッダ
#include "CustomControl.h"	// カスタムコントロールクラス

// リストコントロールクラスCListControl
class CListControl : public CCustomControl {

	// publicメンバ
	public:

		// コンストラクタ・デストラクタ
		CListControl();	// コンストラクタCListControl()
		virtual ~CListControl();	// デストラクタ~CListControl()

		// メンバ関数
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// ウィンドウ作成関数Create(lpctszClassName省略)
		virtual void Destroy();	// ウィンドウ破棄関数Destroy

};