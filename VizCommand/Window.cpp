// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// �E�B���h�E�N���X

// �R���X�g���N�^CWindow()
CWindow::CWindow(){

	// �����o�ϐ��̏�����
	m_hWnd = NULL;	// m_hWnd��NULL�ŏ�����.
	m_x = 0;		// m_x��0�ŏ�����.
	m_y = 0;		// m_y��0�ŏ�����.
	m_iWidth = 0;	// m_iWidth��0�ŏ�����.
	m_iHeight = 0;	// m_iHeight��0�ŏ�����.

}

// �f�X�g���N�^~CWindow()
CWindow::~CWindow() {

	// �����o�ϐ��̏I������
	if (m_hWnd != NULL) {	// m_hWnd��NULL�łȂ����.
		DestroyWindow(m_hWnd);	// m_hWnd��j��.
		m_hWnd = NULL;	// m_hWnd��NULL����.
	}
	m_x = 0;		// m_x��0����.
	m_y = 0;		// m_y��0����.
	m_iWidth = 0;	// m_iWidth��0����.
	m_iHeight = 0;	// m_iHeight��0����.

}

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName){

	// �ϐ��̐錾
	WNDCLASS wc;	// �E�B���h�E�N���Xwc

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = lpctszClassName;						// �E�B���h�E�N���X����lpctszClassName.
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �X�^�C���͂Ƃ肠����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = StaticWindowProc;						// �E�B���h�E�v���V�[�W����StaticWindowProc.
	wc.hInstance = hInstance;								// �C���X�^���X�n���h���͈�����hInstance���Z�b�g.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�v���P�[�V��������A�C�R��IDI_APPLICATION.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);			// �V�X�e������̖��J�[�\��IDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔�(WHITE_BRUSH).
	wc.lpszMenuName = NULL;									// �Ƃ肠���������_�ł�NULL.
	wc.cbClsExtra = 0;										// �Ƃ肠����0�ł���.
	wc.cbWndExtra = 0;										// �Ƃ肠����0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!::RegisterClass(&wc)) {	// RegisterClass��wc���Z�b�g���ēo�^.

		// �G���[����
		return FALSE;	// ���s�Ȃ̂�FALSE��Ԃ�.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// �����Ȃ̂�TRUE��Ԃ�.

}

// �Ǝ��̃E�B���h�E�v���V�[�W��StaticWindowProc��
LRESULT CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �E�B���h�E���b�Z�[�W����
	switch (uMsg) {

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �E�B���h�E�쐬����
				return 0;	// �����Ȃ�0��Ԃ�.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// ���b�Z�[�W���[�v�I��.
				PostQuitMessage(0);	// PostQuitMessage�Ń��b�Z�[�W���[�v�𔲂�������.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ����ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

	}

	// ����̏���
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�ɔC����.

}

// �E�B���h�E�쐬�֐�Create
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�̈ʒu�E�T�C�Y���Z�b�g.
	m_x = x;				// m_x��x����.
	m_y = y;				// m_y��y����.
	m_iWidth = iWidth;		// m_iWidth��iWidth����.
	m_iHeight = iHeight;	// m_iHeight = iHeight����.

	// �E�B���h�E�̍쐬.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, m_x, m_y, m_iWidth, m_iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindow�Ŏw�肳�ꂽ�������g���ăE�B���h�E���쐬.
	if (m_hWnd == NULL) {	// m_hWnd��NULL�Ȃ玸�s.

		// ���s�Ȃ�FALSE.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �E�B���h�E�\���֐�ShowWindow
BOOL CWindow::ShowWindow(int nCmdShow){

	// �E�B���h�E�̕\��
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPI��ShowWindow��m_hWnd��\��.

}