// �w�b�_�̃C���N���[�h
#include "Edit.h"	// �G�f�B�b�g�R���g���[��
#include "EditPanel.h"	// �G�f�B�b�g�p�l���N���X

// �E�B���h�E�쐬�֐�Create.
BOOL CEditPanel::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �����o�ɃZ�b�g.
	m_x = x;
	m_y = y;
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	m_nID = hMenu;

	// �N���X��"EditPanel"�̎q�E�B���h�E���쐬.
	return CWindow::Create(_T("EditPanel"), _T(""), WS_CHILD | WS_VISIBLE | WS_BORDER, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ŃN���X��"EditPanel"�̎q�E�B���h�E���쐬.

}

// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
void CEditPanel::Destroy(){

	// �G�f�B�b�g�̔j��
	m_pEdit->Destroy();
	if (m_pEdit != NULL) {
		delete m_pEdit;
		m_pEdit = NULL;
	}

	// �j��.
	DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
	m_hWnd = NULL;	// m_hWnd��NULL�ɂ���.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CEditPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// �q�E�B���h�E�ƂȂ�G�f�B�b�g�R���g���[���I�u�W�F�N�g�̍쐬.
	m_pEdit = new CEdit();
	if (m_pEdit->Create(m_x, m_y, m_iWidth, m_iHeight, hwnd, m_nID + 100, lpCreateStruct->hInstance)) {
		return 0;
	}
	else {
		if (m_pEdit != NULL) {
			delete m_pEdit;
			m_pEdit = NULL;
		}
		return -1;
	}

}

// �E�B���h�E�j�����̃n���h��OnDestroy
void CEditPanel::OnDestroy(){

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CEditPanel::OnSize(UINT nType, int cx, int cy){

	// �G�f�B�b�g�R���g���[�����T�C�Y�����킹��.
	m_pEdit->MoveWindow(0, 0, cx, cy);

}


// �E�B���h�E����鎞�̃n���h��OnClose.
int CEditPanel::OnClose() {

	// 0��Ԃ�.
	return 0;	// 0��Ԃ��ăE�B���h�E�����.

}
