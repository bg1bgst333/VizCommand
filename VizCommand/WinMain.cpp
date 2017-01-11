// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);	// �Ǝ��̃E�B���h�E�v���V�[�W��WindowProc.

// _tWinMain�֐�
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd) {

	// �ϐ��̐錾
	HWND hWnd;		// HWND�^�E�B���h�E�n���h��hWnd
	MSG msg;		// MSG�^�E�B���h�E���b�Z�[�W�\����msg
	WNDCLASS wc;	// WNDCLASS�^�E�B���h�E�N���X�\����wc

	// �E�B���h�E�N���X�̐ݒ�
	wc.lpszClassName = _T("VizCommand_MainWindow");			// �Ǝ��ɒ�`�����E�B���h�E�N���X"VizCommand_MainWindow".
	wc.style = CS_HREDRAW | CS_VREDRAW;						// �Ƃ肠����CS_HREDRAW | CS_VREDRAW.
	wc.lpfnWndProc = WindowProc;							// �Ǝ��ɒ�`�����E�B���h�E�v���V�[�W��WindowProc.
	wc.hInstance = hInstance;								// WinMain�̈����̃C���X�^���X�n���h��hInstance���w��.
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);		// �A�v���P�[�V��������A�C�R��IDI_APPLICATION.
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);			// �V�X�e������̖��J�[�\��IDC_ARROW.
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// �w�i�͔�(WHITE_BRUSH).
	wc.lpszMenuName = NULL;									// �Ƃ肠����NULL.
	wc.cbClsExtra = 0;										// �Ƃ肠����0�ł���.
	wc.cbWndExtra = 0;										// �Ƃ肠����0�ł���.

	// �E�B���h�E�N���X�̓o�^
	if (!RegisterClass(&wc)) {	// RegisterClass��wc���Z�b�g���ēo�^.

		// �G���[����
		MessageBox(NULL, _T("�E�B���h�E�N���X�̓o�^�Ɏ��s���܂���."), _T("VizCommand"), MB_OK | MB_ICONHAND);	// MessageBox��"�E�B���h�E�N���X�̓o�^�Ɏ��s���܂���!"�ƕ\��.
		return -1;	// �ُ�I��(-1)��Ԃ�.

	}

	// �E�B���h�E�N���X�̍쐬
	hWnd = CreateWindow(wc.lpszClassName, _T("VizCommand"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);	// CreateWindow��"VizCommand_MainWindow"�E�B���h�E�N���X�̃E�B���h�E"VizCommand"���쐬.
	if (hWnd == NULL) {

		// �G���[����
		MessageBox(NULL, _T("�E�B���h�E�̍쐬�Ɏ��s���܂���!"), _T("VizCommand"), MB_OK | MB_ICONHAND);	// MessageBox��"�E�B���h�E�̍쐬�Ɏ��s���܂���!"�ƕ\��.
		return -2;	// �ُ�I��(-2)��Ԃ�.

	}

	// �E�B���h�E�̕\��
	ShowWindow(hWnd, SW_SHOW);	// ShowWindow��hWnd��\��.

	// ���b�Z�[�W���[�v
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�Ń��b�Z�[�W�擾.

		// �E�B���h�E���b�Z�[�W�̑��o
		DispatchMessage(&msg);	// DispatchMessage�ŃE�B���h�E�v���V�[�W���ɑ��o.
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎��֕ϊ�.

	}

	// �v���O�����̏I��
	return (int)msg.wParam;	// �I���R�[�h�Ƃ���msg.wParam��Ԃ�.

}

// �E�B���h�E�v���V�[�W��WindowProc�֐�
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

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