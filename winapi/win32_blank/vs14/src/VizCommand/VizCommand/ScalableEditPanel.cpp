// �w�b�_�̃C���N���[�h
#include "ScalableEdit.h"	// �X�P�[���u���G�f�B�b�g�R���g���[��
#include "ScalableEditPanel.h"	// �X�P�[���u���G�f�B�b�g�p�l���N���X

// �E�B���h�E�쐬�֐�Create(���̃E�B���h�E��p�ɃJ�X�^�}�C�Y���ꂽ����.)
BOOL CScalableEditPanel::Create(int x, int y, int iWidth, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �����o�ɃZ�b�g.
	m_x = x;
	m_y = y;
	m_iWidth = iWidth;
	m_nID = hMenu;

	// �����͓K���ɃZ�b�g.
	m_iHeight = 200;

	// �N���X��"ScalableEditPanel"�̎q�E�B���h�E���쐬.
	return CWindow::Create(_T("ScalableEditPanel"), _T(""), WS_CHILD | WS_VISIBLE , x, y, iWidth, m_iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ŃN���X��"ScalableEditPanel"�̎q�E�B���h�E���쐬.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CScalableEditPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// �ϐ��̏�����
	CScalableEdit *pScalableEdit = NULL;
	BOOL bRet = FALSE;

	// �q�E�B���h�E�ƂȂ�X�P�[���u���G�f�B�b�g�R���g���[���I�u�W�F�N�g�̍쐬.
	pScalableEdit = new CScalableEdit();
	bRet = pScalableEdit->Create(m_x, m_y, m_iWidth, hwnd, m_nID + 100, lpCreateStruct->hInstance);
	m_pEdit = pScalableEdit;
	m_iLineHeight = pScalableEdit->m_iLineHeight;
	m_iHeight = m_iLineHeight;
	::MoveWindow(hwnd, m_x, m_y, m_iWidth, m_iHeight, TRUE);
	if (bRet) {
		return 0;
	}
	else {
		if (m_pEdit != NULL) {
			m_pEdit->Destroy();
			delete m_pEdit;
			m_pEdit = NULL;
		}
		return -1;
	}

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CScalableEditPanel::OnSize(UINT nType, int cx, int cy){

	m_pEdit->MoveWindow(0, 0, cx, cy);

}

// ��ʕ`��̍X�V��v�����ꂽ��.
void CScalableEditPanel::OnPaint(){

	// �ϐ��̐錾
	HDC hDC;
	PAINTSTRUCT ps;

	// �`��̊J�n.
	hDC = ::BeginPaint(m_hWnd, &ps);

	// �A�C�e���Y�p�l���̗̈����`�ŕ`��.
	HPEN hOldPen;
	HBRUSH hOldBrush;
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HBRUSH hWhiteBrush = CreateSolidBrush(RGB(255, 0, 0));
	hOldPen = (HPEN)SelectObject(hDC, hGreenPen);
	hOldBrush = (HBRUSH)SelectObject(hDC, hWhiteBrush);
	Rectangle(hDC, m_x, m_y, m_iWidth, m_iHeight);
	SelectObject(hDC, hOldBrush);
	SelectObject(hDC, hOldPen);
	DeleteObject(hWhiteBrush);
	DeleteObject(hGreenPen);

	// �`��̏I��.
	::EndPaint(m_hWnd, &ps);

}

// �L�[�������ꂽ��.
int CScalableEditPanel::OnKeyDown(WPARAM wParam, LPARAM lParam){

	// �Ƃ肠����0��Ԃ�.
	return 0;

}

// �q�E�B���h�E�̃T�C�Y���ύX���ꂽ��(�Ǝ����b�Z�[�W)
void CScalableEditPanel::OnSizeChild(HWND hWnd, int width, int height, HWND hChildWnd){

	::MoveWindow(m_hWnd, 0, 0, width, height, TRUE);

}
