// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <list>	// std::list
// �Ǝ��̃w�b�_
#include "UserControl.h"	// ���[�U�R���g���[���N���X
#include "WindowListItem.h"	// �E�B���h�E���X�g�A�C�e���N���X
#include "resource.h"			// ���\�[�X

// �E�B���h�E���X�g�A�C�e���Y�p�l���N���XCWindowListItemsPanel
class CWindowListItemsPanel : public CUserControl {

	// public�����o
	public:

		// public�����o�ϐ�
		HPEN m_hPen;		// �y��HPEN�^m_hPen.
		HBRUSH m_hBrush;	// �u���VHBRUSH�^m_hBrush.
		std::list<CWindowListItem *> m_lstWindowList;	// �E�B���h�E���X�gm_vecWindowList.
		int m_nId;	// �E�B���h�E���X�g�A�C�e���̃��\�[�XID, int�^m_nId.

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass

		// �R���X�g���N�^�E�f�X�g���N�^
		CWindowListItemsPanel();	// �R���X�g���N�^CWindowListItemsPanel()
		virtual ~CWindowListItemsPanel();	// �f�X�g���N�^~CWindowListItemsPanel()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual void Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual BOOL Insert(LPCTSTR lpctszWindowName, int iIndex, int iHeight, HINSTANCE hInstance);	// �A�C�e���}���֐�Insert
		virtual BOOL Remove(int iIndex);	// �A�C�e���폜�֐�Remove
		virtual CWindowListItem *Get(int iIndex);	// �A�C�e���擾�֐�Get
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ���[�U��`���b�Z�[�W�������������̃n���h��.
		virtual void OnSizeChild(WPARAM wParam, LPARAM lParam);	// �q����e�փE�B���h�E�T�C�Y�ύX�̗v���������������̓Ǝ��n���h��.

};