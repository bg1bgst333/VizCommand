// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BasicWindow.h"	// �x�[�V�b�N�E�B���h�E�N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CBasicWindow::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�N���X�̓o�^
	return CWindow::RegisterClass(hInstance, _T("BasicWindow"));	// CWindow::RegisterClass�ŃE�B���h�E�N���X"BasicWindow"��o�^.

}

// �R���X�g���N�^CBasicWindow()
CBasicWindow::CBasicWindow() : CWindow(){

	// �����o�̏�����
	m_pUserControl = NULL;	// m_pUserControl��NULL�ŏ�����.

}

// �f�X�g���N�^~CBasicWindow()
CBasicWindow::~CBasicWindow(){

	// �����o�̏I������.
	if (m_pUserControl != NULL) {
		delete m_pUserControl;	// delete��m_pUserControl�����.
		m_pUserControl = NULL;	// m_pUserControl��NULL�Ŗ��߂�.
	}

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CBasicWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){
	
	// �����ɗ���ꍇ�̓E�B���h�E�N���X"BasicWindow"�̃E�B���h�E�Ƃ��č쐬.
	return CWindow::Create(_T("BasicWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X��"BasicWindow"�ɂ���Create�̃t���o�[�W�������Ă�.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CBasicWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// ���[�U�R���g���[���̍쐬.
	m_pUserControl = new CUserControl();	// CUserControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pUserControl�Ɋi�[.
	m_pUserControl->Create(_T("UserControl"), _T(""), WS_BORDER, 100, 100, 200, 200, hwnd, (HMENU)(WM_APP + 1), lpCreateStruct->hInstance);	// m_pUserControl->Create�ŃE�B���h�E�N���X��"UserControl"�ȃE�B���h�E���쐬.

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ̂�0��Ԃ�.

}