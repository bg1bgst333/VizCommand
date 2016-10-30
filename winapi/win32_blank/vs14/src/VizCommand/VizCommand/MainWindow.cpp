// �w�b�_�̃C���N���[�h
#include "MainWindow.h"	// ���C���E�B���h�E�N���X

// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
void CMainWindow::Destroy() {

	// �q�E�B���h�E�̔j��.
	m_pWindowListView->Destroy();	// m_pWindowListView->Destroy�Ŕj��.

	// �E�B���h�E���X�g�r���[�̔j��.
	if (m_pWindowListView != NULL) {	// NULL�łȂ����.

		// m_pWindowListView�̔j��.
		delete m_pWindowListView;	// delete��m_pWindowListView�����.
		m_pWindowListView = NULL;	// m_pWindowListView��NULL�ɃZ�b�g.

	}

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �q�E�B���h�E�ƂȂ�E�B���h�E���X�g�r���[�I�u�W�F�N�g�̍쐬.
	m_pWindowListView = new CWindowListView();	// CWindowListView�I�u�W�F�N�gm_pWindowListView�̍쐬.

	// �q�E�B���h�E�̍쐬.
	m_pWindowListView->Create(100, 100, 200, 200, hwnd, (HMENU)IDC_WINDOW_LISTVIEW, lpCreateStruct->hInstance);	// m_pWindowListView->Create�ŃE�B���h�E���X�g�r���[���쐬.

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �E�B���h�E�j�����̃n���h��OnDestroy
void CMainWindow::OnDestroy() {

	// ���b�Z�[�W���[�v�I��.
	PostQuitMessage(0);	// PostQuitMessage�Ń��b�Z�[�W���[�v�𔲂�������.

}

// �E�B���h�E����鎞�̃n���h��OnClose.
int CMainWindow::OnClose() {

	// �q�E�B���h�E�̔j��.
	Destroy();	// Destroy�Ŏq�E�B���h�E�̔j��.
	return 0;	// 0��Ԃ��ƕ���.

}