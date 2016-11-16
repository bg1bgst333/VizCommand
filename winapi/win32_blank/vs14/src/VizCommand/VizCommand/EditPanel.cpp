// ヘッダのインクルード
#include "Edit.h"	// エディットコントロール
#include "EditPanel.h"	// エディットパネルクラス

// ウィンドウ作成関数Create.
BOOL CEditPanel::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// メンバにセット.
	m_x = x;
	m_y = y;
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	m_nID = hMenu;

	// クラス名"EditPanel"の子ウィンドウを作成.
	return CWindow::Create(_T("EditPanel"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Createでクラス名"EditPanel"の子ウィンドウを作成.

}

// OnCloseとOnDestroyの間に子ウィンドウなどを破棄するメンバ関数Destroy.
void CEditPanel::Destroy(){

	// エディットの破棄
	m_pEdit->Destroy();
	if (m_pEdit != NULL) {
		delete m_pEdit;
		m_pEdit = NULL;
	}

	// 破棄.
	DestroyWindow(m_hWnd);	// DestroyWindowでm_hWndを破棄.
	m_hWnd = NULL;	// m_hWndをNULLにする.

}

// ウィンドウ作成時のハンドラOnCreate.
int CEditPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// 子ウィンドウとなるエディットコントロールオブジェクトの作成.
	m_pEdit = new CEdit();
	if (m_pEdit->Create(m_x, m_y, m_iWidth, m_iHeight, hwnd, m_nID + 100, lpCreateStruct->hInstance)) {
		return 0;
	}
	else {
		if (m_pEdit != NULL) {
			delete m_pEdit;
			m_pEdit = NULL;
		}
		return -1;
	}

}

// ウィンドウ破棄時のハンドラOnDestroy
void CEditPanel::OnDestroy(){

}

// ウィンドウのサイズが変更された時のハンドラOnSize.
void CEditPanel::OnSize(UINT nType, int cx, int cy){

	// エディットコントロールもサイズを合わせる.
	m_pEdit->MoveWindow(0, 0, cx, cy);

}


// ウィンドウを閉じる時のハンドラOnClose.
int CEditPanel::OnClose() {

	// 0を返す.
	return 0;	// 0を返してウィンドウを閉じる.

}
