// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "CustomControl.h"	// �J�X�^���R���g���[���N���X

// �G�f�B�b�g�{�b�N�X�N���XCEditBox
class CEditBox : public CCustomControl {

	// public�����o
	public:

		// �R���X�g���N�^�E�f�X�g���N�^
		CEditBox();	// �R���X�g���N�^CEditBox()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)

};
