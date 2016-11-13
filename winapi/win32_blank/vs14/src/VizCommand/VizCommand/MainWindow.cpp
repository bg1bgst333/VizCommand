// �w�b�_�̃C���N���[�h
#include "MainWindow.h"	// ���C���E�B���h�E�N���X
#include "EditPanel.h"	// �G�f�B�b�g�p�l���N���X
#include "WindowListItem.h"	// �E�B���h�E���X�g�A�C�e���N���X

// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
void CMainWindow::Destroy() {


	// ���E�B���h�E(�E�B���h�E���X�g�A�C�e���̎q�E�B���h�E)�̔j��.
	CChildMapItem *pItem = m_pChildMap->Get(_T("0"));
	pItem->m_pWindow->Destroy();
	delete pItem->m_pWindow;
	delete pItem;
	m_pChildMap->Remove(_T("0"));
	delete m_pChildMap;

	// �A�C�e���̔j��.
	m_pWindowListView->Delete(0);

	// �q�E�B���h�E(�E�B���h�E���X�g�A�C�e��)�̔j��.
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

	// �E�B���h�E���X�g�A�C�e���̎q�E�B���h�E���Ǘ�����}�b�v�̍쐻.
	m_pChildMap = new CChildMap;

	// �E�B���h�E���X�g�r���[�̍쐬.
	m_pWindowListView->Create(0, 0, 200, 200, hwnd, (HMENU)IDC_WINDOW_LIST_VIEW, lpCreateStruct->hInstance);	// m_pWindowListView->Create�ŃE�B���h�E���X�g�r���[���쐬.

	// �E�B���h�E���X�g�A�C�e���̒ǉ�.
	m_pWindowListView->Insert(0, 200, lpCreateStruct->hInstance);	// ����200�̃E�B���h�E���X�g�A�C�e����Insert.

	// �G�f�B�b�g�p�l���̃Z�b�g.
	CWindowListItem *m_pWindowListItem = m_pWindowListView->Get(0);	// 0�Ԗڂ̃A�C�e�����擾.
	CEditPanel *pEditPanel = new CEditPanel();	// pEditPanel�I�u�W�F�N�g�̍쐬.
	pEditPanel->Create(50, 50, 50, 50, m_pWindowListItem->m_hWnd, (HMENU)IDC_EDIT_PANEL, lpCreateStruct->hInstance);	// pEditPanel->Create�Ő���.
	m_pChildMap->Add(_T("0"), new CChildMapItem(0, pEditPanel));	// �`���C���h�}�b�v�ɒǉ�.

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