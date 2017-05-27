// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WindowListItem.h"	// �E�B���h�E���X�g�A�C�e���N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CWindowListItem::RegisterClass(HINSTANCE hInstance) {

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("WindowListItem"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"WindowListItem"��o�^.

}

// �R���X�g���N�^CWindowListItem()
CWindowListItem::CWindowListItem() : CUserControl() {

}

// �f�X�g���N�^~CWindowListItem()
CWindowListItem::~CWindowListItem() {

}

// �E�B���h�E�쐬�֐�Create
BOOL CWindowListItem::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	return CUserControl::Create(_T("WindowListItem"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"WindowListItem"�ȃE�B���h�E���쐬.

}

// �E�B���h�E�j���֐�Destroy
void CWindowListItem::Destroy() {

	// �A�C�e���̈�č폜
	std::map<tstring, CWindow *>::iterator itor = m_mapChildMap.begin();	// �C�e���[�^.
	while (itor != m_mapChildMap.end()) {
		if (itor->second != NULL) {
			itor->second->Destroy();
			delete itor->second;
			itor->second = NULL;
		}
		itor++;
	}
	m_mapChildMap.clear();

	// �y���ƃu���V�̔j��.
	DeleteObject(m_hBrush);	// �u���V�̔j��.
	DeleteObject(m_hPen);	// �y���̔j��.

	// �����̃E�B���h�E���j��.
	CWindow::Destroy();	// CWindow::Destroy�Ŏ��g�̃E�B���h�E���j��.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CWindowListItem::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �y���ƃu���V�̍쐬.
	//m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0xff, 0, 0));		// ��(�Z)�̃y�����쐬.
	//m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0xff, 0xc0, 0xcb));		// ��(�W)�̃u���V���쐬.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 0));		// ���̃y�����쐬.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));		// ���̃u���V���쐬.

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CWindowListItem::OnSize(UINT nType, int cx, int cy) {

	// ���ۂ̃E�B���h�E�T�C�Y���i�[.
	m_iWidth = cx;	// m_iWidth��cx���Z�b�g.
	m_iHeight = cy;	// m_iHeight��cy���Z�b�g.

	// �A�C�e���̈�ă��T�C�Y.
	std::map<tstring, CWindow *>::iterator itor = m_mapChildMap.begin();	// �C�e���[�^.
	while (itor != m_mapChildMap.end()) {
		itor->second->MoveWindow(2, m_iWidth);	// �e�E�B���h�E�̕��ɍ��킹��.
		itor++;
	}

}

// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
void CWindowListItem::OnPaint() {

	// �ϐ��̐錾
	HDC hDC;			// �f�o�C�X�R���e�L�X�g�n���h��HDC�^hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT�\���̕ϐ�ps.

	// �`��J�n.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaint�ŕ`��J�n.
	// �y���ƃu���V�̑I��.
	HPEN hOldPen = (HPEN)SelectObject(hDC, m_hPen);		// �̃y����I��.
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, m_hBrush);	// �̃u���V��I��.
	// ��`��`��.(�N���C�A���g�̈�̓X�N���[���o�[���܂܂Ȃ�.)
	RECT rc;
	GetClientRect(m_hWnd, &rc);	// GetClientRect�ŃN���C�A���g�̈�̋�`���擾.
	Rectangle(hDC, 0, 0, rc.right - rc.left, rc.bottom - rc.top);	// Rectangle�ŋ�`��`��.
	SetTextColor(hDC, RGB(0, 0, 0));
	TCHAR tszText[1024] = { 0 };
	::GetWindowText(m_hWnd, tszText, 1024);
	TextOut(hDC, 10, 10, tszText, lstrlen(tszText));
	// �y���ƃu���V�̕���
	SelectObject(hDC, hOldBrush);		// �Â��u���V��I��.
	SelectObject(hDC, hOldPen);		// �Â��y����I��.
	// �`��I��.
	EndPaint(m_hWnd, &ps);	// EndPaint�ŕ`��I��.

}

// ���[�U��`���b�Z�[�W�������������̃n���h��.
void CWindowListItem::OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {

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
void CWindowListItem::OnSizeChild(WPARAM wParam, LPARAM lParam) {

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

	// UM_SIZECHILD�Őe�E�B���h�E�̃��X�g�𒲐����Ă��炤.
	WPARAM wp;
	wp = MAKEWPARAM(m_iWidth, m_iHeight);
	SendMessage(GetParent(hParent), UM_SIZECHILD, wp, (LPARAM)hParent);

}