// �w�b�_�̃C���N���[�h
#include "EditPanel.h"	// �G�f�B�b�g�p�l���N���X

// �E�B���h�E�쐬�֐�Create.
BOOL CEditPanel::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �N���X��"EditPanel"�̎q�E�B���h�E���쐬.
	return CWindow::Create(_T("EditPanel"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ŃN���X��"EditPanel"�̎q�E�B���h�E���쐬.

}

// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
void CEditPanel::Destroy(){

	// �G�f�B�b�g�̔j��

	// �j��.
	DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
	m_hWnd = NULL;	// m_hWnd��NULL�ɂ���.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CEditPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// �q�E�B���h�E�ƂȂ�G�f�B�b�g�R���g���[���I�u�W�F�N�g�̍쐬.

	return 0;

}

// �E�B���h�E�j�����̃n���h��OnDestroy
void CEditPanel::OnDestroy(){

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CEditPanel::OnSize(UINT nType, int cx, int cy){

}


// �E�B���h�E����鎞�̃n���h��OnClose.
int CEditPanel::OnClose() {

	// 0��Ԃ�.
	return 0;	// 0��Ԃ��ăE�B���h�E�����.

}
