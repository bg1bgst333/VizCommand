// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "CustomControl.h"	// �J�X�^���R���g���[���N���X

// ���X�g�R���g���[���N���XCListControl
class CListControl : public CCustomControl {

	// public�����o
	public:

		// �R���X�g���N�^�E�f�X�g���N�^
		CListControl();	// �R���X�g���N�^CListControl()
		virtual ~CListControl();	// �f�X�g���N�^~CListControl()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
		virtual void Destroy();	// �E�B���h�E�j���֐�Destroy

};