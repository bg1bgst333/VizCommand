// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"		// �E�B���h�E�N���X
// ���\�[�XID�̒�`.
#define IDC_WINDOW_LISTVIEW WM_USER + 100

// �E�B���h�E���X�g�r���[�N���X
class CWindowListView : public CWindow {	// CWindow�̔h���N���X

	// public�����o
	public:

		// public�����o�֐�
		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(���̃E�B���h�E��p�ɃJ�X�^�}�C�Y���ꂽ����.)
		virtual void Destroy();	// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.
		virtual int OnClose();	// �E�B���h�E����鎞�̃n���h��OnClose.

};