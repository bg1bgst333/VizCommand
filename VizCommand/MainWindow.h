// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "BasicWindow.h"		// �x�[�V�b�N�E�B���h�E�N���X
#include "WindowListControl.h"	// �E�B���h�E���X�g�R���g���[���N���X
#include "EditBoxPanel.h"		// �G�f�B�b�g�{�b�N�X�p�l���N���X
#include "ScalableEditBox.h"	// �X�J���u���G�f�B�b�g�{�b�N�X�N���X
#include "resource.h"			// ���\�[�X

// ���C���E�B���h�E�N���XCMainWindow
class CMainWindow : public CBasicWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		CWindowListControl *m_pWindowListControl;	// CWindowListControl *�^�E�B���h�E���X�g�R���g���[���I�u�W�F�N�g�|�C���^m_pWindowListControl
		CScalableEditBox *m_pScalableEditBox;	// CScalableEditBox *�^�X�J���u���G�f�B�b�g�{�b�N�X�I�u�W�F�N�g�|�C���^m_pScalableEditBox

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass.
		static BOOL RegisterClass(HINSTANCE hInstance, HBRUSH hBrush);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�u���V�w��)

		// �R���X�g���N�^�E�f�X�g���N�^
		CMainWindow();			// �R���X�g���N�^CMainWindow()
		virtual ~CMainWindow();	// �f�X�g���N�^~CMainWindow()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
		virtual void Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.

};