// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"		// �E�B���h�E�N���X
#include "WindowListItemsPanel.h"	// �E�B���h�E���X�g�A�C�e���Y�p�l���N���X

// ���\�[�XID�̒�`.
#define IDC_WINDOW_LIST_VIEW WM_APP + 100

// �E�B���h�E���X�g�r���[�N���X
class CWindowListView : public CWindow {	// CWindow�̔h���N���X

	// public�����o
	public:

		// public�����o�ϐ�
		// �����o�ϐ�
		CWindowListItemsPanel *m_pWindowListItemsPanel;	// �A�C�e���Y�p�l��.

		// public�����o�֐�
		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(���̃E�B���h�E��p�ɃJ�X�^�}�C�Y���ꂽ����.)
		virtual void Destroy();	// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
		virtual BOOL Insert(int index, int height, HINSTANCE hInstance);	// �E�B���h�E���X�g�A�C�e����}�����郁���o�֐�Insert.
		virtual void Delete(int index);	// �E�B���h�E���X�g�A�C�e�����폜���郁���o�֐�Delete.
		virtual CWindowListItem * Get(int index);	// �E�B���h�E���X�g�A�C�e�����擾���郁���o�֐�Get.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
		virtual int OnClose();	// �E�B���h�E����鎞�̃n���h��OnClose.
		virtual void OnVScroll(UINT nSBCode, UINT nPos, HWND hScroll);	// �����X�N���[�����̃n���h��OnVScroll.

};