// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "PictureBox.h"	// �s�N�`���[�{�b�N�X�N���X

// �R���X�g���N�^CPictureBox()
CPictureBox::CPictureBox() {

	// ������
	m_hBitmap = NULL;		// m_hBitmap��NULL���Z�b�g.
	m_hMemDC = NULL;		// m_hMemDC��NULL���Z�b�g.
	m_iPictureWidth = 0;	// m_iPictureWidth��0���Z�b�g.
	m_iPictureHeight = 0;	// m_iPictureHeight��0���Z�b�g.

}

// �f�X�g���N�^~CPictureBox()
CPictureBox::~CPictureBox() {

	// �I������
	m_iPictureHeight = 0;	// m_iPictureHeight��0���Z�b�g.
	m_iPictureWidth = 0;	// m_iPictureWidth��0���Z�b�g.
	if (m_hMemDC != NULL) {
		DeleteDC(m_hMemDC);			// DelteDC��m_hMemDC���폜.
		m_hMemDC = NULL;			// m_hMemDC��NULL���Z�b�g.
	}
	if (m_hBitmap != NULL) {
		DeleteObject(m_hBitmap);	// DeleteObject��m_hBitmap���폜.
		m_hBitmap = NULL;			// m_hBitmap��NULL���Z�b�g.
	}

}

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CPictureBox::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �E�B���h�E�̍쐬.
	return CCustomControl::Create(_T("Static"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CCustomControl::Create�ŃE�B���h�E���쐬��, ���̖߂�l��return�ŕԂ�.

}

// �摜�����[�h����֐�Load.
BOOL CPictureBox::Load(LPCTSTR lpctszFileName, int iWidth, int iHeight) {

	// �ϐ��̐錾�E������.
	HINSTANCE hInstance;	// �A�v���P�[�V�����C���X�^���X�n���h��hInstance.
	BITMAP bitmap = { 0 };	// BITMAP�\���̕ϐ�bitmap.

	// ���ƍ����������o�ɃZ�b�g.
	m_iPictureWidth = iWidth;	// m_iPictureWidth��iWidth���Z�b�g.
	m_iPictureHeight = iHeight;	// m_iPictureHeight��iHeight���Z�b�g.

	// �C���X�^���X�n���h���̎擾.
	hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWLP_HINSTANCE);	// GetWindowLong�ŃC���X�^���X�n���h�����擾.

	// �摜�̃��[�h.(�ЂƂ܂��r�b�g�}�b�v�̂�.)
	m_hBitmap = (HBITMAP)LoadImage(hInstance, lpctszFileName, IMAGE_BITMAP, m_iPictureWidth, m_iPictureHeight, LR_LOADFROMFILE);	// LoadImage�Ńr�b�g�}�b�v�����[�h.
	if (m_hBitmap == NULL) {	// NULL�Ȃ�.

		// ���s.
		return FALSE;	// ���s�Ȃ̂�FALSE��Ԃ�.

	}

	// �摜���畝�ƍ������擾.
	GetObject(m_hBitmap, sizeof(BITMAP), &bitmap);	// GetObject�Ńr�b�g�}�b�v�����擾.
	m_iPictureWidth = bitmap.bmWidth;	// m_iPictureWidth��bitmap.bmWidth���Z�b�g.
	m_iPictureHeight = bitmap.bmHeight;	// m_iPictureHeight��bitmap.bmHeight���Z�b�g.

	// ����.
	return TRUE;	// �����Ȃ̂�TRUE��Ԃ�.

}

// �摜���Z�b�g(�\��)����֐�SetImage.
void CPictureBox::SetImage() {

	// �ϐ��̐錾
	HDC hDC;	// �f�o�C�X�R���e�L�X�g�n���h��HDC�^hDC.

	// �f�o�C�X�R���e�L�X�g�̎擾.
	hDC = GetDC(m_hWnd);	// GetDC�Ńf�o�C�X�R���e�L�X�g���擾.

	// �������f�o�C�X�R���e�L�X�g�̍쐬.
	m_hMemDC = CreateCompatibleDC(hDC);	// CreateCompatibleDC�Ń������f�o�C�X�R���e�L�X�g�쐬.

	// �摜���Z�b�g����.
	SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)m_hBitmap);	// SendMessage��STM_SETIMAGE�𑗐M���邱�Ƃ�m_hBitmap���Z�b�g����.

	// �X�N���[���o�[�̈ʒu(�����o)�̏�����.
	m_iHScrollPos = 0;
	m_iVScrollPos = 0;

	// �f�o�C�X�R���e�L�X�g�̉��.
	ReleaseDC(m_hWnd, hDC);	// ReleaseDC�Ńf�o�C�X�R���e�L�X�g���.

}

// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
void CPictureBox::OnPaint() {

	// �ϐ��̐錾
	HDC hDC;			// �f�o�C�X�R���e�L�X�g�n���h��HDC�^hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT�\���̕ϐ�ps.
	HBITMAP hOld;		// �ȑO�̃r�b�g�}�b�v�n���h��hOld.
	int iDrawWidth;		// ���ۂ̕`�敝.
	int iDrawHeight;	// ���ۂ̕`�捂��.

	// �`��J�n.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaint�ŕ`��J�n.

	// �r�b�g�}�b�v�̑I��.
	hOld = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);	// SelectObject��m_hBitmap��I��.

	// �r�b�g�]���ɂ��`��.
	iDrawWidth = m_iWidth - SCROLLBAR_THICKNESS;	// ���ۂɂ̓R���g���[���� - �X�N���[���o�[�̌���.
	iDrawHeight = m_iHeight - SCROLLBAR_THICKNESS;	// ���ۂɂ̓R���g���[������ - �X�N���[���o�[�̌���.
	BitBlt(hDC, 0, 0, iDrawWidth, iDrawHeight, m_hMemDC, m_iHScrollPos, m_iVScrollPos, SRCCOPY);	// BitBlt��m_hMemDC����hDC�Ƀr�b�g�]�����邱�Ƃŕ`�悳���.

	// �Â��r�b�g�}�b�v���đI�����Ė߂�.
	SelectObject(m_hMemDC, hOld);	// SelectObject��hOld��I��.

	// �X�N���[���o�[�ݒ�.
	// ��
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// �T�C�Y���Z�b�g.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// �t���O���Z�b�g.
	m_ScrollInfo.nPage = iDrawWidth;	// �����Z�b�g.
	m_ScrollInfo.nMin = 0;	// �ŏ��l���Z�b�g.
	m_ScrollInfo.nMax = m_iPictureWidth;	// �ő�l���Z�b�g.
	SetScrollInfo(m_hWnd, SB_HORZ, &m_ScrollInfo, FALSE);	// SetScrollInfo�ŃZ�b�g.
	// �c
	ZeroMemory(&m_ScrollInfo, sizeof(SCROLLINFO));
	m_ScrollInfo.cbSize = sizeof(SCROLLINFO);	// �T�C�Y���Z�b�g.
	m_ScrollInfo.fMask = SIF_PAGE | SIF_RANGE;	// �t���O���Z�b�g.
	m_ScrollInfo.nPage = iDrawHeight;	// �������Z�b�g.
	m_ScrollInfo.nMin = 0;	// �ŏ��l���Z�b�g.
	m_ScrollInfo.nMax = m_iPictureHeight;	// �ő�l���Z�b�g.
	SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, FALSE);	// SetScrollInfo�ŃZ�b�g.

	// �`��I��.
	EndPaint(m_hWnd, &ps);	// EndPaint�ŕ`��I��.

}

// ���������X�N���[���o�[�C�x���g���̃n���h��OnHScroll.
void CPictureBox::OnHScroll(UINT nSBCode, UINT nPos) {

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
	// �����o�ɂ��Z�b�g.
	m_iHScrollPos = m_ScrollInfo.nPos;
	// �����̈���쐬���ĉ�ʂ̍X�V.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRect�Ŗ����̈�쐬.

}

// ���������X�N���[���o�[�C�x���g���̃n���h��OnVScroll.
void CPictureBox::OnVScroll(UINT nSBCode, UINT nPos) {

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
	// �����o�ɂ��Z�b�g.
	m_iVScrollPos = m_ScrollInfo.nPos;
	// �����̈���쐬���ĉ�ʂ̍X�V.
	InvalidateRect(m_hWnd, NULL, TRUE);	// InvalidateRect�Ŗ����̈�쐬.

}