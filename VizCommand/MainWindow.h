// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "BasicWindow.h"	// �x�[�V�b�N�E�B���h�E�N���X
#include "CustomControl.h"	// �J�X�^���R���g���[���N���X
#include "UserControl.h"	// ���[�U�R���g���[���N���X

// ���C���E�B���h�E�N���XCMainWindow
class CMainWindow : public CBasicWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		CUserControl *m_pUserControl;		// CUserControl *�^���[�U�R���g���[���I�u�W�F�N�g�|�C���^m_pUserControl
		CCustomControl *m_pCustomControl;	// CCustomControl *�^�J�X�^���R���g���[���I�u�W�F�N�g�|�C���^m_pCustomControl

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