// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BasicApplication.h"	// �x�[�V�b�N�A�v���P�[�V�����N���X
#include "BasicWindow.h"	// �x�[�V�b�N�E�B���h�E�N���X

// �R���X�g���N�^CBasicApplication()
CBasicApplication::CBasicApplication() : CApplication() {

}

// �A�v���P�[�V�����������֐�InitInstance
BOOL CBasicApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ������
	CApplication::InitInstance(hInstance, lpCmdLine, nShowCmd);	// CApplication::InitInstance���Ă�.

	// �x�[�V�b�N�E�B���h�E�N���X�̓o�^
	CBasicWindow::RegisterClass(hInstance);	// CBasicWindow::RegisterClass�ŃE�B���h�E�N���X"BasicWindow"��o�^.

	// TRUE��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}
