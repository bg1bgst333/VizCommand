// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Application.h"	// �A�v���P�[�V�����N���X

// �R���X�g���N�^CApplication()
CApplication::CApplication(){

	// �����o�ϐ��̏�����
	m_pMainWindow = NULL;	// m_pMainWindow��NULL�ɏ�����.

}

// �f�X�g���N�^~CApplication()
CApplication::~CApplication(){

	// �����o�ϐ��̏I������
	if (m_pMainWindow != NULL) {	// m_pMainWindow��NULL�łȂ����.
		delete m_pMainWindow;	// delete��m_pMainWindow�����.
		m_pMainWindow = NULL;	// m_pMainWindow��NULL����.
	}

}

// �A�v���P�[�V�����������֐�InitInstance
BOOL CApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// �E�B���h�E�N���X�̓o�^
	CWindow::RegisterClass(hInstance, _T("Window"));	// CWindow::RegisterClass�ŃE�B���h�E�N���X"Window"��o�^.
	
	// �E�B���h�E�I�u�W�F�N�g�̐���
	m_pMainWindow = new CWindow();	// CWindow�I�u�W�F�N�g���쐬��, �A�h���X��m_pMainWindow�Ɋi�[.

	// �E�B���h�E�쐬
	if (!m_pMainWindow->Create(_T("Window"), _T("VizCommand"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWindow->Create�ł̍쐬�����s�Ȃ�.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �E�B���h�E�\��
	m_pMainWindow->ShowWindow(SW_SHOW);	// m_pMainWindow->ShowWindow�ŕ\��.

	// �����Ȃ̂�TRUE��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}

// ���b�Z�[�W���[�v�֐�Run
int CApplication::Run(){

	// �ϐ��̐錾
	MSG msg;	// ���b�Z�[�W���msg

	// ���b�Z�[�W�擾
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�Ń��b�Z�[�W�擾.

		// �E�B���h�E���b�Z�[�W�̑��o
		DispatchMessage(&msg);	// DispatchMessage�ŃE�B���h�E�v���V�[�W���ɑ��o.
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎��֕ϊ�.

	}

	// �I������
	return ExitInstance();	// ExitInstance�̒l��Ԃ�.

}

// �A�v���P�[�V�����I�������֐�ExitInstance
int CApplication::ExitInstance(){

	// ���C���E�B���h�E�I�u�W�F�N�g������Ή��.
	if (m_pMainWindow != NULL) {	// m_pMainWindow��NULL����Ȃ����.

		// ���.
		delete m_pMainWindow;	// delete��m_pMainWindow�����.
		m_pMainWindow = NULL;	// NULL���Z�b�g.

	}

	// 0��Ԃ�.
	return 0;

}