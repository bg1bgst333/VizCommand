// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
// �Ǝ��̃w�b�_
#include "MainApplication.h"	// ���C���A�v���P�[�V�����N���X

// _tWinMain�֐�
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��E�|�C���^�̐錾
	CApplication *pApplication;	// CApplication�|�C���^pApplication.
	int iRet;	// int�^�ϐ�iRet.

	// �I�u�W�F�N�g�̍쐬.
	pApplication = new CMainApplication();	// CMainApplication�I�u�W�F�N�g���쐬��, CApplication�I�u�W�F�N�g�|�C���^��pApplication�Ɋi�[.

	// �C���X�^���X������.
	if (!pApplication->InitInstance(hInstance, lpCmdLine, nShowCmd)) {	// pApplication->InitInstance�ŃA�v���P�[�V�����C���X�^���X������.

		// �I������.
		iRet = pApplication->ExitInstance();	// pApplication->ExitInstance�ŏI������.
		delete pApplication;	// pApplication�����.
		return iRet;	// iRet��߂�l�Ƃ���.

	}

	// ���b�Z�[�W���[�v����.
	iRet = pApplication->Run();	// pApplication->Run�Ń��b�Z�[�W���[�v����.

	// pApplication�̉��.
	delete pApplication;	// delete��pApplication�̉��.

	// �v���O�����̏I��.
	return iRet;

}