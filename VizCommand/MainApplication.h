// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "StandardApplication.h"	// �X�^���_�[�h�A�v���P�[�V�����N���X

// ���C���A�v���P�[�V�����N���XCMainApplication
class CMainApplication : public CStandardApplication {

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CMainApplication();	// �R���X�g���N�^CMainApplication()

		// �����o�֐�
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// �A�v���P�[�V�����������֐�InitInstance

};