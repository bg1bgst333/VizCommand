// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "StandardApplication.h"	// �X�^���_�[�h�A�v���P�[�V�����N���X
//#include "StandardWindow.h"			// �X�^���_�[�h�E�B���h�E�N���X

// �R���X�g���N�^CStandardApplication()
CStandardApplication::CStandardApplication() : CBasicApplication() {

}

// �A�v���P�[�V�����������֐�InitInstance
BOOL CStandardApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// ������
	CBasicApplication::InitInstance(hInstance, lpCmdLine, nShowCmd);	// CBasicApplication::InitInstance���Ă�.

	// �X�^���_�[�h�E�B���h�E�N���X�̓o�^
	//CStandardWindow::RegisterClass(hInstance, IDR_MAINMENU);	// CStandardWindow::RegisterClass�Ń��j���[ID��IDR_MAINMENU�ȃE�B���h�E�N���X"StandardWindow"��o�^.

	// �����Ȃ̂�TRUE��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}