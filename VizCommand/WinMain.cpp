// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BasicApplication.h"	// �x�[�V�b�N�A�v���P�[�V�����N���X

// _tWinMain�֐�
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��̐錾
	CApplication *pApp;	// CApplication�I�u�W�F�N�g�|�C���^pApp

	// CBasicApplication�I�u�W�F�N�g�̏�����
	pApp = new CBasicApplication();	// CBasicApplication�I�u�W�F�N�g���쐬��, pApp�ɃA�h���X���i�[.
	if (!pApp->InitInstance(hInstance, lpCmdLine, nShowCmd)){	// pApp->InitInstance�ŏ��������������s�Ȃ�.

		// �G���[����
		MessageBox(NULL, _T("�A�v���P�[�V�����̏������Ɏ��s���܂���."), _T("VizCommand"), MB_OK | MB_ICONHAND);	// MessageBox��"�A�v���P�[�V�����̏������Ɏ��s���܂���."�ƕ\��.
		pApp->ExitInstance();	// pApp->ExitInstance�ŏI������.
		delete pApp;	// delete��pApp�����.
		return -1;	// �ُ�I��(-1)��Ԃ�.

	}

	// ���b�Z�[�W���[�v����
	pApp->Run();

	// �v���O�����̏I��
	delete pApp;	// delete��pApp�����.
	return 0;		// ����I��(0)��Ԃ�.

}