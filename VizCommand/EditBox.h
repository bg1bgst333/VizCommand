// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "CustomControl.h"	// �J�X�^���R���g���[���N���X

// �G�f�B�b�g�{�b�N�X�N���XCEditBox
class CEditBox : public CCustomControl {

	// public�����o
	public:

		// �����o�ϐ�
		TCHAR *m_ptszText;	// �G�f�B�b�g�{�b�N�X�̃e�L�X�g���i�[����o�b�t�@�ւ̃|�C���^TCHAR *�^m_ptszText.
		int m_iLen;	// �G�f�B�b�g�{�b�N�X�̃e�L�X�g�̒���int�^m_iLen.

		// �R���X�g���N�^�E�f�X�g���N�^
		CEditBox();	// �R���X�g���N�^CEditBox()
		virtual ~CEditBox();	// �f�X�g���N�^~CEditBox()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
		virtual void Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual BOOL CreateTextBuffer();	// �G�f�B�b�g�{�b�N�X�̃e�L�X�g���i�[����o�b�t�@�쐬�֐�CreateTextBuffer.
		virtual void DestroyTextBuffer();	// �G�f�B�b�g�{�b�N�X�̃e�L�X�g���i�[����o�b�t�@�j���֐�DestroyTextBuffer.
		virtual int GetWindowTextLength();	// �G�f�B�b�g�{�b�N�X�̃e�L�X�g�̒����擾�֐�GetWindowTextLength.
		virtual int GetWindowText();		// �G�f�B�b�g�{�b�N�X�̃e�L�X�g�̎擾�֐�GetWindowText.(���O�̓����o�b�t�@�ɓǂݍ���.)
		virtual void SetWindowText();		// �G�f�B�b�g�{�b�N�X�̃e�L�X�g�̐ݒ�֐�SetWindowText.(���O�̓����o�b�t�@�Ɋi�[����Ă�����̂��Z�b�g.)

};