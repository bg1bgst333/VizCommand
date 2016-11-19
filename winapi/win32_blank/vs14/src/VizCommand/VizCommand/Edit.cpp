// ヘッダのインクルード
#include "Edit.h"	// エディットコントロール

// ウィンドウ作成関数Create.
BOOL CEdit::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){
	
	// クラス名"Edit"の子ウィンドウ作成.
	return CWindow::Create(_T("Edit"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, TRUE);	// CWindow::Createでクラス名"EditPanel"の子ウィンドウを作成.

}

// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
void CEdit::Destroy() {

	// 破棄.
	DestroyWindow(m_hWnd);	// DestroyWindowでm_hWndを破棄.
	m_hWnd = NULL;	// m_hWndをNULLにする.

}

// ウィンドウのサイズや位置を変更するメンバ関数MoveWindow.
void CEdit::MoveWindow(int x, int y, int iWidth, int iHeight){

	// エディットコントロールのサイズ更新.
	m_x = x;
	m_y = y;
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	::MoveWindow(m_hWnd, x, y, iWidth, iHeight, TRUE);

}

// ウィンドウ作成時のハンドラOnCreate.
int CEdit::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	return 0;

}

// ウィンドウ破棄時のハンドラOnDestroy.
void CEdit::OnDestroy(){

}

// ウィンドウを閉じる時のハンドラOnClose.
int CEdit::OnClose(){

	return 0;

}

// キーが押された時.
int CEdit::OnKeyDown(WPARAM wParam, LPARAM lParam){

	// リターンキーが押されたらメッセージボックス.
	if (wParam == VK_RETURN) {
		MessageBox(m_hWnd, _T("リターンキーが押された!"), _T("VizCommand"), MB_OK);
	}

	// 0を返す.
	return 0;

}
