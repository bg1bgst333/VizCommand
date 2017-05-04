// ヘッダのインクルード
// 独自のヘッダ
#include "ListControl.h"	// リストコントロールクラス

// コンストラクタCListControl()
CListControl::CListControl() : CCustomControl() {

}

// デストラクタ~CListControl()
CListControl::~CListControl() {

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CListControl::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの作成.
	return CCustomControl::Create(_T("SysListView32"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Createでウィンドウを作成し, その戻り値をreturnで返す.

}

// ウィンドウ破棄関数Destroy
void CListControl::Destroy() {

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}