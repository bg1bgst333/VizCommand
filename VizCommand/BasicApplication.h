// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "Application.h"	// �A�v���P�[�V�����N���X

// �x�[�V�b�N�A�v���P�[�V�����N���XCBasicApplication
class CBasicApplication : public CApplication {

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CBasicApplication();	// �R���X�g���N�^CBasicApplication()

		// �����o�֐�
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// �A�v���P�[�V�����������֐�InitInstance

};