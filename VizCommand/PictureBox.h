// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "CustomControl.h"	// �J�X�^���R���g���[���N���X

// �}�N����`
#define SCROLLBAR_THICKNESS 16

// �s�N�`���[�{�b�N�X�N���XCPictureBox
class CPictureBox : public CCustomControl {

	// public�����o
	public:

		// �����o�ϐ�
		HBITMAP m_hBitmap;			// ���[�h����r�b�g�}�b�v�̃n���h��HBITMAP�^m_hBitmap.
		HDC m_hMemDC;				// �������f�o�C�X�R���e�L�X�gHDC�^m_hMemDC.
		SCROLLINFO m_ScrollInfo;	// �X�N���[�����m_ScrollInfo.
		int m_iPictureWidth;	// �摜�̕�int�^m_iPictureWidth.
		int m_iPictureHeight;	// �摜�̍���int�^m_iPictureHeight.
		//int m_iHScrollRange;	// �X�N���[���o�[�̐��������̃����Wint�^m_iHScrollRange.
		//int m_iVScrollRange;	// �X�N���[���o�[�̐��������̃����Wint�^m_iVScrollRange.
		int m_iHScrollPos;		// �X�N���[���o�[�̐��������̈ʒuint�^m_iHScrollPos.
		int m_iVScrollPos;		// �X�N���[���o�[�̐��������̈ʒuint�^m_iVScrollPos.

		// �R���X�g���N�^�E�f�X�g���N�^
		CPictureBox();	// �R���X�g���N�^CPictureBox()
		virtual ~CPictureBox();	// �f�X�g���N�^~CPictureBox()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
		virtual BOOL Load(LPCTSTR lpctszFileName, int iWidth, int iHeight);	// �摜�����[�h����֐�Load.
		virtual void SetImage();	// �摜���Z�b�g(�\��)����֐�SetImage.
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
		virtual void OnHScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g���̃n���h��OnHScroll.
		virtual void OnVScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g���̃n���h��OnVScroll.

};