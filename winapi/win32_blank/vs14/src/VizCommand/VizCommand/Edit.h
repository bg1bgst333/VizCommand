// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"		// �E�B���h�E�N���X

// �G�f�B�b�g�R���g���[���N���X
class CEdit : CWindow {

	// public�����o
	public:

		// �����o�ϐ�
		int m_x;	// �ʒum_x.
		int m_y;	// �ʒum_y.
		int m_iWidth;	// ��m_iWidth.
		int m_iHeight;	// ����m_iHeight.

		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(���̃E�B���h�E��p�ɃJ�X�^�}�C�Y���ꂽ����.)
		virtual void Destroy();	// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
		virtual void MoveWindow(int x, int y, int iWidth, int iHeight);	// �E�B���h�E�̃T�C�Y��ʒu��ύX���郁���o�֐�MoveWindow.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.
		virtual int OnClose();	// �E�B���h�E����鎞�̃n���h��OnClose.

};