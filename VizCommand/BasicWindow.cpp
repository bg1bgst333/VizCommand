// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BasicWindow.h"	// �x�[�V�b�N�E�B���h�E�N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CBasicWindow::RegisterClass(HINSTANCE hInstance){

	// �E�B���h�E�N���X�̓o�^
	return CWindow::RegisterClass(hInstance, _T("BasicWindow"));	// CWindow::RegisterClass�ŃE�B���h�E�N���X"BasicWindow"��o�^.

}

// �R���X�g���N�^CBasicWindow()
CBasicWindow::CBasicWindow() : CWindow(){

}

// �f�X�g���N�^~CBasicWindow()
CBasicWindow::~CBasicWindow(){

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CBasicWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){
	
	// �����ɗ���ꍇ�̓E�B���h�E�N���X"BasicWindow"�̃E�B���h�E�Ƃ��č쐬.
	return CWindow::Create(_T("BasicWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X��"BasicWindow"�ɂ���Create�̃t���o�[�W�������Ă�.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CBasicWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ̂�0��Ԃ�.

}