// ヘッダのインクルード
#include "WindowListItem.h"	// ウィンドウリストアイテムクラス

// ウィンドウ作成関数Create.
BOOL CWindowListItem::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// メンバにセット.
	m_x = x;	// m_xにxをセット.
	m_y = y;	// m_yにyをセット.
	m_iWidth = iWidth;	// m_iWidthにiWidthをセット.
	m_iHeight = iHeight;	// m_iHeightにiHeightをセット.

	// クラス名"WindowListItem"の子ウィンドウを作成.
	return CWindow::Create(_T("WindowListItem"), _T(""), WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createでクラス名"WindowListItem"の子ウィンドウを作成.

}

// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
void CWindowListItem::Destroy() {

	// 破棄.
	DestroyWindow(m_hWnd);	// DestroyWindowでm_hWndを破棄.
	m_hWnd = NULL;	// m_hWndをNULLにする.

}

// ウィンドウにテキストをセットするメンバ関数SetWindowText.
void CWindowListItem::SetWindowText(LPCTSTR lpctszString) {

	_tcscpy_s(m_tszText, 256, lpctszString);

}

// ウィンドウのサイズや位置を変更するメンバ関数MoveWindow.
void CWindowListItem::MoveWindow(int x, int y, int iWidth, int iHeight){

	m_x = x;
	m_y = y;
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	::MoveWindow(m_hWnd, x, y, iWidth, iHeight, TRUE);

}

// ウィンドウ作成時のハンドラOnCreate.
int CWindowListItem::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// ウィンドウ作成成功
	return 0;	// 成功なら0を返す.

}

// ウィンドウ破棄時のハンドラOnDestroy
void CWindowListItem::OnDestroy() {

}

// ウィンドウのサイズが変更された時のハンドラOnSize.
void CWindowListItem::OnSize(UINT nType, int cx, int cy){

	// サイズ更新
	m_iWidth = cx;
	m_iHeight = cy;

}

// 画面描画の更新を要求された時.
void CWindowListItem::OnPaint() {

	// 変数の宣言
	HDC hDC;
	PAINTSTRUCT ps;

	// 描画の開始.
	hDC = ::BeginPaint(m_hWnd, &ps);

	// アイテムズパネルの領域を矩形で描画.
	HPEN hOldPen;
	HBRUSH hOldBrush;
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	HBRUSH hWhiteBrush = CreateSolidBrush(RGB(0, 0, 255));
	hOldPen = (HPEN)SelectObject(hDC, hGreenPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hWhiteBrush);
	Rectangle(hDC, m_x, m_y, m_iWidth, m_iHeight);
	SelectObject(hDC, hOldBrush);
	SelectObject(hDC, hOldPen);
	DeleteObject(hWhiteBrush);
	DeleteObject(hGreenPen);

	// テキスト描画.
	::TextOut(hDC, 0, 0, m_tszText, lstrlen(m_tszText));

	// 描画の終了.
	::EndPaint(m_hWnd, &ps);

}

// ウィンドウを閉じる時のハンドラOnClose.
int CWindowListItem::OnClose() {

	// 0を返す.
	return 0;	// 0を返してウィンドウを閉じる.

}