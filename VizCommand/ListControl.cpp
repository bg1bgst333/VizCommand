// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "ListControl.h"	// ���X�g�R���g���[���N���X

// �R���X�g���N�^CListControl()
CListControl::CListControl() : CCustomControl() {

}

// �f�X�g���N�^~CListControl()
CListControl::~CListControl() {

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CListControl::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�̍쐬.
	return CCustomControl::Create(_T("SysListView32"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Create�ŃE�B���h�E���쐬��, ���̖߂�l��return�ŕԂ�.

}

// �E�B���h�E�j���֐�Destroy
void CListControl::Destroy() {

	// �����̃E�B���h�E���j��.
	CWindow::Destroy();	// CWindow::Destroy�Ŏ��g�̃E�B���h�E���j��.

}