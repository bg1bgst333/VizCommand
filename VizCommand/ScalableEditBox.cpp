// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "ScalableEditBox.h"	// �X�J���u���G�f�B�b�g�{�b�N�X�N���X

// �R���X�g���N�^CScalableEditBox()
CScalableEditBox::CScalableEditBox() : CEditBox() {

	// ������.
	m_iLineHeight = 0;	// 1�s���̍�����0�ɏ�����.
	m_iLineCount = 0;	// �s����0�ɏ�����.

}

// �f�X�g���N�^~CScalableEditBox()
CScalableEditBox::~CScalableEditBox() {

	// �I������.
	m_iLineHeight = 0;	// 1�s���̍�����0�ɃZ�b�g.
	m_iLineCount = 0;	// �s����0�ɃZ�b�g.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CScalableEditBox::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �ϐ��̐錾
	HDC hDC;		// �f�o�C�X�R���e�L�X�g�n���h��HDC�^hDC.
	HFONT hFont;	// �t�H���g�n���h��HFONT�^hFont.
	HFONT hOldFont;	// �I��O�̃t�H���g�n���h��HFONT�^hOldFont.
	TEXTMETRIC tm;	// �t�H���g��������TEXTMETRIC�\���̕ϐ�tm.

	// �����̒���
	hDC = GetDC(hwnd);	// GetDC�Ńf�o�C�X�R���e�L�X�g�n���h�����擾.
	hFont = (HFONT)SendMessage(hwnd, WM_GETFONT, 0, 0);	// SendMessage��WM_GETFONT���w�肵�ăt�H���g�n���h��hFont���擾��, hFont�Ɋi�[.
	hOldFont = (HFONT)SelectObject(hDC, hFont);	// SelectObject��hFont��I��.
	GetTextMetrics(hDC, &tm);	// GetTextMetrics�Ńt�H���g�����擾��, tm�Ɋi�[.
	m_iLineHeight = tm.tmHeight;	// 1�s���̍������t�H���g�̍����ɂ���.
	SelectObject(hDC, hOldFont);	// �t�H���g�����ɖ߂�.
	ReleaseDC(hwnd, hDC);	// ReleaseDC�Ńf�o�C�X�R���e�L�X�g�������[�X.

	// �E�B���h�E�̃��T�C�Y
	MoveWindow(3, m_iLineHeight);	// MoveWindow�ō�����1�s����m_iLineHeight�ɂ���.

	// UM_SIZECHILD�Ŏq�E�B���h�E�̃T�C�Y�ɍ��킹��.
	WPARAM wParam;
	wParam = MAKEWPARAM(m_iWidth, m_iHeight);
	SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);

	// �s���̃Z�b�g.
	m_iLineCount = 1;	// 1�s���͂ł����̂�m_iLineCount��1���Z�b�g.

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// �L�[�������ꂽ���̃n���h��OnKeyDown.
void CScalableEditBox::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {

	// ���^�[��, �o�b�N�X�y�[�X�̎��̓���.
	if (nChar == VK_RETURN) {		// VK_RETURN�̎�.

		// �ϐ��̐錾
		int iHeight;	// �V��������iHeight.

		// ���s������1�s���傫������.
		iHeight = m_iHeight + m_iLineHeight;	// ���݂̃E�B���h�E�̍�����1�s���̍����𑫂�.
		MoveWindow(3, iHeight);	// MoveWindow�ō�����V����iHeight�ɂ���.
		m_iLineCount++;		// �s���𑝂₷.

		// UM_SIZECHILD�Ŏq�E�B���h�E�̃T�C�Y�ɍ��킹��.
		WPARAM wParam;
		wParam = MAKEWPARAM(m_iWidth, m_iHeight);
		SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);

	}
	else if (nChar == VK_BACK) {	// VK_BACK�̎�.

		// �ϐ��̐錾
		POINT pt;		// ���WPOINT�^pt.
		DWORD dwPos;	// HIWORD�͍s�̉��Ԗ�, LOWORD�̓G�f�B�b�g�{�b�N�X�̑��������ƂȂ�DWORD�^dwPos.
		WORD wRow;		// �s.
		WORD wAllLen;	// ��������.
		WORD wRowStart;	// �G�f�B�b�g�{�b�N�X��1�s�ڂ̐擪����L�����b�g�̂���s�̐擪�܂ł̕�����.
		WORD wCol;		// ��.
		int iHeight;	// �V��������iHeight.

		// �o�b�N�X�y�[�X�ōs���������珬��������.
		GetCaretPos(&pt);	// �L�����b�g�̈ʒu�����W�Ŏ擾.
		dwPos = (DWORD)SendMessage(m_hWnd, EM_CHARFROMPOS, 0, MAKELPARAM(pt.x, pt.y));	// EM_CHARFROMPOS�ō��W���s�Ɨ�ɕϊ�.
		wRow = HIWORD(dwPos);	// �s�����o��.
		wAllLen = LOWORD(dwPos);	// �������������o��.
		wRowStart = (WORD)SendMessage(m_hWnd, EM_LINEINDEX, wRow, 0);	// EM_LINEINDEX�ŃL�����b�g�s�̐擪�܂ł̕��������擾.
		wCol = wAllLen - wRowStart;	// ������������L�����b�g�s�̐擪�܂ł̕�������������, �悤�₭����ڂ����킩��.
		if (wCol == 0) {	// �񂪐擪�̏ꍇ.
			if (wRow > 0) {	// �s���擪�łȂ��ꍇ.

				// 1�s������������.
				iHeight = m_iHeight - m_iLineHeight;	// �V��������iHeight��m_iHeight����m_iLineHeight�����������̂ɂ���.
				MoveWindow(3, iHeight);	// MoveWindow�ō�����V����iHeight�ɂ���.
				m_iLineCount--;	// m_iLineCount�����炷.

				// UM_SIZECHILD�Ŏq�E�B���h�E�̃T�C�Y�ɍ��킹��.
				WPARAM wParam;
				wParam = MAKEWPARAM(m_iWidth, m_iHeight);
				SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);

			}
		}

	}

}

// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CScalableEditBox::OnSize(UINT nType, int cx, int cy) {

	// ���ۂ̃E�B���h�E�T�C�Y���i�[.
	m_iWidth = cx;	// m_iWidth��cx���Z�b�g.
	m_iHeight = cy;	// m_iHeight��cy���Z�b�g.

	// UM_SIZECHILD�Ŏq�E�B���h�E�̃T�C�Y�ɍ��킹��.
	//WPARAM wParam;
	//wParam = MAKEWPARAM(m_iWidth, m_iHeight);
	//SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);

}