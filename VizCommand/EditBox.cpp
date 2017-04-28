// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "EditBox.h"	// �G�f�B�b�g�{�b�N�X�N���X

// �R���X�g���N�^CEditBox()
CEditBox::CEditBox() : CCustomControl() {

	// ������.
	m_ptszText = NULL;	// m_ptszText��NULL���Z�b�g.

}

// �f�X�g���N�^~CEditBox()
CEditBox::~CEditBox() {

	// �����o�̏I������.
	Destroy();	// Destroy�Ŕj��.

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CEditBox::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�̍쐬.
	return CCustomControl::Create(_T("Edit"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Create�ŃE�B���h�E���쐬��, ���̖߂�l��return�ŕԂ�.

}

// �E�B���h�E�j���֐�Destroy
void CEditBox::Destroy() {

	// �j������.
	DestroyTextBuffer();	// �o�b�t�@�̔j��.

	// �����̃E�B���h�E���j��.
	CWindow::Destroy();	// CWindow::Destroy�Ŏ��g�̃E�B���h�E���j��.

}

// �G�f�B�b�g�{�b�N�X�̃e�L�X�g���i�[����o�b�t�@�쐬�֐�CreateTextBuffer.
BOOL CEditBox::CreateTextBuffer() {

	// �e�L�X�g�̒��� + 1�̃o�b�t�@���m��.
	m_ptszText = new TCHAR[GetWindowTextLength() + 1];	// �e�L�X�g�̒��� + 1�̃o�b�t�@��new�Ŋm��.
	if (m_ptszText == NULL) {	// ������m�ێ��s�̏ꍇ.
		return FALSE;	// FALSE.
	}

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE.

}

// �G�f�B�b�g�{�b�N�X�̃e�L�X�g���i�[����o�b�t�@�j���֐�DestroyTextBuffer.
void CEditBox::DestroyTextBuffer() {

	// �e�L�X�g�o�b�t�@���m�ۂ���Ă�������.
	if (m_ptszText != NULL) {
		delete[] m_ptszText;	// delete��m_ptszText�����.
		m_ptszText = NULL;	// NULL���Z�b�g.
	}

}

// �G�f�B�b�g�{�b�N�X�̃e�L�X�g�̒����擾�֐�GetWindowTextLength.
int CEditBox::GetWindowTextLength() {

	// �E�B���h�E���̒������擾.
	m_iLen = CWindow::GetWindowTextLength();	// CWindow::GetWindowTextLength�ŃE�B���h�E���̒������擾.

	// ������Ԃ�.
	return m_iLen;	// m_iLen��Ԃ�.

}

// �G�f�B�b�g�{�b�N�X�̃e�L�X�g�̎擾�֐�GetWindowText.(���O�̓����o�b�t�@�ɓǂݍ���.)
int CEditBox::GetWindowText() {

	// �e�L�X�g�̒������擾.
	GetWindowTextLength();	// GetWindowTextLength�Ńe�L�X�g�̒������擾.

	// �o�b�t�@�̐���.
	CreateTextBuffer();	// CreateTextBuffer�Ńo�b�t�@�𐶐�.

	// �e�L�X�g�̎擾.
	m_iLen = CWindow::GetWindowText(m_ptszText, m_iLen + 1);	// CWindow::GetWindowText�Ńe�L�X�g���擾��, �߂�l��m_iLen�Ɋi�[.

	// ������Ԃ�.
	return m_iLen;	// m_iLen��Ԃ�.

}

// �G�f�B�b�g�{�b�N�X�̃e�L�X�g�̐ݒ�֐�SetWindowText.(���O�̓����o�b�t�@�Ɋi�[����Ă�����̂��Z�b�g.)
void CEditBox::SetWindowText() {

	// �o�b�t�@�ɃZ�b�g����Ă������ɃG�f�B�b�g�{�b�N�X�ɃZ�b�g.
	if (m_ptszText != NULL && m_iLen > 0) {	// �e�L�X�g���Z�b�g����Ă���Ȃ�.
		::SetWindowText(m_hWnd, m_ptszText);	// SetWindowText��m_ptszText���G�f�B�b�g�{�b�N�X�ɃZ�b�g.
	}

}