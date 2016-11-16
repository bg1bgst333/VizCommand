// �w�b�_�̃C���N���[�h
#include "Edit.h"	// �G�f�B�b�g�R���g���[��

// �E�B���h�E�쐬�֐�Create.
BOOL CEdit::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){
	
	// �N���X��"Edit"�̎q�E�B���h�E�쐬.
	return CWindow::Create(_T("Edit"), _T(""), WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ŃN���X��"EditPanel"�̎q�E�B���h�E���쐬.

}

// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
void CEdit::Destroy() {

	// �j��.
	DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
	m_hWnd = NULL;	// m_hWnd��NULL�ɂ���.

}

// �E�B���h�E�̃T�C�Y��ʒu��ύX���郁���o�֐�MoveWindow.
void CEdit::MoveWindow(int x, int y, int iWidth, int iHeight){

	// �G�f�B�b�g�R���g���[���̃T�C�Y�X�V.
	m_x = x;
	m_y = y;
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	::MoveWindow(m_hWnd, x, y, iWidth, iHeight, TRUE);

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CEdit::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	return 0;

}

// �E�B���h�E�j�����̃n���h��OnDestroy.
void CEdit::OnDestroy(){

}

// �E�B���h�E����鎞�̃n���h��OnClose.
int CEdit::OnClose(){

	return 0;

}
