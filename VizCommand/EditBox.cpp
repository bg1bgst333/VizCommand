// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "EditBox.h"	// �G�f�B�b�g�{�b�N�X�N���X

// �R���X�g���N�^CEditBox()
CEditBox::CEditBox() : CCustomControl() {

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CEditBox::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){
	
	// �E�B���h�E�̍쐬.
	return CCustomControl::Create(_T("Edit"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Create�ŃE�B���h�E���쐬��, ���̖߂�l��return�ŕԂ�.

}