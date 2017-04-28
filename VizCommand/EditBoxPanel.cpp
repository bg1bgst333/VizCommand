// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "EditBoxPanel.h"	// �G�f�B�b�g�{�b�N�X�p�l���N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CEditBoxPanel::RegisterClass(HINSTANCE hInstance) {

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("EditBoxPanel"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"EditBoxPanel"��o�^.

}

// �R���X�g���N�^CEditBoxPanel
CEditBoxPanel::CEditBoxPanel() : CUserControl() {

	// �����o�̏�����
	m_pEditBox = NULL;	// m_pEditBox��NULL�ŏ�����.

}

// �f�X�g���N�^~CEditBoxPanel()
CEditBoxPanel::~CEditBoxPanel() {

	// �����o�̏I������.
	Destroy();	// Destroy�Ŕj��.

}

// �E�B���h�E�쐬�֐�Create
BOOL CEditBoxPanel::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	m_nId = hMenu;
	return CUserControl::Create(_T("EditBoxPanel"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, m_nId, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"EditBoxPanel"�ȃE�B���h�E���쐬.

}

// �E�B���h�E�j���֐�Destroy
void CEditBoxPanel::Destroy() {

	// �q�E�B���h�E�̔j��.
	if (m_pEditBox != NULL) {
		m_pEditBox->Destroy();	// m_pEditBox�̃E�B���h�E��j��.
		delete m_pEditBox;	// delete�ŉ��.
		m_pEditBox = NULL;	// NULL�Ŗ��߂�.
	}

	// �����̃E�B���h�E���j��.
	CWindow::Destroy();	// CWindow::Destroy�Ŏ��g�̃E�B���h�E���j��.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CEditBoxPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �q�G�f�B�b�g�{�b�N�X�̐���.
	m_pEditBox = new CEditBox();	// CEditBox�I�u�W�F�N�g���쐬��, �|�C���^��m_pEditBox�Ɋi�[.
	m_pEditBox->Create(_T(""), WS_BORDER | ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL | WS_HSCROLL | WS_VSCROLL, 3, 3, m_iWidth - 3, m_iHeight - 3, hwnd, m_nId + 100, lpCreateStruct->hInstance);	// m_pEditBox->Create�ŃG�f�B�b�g�{�b�N�X�쐬.

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}