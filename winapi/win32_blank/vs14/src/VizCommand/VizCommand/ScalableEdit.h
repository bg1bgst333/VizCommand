// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Edit.h"	// �G�f�B�b�g�N���X

// �X�P�[���u���G�f�B�b�g�R���g���[���N���X
class CScalableEdit : public CEdit {

	// public�����o
	public:

		// �����o�ϐ�
		int m_iLineHeight;	// �s�̍���.
		int m_iExternalLeading;	// �s��.
		int m_iLineCount;	//�s��.

		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(���̃E�B���h�E��p�ɃJ�X�^�}�C�Y���ꂽ����.)
		virtual int OnKeyDown(WPARAM wParam, LPARAM lParam);	// �L�[�������ꂽ��.
		virtual void OnSizeChild(HWND hWnd, int width, int height, HWND hChildWnd);	// �q�E�B���h�E�̃T�C�Y���ύX���ꂽ��(�Ǝ����b�Z�[�W)

};