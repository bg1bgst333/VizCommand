// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "ScalableEdit.h"	// �X�P�[���u���G�f�B�b�g�N���X
#include "EditPanel.h"	// �G�f�B�b�g�p�l���N���X

// �X�P�[���u���G�f�B�b�g�p�l���N���X
class CScalableEditPanel : public CEditPanel {

	// public�����o
	public:

		// �����o�ϐ�
		int m_iLineHeight;	// �s�̍���.

		// �����o�֐�
		virtual BOOL Create(int x, int y, int iWidth, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(���̃E�B���h�E��p�ɃJ�X�^�}�C�Y���ꂽ����.)
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
		virtual void OnPaint();	// ��ʕ`��̍X�V��v�����ꂽ��.
		virtual int OnKeyDown(WPARAM wParam, LPARAM lParam);	// �L�[�������ꂽ��.
		virtual void OnSizeChild(HWND hWnd, int width, int height, HWND hChildWnd);	// �q�E�B���h�E�̃T�C�Y���ύX���ꂽ��(�Ǝ����b�Z�[�W)

};
