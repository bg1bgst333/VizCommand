// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "UserControl.h"	// ���[�U�R���g���[���N���X
#include "ScalableEditBoxPanel.h"	// �X�J���u���G�f�B�b�g�{�b�N�X�p�l���N���X
#include "ConsoleCore.h"	// �R���\�[���R�A�N���X

// �R���\�[���N���XCConsole
class CConsole : public CScalableEditBoxPanel {

	// public�����o
	public:

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass

		// �R���X�g���N�^�E�f�X�g���N�^
		CConsole();	// �R���X�g���N�^CCConsole()
		virtual ~CConsole();	// �f�X�g���N�^~CCConsole()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ���[�U��`���b�Z�[�W�������������̃n���h��.
		virtual int OnConsoleCoreCommand(WPARAM wParam, LPARAM lParam);	// CConsoleCore���瑗��ꂽ���b�Z�[�W����������Ǝ��n���h��.
		virtual void OnHello(HWND hSrc);		// "Hello, world!"���o�͂���Ǝ��n���h��.
		virtual void OnErrorCommandNotFound(HWND hSrc);	// �R�}���h��������Ȃ����̃G���[�p�Ǝ��n���h��.

};