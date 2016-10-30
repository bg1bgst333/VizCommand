// �w�b�_�̃C���N���[�h
#include "WindowListView.h"	// �E�B���h�E���X�g�r���[�N���X

// �E�B���h�E�쐬�֐�Create.
BOOL CWindowListView::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �N���X��"WindowListView"�̎q�E�B���h�E���쐬.
	return CWindow::Create(_T("WindowListView"), _T(""), WS_CHILD | WS_VISIBLE | WS_VSCROLL, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ŃN���X��"WindowListView"�̎q�E�B���h�E���쐬.

}

// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
void CWindowListView::Destroy() {

	// �j��.
	DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
	m_hWnd = NULL;	// m_hWnd��NULL�ɂ���.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CWindowListView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �E�B���h�E�j�����̃n���h��OnDestroy
void CWindowListView::OnDestroy() {

}

// �E�B���h�E����鎞�̃n���h��OnClose.
int CWindowListView::OnClose() {

	// 0��Ԃ�.
	return 0;	// 0��Ԃ��ăE�B���h�E�����.

}