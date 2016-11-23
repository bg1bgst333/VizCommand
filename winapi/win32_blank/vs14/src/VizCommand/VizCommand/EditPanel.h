// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"		// �E�B���h�E�N���X
#include "Edit.h"		// �G�f�B�b�g�N���X

// ���\�[�XID�̒�`.
#define IDC_EDIT_PANEL WM_APP + 400

// �G�f�B�b�g�p�l���N���X
class CEditPanel : public CWindow {	// CWindow�̔h���N���X

	// public�����o
	public:

		// �����o�ϐ�
		CEdit *m_pEdit;	// CEdit�I�u�W�F�N�g�|�C���^m_pEdit
		int m_x;	// �ʒum_x.
		int m_y;	// �ʒum_y.
		int m_iWidth;	// ��m_iWidth.
		int m_iHeight;	// ����m_iHeight.
		HMENU m_nID;	// ���\�[�XID m_nID.

		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(���̃E�B���h�E��p�ɃJ�X�^�}�C�Y���ꂽ����.)
		virtual void Destroy();	// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
		virtual int OnClose();	// �E�B���h�E����鎞�̃n���h��OnClose.

};