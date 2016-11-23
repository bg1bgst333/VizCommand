// ヘッダのインクルード
#include "ScalableEdit.h"	// スケーラブルエディットコントロール
#include "ScalableEditPanel.h"	// スケーラブルエディットパネルクラス

// ウィンドウ作成関数Create(このウィンドウ専用にカスタマイズされたもの.)
BOOL CScalableEditPanel::Create(int x, int y, int iWidth, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// メンバにセット.
	m_x = x;
	m_y = y;
	m_iWidth = iWidth;
	m_nID = hMenu;

	// 高さは適当にセット.
	m_iHeight = 200;

	// クラス名"ScalableEditPanel"の子ウィンドウを作成.
	return CWindow::Create(_T("ScalableEditPanel"), _T(""), WS_CHILD | WS_VISIBLE , x, y, iWidth, m_iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createでクラス名"ScalableEditPanel"の子ウィンドウを作成.

}

// ウィンドウ作成時のハンドラOnCreate.
int CScalableEditPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// 変数の初期化
	CScalableEdit *pScalableEdit = NULL;
	BOOL bRet = FALSE;

	// 子ウィンドウとなるスケーラブルエディットコントロールオブジェクトの作成.
	pScalableEdit = new CScalableEdit();
	bRet = pScalableEdit->Create(m_x, m_y, m_iWidth, hwnd, m_nID + 100, lpCreateStruct->hInstance);
	m_pEdit = pScalableEdit;
	m_iLineHeight = pScalableEdit->m_iLineHeight;
	m_iHeight = m_iLineHeight;
	::MoveWindow(hwnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);
	if (bRet) {
		return 0;
	}
	else {
		if (m_pEdit != NULL) {
			m_pEdit->Destroy();
			delete m_pEdit;
			m_pEdit = NULL;
		}
		return -1;
	}

}

// ウィンドウのサイズが変更された時のハンドラOnSize.
void CScalableEditPanel::OnSize(UINT nType, int cx, int cy){

	m_pEdit->MoveWindow(0, 0, cx, cy);

}

// 画面描画の更新を要求された時.
void CScalableEditPanel::OnPaint(){

	// 変数の宣言
	HDC hDC;
	PAINTSTRUCT ps;

	// 描画の開始.
	hDC = ::BeginPaint(m_hWnd, &ps);

	// アイテムズパネルの領域を矩形で描画.
	HPEN hOldPen;
	HBRUSH hOldBrush;
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 0, 0));
	hOldPen = (HPEN)SelectObject(hDC, hGreenPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hWhiteBrush);
	Rectangle(hDC, m_x, m_y, m_iWidth, m_iHeight);
	SelectObject(hDC, hOldBrush);
	SelectObject(hDC, hOldPen);
	DeleteObject(hWhiteBrush);
	DeleteObject(hGreenPen);

	// 描画の終了.
	::EndPaint(m_hWnd, &ps);

}

// キーが押された時.
int CScalableEditPanel::OnKeyDown(WPARAM wParam, LPARAM lParam){

	// とりあえず0を返す.
	return 0;

}

// 子ウィンドウのサイズが変更された時(独自メッセージ)
void CScalableEditPanel::OnSizeChild(HWND hWnd, int width, int height, HWND hChildWnd){

	::MoveWindow(m_hWnd, 0, 0, width, height, TRUE);

}
