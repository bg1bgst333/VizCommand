// �w�b�_�̃C���N���[�h
#include "MainApplication.h"	// ���C���A�v���P�[�V�����N���X
#include "MainWindow.h"	// ���C���E�B���h�E�N���X

// �C���X�^���X�������֐�InitInstance
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �E�B���h�E�N���X�̓o�^.
	CWindow::RegisterClass(hInstance, _T("VizCommand_MainWindow"));	// CWindow::RegisterClass��"VizCommand_MainWindow"���E�B���h�E�N���X�ɓo�^.
	CWindow::RegisterClass(hInstance, _T("WindowListView"));	// CWindow::RegisterClass��"WindowListView"���E�B���h�E�N���X�ɓo�^.

	// CMainWindow�I�u�W�F�N�g�̍쐬.
	m_pMainWindow = new CMainWindow();	// CMainWindow�I�u�W�F�N�g���쐬��, ���̃|�C���^��m_pMainWindow�Ɋi�[.

	// �E�B���h�E�̍쐬.
	BOOL bRet = m_pMainWindow->Create(_T("VizCommand_MainWindow"), _T("VizCommand"), hInstance);	// m_pMainWindow->Create�ŃE�B���h�E�쐬.
	if (!bRet) {	// FALSE�Ȃ玸�s.

		// ���s�Ȃ�G���[����.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �E�B���h�E�̕\��
	m_pMainWindow->ShowWindow(SW_SHOW);	// m_pMainWindow->ShowWindow�ŃE�B���h�E��\��.

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}