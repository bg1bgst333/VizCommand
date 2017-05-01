// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "MainWindow.h"		// ���j���[�E�B���h�E�N���X
#include "EditBoxPanel.h"	// �G�f�B�b�g�{�b�N�X�p�l���N���X
//#include "MainMenuBar.h"	// ���C�����j���[�o�[�N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E�N���X�̓o�^
	return CWindow::RegisterClass(hInstance, _T("MainWindow"));	// CWindow::RegisterClass�ŃE�B���h�E�N���X"MainWindow"��o�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�u���V�w��)
BOOL CMainWindow::RegisterClass(HINSTANCE hInstance, HBRUSH hBrush) {

	// �E�B���h�E�N���X�̓o�^
	return CWindow::RegisterClass(hInstance, _T("MainWindow"), hBrush);	// CWindow::RegisterClass(�w�i�u���V�w��)�ŃE�B���h�E�N���X"MainWindow"��o�^.

}

// �R���X�g���N�^CMainWindow()
CMainWindow::CMainWindow() : CBasicWindow() {

	// �����o�̏�����
	m_pWindowListControl = NULL;	// m_pWindowListControl��NULL�ŏ�����.
	m_pScalableEditBox = NULL;	// m_pScalableEditBox��NULL�ɃZ�b�g.

}

// �f�X�g���N�^~CMainWindow()
CMainWindow::~CMainWindow() {

	// �����o�̏I������.
	Destroy();	// Destroy�Ŕj��.

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CMainWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �����ɗ���ꍇ�̓E�B���h�E�N���X"MainWindow"�̃E�B���h�E�Ƃ��č쐬.
	return CWindow::Create(_T("MainWindow"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X��"MainWindow"�ɂ���Create�̃t���o�[�W�������Ă�.

}

// �E�B���h�E�j���֐�Destroy
void CMainWindow::Destroy() {

	// �q�E�B���h�E�̔j��.
	if (m_pScalableEditBox != NULL) {
		m_pScalableEditBox->Destroy();
		delete m_pScalableEditBox;
		m_pScalableEditBox = NULL;
	}
	if (m_pWindowListControl != NULL) {
		m_pWindowListControl->Destroy();	// m_pWindowListControl�̃E�B���h�E��j��.
		delete m_pWindowListControl;		// m_pWindowListControl�����.
		m_pWindowListControl = NULL;		// m_pWindowListControl��NULL�Ŗ��߂�.
	}

	// �����̃E�B���h�E���j��.
	CWindow::Destroy();	// CWindow::Destroy�Ŏ��g�̃E�B���h�E���j��.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CMainWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

#if 1

	m_pScalableEditBox = new CScalableEditBox();
	m_pScalableEditBox->Create(_T(""), ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 50, 50, 300, 200, hwnd, (HMENU)IDC_SCALABLEEDIT1, lpCreateStruct->hInstance);

#else

#if 1

	// �E�B���h�E���X�g�R���g���[���̍쐬.
	m_pWindowListControl = new CWindowListControl();	// CWindowListControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pWindowListControl�Ɋi�[.
	//m_pWindowListControl->Create(_T(""), 0, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Create�ŃE�B���h�E���X�g�R���g���[�����쐬.
	m_pWindowListControl->Create(_T(""), WS_VSCROLL, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Create�ŃE�B���h�E���X�g�R���g���[�����쐬.

	// �A�C�e����}��.
	m_pWindowListControl->Insert(_T("0"), 0, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insert��0�ԖڂɃE�B���h�E��}��.
	m_pWindowListControl->Insert(_T("1"), 1, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insert��1�ԖڂɃE�B���h�E��}��.
	m_pWindowListControl->Insert(_T("2"), 2, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insert��2�ԖڂɃE�B���h�E��}��.
	//m_pWindowListControl->Insert(_T("3"), 3, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insert��3�ԖڂɃE�B���h�E��}��.
	//m_pWindowListControl->Insert(_T("4"), 4, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insert��4�ԖڂɃE�B���h�E��}��.
	//m_pWindowListControl->Insert(_T("5"), 5, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insert��5�ԖڂɃE�B���h�E��}��.
	//m_pWindowListControl->Insert(_T("6"), 6, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insert��6�ԖڂɃE�B���h�E��}��.

#if 1
	// �q�E�B���h�E��}��.
	CWindowListItem * pItem1 = m_pWindowListControl->Get(0);	// m_pWindowListControl->Get��0�Ԗڂ��擾.
	CEditBoxPanel *pEditBoxPanel1 = new CEditBoxPanel();	// �G�f�B�b�g�{�b�N�X�p�l���̐���.
	pEditBoxPanel1->Create(_T(""), 0, PADDING + 50, PADDING, pItem1->m_iWidth - (PADDING * 2), pItem1->m_iHeight - (PADDING * 2), pItem1->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, lpCreateStruct->hInstance);	// Create�Ő���.
	pItem1->m_mapChildMap.insert(std::make_pair(_T("EditBoxPanel"), pEditBoxPanel1));	// pItem->m_mapChildMap.insert�Ń}�b�v�o�^.

	// �q�E�B���h�E��}��.
	CWindowListItem * pItem2 = m_pWindowListControl->Get(1);	// m_pWindowListControl->Get��1�Ԗڂ��擾.
	CEditBoxPanel *pEditBoxPanel2 = new CEditBoxPanel();	// �G�f�B�b�g�{�b�N�X�p�l���̐���.
	pEditBoxPanel2->Create(_T(""), 0, PADDING + 50, PADDING, pItem2->m_iWidth - (PADDING * 2), pItem2->m_iHeight - (PADDING * 2), pItem2->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + 1, lpCreateStruct->hInstance);	// Create�Ő���.
	pItem2->m_mapChildMap.insert(std::make_pair(_T("EditBoxPanel"), pEditBoxPanel2));	// pItem->m_mapChildMap.insert�Ń}�b�v�o�^.

	// �q�E�B���h�E��}��.
	CWindowListItem * pItem3 = m_pWindowListControl->Get(2);	// m_pWindowListControl->Get��2�Ԗڂ��擾.
	CEditBoxPanel *pEditBoxPanel3 = new CEditBoxPanel();	// �G�f�B�b�g�{�b�N�X�p�l���̐���.
	pEditBoxPanel3->Create(_T(""), 0, PADDING + 50, PADDING, pItem3->m_iWidth - (PADDING * 2), pItem3->m_iHeight - (PADDING * 2), pItem3->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + 2, lpCreateStruct->hInstance);	// Create�Ő���.
	pItem3->m_mapChildMap.insert(std::make_pair(_T("EditBoxPanel"), pEditBoxPanel3));	// pItem->m_mapChildMap.insert�Ń}�b�v�o�^.
#endif
																						
	// �폜
	m_pWindowListControl->Remove(1);
	//m_pWindowListControl->Remove(1);
	//m_pWindowListControl->Remove(0);
#else

	// �E�B���h�E���X�g�R���g���[���̍쐬.
	m_pWindowListControl = new CWindowListControl();	// CWindowListControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pWindowListControl�Ɋi�[.
	m_pWindowListControl->Create(_T(""), WS_HSCROLL | WS_VSCROLL, 3, 3, m_iWidth - 3, m_iHeight - 3, hwnd, (HMENU)IDC_WINDOWLISTCONTROL1, lpCreateStruct->hInstance);	// m_pWindowListControl->Create�ŃE�B���h�E���X�g�R���g���[�����쐬.(���̎��_�ł�, �܂�WS_BORDER��t���Ă���.)

	// 1�ڂ̃A�C�e����}��.
	m_pWindowListControl->Insert(_T("0"), 0, 100, lpCreateStruct->hInstance);	// m_pWindowListControl->Insert��0�ԖڂɃE�B���h�E��}��.
	CWindowListItem * pItem = m_pWindowListControl->Get(0);	// m_pWindowListControl->Get��0�Ԗڂ��擾.
	CEditBoxPanel *pEditBoxPanel = new CEditBoxPanel();
	pEditBoxPanel->Create(_T(""), WS_BORDER, 3, 3, pItem->m_iWidth - 6, pItem->m_iHeight - 6, pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, lpCreateStruct->hInstance);	// Create�Ő���.
	pItem->m_mapChildMap.insert(std::make_pair(_T("EditBoxPanel"), pEditBoxPanel));	// pItem->m_mapChildMap.insert�Ń}�b�v�o�^.

#endif

#endif

	// ����.
	return 0;	// �����Ȃ̂�0��Ԃ�.

}

// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CMainWindow::OnSize(UINT nType, int cx, int cy) {

	// ���ۂ̃E�B���h�E�T�C�Y���i�[.
	RECT rcWindow;
	GetWindowRect(m_hWnd, &rcWindow);	// GetWindowRect�ŃE�B���h�E�S�̂̃T�C�Y���擾.
	m_iWidth = rcWindow.right - rcWindow.left;	// m_iWidth��rcWindow.right - rcWindow.left���Z�b�g.
	m_iHeight = rcWindow.bottom - rcWindow.top;	// m_iHeight��rcWindow.bottom - rcWindow.top���Z�b�g.

	// �����̃N���C�A���g�̈�̃T�C�Y���g���Ďq�E�B���h�E�����T�C�Y.
	//m_pWindowListControl->MoveWindow(1, 1, cx - (1 * 2), cy - (1 * 2));	// 1���菬�����ƂȂ��, 1px�Ȃ�2�{��2px�T�C�Y���������Ȃ�Ȃ���΂Ȃ�Ȃ�.
	if (m_pWindowListControl != NULL) {
		m_pWindowListControl->MoveWindow(PADDING, PADDING, cx - (PADDING * 2), cy - (PADDING * 2));	// 3px�Ȃ�2�{��6px�T�C�Y���������Ȃ�Ȃ���΂Ȃ�Ȃ�.
	}

}