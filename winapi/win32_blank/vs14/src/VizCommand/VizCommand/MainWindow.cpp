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

	// �E�B���h�E���X�g�r���[�̍쐬.
	m_pWindowListView->Create(100, 100, 200, 200, hwnd, (HMENU)IDC_WINDOW_LISTVIEW, lpCreateStruct->hInstance);	// m_pWindowListView->Create�ŃE�B���h�E���X�g�r���[���쐬.

	// �E�B���h�E���X�g�A�C�e���̒ǉ�.
	m_pWindowListView->Insert(0, 50, lpCreateStruct->hInstance);	// ����50�̃E�B���h�E���X�g�A�C�e����Insert.

	// �E�B���h�E���X�g�A�C�e���̒ǉ�.
	m_pWindowListView->Insert(1, 50, lpCreateStruct->hInstance);	// ����50�̃E�B���h�E���X�g�A�C�e����Insert.

	// �E�B���h�E���X�g�A�C�e���̒ǉ�.
	m_pWindowListView->Insert(2, 50, lpCreateStruct->hInstance);	// ����50�̃E�B���h�E���X�g�A�C�e����Insert.

	// �E�B���h�E���X�g�A�C�e���̒ǉ�.
	m_pWindowListView->Insert(3, 50, lpCreateStruct->hInstance);	// ����50�̃E�B���h�E���X�g�A�C�e����Insert.

	// �E�B���h�E���X�g�A�C�e���̒ǉ�.
	m_pWindowListView->Insert(4, 50, lpCreateStruct->hInstance);	// ����50�̃E�B���h�E���X�g�A�C�e����Insert.

	// �E�B���h�E���X�g�A�C�e���̒ǉ�.
	m_pWindowListView->Insert(1, 50, lpCreateStruct->hInstance);	// ����50�̃E�B���h�E���X�g�A�C�e����Insert.

	// �E�B���h�E���X�g�A�C�e���̍폜
	m_pWindowListView->Delete(-1);	// -1�Ԗ�(0�Ԗ�)���폜.

	// �E�B���h�E���X�g�A�C�e���̍폜
	m_pWindowListView->Delete(10);	// 10�Ԗ�(4�Ԗ�)���폜.

	// �E�B���h�E���X�g�A�C�e���̍폜
	m_pWindowListView->Delete(0);	// 0�Ԗڂ��폜.

	// �E�B���h�E���X�g�A�C�e���̍폜
	m_pWindowListView->Delete(1);	// 1�Ԗڂ��폜.

	// �E�B���h�E���X�g�A�C�e���̍폜
	m_pWindowListView->Delete(1);	// 1�Ԗڂ��폜.

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �E�B���h�E�j�����̃n���h��OnDestroy
void CMainWindow::OnDestroy() {

	// ���b�Z�[�W���[�v�I��.
	PostQuitMessage(0);	// PostQuitMessage�Ń��b�Z�[�W���[�v�𔲂�������.

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {
	
	// �q�E�B���h�E�̃E�B���h�E���X�g�r���[�̃T�C�Y���ύX.
	::MoveWindow(m_pWindowListView->m_hWnd, 0, 0, cx, cy, TRUE);	// MoveWindow�Ŏq�E�B���h�Em_pWindowListView�̃T�C�Y�����̃E�B���h�E�ɍ��킹��.

}

// �E�B���h�E����鎞�̃n���h��OnClose.
int CMainWindow::OnClose() {

	// �q�E�B���h�E�̔j��.
	Destroy();	// Destroy�Ŏq�E�B���h�E�̔j��.
	return 0;	// 0��Ԃ��ƕ���.

}