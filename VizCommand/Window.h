// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <map>			// std::map
// �Ǝ��̃w�b�_
#include "resource.h"	// ���\�[�X

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

// �E�B���h�E�N���XCWindow
class CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		// static�����o�ϐ�
		static std::map<HWND, CWindow *> m_mapWindowMap;	// �E�B���h�E�n���h������CWindow�I�u�W�F�N�g�|�C���^�������}�b�vm_mapWindowMap.

		// �����o�ϐ�
		HWND m_hWnd;	// HWND�^�E�B���h�E�n���h��m_hWnd
		int m_x;		// �E�B���h�E�̈ʒux���Wm_x
		int m_y;		// �E�B���h�E�̈ʒuy���Wm_y
		int m_iWidth;	// �E�B���h�E�̕�m_iWidth
		int m_iHeight;	// �E�B���h�E�̍���m_iHeight

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CWindow();	// �R���X�g���N�^CWindow()
		virtual ~CWindow();	// �f�X�g���N�^~CWindow()

		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName);	// �E�B���h�E�N���X�o�^�֐�RegisterClass
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, UINT nID);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�w��)
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, HBRUSH hBrush);	// �E�B���h�E�N���X�o�^�֐�RegisterClass(�w�i�u���V�w��)
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �Ǝ��̃E�B���h�E�v���V�[�W��StaticWindowProc.

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create
		virtual BOOL Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
		virtual void Destroy();	// �E�B���h�E�j���֐�Destroy
		virtual BOOL ShowWindow(int nCmdShow);	// �E�B���h�E�\���֐�ShowWindow
		virtual BOOL MoveWindow(int x, int y, int iWidth, int iHeight);	// �ʒu�ƃT�C�Y��ύX����֐�MoveWindow.
		virtual BOOL MoveWindow(BOOL bResize, int iRelativeHorizontal, int iRelativeVertical);	// ���΍��W���T�C�Yor�ړ��֐�MoveWindow.
		virtual BOOL MoveWindow(int xywh, int value);	// ��΍��W�Ŏw��(xywh�̂ǂꂩ.)�̒l�����ύX����֐�MoveWindow.
		virtual int GetWindowTextLength();	// �E�B���h�E���̒����擾�֐�GetWindowTextLength.
		virtual int GetWindowText(LPTSTR lpszStringBuf, int nMaxCount);	// �E�B���h�E���擾�֐�GetWindowText.
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// StaticWindowProc����e�E�B���h�E�I�u�W�F�N�g���ƂɌĂяo�����T�u�E�B���h�E�v���V�[�W��DynamicWindowProc.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnDestroy();	// �E�B���h�E�j�����̃n���h��OnDestroy.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// �R�}���h�������̃n���h��OnCommand.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
		virtual void OnPaint();	// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
		virtual void OnHScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g���̃n���h��OnHScroll.
		virtual void OnVScroll(UINT nSBCode, UINT nPos);	// ���������X�N���[���o�[�C�x���g���̃n���h��OnVScroll.
		virtual int OnClose();	// �E�B���h�E����鎞�̃n���h��OnClose.
		virtual int OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	// �L�[�������ꂽ���̃n���h��OnKeyDown.
		virtual int OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);		// �����L�[�������ꂽ���̃n���h��OnChar.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ���[�U��`���b�Z�[�W�������������̃n���h��.

};