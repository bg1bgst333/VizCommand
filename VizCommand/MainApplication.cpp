// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// ���C���A�v���P�[�V�����N���X
#include "MainWindow.h"			// ���C���E�B���h�E�N���X

// �R���X�g���N�^CMainApplication()
CMainApplication::CMainApplication() : CStandardApplication() {

}

// �A�v���P�[�V�����������֐�InitInstance
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// ������
	CStandardApplication::InitInstance(hInstance, lpCmdLine, nShowCmd);	// CStandardApplication::InitInstance���Ă�.

	// ���C���E�B���h�E�N���X�̓o�^
	CMainWindow::RegisterClass(hInstance, (HBRUSH)GetStockObject(GRAY_BRUSH));	// CMainWindow::RegisterClass�Ŕw�i�u���V��GRAY_BRUSH�ȃE�B���h�E�N���X"MainWindow"��o�^.

	// �E�B���h�E���X�g�R���g���[���N���X�̓o�^
	CWindowListControl::RegisterClass(hInstance);	// CWindowListControl::RegisterClass�ŃE�B���h�E���X�g�R���g���[���N���X�̓o�^.

	// �G�f�B�b�g�{�b�N�X�p�l���N���X�̓o�^
	//CEditBoxPanel::RegisterClass(hInstance);			// CEditBoxPanel::RegisterClass�ŃG�f�B�b�g�{�b�N�X�p�l���N���X�̓o�^.
	CScalableEditBoxPanel::RegisterClass(hInstance, (HBRUSH)GetStockObject(LTGRAY_BRUSH));	// CScalableEditBoxPanel::RegisterClass�Ŕw�i�u���V��LTGRAY_BRUSH�ȃX�J���u���G�f�B�b�g�{�b�N�X�p�l���N���X�̓o�^.

	// ���C���E�B���h�E�I�u�W�F�N�g�̐���
	m_pMainWindow = new CMainWindow();	// CMainWindow�I�u�W�F�N�g���쐬��, �A�h���X��m_pMainWindow�Ɋi�[.

	// �E�B���h�E�쐬
	if (!m_pMainWindow->Create(_T("VizCommand"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)) {	// m_pMainWindow->Create�ł̍쐬�����s�Ȃ�.
		return FALSE;	// FALSE��Ԃ�.
	}

	// �E�B���h�E�\��
	m_pMainWindow->ShowWindow(SW_SHOW);	// m_pMainWindow->ShowWindow�ŕ\��.

	// �����Ȃ̂�TRUE��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}