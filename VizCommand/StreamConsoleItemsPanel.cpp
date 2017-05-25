// ヘッダのインクルード
// 独自のヘッダ
#include "StreamConsoleItemsPanel.h"	// ストリームコンソールアイテムズパネルクラス

// 子から親へウィンドウサイズ変更の要求が発生した時の独自ハンドラ.
void CStreamConsoleItemsPanel::OnSizeChild(WPARAM wParam, LPARAM lParam){

	// 親ウィンドウの処理だが必要な変数もあるので呼び出しではなくここにコピー.
	// 変数の宣言・初期化.
	int iWidth;
	int iHeight;
	HWND hWnd;
	BOOL bFound = FALSE;

	// 特定のアイテムのリサイズ.
	iWidth = LOWORD(wParam);
	iHeight = HIWORD(wParam);
	hWnd = (HWND)lParam;
	int iTotalHeight = 0;;
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// イテレータ.
	int y = (*itor)->m_y;
	while (itor != m_lstWindowList.end()) {
		(*itor)->MoveWindow(1, y + iTotalHeight);
		iTotalHeight = iTotalHeight + (*itor)->m_iHeight;
		iTotalHeight = iTotalHeight + (PADDING * 2);
		itor++;
	}

	// ウィンドウサイズの変更.
	HWND hParent = GetParent(hWnd);	// hParentがこのウィンドウ.(OnCreateの後なのでメンバに入ってない.)
	::MoveWindow(hParent, m_x, m_y, m_iWidth, iTotalHeight, TRUE);	// 子ウィンドウと同じする.

	// 下へのスクロール要求
	SendMessage(GetParent(hParent), UM_REQUESTSCROLLBOTTOM, (WPARAM)iTotalHeight, 0);	// UM_REQUESTSCROLLBOTTOMで下へスクロール要求.

}
