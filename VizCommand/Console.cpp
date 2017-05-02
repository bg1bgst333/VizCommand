// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Console.h"	// �R���\�[���N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CConsole::RegisterClass(HINSTANCE hInstance) {

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("Console"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"Console"��o�^.

}

// �R���X�g���N�^�E�f�X�g���N�^
CConsole::CConsole() : CScalableEditBoxPanel() {

}

// �f�X�g���N�^~CCConsole()
CConsole::~CConsole() {

}

// �E�B���h�E�쐬�֐�Create
BOOL CConsole::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	m_nId = hMenu;
	return CUserControl::Create(_T("Console"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, m_nId, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"Console"�ȃE�B���h�E���쐬.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CConsole::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �q�G�f�B�b�g�{�b�N�X�̐���.
	m_pEditBox = new CConsoleCore();	// CConsoleCore�I�u�W�F�N�g���쐬��, �|�C���^��m_pEditBox�Ɋi�[.
	m_pEditBox->Create(_T(""), ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL /*| ES_AUTOVSCROLL*/, 0, 0, m_iWidth, m_iHeight, hwnd, m_nId + 100, lpCreateStruct->hInstance);	// m_pEditBox->Create�ŃG�f�B�b�g�{�b�N�X�쐬.

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}