// 二重インクルード防止
#pragma once	// #pragma onceで二重インクルード防止.

// ヘッダのインクルード
// 独自のヘッダ
#include "EditBox.h"	// エディットボックスクラス

// コンストラクタCEditBox()
CEditBox::CEditBox() : CCustomControl() {

	// 初期化.
	m_ptszText = NULL;	// m_ptszTextにNULLをセット.

}

// デストラクタ~CEditBox()
CEditBox::~CEditBox() {

	// メンバの終了処理.
	Destroy();	// Destroyで破棄.

}

// ウィンドウ作成関数Create(lpctszClassName省略)
BOOL CEditBox::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ウィンドウの作成.
	return CCustomControl::Create(_T("Edit"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Createでウィンドウを作成し, その戻り値をreturnで返す.

}

// ウィンドウ破棄関数Destroy
void CEditBox::Destroy() {

	// 破棄処理.
	DestroyTextBuffer();	// バッファの破棄.

	// 自分のウィンドウも破棄.
	CWindow::Destroy();	// CWindow::Destroyで自身のウィンドウも破棄.

}

// エディットボックスのテキストを格納するバッファ作成関数CreateTextBuffer.
BOOL CEditBox::CreateTextBuffer() {

	// テキストの長さ + 1のバッファを確保.
	m_ptszText = new TCHAR[GetWindowTextLength() + 1];	// テキストの長さ + 1のバッファをnewで確保.
	if (m_ptszText == NULL) {	// 万が一確保失敗の場合.
		return FALSE;	// FALSE.
	}

	// 成功ならTRUE.
	return TRUE;	// TRUE.

}

// エディットボックスのテキストを格納するバッファ破棄関数DestroyTextBuffer.
void CEditBox::DestroyTextBuffer() {

	// テキストバッファが確保されていたら解放.
	if (m_ptszText != NULL) {
		delete[] m_ptszText;	// deleteでm_ptszTextを解放.
		m_ptszText = NULL;	// NULLをセット.
	}

}

// エディットボックスのテキストの長さ取得関数GetWindowTextLength.
int CEditBox::GetWindowTextLength() {

	// ウィンドウ名の長さを取得.
	m_iLen = CWindow::GetWindowTextLength();	// CWindow::GetWindowTextLengthでウィンドウ名の長さを取得.

	// 長さを返す.
	return m_iLen;	// m_iLenを返す.

}

// エディットボックスのテキストの取得関数GetWindowText.(自前の内部バッファに読み込む.)
int CEditBox::GetWindowText() {

	// テキストの長さを取得.
	GetWindowTextLength();	// GetWindowTextLengthでテキストの長さを取得.

	// バッファの生成.
	CreateTextBuffer();	// CreateTextBufferでバッファを生成.

	// テキストの取得.
	m_iLen = CWindow::GetWindowText(m_ptszText, m_iLen + 1);	// CWindow::GetWindowTextでテキストを取得し, 戻り値をm_iLenに格納.

	// 長さを返す.
	return m_iLen;	// m_iLenを返す.

}

// エディットボックスのテキストの設定関数SetWindowText.(自前の内部バッファに格納されているものをセット.)
void CEditBox::SetWindowText() {

	// バッファにセットされていた時にエディットボックスにセット.
	if (m_ptszText != NULL && m_iLen > 0) {	// テキストがセットされているなら.
		::SetWindowText(m_hWnd, m_ptszText);	// SetWindowTextでm_ptszTextをエディットボックスにセット.
	}

}