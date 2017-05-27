// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Console.h"	// �R���\�[���N���X
#include "Command.h"	// �R�}���h�N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CConsole::RegisterClass(HINSTANCE hInstance) {

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("Console"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"Console"��o�^.

}

// �R���X�g���N�^�E�f�X�g���N�^
CConsole::CConsole() : CScalableEditBoxPanel() {

}

// �R���X�g���N�^CConsole(tstring tstrDefaultCurrentPath)
CConsole::CConsole(tstring tstrDefaultCurrentPath) : CScalableEditBoxPanel() {

	// �f�t�H���g�J�����g�p�X�̃Z�b�g.
	m_tstrDefaultCurrentPath = tstrDefaultCurrentPath;

}

// �f�X�g���N�^~CCConsole()
CConsole::~CConsole() {

}

// �E�B���h�E�쐬�֐�Create
BOOL CConsole::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	m_nId = hMenu;
	return CUserControl::Create(_T("Console"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, m_nId, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"Console"�ȃE�B���h�E���쐬.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CConsole::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �ϐ��̐錾.
	CConsoleCore *pConsoleCore;	// CConsoleCore *�^�|�C���^pConsoleCore.

	// �q�G�f�B�b�g�{�b�N�X�̐���.
	pConsoleCore = new CConsoleCore();	// CConsoleCore�I�u�W�F�N�g���쐬��, �|�C���^��pConsoleCore�Ɋi�[.
	pConsoleCore->SetCurrentPath(m_tstrDefaultCurrentPath);	// �f�t�H���g�J�����g�p�X�̃Z�b�g.
	m_pEditBox = pConsoleCore;	// m_pEditBox��pConsoleCore���Z�b�g.
	m_pEditBox->Create(_T(""), ES_MULTILINE | ES_WANTRETURN | ES_AUTOHSCROLL /*| ES_AUTOVSCROLL*/, 0, 0, m_iWidth, m_iHeight, hwnd, m_nId + 100, lpCreateStruct->hInstance);	// m_pEditBox->Create�ŃG�f�B�b�g�{�b�N�X�쐬.

	// ConsoleCore�̃R�}���h�ɑ΂��鏈�������̃E�B���h�E�����s����悤�ɂ���.
	pConsoleCore->SetProcWindow(hwnd);	// pConsoleCore->SetProcWindow��hwnd���Z�b�g.

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// ���[�U��`���b�Z�[�W�������������̃n���h��.
void CConsole::OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// switch-case���ŐU�蕪����.
	switch (uMsg) {

		// CConsoleCore���烁�b�Z�[�W������ꂽ��.
		case UM_CONSOLECORECOMMAND:

			// UM_CONSOLECORECOMMAND�u���b�N
			{

				// OnConsoleCoreCommand�ɔC����.
				OnConsoleCoreCommand(wParam, lParam);	// OnConsoleCoreCommand�ɔC����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ����ȊO.
		default:

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

	}

	// �e�N���X�̃��[�U���b�Z�[�W����.
	CScalableEditBoxPanel::OnUserMessage(uMsg, wParam, lParam);	// CScalableEditBoxPanel::OnUserMessage�ɔC����.

}

// CConsoleCore���瑗��ꂽ���b�Z�[�W����������Ǝ��n���h��.
int CConsole::OnConsoleCoreCommand(WPARAM wParam, LPARAM lParam) {

	// �ϐ��̐錾
	//tstring tstrCommand;	// �R�}���h������tstring�^tstrCommand.
	CCommand *pCommand;	// �R�}���h�I�u�W�F�N�g�|�C���^pCommand.
	HWND hSrc;	// ���M���E�B���h�E�n���h��HWND�^hSrc.

	// �R�}���h�ƃ\�[�X���擾.
	//tstrCommand = (TCHAR *)wParam;	// wParam��TCHAR *�^�ɃL���X�g����tstrCommand�Ɋi�[.
	pCommand = (CCommand *)wParam;		// wParam��CCommand *�^�ɃL���X�g����pCommand�Ɋi�[.
	hSrc = (HWND)lParam;	// lParam��HWND�^�ɃL���X�g����hSrc�Ɋi�[.

#if 0
	// �R�}���h�ƈ����̃p�[�X.
	LPTSTR next;
	tstring command;
	TCHAR *ptszCommand = new TCHAR[tstrCommand.length() + 1];
	_tcscpy_s(ptszCommand, tstrCommand.length() + 1, tstrCommand.c_str());
	TCHAR *p = _tcstok_s(ptszCommand, _T(" ."), &next);
	command = p;
	delete[] ptszCommand;
#endif

	// �R�}���h�̔���.
	tstring tstrCommandName = pCommand->GetCommandName();	// pCommand->GetCommandName�ŃR�}���h�����擾��, tstrCommandName�Ɋi�[.
	if (tstrCommandName == _T("hello")) {	// �R�}���h"hello".

		// OnHello�ɔC����.
		OnHello(hSrc);	// hSrc�������Ƃ��ēn����, OnHello���Ă�.

	}
	else if (tstrCommandName == _T("list")) {	// �R�}���h"list"

		// StreamConsole�ɓ�����.
		SendMessage(m_hProcWnd, UM_STREAMCOMMAND, (WPARAM)pCommand, (LPARAM)m_hWnd);	// UM_STREAMCOMMAND�ŃR�}���h��������R�}���h�ɑ΂��鏈�������s����E�B���h�E�ɑ��M.

	}
	else if (tstrCommandName == _T("walk")) {	// �R�}���h"walk"

		// OnWalk�ɔC����.
		OnWalk(hSrc, pCommand);	// OnWalk��pCommand��n��.

	}
	else if (tstrCommandName == _T("view")) {	// �R�}���h"view"

		// StreamConsole�ɓ�����.
		SendMessage(m_hProcWnd, UM_STREAMCOMMAND, (WPARAM)pCommand, (LPARAM)m_hWnd);	// UM_STREAMCOMMAND�ŃR�}���h��������R�}���h�ɑ΂��鏈�������s����E�B���h�E�ɑ��M.

	}
	else {	// �R�}���h��������Ȃ�.

		// �R�}���h��������Ȃ��G���[.
		OnErrorCommandNotFound(hSrc);	// hSrc�������Ƃ��ēn����, OnErrorCommandNotFound���Ă�.

	}

	// �����Ȃ�0��Ԃ�.
	return 0;	// 0��Ԃ�.

}

// "Hello, world!"���o�͂���Ǝ��n���h��.
void CConsole::OnHello(HWND hSrc) {

	// "Hello, world!"���o��.
	SendMessage(hSrc, UM_RESPONSEMESSAGE, (WPARAM)_T("Hello, world!\r\n"), 0);	// UM_RESPONSEMESSAGE��"Hello, world!"�𑗂�.

	// ���X�|���X�I��.
	SendMessage(hSrc, UM_FINISHRESPONSE, 0, 0);	// UM_FINISHRESPONSE�𑗂�.

}

// �t�H���_�ړ�����Ǝ��n���h��.
void CConsole::OnWalk(HWND hSrc, CCommand *pCommand){

	// �p�X�̎擾.
	tstring tstrPath = pCommand->GetParam(1);	// 1�Ԗڂ��p�X�Ȃ̂�, pCommand->GetParam(1)��1�Ԗڂ̃p�X���擾.
	CConsoleCore *pConsoleCore = (CConsoleCore *)m_pEditBox;	// pConsoleCore�����o��.
	if (tstrPath == _T("")) {	// �󕶎���̏ꍇ.
		tstrPath = pConsoleCore->GetMyDocumentPath(hSrc);	// pConsoleCore->GetMyDocumentPath�Ń}�C�h�L�������g�p�X���擾��, �����tstrPath�Ɋi�[.
	}
	else {
		tstring newPath = pConsoleCore->GetFullPath(tstrPath);	// pConsoleCore->GetFullPath�Ńt���p�X�ɕϊ��������̂�newPath�ɑ��.
		tstrPath = newPath;	// newPath��tstrPath�ɑ��.
	}
	pConsoleCore->SetCurrentPath(tstrPath);	// pConsoleCore->SetCurrentPath��tstrPath���Z�b�g.
	pConsoleCore->GetOutputFormString();	// pConsoleCore->GetOutputFormString�Ńt�H�[���̍Đ���.

	// ���X�|���X�I��.
	SendMessage(hSrc, UM_FINISHRESPONSE, 0, 0);	// UM_FINISHRESPONSE�𑗂�.

}

// �R�}���h��������Ȃ����̃G���[�p�Ǝ��n���h��.
void CConsole::OnErrorCommandNotFound(HWND hSrc) {

	// "Error: Command not found!"���o��.
	SendMessage(hSrc, UM_RESPONSEMESSAGE, (WPARAM)_T("Error: Command not found!\r\n"), 0);	// UM_RESPONSEMESSAGE��"Error: Command not found!"�𑗂�.

	// ���X�|���X�I��.
	SendMessage(hSrc, UM_FINISHRESPONSE, 0, 0);	// UM_FINISHRESPONSE�𑗂�.

}

// �R�}���h�ɑ΂��鏈�������s����E�B���h�E�̃E�B���h�E�n���h�����Z�b�g����֐�SetProcWindow.
void CConsole::SetProcWindow(HWND hWnd) {

	// �����o�ɃZ�b�g.
	m_hProcWnd = hWnd;	// m_hProcWnd��hWnd���Z�b�g.

}