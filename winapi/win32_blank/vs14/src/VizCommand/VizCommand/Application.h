// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
// �Ǝ��̃w�b�_
#include "Window.h"		// �E�B���h�E�N���X

// �A�v���P�[�V�����N���X
class CApplication {

	// public�����o
	public:

		// public�����o�ϐ�
		CWindow *m_pMainWindow;	// CWindow *�^�E�B���h�E�I�u�W�F�N�gm_pMainWindow.

		// public�����o�֐�
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) = 0;	// �C���X�^���X�������֐�InitInstance(�������z�֐�)
		virtual int Run();	// ���b�Z�[�W���[�v�֐�Run
		virtual int ExitInstance();	// �C���X�^���X�I�������֐�ExitInstance

};