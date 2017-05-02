// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "ScalableEditBoxPanel.h"	// �X�J���u���G�f�B�b�g�{�b�N�X�p�l���N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CScalableEditBoxPanel::RegisterClass(HINSTANCE hInstance) {

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("ScalableEditBoxPanel"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"ScalableEditBoxPanel"��o�^.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�u���V�w��)
BOOL CScalableEditBoxPanel::RegisterClass(HINSTANCE hInstance, HBRUSH hBrush) {

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("ScalableEditBoxPanel"), hBrush);	// CUserControl::RegisterClass(�w�i�u���V�w��)�ŃE�B���h�E�N���X"ScalableEditBoxPanel"��o�^.

}

// �R���X�g���N�^CScalableEditBoxPanel()
CScalableEditBoxPanel::CScalableEditBoxPanel() : CEditBoxPanel() {

}

// �f�X�g���N�^~CScalableEditBoxPanel()
CScalableEditBoxPanel::~CScalableEditBoxPanel() {

}

// �E�B���h�E�쐬�֐�Create
BOOL CScalableEditBoxPanel::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	m_nId = hMenu;
	return CUserControl::Create(_T("ScalableEditBoxPanel"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, m_nId, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"ScalableEditBoxPanel"�ȃE�B���h�E���쐬.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CScalableEditBoxPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �q�G�f�B�b�g�{�b�N�X�̐���.
	m_pEditBox = new CScalableEditBox();	// CScalableEditBox�I�u�W�F�N�g���쐬��, �|�C���^��m_pEditBox�Ɋi�[.
	m_pEditBox->Create(_T(""), ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 0, 0, m_iWidth, m_iHeight, hwnd, m_nId + 100, lpCreateStruct->hInstance);	// m_pEditBox->Create�ŃG�f�B�b�g�{�b�N�X�쐬.

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CScalableEditBoxPanel::OnSize(UINT nType, int cx, int cy) {

	// ���ۂ̃E�B���h�E�T�C�Y���i�[.
	m_iWidth = cx;	// m_iWidth��cx���Z�b�g.
	m_iHeight = cy;	// m_iHeight��cy���Z�b�g.

#if 1

	// �q�E�B���h�E�̃��T�C�Y
	if (m_pEditBox != NULL) {
		//m_pEditBox->MoveWindow(PADDING, PADDING, m_iWidth - (PADDING * 2), m_iHeight - (PADDING * 2));
		m_pEditBox->MoveWindow(0, 0, m_iWidth, m_iHeight);
	}

#endif

}

// ���[�U��`���b�Z�[�W�������������̃n���h��.
void CScalableEditBoxPanel::OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// switch-case���ŐU�蕪����.
	switch (uMsg) {

		// �q����e�փE�B���h�E�T�C�Y�ύX�̗v��������������.
		case UM_SIZECHILD:

			// UM_SIZECHILD�u���b�N
			{

				// OnSizeChild�ɔC����.
				OnSizeChild(wParam, lParam);	// OnSizeChild�ɔC����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ����ȊO.
		default:

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

	}

}

// �q����e�փE�B���h�E�T�C�Y�ύX�̗v���������������̓Ǝ��n���h��.
void CScalableEditBoxPanel::OnSizeChild(WPARAM wParam, LPARAM lParam) {

	// �ϐ��̐錾.
	int iWidth;
	int iHeight;

	// �q�E�B���h�E�̃T�C�Y���擾.
	iWidth = LOWORD(wParam);
	iHeight = HIWORD(wParam);

	// �E�B���h�E�T�C�Y�̕ύX.
	HWND hWnd = (HWND)lParam;	// lParam�͎q�E�B���h�E�̃n���h��.
	HWND hParent = GetParent(hWnd);	// hParent�����̃E�B���h�E.(OnCreate�̌�Ȃ̂Ń����o�ɓ����ĂȂ�.)
	::MoveWindow(hParent, m_x, m_y, iWidth, iHeight, TRUE);	// �q�E�B���h�E�Ɠ�������.

	// UM_SIZECHILD�Ŏq�E�B���h�E�̃T�C�Y�ɍ��킹��.
	WPARAM wp;
	wp = MAKEWPARAM(m_iWidth, m_iHeight);
	SendMessage(GetParent(hParent), UM_SIZECHILD, wp, (LPARAM)hParent);

}