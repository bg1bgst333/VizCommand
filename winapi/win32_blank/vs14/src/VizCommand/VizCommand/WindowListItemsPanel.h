// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <vector>	// std::vector
// �Ǝ��̃w�b�_
#include "Window.h"		// �E�B���h�E�N���X
#include "WindowListItem.h"	// �E�B���h�E���X�g�A�C�e���N���X

// ���\�[�XID�̒�`.
#define IDC_WINDOW_LIST_ITEMS_PANEL WM_USER + 200

// �E�B���h�E���X�g�A�C�e���Y�p�l���N���X
class CWindowListItemsPanel : public CWindow {	// CWindow�̔h���N���X

	// public�����o
	public:

		// public�����o�ϐ�
		// �����o�ϐ�
		std::vector<CWindowListItem *> m_vecpWindowList;	// �E�B���h�E���X�gm_vecpWindowList.
		int m_x;	// �ʒum_x.
		int m_y;	// �ʒum_y.
		int m_iWidth;	// ��m_iWidth.
		int m_iHeight;	// ����m_iHeight.

		// public�����o�֐�
		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(���̃E�B���h�E��p�ɃJ�X�^�}�C�Y���ꂽ����.)
		virtual void Destroy();	// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
		virtual BOOL Insert(int index, int height, HINSTANCE hInstance);	// �E�B���h�E���X�g�A�C�e����}�����郁���o�֐�Insert.
		virtual void Delete(int index);	// �E�B���h�E���X�g�A�C�e�����폜���郁���o�֐�Delete.
		virtual CWindowListItem * Get(int index);	// �E�B���h�E���X�g�A�C�e�����擾���郁���o�֐�Get.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.
		virtual void OnMove(int x, int y);	// �E�B���h�E���ړ����ꂽ���̃n���h��OnMove.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
		virtual void OnPaint();	// ��ʕ`��̍X�V��v�����ꂽ��.
		virtual int OnClose();	// �E�B���h�E����鎞�̃n���h��OnClose.

};