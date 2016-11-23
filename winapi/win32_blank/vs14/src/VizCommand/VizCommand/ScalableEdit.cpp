// ヘッダのインクルード
#include "ScalableEdit.h"	// スケーラブルエディットコントロール

// ウィンドウ作成関数Create(このウィンドウ専用にカスタマイズされたもの.)
BOOL CScalableEdit::Create(int x, int y, int iWidth, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// 変数の宣言
	HDC hDC;
	HFONT hFont;
	HFONT hOldFont;
	TEXTMETRIC tm;
	BOOL bRet;

	// メンバにセット.
	m_x = x;
	m_y = y;
	m_iWidth = iWidth;
	m_iLineCount = 0;

	// ウィンドウ作成.
	// クラス名"Edit"の子ウィンドウ作成.
	bRet = CWindow::Create(_T("Edit"), _T(""), WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL, x, y, iWidth, 30, hWndParent, hMenu, hInstance, TRUE);	// CWindow::Createでクラス名"Edit"の子ウィンドウを作成.
	if (!bRet) {
		return bRet;
	}

	// 行の高さを計算.
	hDC = GetDC(hWndParent);
	hFont = (HFONT)SendMessage(m_hWnd, WM_GETFONT, 0, 0);
	hOldFont = (HFONT)SelectObject(hDC, hFont);
	GetTextMetrics(hDC, &tm);
	m_iHeight = tm.tmHeight;
	m_iLineHeight = tm.tmHeight;
	m_iExternalLeading = tm.tmExternalLeading;
	SelectObject(hDC, hOldFont);
	ReleaseDC(hWndParent, hDC);

	// ウィンドウリサイズ
	MoveWindow(0, 0, m_iWidth, m_iHeight);

	// bRetを返す.
	return bRet;

}

// キーが押された時.
int CScalableEdit::OnKeyDown(WPARAM wParam, LPARAM lParam) {

	// リターンキーが押された時.
	if (wParam == VK_RETURN) {
		m_iHeight = m_iHeight + m_iLineHeight;
		MoveWindow(m_x, m_y, m_iWidth, m_iHeight);
		m_iLineCount = m_iLineCount + 1;
		WPARAM wParam;
		wParam = MAKEWPARAM(m_iWidth, m_iHeight);
		SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);
	}
	else if (wParam == VK_BACK) {	// バックスペースキーが押された時.
		// 0列目の時.
		POINT pt;
		::GetCaretPos(&pt);
		DWORD dwPos = (DWORD)SendMessage(m_hWnd, EM_CHARFROMPOS, 0, (LPARAM)MAKELPARAM(pt.x, pt.y));
		WORD wRow = HIWORD(dwPos);
		WORD wRowStart = (WORD)SendMessage(m_hWnd, EM_LINEINDEX, wRow, 0);
		WORD wCol;
		wCol = LOWORD(dwPos) - wRowStart;
		if (wCol == 0){
			m_iLineCount = m_iLineCount - 1;
			m_iHeight = m_iHeight - m_iLineHeight;
			MoveWindow(m_x, m_y, m_iWidth, m_iHeight);
			WPARAM wParam;
			wParam = MAKEWPARAM(m_iWidth, m_iHeight);
			SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);
		}
	}

	// 0を返す.
	return 0;

}

// 子ウィンドウのサイズが変更された時(独自メッセージ)
void CScalableEdit::OnSizeChild(HWND hWnd, int width, int height, HWND hChildWnd){

}
