// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "UserControl.h"	// ���[�U�R���g���[���N���X
#include "WindowListControl.h"	// �E�B���h�E���X�g�R���g���[���N���X

// �X�g���[���R���\�[���N���XCStreamConsole
class CStreamConsole : public CWindowListControl {

	// public�����o
	public:

		// public�����o�ϐ�
		UINT m_nId;	// ���\�[�XID

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance);	// �E�B���h�E�N���X�o�^�֐�RegisterClass

		// �R���X�g���N�^�E�f�X�g���N�^
		CStreamConsole();	// �R���X�g���N�^CStreamConsole
		virtual ~CStreamConsole();	// �f�X�g���N�^~CStreamConsole()

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ���[�U��`���b�Z�[�W�������������̃n���h��.
		virtual void OnRequestScrollBottom(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ���ւ̃X�N���[���v��.
		virtual int OnStreamCommand(WPARAM wParam, LPARAM lParam);	// CConsole����StreamConsole�����R�}���h������ꂽ���̓Ǝ��n���h��.
		virtual int OnList(WPARAM wParam, LPARAM lParam);	// "list"�R�}���h�̓Ǝ��n���h��.
		virtual int OnView(WPARAM wParam, LPARAM lParam);	// "view"�R�}���h�̓Ǝ��n���h��.

};