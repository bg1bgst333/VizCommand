// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "BasicApplication.h"	// �x�[�V�b�N�A�v���P�[�V�����N���X

// �X�^���_�[�h�A�v���P�[�V�����N���XCStandardApplication
class CStandardApplication : public CBasicApplication {

	// public�����o
	public:

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CStandardApplication();	// �R���X�g���N�^CStandardApplication()

		// �����o�֐�
		virtual BOOL InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd);	// �A�v���P�[�V�����������֐�InitInstance

};