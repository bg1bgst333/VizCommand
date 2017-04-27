// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "UserControl.h"	// ���[�U�R���g���[���N���X
#include "WindowListItemsPanel.h"	// �E�B���h�E���X�g�A�C�e���Y�p�l���N���X
#include "resource.h"			// ���\�[�X

// �E�B���h�E���X�g�R���g���[���N���XCWindowListControl
class CWindowListControl : public CUserControl {

	// public�����o
	public:

		// public�����o�ϐ�
		HPEN m_hPen;		// �y��HPEN�^m_hPen.
		HBRUSH m_hBrush;	// �u���VHBRUSH�^m_hBrush.
		CWindowListItemsPanel *m_pWindowListItemsPanel;	// CWindowListItemsPanel *�^�E�B���h�E���X�g�A�C�e���Y�p�l���I�u�W�F�N�g�|�C���^m_pWindowListItemsPanel
		SCROLLINFO m_ScrollInfo;	// �X�N���[�����m_ScrollInfo.

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass

		// �R���X�g���N�^�E�f�X�g���N�^
		CWindowListControl();	// �R���X�g���N�^CWindowListControl()
		virtual ~CWindowListControl();	// �f�X�g���N�^~CWindowListControl()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual void Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual BOOL Insert(LPCTSTR lpctszWindowName, int iIndex, int iHeight, HINSTANCE hInstance);	// �A�C�e���}���֐�Insert
		virtual BOOL Remove(int iIndex);	// �A�C�e���폜�֐�Remove
		virtual CWindowListItem *Get(int iIndex);	// �A�C�e���擾�֐�Get
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
		virtual void OnHScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g���̃n���h��OnHScroll.
		virtual void OnVScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g���̃n���h��OnVScroll.

};