// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "Window.h"	// �E�B���h�E�N���X

// ���[�U�R���g���[���N���XCUserControl
class CUserControl : public CWindow {

	// public�����o
	public:

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�E�B���h�E�N���X���w��)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, HBRUSH hBrush);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�u���V�w��)

		// �R���X�g���N�^�E�f�X�g���N�^
		CUserControl();	// �R���X�g���N�^CUserControl()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.

};
