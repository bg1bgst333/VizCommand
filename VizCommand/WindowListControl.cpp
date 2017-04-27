// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WindowListControl.h"	// �E�B���h�E���X�g�R���g���[���N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CWindowListControl::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E���X�g�A�C�e���Y�p�l����o�^.
	CWindowListItemsPanel::RegisterClass(hInstance);	// �q�E�B���h�E��o�^.

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("WindowListControl"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"WindowListControl"��o�^.

}

// �R���X�g���N�^CWindowListControl()
CWindowListControl::CWindowListControl() : CUserControl() {

	// �����o�̏�����
	m_pWindowListItemsPanel = NULL;	// m_pWindowListItemsPanel��NULL�ŏ�����.

}

// �f�X�g���N�^~CWindowListControl()
CWindowListControl::~CWindowListControl() {

	// �����o�̏I������.
	Destroy();	// Destroy�Ŕj��.

}

// �E�B���h�E�쐬�֐�Create
BOOL CWindowListControl::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	return CUserControl::Create(_T("WindowListControl"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"WindowListControl"�ȃE�B���h�E���쐬.

}

// �E�B���h�E�j���֐�Destroy
void CWindowListControl::Destroy() {

	// �q�E�B���h�E�̔j��.
	if (m_pWindowListItemsPanel != NULL) {
		m_pWindowListItemsPanel->Destroy();	// m_pWindowListItemsPanel�̃E�B���h�E��j��.
		delete m_pWindowListItemsPanel;		// m_pWindowListItemsPanel�����.
		m_pWindowListItemsPanel = NULL;		// m_pWindowListItemsPanel��NULL�Ŗ��߂�.
	}

	// �y���ƃu���V�̔j��.
	DeleteObject(m_hBrush);	// �u���V�̔j��.
	DeleteObject(m_hPen);	// �y���̔j��.

	// �����̃E�B���h�E���j��.
	CWindow::Destroy();	// CWindow::Destroy�Ŏ��g�̃E�B���h�E���j��.

}

// �A�C�e���}���֐�Insert
BOOL CWindowListControl::Insert(LPCTSTR lpctszWindowName, int iIndex, int iHeight, HINSTANCE hInstance) {

	// �A�C�e���Y�p�l����Insert���Ă�.
	return m_pWindowListItemsPanel->Insert(lpctszWindowName, iIndex, iHeight, hInstance);	// m_pWindowListItemsPanel->Insert�ő}��.

}

// �A�C�e���폜�֐�Remove
BOOL CWindowListControl::Remove(int iIndex) {

	// �A�C�e���Y�p�l����Remove���Ă�.
	return m_pWindowListItemsPanel->Remove(iIndex);	// m_pWindowListItemsPanel->Remove�ō폜.

}

// �A�C�e���擾�֐�Get
CWindowListItem * CWindowListControl::Get(int iIndex) {

	// iIndex�Ԗڂ�Ԃ�.
	return m_pWindowListItemsPanel->Get(iIndex);	// m_pWindowListItemsPanel->Get��iIndex�Ԗڂ�Ԃ�.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CWindowListControl::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �y���ƃu���V�̍쐬.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0x7f, 0));		// ��(�Z)�̃y�����쐬.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0xff, 0));		// ��(�W)�̃u���V���쐬.

	// �E�B���h�E���X�g�A�C�e���Y�p�l���N���X�̍쐬.
	m_pWindowListItemsPanel = new CWindowListItemsPanel();	// CWindowListItemsPanel�I�u�W�F�N�g���쐬��, �|�C���^��m_pWindowListItemsPanel�Ɋi�[.
	m_pWindowListItemsPanel->Create(_T(""), 0, 30, 0, 300, 10, hwnd, (HMENU)IDC_WINDOWLISTITEMSPANEL1, lpCreateStruct->hInstance);	// m_pWindowListItemsPanel->Create�ŃE�B���h�E���X�g�A�C�e���Y�p�l�����쐬.(�e�E�B���h�E��菬����.)

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
void CWindowListControl::OnPaint() {

	// �ϐ��̐錾
	HDC hDC;			// �f�o�C�X�R���e�L�X�g�n���h��HDC�^hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT�\���̕ϐ�ps.

	// ��`��`��.(�N���C�A���g�̈�̓X�N���[���o�[���܂܂Ȃ�.)
	RECT rc;
	GetClientRect(m_hWnd, &rc);	// GetClientRect�ŃN���C�A���g�̈�̋�`���擾.

	// �X�N���[���o�[�ݒ�.
	// ��
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// �T�C�Y���Z�b�g.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// �t���O���Z�b�g.
	m_ScrollInfo.nPage = rc.right - rc.left;	// �N���C�A���g�̈�̕����Z�b�g.
	m_ScrollInfo.nMin = 0;	// �ŏ��l���Z�b�g.
	m_ScrollInfo.nMax = m_pWindowListItemsPanel->m_iWidth;	// �q�E�B���h�E�̕����Z�b�g.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, TRUE);	// SetScrollInfo�ŃZ�b�g.

	// �c
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// �T�C�Y���Z�b�g.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// �t���O���Z�b�g.
	m_ScrollInfo.nPage = rc.bottom - rc.top;	// �N���C�A���g�̈�̍������Z�b�g.
	m_ScrollInfo.nMin = 0;	// �ŏ��l���Z�b�g.
	m_ScrollInfo.nMax = m_pWindowListItemsPanel->m_iHeight;	// �q�E�B���h�E�̍������Z�b�g.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);	// SetScrollInfo�ŃZ�b�g.

	// �`��J�n.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaint�ŕ`��J�n.

	// �y���ƃu���V�̑I��.
	HPEN hOldPen = (HPEN)SelectObject(hDC, m_hPen);		// �΂̃y����I��.
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, m_hBrush);	// �΂̃u���V��I��.
	// ��`�`��.
	Rectangle(hDC, 0, 0, rc.right - rc.left, rc.bottom - rc.top);	// Rectangle�ŋ�`��`��.
	// �y���ƃu���V�̕���
	SelectObject(hDC, hOldBrush);		// �Â��u���V��I��.
	SelectObject(hDC, hOldPen);		// �Â��y����I��.

	// �`��I��.
	EndPaint(m_hWnd, &ps);	// EndPaint�ŕ`��I��.

}

// ���������X�N���[���o�[�C�x���g���̃n���h��OnHScroll.
void CWindowListControl::OnHScroll(UINT nSBCode, UINT nPos) {

	// �X�N���[�����擾.
	m_ScrollInfo.fMask = SIF_POS;	// �ʒu�����ύX���[�h(���ꂪ�Ȃ���, �X�N���[���o�[�����̈ʒu�ɖ߂��Ă��܂��̂Œ���!���������O!)
	GetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo);	// �}�X�N��ݒ肵�Ă���GetScrollInfo.(����������!)

	// �X�N���[���o�[����.
	switch (nSBCode) {	// nSBCode���ƂɐU�蕪��.

		// ��ԍ�
		case SB_LEFT:

			// �ʒu���ŏ��l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// ��ԉE
		case SB_RIGHT:

			// �ʒu���ő�l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1��
		case SB_LINELEFT:

			// nPos��0�łȂ���΃f�N�������g.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1��E
		case SB_LINERIGHT:

			// nPos���ő�l-1�łȂ���΃C���N�������g.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1�y�[�W��
		case SB_PAGELEFT:

			// nPage�����炷.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1�y�[�W�E
		case SB_PAGERIGHT:

			// nPage�����₷.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBTRACK:

			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBPOSITION:

			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// ����ȊO.
		default:

			break;

	}

	// �X�N���[�����ݒ�.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, TRUE);

	// �A�C�e���Y�p�l���̈ړ�.
	m_pWindowListItemsPanel->MoveWindow(0, -m_ScrollInfo.nPos);	// m_pWindowListItemsPanel->MoveWindow��x�������ύX.

}

// ���������X�N���[���o�[�C�x���g���̃n���h��OnVScroll.
void CWindowListControl::OnVScroll(UINT nSBCode, UINT nPos) {

	// �X�N���[�����擾.
	m_ScrollInfo.fMask = SIF_POS;	// �ʒu�����ύX���[�h(���ꂪ�Ȃ���, �X�N���[���o�[�����̈ʒu�ɖ߂��Ă��܂��̂Œ���!���������O!)
	GetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo);	// �}�X�N��ݒ肵�Ă���GetScrollInfo.(����������!)

	// �X�N���[���o�[����.
	switch (nSBCode) {	// nSBCode���ƂɐU�蕪��.

		// ��ԏ�
		case SB_TOP:

			// �ʒu���ŏ��l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMin;
			break;

		// ��ԉ�
		case SB_BOTTOM:

			// �ʒu���ő�l��.
			m_ScrollInfo.nPos = m_ScrollInfo.nMax;
			break;

		// 1�s��
		case SB_LINEUP:

			// nPos��0�łȂ���΃f�N�������g.
			if (m_ScrollInfo.nPos > 0) {
				m_ScrollInfo.nPos--;
			}
			break;

		// 1�s��
		case SB_LINEDOWN:

			// nPos���ő�l-1�łȂ���΃C���N�������g.
			if (m_ScrollInfo.nPos < m_ScrollInfo.nMax - 1) {
				m_ScrollInfo.nPos++;
			}
			break;

		// 1�y�[�W��
		case SB_PAGEUP:

			// nPage�����炷.
			m_ScrollInfo.nPos -= m_ScrollInfo.nPage;
			break;

		// 1�y�[�W��
		case SB_PAGEDOWN:

			// nPage�����₷.
			m_ScrollInfo.nPos += m_ScrollInfo.nPage;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBTRACK:

			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// �܂݂��h���b�O��.
		case SB_THUMBPOSITION:

			// ������nPos���Z�b�g
			m_ScrollInfo.nPos = nPos;
			break;

		// ����ȊO.
		default:

			break;

	}

	// �X�N���[�����ݒ�.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);

	// �A�C�e���Y�p�l���̈ړ�.
	m_pWindowListItemsPanel->MoveWindow(1, -m_ScrollInfo.nPos);	// m_pWindowListItemsPanel->MoveWindow��y�������ύX.

}