// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "UserControl.h"	// ���[�U�R���g���[���N���X
#include "ListControl.h"	// ���X�g�R���g���[���N���X
// ����̃w�b�_
#include <commctrl.h>	// �R�����R���g���[��

// ���X�g�R���g���[���p�l���N���XCListControlPanel
class CListControlPanel : public CUserControl {

	// public�����o
	public:

		// public�����o�ϐ�
		CListControl *m_pListControl;	// CListControl *�^�|�C���^m_pListControl.
		HMENU m_nId;	// HMENU�^���\�[�XID, m_nId.

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass

		// �R���X�g���N�^�E�f�X�g���N�^
		CListControlPanel();	// �R���X�g���N�^CListControlPanel
		virtual ~CListControlPanel();	// �f�X�g���N�^~CListControlPanel()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual void Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.

};