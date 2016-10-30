// �w�b�_�̃C���N���[�h
#include "Window.h"		// �E�B���h�E�N���X

// static�����o�ϐ��̒�`.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// static�����o�ϐ�CWindow::m_mapWindowMap�͐錾�ƕʂɂ����ɒ�`���Ȃ��Ƃ����Ȃ�.

// �E�B���h�E�N���X�o�^�֐�RegisterClass.
BOOL CWindow::RegisterClass(HINSTANCE hInstance, LPCTSTR lpctszClassName) {

	// �ϐ��̐錾
	WNDCLASS wc;	// �E�B���h�E�N���Xwc

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = lpctszClassName;						// �E�B���h�E�N���X���ɂ�lpctszClassName���w��.
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �Ƃ肠����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = StaticWindowProc;						// �Ǝ��ɒ�`�����E�B���h�E�v���V�[�W��StaticWindowProc.
	wc.hInstance = hInstance;								// WinMain�̈����̃C���X�^���X�n���h��hInstance���w��.
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);				// �A�v���P�[�V��������A�C�R��IDI_APPLICATION.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);			// �V�X�e������̖��J�[�\��IDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔�(WHITE_BRUSH).
	wc.lpszMenuName = NULL;									// �Ƃ肠����NULL.
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
LRESULT CALLBACK CWindow::StaticWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// �|�C���^�̐錾
	CWindow *pWindow = NULL;	// CWindow�I�u�W�F�N�g�|�C���^pWindow.

	// �E�B���h�E���b�Z�[�W����
	switch (uMsg) {	// uMsg���ƂɐU�蕪����.

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// �|�C���^�̏�����
				LPCREATESTRUCT lpCreateStruct = NULL;	// CREATESTRUCT�\���̂ւ̃|�C���^lpCreateStruct��NULL.

				// lParam����lpCreateStruct�����o��.
				lpCreateStruct = (LPCREATESTRUCT)lParam;	// lParam��(LPCREATESTRUCT)�ɃL���X�g.
				if (lpCreateStruct->lpCreateParams != NULL) {	// NULL�łȂ����.
					pWindow = (CWindow *)lpCreateStruct->lpCreateParams;	// lpCreateStruct->lpCreateParams��(CWindow *)�ɃL���X�g��pWindow�ɓ����.
					CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(hwnd, pWindow));	// CWindow::m_mapWindowMap��hwnd��pWindow�̃y�A��o�^.
				}

			}

			// ���菈����.
			break;	// break�Ŕ�����.

		// ����ȊO.
		default:

			// default�u���b�N
			{

				// hwnd�ŃE�B���h�E�I�u�W�F�N�g�|�C���^����������, pWindow�Ɋi�[.
				if (CWindow::m_mapWindowMap.find(hwnd) != CWindow::m_mapWindowMap.end()) {	// find�Ō���������.
					pWindow = CWindow::m_mapWindowMap[hwnd];	// pWindow��hwnd�ň�����CWindow�I�u�W�F�N�g�|�C���^����.
				}

			}

			// ���菈����.
			break;	// break�Ŕ�����.

	}

	// �E�B���h�E�I�u�W�F�N�g�擾�ł��Ȃ��ꍇ.
	if (pWindow == NULL) {	// pWindow��NULL.

		// DefWindowProc�ɔC����.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);

	}
	else {	// pWindow��������.

		// ���̃E�B���h�E��DynamicWindowProc�ɓn��.
		return pWindow->DynamicWindowProc(hwnd, uMsg, wParam, lParam);	// pWindow->DynamicWindowProc�ɓn��.

	}

}

// �E�B���h�E�쐬�֐�Create(CW_USEDEFAULT��)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�̍쐬.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindow�Ŏw�肳�ꂽ�������g���ăE�B���h�E���쐬.
	if (m_hWnd == NULL) {	// m_hWnd��NULL�Ȃ玸�s.

		// ���s�Ȃ�FALSE.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �E�B���h�E�쐬�֐�Create(RECT�w��)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, const RECT & rect, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance){

	// �E�B���h�E�̍쐬.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, hWndParent, hMenu, hInstance, this);	// CreateWindow�Ŏw�肳�ꂽ�������g���ăE�B���h�E���쐬.
	if (m_hWnd == NULL) {	// m_hWnd��NULL�Ȃ玸�s.

		// ���s�Ȃ�FALSE.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �����Ȃ�TRUE.
	return TRUE;	// TRUE��Ԃ�.

}

// �E�B���h�E�쐬�֐�Create(�ȗ���)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, HINSTANCE hInstance){

	// �E�B���h�E�쐬
	return CWindow::Create(lpctszClassName, lpctszWindowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance);	// CWindow::Create(CW_USEDEFAULT��)�ŃE�B���h�E�쐬.

}

// �E�B���h�E�\���֐�ShowWindow.
BOOL CWindow::ShowWindow(int nCmdShow) {

	// �E�B���h�E�̕\��
	return ::ShowWindow(m_hWnd, nCmdShow);	// WindowsAPI��ShowWindow��m_hWnd��\��.

}

// StaticWindowProc����e�E�B���h�E�I�u�W�F�N�g���ƂɌĂяo�����T�u�E�B���h�E�v���V�[�W��DynamicWindowProc.
LRESULT CWindow::DynamicWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// �E�B���h�E���b�Z�[�W����
	switch (uMsg) {

		// �E�B���h�E�̍쐬���J�n���ꂽ��.
		case WM_CREATE:

			// WM_CREATE�u���b�N
			{

				// OnCreate�ɔC����.
				return OnCreate(hwnd, (LPCREATESTRUCT)lParam);	// hwnd��lParam��OnCreate�ɓn���Ă��Ƃ͔C����.

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

		// �E�B���h�E������ꂽ�Ƃ�.
		case WM_CLOSE:

			// WM_CLOSE�u���b�N
			{

				// OnClose�ɔC����.
				if (OnClose() != 0) {	// 0�ȊO�Ȃ�
					return 0;	// 0��Ԃ�.
				}

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// �R�}���h�������ꂽ��.
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

	// ����̏���
	return DefWindowProc(hwnd, uMsg, wParam, lParam);	// DefWindowProc�ɔC����.

}

// �R�}���h�������̃n���h��OnCommand.
BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam) {

	// FALSE��Ԃ�.
	return FALSE;	// FALSE��Ԃ�.

}