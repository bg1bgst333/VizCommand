// �w�b�_�̃C���N���[�h
#include "ScalableEdit.h"	// �X�P�[���u���G�f�B�b�g�R���g���[��

// �E�B���h�E�쐬�֐�Create(���̃E�B���h�E��p�ɃJ�X�^�}�C�Y���ꂽ����.)
BOOL CScalableEdit::Create(int x, int y, int iWidth, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �ϐ��̐錾
	HDC hDC;
	HFONT hFont;
	HFONT hOldFont;
	TEXTMETRIC tm;
	BOOL bRet;

	// �����o�ɃZ�b�g.
	m_x = x;
	m_y = y;
	m_iWidth = iWidth;
	m_iLineCount = 0;

	// �E�B���h�E�쐬.
	// �N���X��"Edit"�̎q�E�B���h�E�쐬.
	bRet = CWindow::Create(_T("Edit"), _T(""), WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOHSCROLL | ES_AUTOVSCROLL, x, y, iWidth, 30, hWndParent, hMenu, hInstance, TRUE);	// CWindow::Create�ŃN���X��"Edit"�̎q�E�B���h�E���쐬.
	if (!bRet) {
		return bRet;
	}

	// �s�̍������v�Z.
	hDC = GetDC(hWndParent);
	hFont = (HFONT)SendMessage(m_hWnd, WM_GETFONT, 0, 0);
	hOldFont = (HFONT)SelectObject(hDC, hFont);
	GetTextMetrics(hDC, &tm);
	m_iHeight = tm.tmHeight;
	m_iLineHeight = tm.tmHeight;
	m_iExternalLeading = tm.tmExternalLeading;
	SelectObject(hDC, hOldFont);
	ReleaseDC(hWndParent, hDC);

	// �E�B���h�E���T�C�Y
	MoveWindow(0, 0, m_iWidth, m_iHeight);

	// bRet��Ԃ�.
	return bRet;

}

// �L�[�������ꂽ��.
int CScalableEdit::OnKeyDown(WPARAM wParam, LPARAM lParam) {

	// ���^�[���L�[�������ꂽ��.
	if (wParam == VK_RETURN) {
		m_iHeight = m_iHeight + m_iLineHeight;
		MoveWindow(m_x, m_y, m_iWidth, m_iHeight);
		m_iLineCount = m_iLineCount + 1;
		WPARAM wParam;
		wParam = MAKEWPARAM(m_iWidth, m_iHeight);
		SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);
	}
	else if (wParam == VK_BACK) {	// �o�b�N�X�y�[�X�L�[�������ꂽ��.
		// 0��ڂ̎�.
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

	// 0��Ԃ�.
	return 0;

}

// �q�E�B���h�E�̃T�C�Y���ύX���ꂽ��(�Ǝ����b�Z�[�W)
void CScalableEdit::OnSizeChild(HWND hWnd, int width, int height, HWND hChildWnd){

}
