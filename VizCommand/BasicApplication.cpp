// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BasicApplication.h"	// �x�[�V�b�N�A�v���P�[�V�����N���X
#include "BasicWindow.h"	// �x�[�V�b�N�E�B���h�E�N���X

// �R���X�g���N�^CBasicApplication()
CBasicApplication::CBasicApplication() : CApplication() {

}

// �A�v���P�[�V�����������֐�InitInstance
BOOL CBasicApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ������
	CApplication::InitInstance(hInstance, lpCmdLine, nShowCmd);	// CApplication::InitInstance���Ă�.

	// �x�[�V�b�N�E�B���h�E�N���X�̓o�^
	CBasicWindow::RegisterClass(hInstance);	// CBasicWindow::RegisterClass�ŃE�B���h�E�N���X"BasicWindow"��o�^.

	// �x�[�V�b�N�E�B���h�E�I�u�W�F�N�g�̐���
	m_pMainWindow = new CBasicWindow();	// CBasicWindow�I�u�W�F�N�g���쐬��, �A�h���X��m_pMainWindow�Ɋi�[.

	// �E�B���h�E�쐬
	if (!m_pMainWindow->Create(_T("VizCommand"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWindow->Create�ł̍쐬�����s�Ȃ�.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �E�B���h�E�\��
	m_pMainWindow->ShowWindow(SW_SHOW);	// m_pMainWindow->ShowWindow�ŕ\��.

	// �����Ȃ̂�TRUE��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}
