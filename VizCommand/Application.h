// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
// �Ǝ��̃w�b�_
#include "Window.h"	// �E�B���h�E�N���X

// �A�v���P�[�V�����N���XCApplication
class CApplication {

	// public�����o
	public:

		// public�����o�ϐ�
		// �����o�ϐ�
		CWindow *m_pMainWindow;	// CWindow *�^�E�B���h�E�I�u�W�F�N�g�|�C���^m_pMainWindow.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CApplication();	// �R���X�g���N�^CApplication()
		~CApplication();	// �f�X�g���N�^~CApplication()

		// �����o�֐�
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// �A�v���P�[�V�����������֐�InitInstance
		virtual int Run();	// ���b�Z�[�W���[�v�֐�Run
		virtual int ExitInstance();	// �A�v���P�[�V�����I�������֐�ExitInstance

};