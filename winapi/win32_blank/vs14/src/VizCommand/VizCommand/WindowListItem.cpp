// �w�b�_�̃C���N���[�h
#include "WindowListItem.h"	// �E�B���h�E���X�g�A�C�e���N���X

// �E�B���h�E�쐬�֐�Create.
BOOL CWindowListItem::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �����o�ɃZ�b�g.
	m_x = x;	// m_x��x���Z�b�g.
	m_y = y;	// m_y��y���Z�b�g.
	m_iWidth = iWidth;	// m_iWidth��iWidth���Z�b�g.
	m_iHeight = iHeight;	// m_iHeight��iHeight���Z�b�g.

	// �N���X��"WindowListItem"�̎q�E�B���h�E���쐬.
	return CWindow::Create(_T("WindowListItem"), _T(""), WS_CHILD | WS_VISIBLE, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ŃN���X��"WindowListItem"�̎q�E�B���h�E���쐬.

}

// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
void CWindowListItem::Destroy() {

	// �j��.
	DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
	m_hWnd = NULL;	// m_hWnd��NULL�ɂ���.

}

// �E�B���h�E�Ƀe�L�X�g���Z�b�g���郁���o�֐�SetWindowText.
void CWindowListItem::SetWindowText(LPCTSTR lpctszString) {

	_tcscpy_s(m_tszText, 256, lpctszString);

}

// �E�B���h�E�̃T�C�Y��ʒu��ύX���郁���o�֐�MoveWindow.
void CWindowListItem::MoveWindow(int x, int y, int iWidth, int iHeight){

	m_x = x;
	m_y = y;
	m_iWidth = iWidth;
	m_iHeight = iHeight;
	::MoveWindow(m_hWnd, x, y, iWidth, iHeight, TRUE);

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CWindowListItem::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �E�B���h�E�j�����̃n���h��OnDestroy
void CWindowListItem::OnDestroy() {

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CWindowListItem::OnSize(UINT nType, int cx, int cy){

	// �T�C�Y�X�V
	m_iWidth = cx;
	m_iHeight = cy;

}

// ��ʕ`��̍X�V��v�����ꂽ��.
void CWindowListItem::OnPaint() {

	// �ϐ��̐錾
	HDC hDC;
	PAINTSTRUCT ps;

	// �`��̊J�n.
	hDC = ::BeginPaint(m_hWnd, &ps);

	// �A�C�e���Y�p�l���̗̈����`�ŕ`��.
	HPEN hOldPen;
	HBRUSH hOldBrush;
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	HBRUSH hWhiteBrush = CreateSolidBrush(RGB(0, 0, 255));
	hOldPen = (HPEN)SelectObject(hDC, hGreenPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hWhiteBrush);
	Rectangle(hDC, m_x, m_y, m_iWidth, m_iHeight);
	SelectObject(hDC, hOldBrush);
	SelectObject(hDC, hOldPen);
	DeleteObject(hWhiteBrush);
	DeleteObject(hGreenPen);

	// �e�L�X�g�`��.
	::TextOut(hDC, 0, 0, m_tszText, lstrlen(m_tszText));

	// �`��̏I��.
	::EndPaint(m_hWnd, &ps);

}

// �E�B���h�E����鎞�̃n���h��OnClose.
int CWindowListItem::OnClose() {

	// 0��Ԃ�.
	return 0;	// 0��Ԃ��ăE�B���h�E�����.

}