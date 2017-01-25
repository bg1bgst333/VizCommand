// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Window.h"	// �E�B���h�E�N���X

// static�����o�ϐ��̒�`.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// static�����o�ϐ�CWindow::m_mapWindowMap�͐錾�Ƃ͕ʂɂ����ɒ�`���Ȃ��Ƃ����Ȃ�.

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

// �E�B���h�E�N���X�o�^�֐�RegisterClass(���j���[�w��)
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName, UINT nID) {

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
	wc.lpszMenuName = MAKEINTRESOURCE(nID);					// ���j���[�ɂ�nID��MAKEINTRESOURCE�ŕϊ���������.
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

// �Ǝ��̃E�B���h�E�v���V�[�W��StaticWindowProc�֐�
LRESULT CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �|�C���^�̏�����
	CWindow *pWindow = NULL;	// CWindow�I�u�W�F�N�g�|�C���^pWIndow��NULL�ɏ�����.

	// �E�B���h�E���b�Z�[�W����
	switch (uMsg) {

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �|�C���^�̏�����
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCT�\���̂ւ̃|�C���^lpCreateStruct��NULL.
				// lParam����lpCreateStruct�����o��.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParam��LPCREATESTRUCT�^�ɃL���X�g����lpCreateStruct�Ɋi�[.
				if (lpCreateStruct != NULL) {	// lpCreateStruct��NULL�łȂ����.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParams��CWindow *�^�ɃL���X�g��, pWindow�Ɋi�[.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// CWindow::m_mapWindowMap��hwnd��pWindow�̃y�A��o�^.
				}

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ����ȊO�̎�.
		default:

			// default�u���b�N
			{

				// hwnd��CWindow�I�u�W�F�N�g�|�C���^����������, pWindow�Ɋi�[.
				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()){	// find�ŃL�[��hwnd�Ƃ���CWindow�I�u�W�F�N�g�|�C���^������������.
					pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindow��hwnd�ň�����CWindow�I�u�W�F�N�g�|�C���^���i�[.
				}

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

	}

	// CWindow�I�u�W�F�N�g�|�C���^���擾�ł��Ȃ������ꍇ, �擾�ł����ꍇ�ŕ�����.
	if (pWindow == NULL) {	// pWindow��NULL

		// DefWindowProc�ɔC����.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�ɂ��̂܂܈�����n����, ���̒l��߂�l�Ƃ���.

	}
	else {	// pWindow��NULL�łȂ�.

		// ����CWindow�I�u�W�F�N�g��DynamicWindowProc�ɓn��.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProc�ɂ��̂܂܈�����n����, ���̒l��߂�l�Ƃ���.

	}

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

// �E�B���h�E�쐬�֐�Create(lpctszClassName�ȗ�)
BOOL CWindow::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �����ɗ���ꍇ�̓E�B���h�E�N���X"Window"�̃E�B���h�E�Ƃ��č쐬.
	return Create(_T("Window"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// �E�B���h�E�N���X��"Window"�ɂ���Create�̃t���o�[�W�������Ă�.
	
}

// �E�B���h�E�\���֐�ShowWindow
BOOL CWindow::ShowWindow(int nCmdShow){

	// �E�B���h�E�̕\��
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPI��ShowWindow��m_hWnd��\��.

}

// StaticWindowProc����e�E�B���h�E�I�u�W�F�N�g���ƂɌĂяo�����T�u�E�B���h�E�v���V�[�W��DynamicWindowProc.
LRESULT CWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	// �E�B���h�E���b�Z�[�W����
	switch (uMsg) {

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// OnCreate�ɔC����.
				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);	// hwnd��lParam��OnCreate�ɓn��, ���Ƃ͔C����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// OnDestroy�ɔC����.
				OnDestroy();	// OnDestroy���Ă�.
				
			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// �R�}���h���������ꂽ��.
		case WM_COMMAND:

			// WM_COMMAND�u���b�N
			{

				// OnCommand�ɔC����.
				return OnCommand(wParam, lParam) ? 0 : 1;	// wParam��lParam��n���ĔC����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ����ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

	}

	// DefWindowProc�ɔC����.
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�ɂ��̂܂܈�����n����, ���̒l��߂�l�Ƃ���.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CWindow::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct){

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �E�B���h�E�j�����̃n���h��OnDestroy.
void CWindow::OnDestroy(){

	// ���b�Z�[�W���[�v�I��.
	PostQuitMessage(0);	// PostQuitMessage�Ń��b�Z�[�W���[�v�𔲂�������.

}

// �R�}���h�������̃n���h��OnCommand.
BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam){

	// �Ƃ肠����TRUE��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}
