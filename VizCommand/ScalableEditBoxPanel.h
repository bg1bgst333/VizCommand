// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "EditBoxPanel.h"		// �G�f�B�b�g�{�b�N�X�p�l���N���X
#include "ScalableEditBox.h"	// �X�J���u���G�f�B�b�g�{�b�N�X�N���X

// �X�J���u���G�f�B�b�g�{�b�N�X�p�l���N���XCScalableEditBoxPanel
class CScalableEditBoxPanel : public CEditBoxPanel {

	// public�����o
	public:

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass
		static BOOL RegisterClass(HINSTANCE hInstance, HBRUSH hBrush);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�u���V�w��)

		// �R���X�g���N�^�E�f�X�g���N�^
		CScalableEditBoxPanel();	// �R���X�g���N�^CScalableEditBoxPanel()
		virtual ~CScalableEditBoxPanel();	// �f�X�g���N�^~CScalableEditBoxPanel()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ���[�U��`���b�Z�[�W�������������̃n���h��.
		virtual void OnSizeChild(WPARAM wParam, LPARAM lParam);	// �q����e�փE�B���h�E�T�C�Y�ύX�̗v���������������̓Ǝ��n���h��.

};