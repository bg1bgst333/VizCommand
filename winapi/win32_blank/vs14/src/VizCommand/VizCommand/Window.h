// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <map>			// std::map

// �E�B���h�E�N���XCWindow
class CWindow {

	// public�����o
	public:

		// public�����o�ϐ�
		// static�����o�ϐ�
		static std::map<HWND, CWindow *> m_mapWindowMap;	// �E�B���h�E�n���h������E�B���h�E�I�u�W�F�N�g�������}�b�vm_mapWindowMap.

		// �����o�ϐ�
		HWND m_hWnd;	// HWND�^�E�B���h�E�n���h��m_hWnd

		// public�����o�֐�
		// static�����o�֐�
		static BOOL RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName = _T("CWindow"));	// �E�B���h�E�N���X�o�^�֐�RegisterClass
		static LRESULT CALLBACK StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �Ǝ��̃E�B���h�E�v���V�[�W��StaticWindowProc.
		
		// �����o�֐�
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(CW_USEDEFAULT��)
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(RECT�w��)
		virtual BOOL Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, HINSTANCE hInstance);	// �E�B���h�E�쐬�֐�Create(�ȗ���)
		virtual BOOL ShowWindow(int nCmdShow);	// �E�B���h�E�\���֐�ShowWindow
		virtual LRESULT DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// WindowProc����e�E�B���h�E�I�u�W�F�N�g���ƂɌĂяo�����T�u�E�B���h�E�v���V�[�W��DynamicWindowProc
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) = 0;	// �E�B���h�E�쐬���̃n���h��OnCreate.(�������z�֐�)
		virtual void OnDestroy() = 0;	// �E�B���h�E�j�����̃n���h��OnDestroy.(�������z�֐�)

};