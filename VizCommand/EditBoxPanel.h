// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "UserControl.h"	// ���[�U�R���g���[���N���X
#include "EditBox.h"		// �G�f�B�b�g�{�b�N�X�N���X

// �G�f�B�b�g�{�b�N�X�p�l���N���XCEditBoxPanel
class CEditBoxPanel : public CUserControl {

	// public�����o
	public:

		// public�����o�ϐ�
		CEditBox *m_pEditBox;	// CEditBox *�^�|�C���^m_pEditBox.
		HMENU m_nId;	// HMENU�^���\�[�XID, m_nId.

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass

		// �R���X�g���N�^�E�f�X�g���N�^
		CEditBoxPanel();	// �R���X�g���N�^CEditBoxPanel
		virtual ~CEditBoxPanel();	// �f�X�g���N�^~CEditBoxPanel()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual void Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.

};