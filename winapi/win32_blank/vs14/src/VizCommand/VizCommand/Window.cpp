// �w�b�_�̃C���N���[�h
#include "Window.h"		// �E�B���h�E�N���X

// static�����o�ϐ��̒�`.
std::map<HWND, CWindow *> CWindow::m_mapWindowMap;	// static�����o�ϐ�CWindow::m_mapWindowMap�͐錾�ƕʂɂ����ɒ�`���Ȃ��Ƃ����Ȃ�.
std::map<tstring, WNDPROC> CWindow::m_mapBaseWndProcMap;		// static�����o�ϐ�CWindow::m_mapBaseWndProcMap�͐錾�Ƃ͕ʂɂ����ɒ�`���Ȃ��Ƃ����Ȃ�.

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

		// �z��̐錾.
		TCHAR tszClassName[256] = { 0 };	// tszClassName��0�ŏ�����.

		// �E�B���h�E�n���h������E�B���h�E�N���X�����擾.
		GetClassName(hwnd, tszClassName, 256);	// GetClassName�ŃE�B���h�E�N���X�����擾.

		// tszClassName��m_mapBaseWndProcMap�̃L�[�ɂ����.
		if (m_mapBaseWndProcMap.find(tszClassName) != m_mapBaseWndProcMap.end()) {	// �݂�������.

			// ����̂̃v���V�[�W���ɔC����.
			return CallWindowProc(m_mapBaseWndProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProc�ł��̃��b�Z�[�W��m_mapBaseWndProcMap[tszClassName]�ɔC����.

		}
		else {

			// �����łȂ��Ȃ�, DefWindowProc�ɔC����.
			return DefWindowProc(hwnd, uMsg, wParam, lParam);

		}

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

// �E�B���h�E�쐬�֐�Create(�����̃E�B���h�E�N���X�̃E�B���h�E�v���V�[�W���������ւ���ꍇ.)
BOOL CWindow::Create(LPCTSTR lpctszClassName, LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, BOOL bProcChange){
	
	// �E�B���h�E�̍쐬.
	m_hWnd = CreateWindow(lpctszClassName, lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance, this);	// CreateWindow�Ŏw�肳�ꂽ�������g���ăE�B���h�E���쐬.
	if (m_hWnd == NULL) {	// m_hWnd��NULL�Ȃ玸�s.

		// ���s�Ȃ�FALSE.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �v���V�[�W���������ւ���ꍇ.
	if (bProcChange) {	// bProcChange��TRUE�Ȃ�.

		// OnCreate�͈ȍ~�Ă΂�Ȃ��̂ł����ŌĂ�ł���.
		CREATESTRUCT cs;	// CREATESTRUCT���ꉞ�p��.
		cs.hInstance = hInstance;	// hInstance�͗v�邩������Ȃ��̂�, ����͓n����悤�ɂ��Ă���.
		if (OnCreate(m_hWnd, &cs) != 0) {	// OnCreate��cs��n��.

			// �E�B���h�E��j������.
			DestroyWindow(m_hWnd);
			m_hWnd = NULL;
			return FALSE;

		}

		// ����̃E�B���h�E�v���V�[�W�����擾��, StaticWindowProc�ɍ����ւ���.
		WNDPROC lpfnWndProc;	// ����̃v���V�[�W��lpfnWndProc.
		lpfnWndProc = (WNDPROC)GetWindowLong(m_hWnd, GWL_WNDPROC);	// GetWindowLong�Ńv���V�[�W��lpfnWndProc�擾.
		SetWindowLong(m_hWnd, GWL_WNDPROC, (LONG)StaticWindowProc);	// SetWindowLong�Ńv���V�[�W��StaticWindowProc�ݒ�.

		// �}�b�v�ɃE�B���h�E�N���X�����Ȃ���Γo�^.
		if (m_mapBaseWndProcMap.find(lpctszClassName) == m_mapBaseWndProcMap.end()) {
			m_mapBaseWndProcMap.insert(std::pair<tstring, WNDPROC>(lpctszClassName, lpfnWndProc));	// �v���V�[�W����o�^.
		}

		// WM_CREATE��ʂ�Ȃ��̂ŃE�B���h�E�}�b�v�̓o�^���s��.
		if (CWindow::m_mapWindowMap.find(m_hWnd) == CWindow::m_mapWindowMap.end()) {
			CWindow::m_mapWindowMap.insert(std::pair<HWND, CWindow *>(m_hWnd, this));
		}

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
			break;

		// �E�B���h�E���j�����ꂽ��.
		case WM_DESTROY:

			// WM_DESTROY�u���b�N
			{

				// OnDestroy�ɔC����.
				OnDestroy();	// OnDestroy���Ă�.

			}

			// ����̏����֌�����.
			break;

		// �E�B���h�E���ړ����ꂽ��.
		case WM_MOVE:

			// WM_MOVE�u���b�N
			{

				// OnMove�ɔC����.
				OnMove(LOWORD(lParam), HIWORD(lParam));

			}

			// ����̏����֌�����.
			break;

		// �E�B���h�E�̃T�C�Y���ύX���ꂽ��.
		case WM_SIZE:
			
			// WM_SIZE�u���b�N
			{

				// �ϐ��̐錾
				UINT nType;	// �T�C�Y�ύX�̃^�C�v
				int cx;	// �ύX��̕�
				int cy;	// �ύX��̍���

				// �l�̎�o��.
				nType = wParam;	// nType��wParam���Z�b�g.
				cx = LOWORD(lParam);	// cx��lParam�̉��ʃ��[�h���Z�b�g.
				cy = HIWORD(lParam);	// cy��lParam�̏�ʃ��[�h���Z�b�g.

				// OnSize�ɔC����.
				OnSize(nType, cx, cy);	// OnSize���Ă�.

			}

			// ����̏����֌�����.
			break;

		// ��ʕ`��̍X�V��v�����ꂽ��.
		case WM_PAINT:

			// WM_PAINT�u���b�N
			{

				// OnPaint�ɔC����.
				OnPaint();

			}

			// ����̏����֌�����.
			break;

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
			break;

		// �L�[�������ꂽ��.
		case WM_KEYDOWN:

			// WM_KEYDOWN�u���b�N
			{

				// OnKeyDown�ɔC����.	
				return OnKeyDown(wParam, lParam);

			}

			// ����̏����֌�����.
			break;

		// �R�}���h�������ꂽ��.
		case WM_COMMAND:

			// WM_COMMAND�u���b�N
			{

				// OnCommand�ɔC����.
				return OnCommand(wParam, lParam) ? 0 : 1;	// wParam��lParam��n���ĔC����.

			}

			// ����̏����֌�����.
			break;
		
		// �X�N���[�����ꂽ��.
		case WM_VSCROLL:

			// WM_VSCROLL�u���b�N
			{

				// �ϐ��̐錾.
				UINT nSBCode;
				UINT nPos;
				HWND hScroll;

				// ��o��.
				nSBCode = LOWORD(wParam);
				nPos = HIWORD(wParam);
				hScroll = (HWND)lParam;

				// OnVScroll�ɔC����.
				OnVScroll(nSBCode, nPos, hScroll);

			}

			// ����̏����֌�����.
			break;

		// ����ȊO�̎�.
		default:

			// ����̏����֌�����.
			break;

	}

	// �z��̐錾.
	TCHAR tszClassName[256] = { 0 };	// tszClassName��0�ŏ�����.

	// �E�B���h�E�n���h������E�B���h�E�N���X�����擾.
	GetClassName(hwnd, tszClassName, 256);	// GetClassName�ŃE�B���h�E�N���X�����擾.

	// tszClassName��m_mapBaseWndProcMap�̃L�[�ɂ����.
	if (m_mapBaseWndProcMap.find(tszClassName) != m_mapBaseWndProcMap.end()) {	// �݂�������.

		// ����̂̃v���V�[�W���ɔC����.
		return CallWindowProc(m_mapBaseWndProcMap[tszClassName], hwnd, uMsg, wParam, lParam);	// CallWindowProc�ł��̃��b�Z�[�W��m_mapBaseWndProcMap[tszClassName]�ɔC����.

	}
	else {

		// �����łȂ��Ȃ�, DefWindowProc�ɔC����.
		return DefWindowProc(hwnd, uMsg, wParam, lParam);

	}

}

// �E�B���h�E�Ƀe�L�X�g���Z�b�g���郁���o�֐�SetWindowText.
void CWindow::SetWindowText(LPCTSTR lpctszString){

}

// �E�B���h�E�̃T�C�Y��ʒu��ύX���郁���o�֐�MoveWindow.
void CWindow::MoveWindow(int x, int y, int iWidth, int iHeight){

}

// �E�B���h�E���ړ����ꂽ���̃n���h��OnMove.
void CWindow::OnMove(int x, int y){

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CWindow::OnSize(UINT nType, int cx, int cy){

}

// ��ʕ`��̍X�V��v�����ꂽ��.
void CWindow::OnPaint(){

}

// �L�[�������ꂽ��.
int CWindow::OnKeyDown(WPARAM wParam, LPARAM lParam){

	return 0;

}

// �R�}���h�������̃n���h��OnCommand.
BOOL CWindow::OnCommand(WPARAM wParam, LPARAM lParam) {

	// FALSE��Ԃ�.
	return FALSE;	// FALSE��Ԃ�.

}

// �����X�N���[�����̃n���h��OnVScroll.
void CWindow::OnVScroll(UINT nSBCode, UINT nPos, HWND hScroll){

}