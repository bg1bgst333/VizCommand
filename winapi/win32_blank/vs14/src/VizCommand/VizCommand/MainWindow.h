// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"		// �E�B���h�E�N���X
#include "WindowListView.h"	// �E�B���h�E���X�g�r���[�N���X
#include "ChildMap.h"	// �`���C���h�}�b�v�N���X

// ���C���E�B���h�E�N���X
class CMainWindow : public CWindow {	// CWindow�̔h���N���X

	// public�����o
	public:

		// public�����o�ϐ�
		CWindowListView *m_pWindowListView;	// CWindowListView�I�u�W�F�N�g�|�C���^m_pWindowListView.
		CChildMap *m_pChildMap;	// CChildMap�I�u�W�F�N�g�|�C���^m_pChildMap.

		// public�����o�֐�
		// �����o�֐�
		virtual void Destroy();	// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
		virtual void AddEdit(int index, int x, int y, int w, int h, HINSTANCE hInstance);	// �w���index�̃E�B���h�E���X�g�A�C�e���ɃG�f�B�b�g�{�b�N�X��ǉ����郁���o�֐�AddEdit.
		virtual void DeleteEdit(int index);	// �w��̃E�B���h�E���X�g�A�C�e���̃G�f�B�b�g�{�b�N�X���폜���郁���o�֐�DeleteEdit.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
		virtual int OnClose();	// �E�B���h�E����鎞�̃n���h��OnClose.

};