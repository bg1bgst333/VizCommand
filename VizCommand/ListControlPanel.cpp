// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "ListControlPanel.h"	// ���X�g�R���g���[���p�l���N���X
// ����̃w�b�_
#include <commctrl.h>	// �R�����R���g���[��

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CListControlPanel::RegisterClass(HINSTANCE hInstance) {

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("ListControlPanel"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"ListControlPanel"��o�^.

}

// �R���X�g���N�^CListControlPanel
CListControlPanel::CListControlPanel() : CUserControl() {

	// �����o�̏�����
	m_pListControl = NULL;	// m_pListControl��NULL�ŏ�����.

}

// �f�X�g���N�^~CListControlPanel()
CListControlPanel::~CListControlPanel() {

	// �����o�̏I������.
	Destroy();	// Destroy�Ŕj��.

}

// �E�B���h�E�쐬�֐�Create
BOOL CListControlPanel::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	m_nId = hMenu;
	return CUserControl::Create(_T("ListControlPanel"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, m_nId, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"ListControlPanel"�ȃE�B���h�E���쐬.

}

// �E�B���h�E�j���֐�Destroy
void CListControlPanel::Destroy() {

	// �q�E�B���h�E�̔j��.
	if (m_pListControl != NULL) {
		m_pListControl->Destroy();	// m_pListControl�̃E�B���h�E��j��.
		delete m_pListControl;	// delete�ŉ��.
		m_pListControl = NULL;	// NULL�Ŗ��߂�.
	}

	// �����̃E�B���h�E���j��.
	CWindow::Destroy();	// CWindow::Destroy�Ŏ��g�̃E�B���h�E���j��.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CListControlPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �q���X�g�R���g���[���̐���.
	m_pListControl = new CListControl();	// CListControl�I�u�W�F�N�g���쐬��, �|�C���^��m_pListControl�Ɋi�[.
	m_pListControl->Create(_T(""), WS_BORDER | WS_VSCROLL | WS_HSCROLL | LVS_ICON, PADDING, PADDING, m_iWidth - (PADDING * 2), m_iHeight - (PADDING * 2), hwnd, m_nId + 100, lpCreateStruct->hInstance);	// m_pListControl->Create�Ń��X�g�R���g���[���쐬.

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CListControlPanel::OnSize(UINT nType, int cx, int cy) {

	// ���ۂ̃E�B���h�E�T�C�Y���i�[.
	m_iWidth = cx;	// m_iWidth��cx���Z�b�g.
	m_iHeight = cy;	// m_iHeight��cy���Z�b�g.

	// �q�E�B���h�E�̃��T�C�Y
	if (m_pListControl != NULL) {
		m_pListControl->MoveWindow(PADDING, PADDING, m_iWidth - (PADDING * 2), m_iHeight - (PADDING * 2));
	}

}