// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <map>			// std::map

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
		static std::map<HWND, CWindow *> m_mapWindowMap;	// �E�B���h�E�n���h������E�B���h�E�I�u�W�F�N�g�������}�b�vm_mapWindowMap.
		static std::map<tstring, WNDPROC> m_mapBaseWndProcMap;	// ����̃E�B���h�E�N���X���������̃E�B���h�E�v���V�[�W���������}�b�vm_mapBaseWndProcMap.

		// �����o�ϐ�
		HWND m_hWnd;	// HWND�^�E�B���h�E�n���h��m_hWnd

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName = _T("CWindow"));	// �E�B���h�E�N���X�o�^�֐�RegisterClass
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �Ǝ��̃E�B���h�E�v���V�[�W��StaticWindowProc.

		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(CW_USEDEFAULT��)
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, BOOL bProcChange);	// �E�B���h�E�쐬�֐�Create(�����̃E�B���h�E�N���X�̃E�B���h�E�v���V�[�W���������ւ���ꍇ.)
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(RECT�w��)
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(�ȗ���)
		virtual BOOL ShowWindow(int nCmdShow);	// �E�B���h�E�\���֐�ShowWindow
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// WindowProc����e�E�B���h�E�I�u�W�F�N�g���ƂɌĂяo�����T�u�E�B���h�E�v���V�[�W��DynamicWindowProc
		virtual void Destroy() = 0;	// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.(�������z�֐�)
		virtual void SetWindowText(LPCTSTR lpctszString);	// �E�B���h�E�Ƀe�L�X�g���Z�b�g���郁���o�֐�SetWindowText.
		virtual void MoveWindow(int x, int y, int iWidth, int iHeight);	// �E�B���h�E�̃T�C�Y��ʒu��ύX���郁���o�֐�MoveWindow.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) = 0;	// �E�B���h�E�쐬���̃n���h��OnCreate.(�������z�֐�)
		virtual void OnDestroy() = 0;	// �E�B���h�E�j�����̃n���h��OnDestroy.(�������z�֐�)
		virtual void OnMove(int x, int y);	// �E�B���h�E���ړ����ꂽ���̃n���h��OnMove.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
		virtual void OnPaint();	// ��ʕ`��̍X�V��v�����ꂽ��.
		virtual int OnClose() = 0;		// �E�B���h�E����鎞�̃n���h��OnClose.(�������z�֐�)
		virtual int OnKeyDown(WPARAM wParam, LPARAM lParam);	// �L�[�������ꂽ��.
		virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);	// �R�}���h�������̃n���h��OnCommand.
		virtual void OnVScroll(UINT nSBCode, UINT nPos, HWND hScroll);	// �����X�N���[�����̃n���h��OnVScroll.

};