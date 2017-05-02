// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "StreamConsole.h"	// �X�g���[���R���\�[���N���X
#include "Console.h"	// �R���\�[���N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CStreamConsole::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E���X�g�A�C�e���Y�p�l����o�^.
	CWindowListItemsPanel::RegisterClass(hInstance);	// �q�E�B���h�E��o�^.

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("StreamConsole"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"StreamConsole"��o�^.

}

// �R���X�g���N�^CStreamConsole()
CStreamConsole::CStreamConsole() : CWindowListControl() {

}

// �f�X�g���N�^~CStreamConsole()
CStreamConsole::~CStreamConsole() {

}

// �E�B���h�E�쐬�֐�Create
BOOL CStreamConsole::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	return CUserControl::Create(_T("StreamConsole"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"StreamConsole"�ȃE�B���h�E���쐬.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CStreamConsole::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �y���ƃu���V�̍쐬.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 0));		// ���̃y�����쐬.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));		// ���̃u���V���쐬.

	// �E�B���h�E���X�g�A�C�e���Y�p�l���N���X�̍쐬.
	m_pWindowListItemsPanel = new CWindowListItemsPanel();	// CWindowListItemsPanel�I�u�W�F�N�g���쐬��, �|�C���^��m_pWindowListItemsPanel�Ɋi�[.
	m_pWindowListItemsPanel->Create(_T(""), 0, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTITEMSPANEL1, lpCreateStruct->hInstance);	// m_pWindowListItemsPanel->Create�ŃE�B���h�E���X�g�A�C�e���Y�p�l�����쐬.(�e�E�B���h�E��菬����.)

	// �f�t�H���g�A�C�e���̑}��.
	Insert(_T("0"), 0, 100, lpCreateStruct->hInstance);	// Insert��0�ԖڂɃE�B���h�E��}��

	// �f�t�H���g�A�C�e���Ɏq�E�B���h�E���Z�b�g.
	CWindowListItem *pItem = m_pWindowListItemsPanel->Get(0);	// 0�Ԗڂ��擾.
	CConsole *pConsole = new CConsole();	// �R���\�[���𐶐�.
	pConsole->Create(_T(""), 0, 0, 0, pItem->m_iWidth, pItem->m_iHeight, pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START, lpCreateStruct->hInstance);	// �R���\�[���̃E�B���h�E�𐶐�.
	pItem->m_mapChildMap.insert(std::make_pair(_T("Console"), pConsole));	// �A�C�e���Ɏq�E�B���h�E��}��.

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}