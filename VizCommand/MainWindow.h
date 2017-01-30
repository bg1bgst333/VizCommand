// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "BasicWindow.h"	// �x�[�V�b�N�E�B���h�E�N���X
#include "EditBox.h"		// �G�f�B�b�g�{�b�N�X�N���X
#include "UserControl.h"	// ���[�U�R���g���[���N���X

// ���C���E�B���h�E�N���XCMainWindow
class CMainWindow : public CBasicWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		CUserControl *m_pUserControl;		// CUserControl *�^���[�U�R���g���[���I�u�W�F�N�g�|�C���^m_pUserControl
		CEditBox *m_pEditBox;				// CEditBox *�^�G�f�B�b�g�{�b�N�X�I�u�W�F�N�g�|�C���^m_pEditBox

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass

		// �R���X�g���N�^�E�f�X�g���N�^
		CMainWindow();			// �R���X�g���N�^CMainWindow()
		virtual ~CMainWindow();	// �f�X�g���N�^~CMainWindow()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.

};