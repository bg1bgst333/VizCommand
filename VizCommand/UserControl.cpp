// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "UserControl.h"	// ���[�U�R���g���[���N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass(�E�B���h�E�N���X���w��)
BOOL CUserControl::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName) {

	// �E�B���h�E�N���X�̓o�^
	return CWindow::RegisterClass(hInstance, lpctszClassName);	// CWindow::RegisterClass�ŃE�B���h�E�N���XlpctszClassName��o�^.

}

// �R���X�g���N�^CUserControl()
CUserControl::CUserControl() : CWindow() {

}

// �E�B���h�E�쐬�֐�Create
BOOL CUserControl::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �����ɗ���ꍇ�̓E�B���h�E�N���XlpctszClassName�ȃE�B���h�E�Ƃ��č쐬.
	return CWindow::Create(lpctszClassName, lpctszWindowName, dwStyle | WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X��lpctszClassName�ɂ���, dwStyle��WS_CHILD��WS_VISIBLE��ǉ�����, Create�̃t���o�[�W�������Ă�.

}

// �E�B���h�E�j�����̃n���h��OnDestroy.
void CUserControl::OnDestroy() {

}
