// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "Window.h"			// �E�B���h�E�N���X
#include "UserControl.h"	// ���[�U�R���g���[���N���X

// �x�[�V�b�N�E�B���h�E�N���XCBasicWindow
class CBasicWindow : public CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		CUserControl *m_pUserControl;	// CUserControl *�^���[�U�R���g���[���I�u�W�F�N�g�|�C���^m_pUserControl

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass

		// �R���X�g���N�^�E�f�X�g���N�^
		CBasicWindow();	// �R���X�g���N�^CBasicWindow()
		virtual ~CBasicWindow();	// �f�X�g���N�^~CBasicWindow()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.

};