// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "ConsoleCore.h"	// �R���\�[���R�A�N���X
#include <shlobj.h>			// �V�F���I�u�W�F�N�g.

// �R���X�g���N�^CConsoleCore()
CConsoleCore::CConsoleCore() : CScalableEditBox() {

	// �����o�̏�����.
	m_tstrFormString = GREATER_THAN;	// �t�H�[���������">"�ɏ�����.
	m_lStartPos = 0;	// ���͊J�n�ʒu��0�ɏ�����.
	m_ccmdCommand.Clear();	// �R�}���h�̃N���A.

}

// �f�X�g���N�^~CConsoleCore()
CConsoleCore::~CConsoleCore() {

}

// �z�[���t�H���_(CSIDL_PROFILE)�̃p�X���擾����֐�GetProfilePath.
tstring CConsoleCore::GetProfilePath(HWND hWnd) {

	// �z��̐錾.
	TCHAR tszPath[1024];	// CSIDL_PROFILE�ȃp�X���i�[����tszPath.

	// �z�[���t�H���_�p�X�̎擾.
	SHGetSpecialFolderPath(hWnd, tszPath, CSIDL_PROFILE, FALSE);	// SHGetSpecialFolderPath��CSIDL_PROFILE�ȃp�X���擾.

	// �����o�Ɋi�[.
	m_tstrProfilePath = tszPath;	// m_tstrProfilePath��tszPath���i�[.

	// �z�[���t�H���_�p�X��Ԃ�.
	return m_tstrProfilePath;	// m_tstrProfilePath��Ԃ�.

}
// �}�C�h�L�������g(CSIDL_MYDOCUMENTS)�̃p�X���擾����֐�GetMyDocumentPath.
tstring CConsoleCore::GetMyDocumentPath(HWND hWnd){

	// �z��̐錾.
	TCHAR tszPath[1024];	// CSIDL_MYDOCUMENTS�ȃp�X���i�[����tszPath.

	// �}�C�h�L�������g�p�X�̎擾.
	SHGetSpecialFolderPath(hWnd, tszPath, CSIDL_MYDOCUMENTS, FALSE);	// SHGetSpecialFolderPath��CSIDL_MYDOCUMENTS�ȃp�X���擾.

	// �����o�Ɋi�[.
	m_tstrMyDocumentPath = tszPath;	// m_tstrMyDocumentPath��tszPath���i�[.

	// �}�C�h�L�������g�p�X��Ԃ�.
	return m_tstrMyDocumentPath;	// m_tstrMyDocumentPath��Ԃ�.

}

// �w�肳�ꂽ�p�X�����݂̃p�X�Ƃ��ăZ�b�g����֐�SetCurrentPath.
void CConsoleCore::SetCurrentPath(tstring tstrPath){

	// �w�肳�ꂽ�p�X�����݂̃p�X�Ƃ��ăZ�b�g.
	m_tstrCurrentPath = tstrPath;	// m_tstrCurrentPath��tstrPath�ɂ���.
	SetCurrentDirectory(m_tstrCurrentPath.c_str());	// SetCurrentDirectory�Ō��݂̃p�X�Ƃ���m_tstrCurrentPath.c_str()���Z�b�g.

}

// ���݂̃p�X���擾����֐�GetCurrentPath.
tstring CConsoleCore::GetCurrentPath(){

	// �ϐ��̏�����.
	TCHAR tszPath[1024] = { 0 };	// tszPath(�v�f��1024)��0�ŏ�����.

	// ���݂̃p�X���擾.
	GetCurrentDirectory(1024, tszPath);	// GetCurrentDirectory�Ō��݂̃p�X���擾.
	m_tstrCurrentPath = tszPath;	// tszPath��m_tstrCurrentPath�ɃZ�b�g.

	// �p�X��Ԃ�.
	return m_tstrCurrentPath;	// m_tstrCurrentPath��Ԃ�.

}

// �w�肳�ꂽ�p�X�̃t���p�X��Ԃ��֐�GetFullPath.
tstring CConsoleCore::GetFullPath(tstring tstrPath){
	
	// �ϐ��̏�����
	TCHAR tszPath[1024] = { 0 };	// tszPath(�v�f��1024)��0�ŏ�����.

	// �t���p�X���擾.
	GetFullPathName(tstrPath.c_str(), 1024, tszPath, NULL);	// GetFullPathName�Ńt���p�X���擾.

	// tszPath��Ԃ�.
	return tstring(tszPath);	// tszPath��tstring�ɕϊ����ĕԂ�.

}

// �o�̓t�H�[����������擾����֐�GetOutputFormString.
tstring CConsoleCore::GetOutputFormString() {

	// �o�̓t�H�[���������"���݂̃p�X"+"�t�H�[��������".
	m_tstrOutputFormString = m_tstrCurrentPath + m_tstrFormString;	// m_tstrOutputFormString��m_tstrCurrentPath��m_tstrFormString��A���������̂��i�[.

	// �o�̓t�H�[���������Ԃ�.
	return m_tstrOutputFormString;	// m_tstrOutputFormString��Ԃ�.

}

// �R���\�[���ɕ�������o�͂���֐�PutConsole.
void CConsoleCore::PutConsole(tstring tstrString) {

	// �ϐ��̏�����
	int iCount = 0;	// ���s�̌�iCount��0�ɏ�����.

	// ���s�̐��𐔂���.
	for (int i = 1; i < (int)tstrString.length(); i++) {
		if (tstrString.at(i - 1) == _T('\r') && tstrString.at(i) == _T('\n')) {

			// �ϐ��̐錾
			int iHeight;	// �V��������iHeight.

			// ���s������1�s���傫������.
			iHeight = m_iHeight + m_iLineHeight;	// ���݂̃E�B���h�E�̍�����1�s���̍����𑫂�.
			MoveWindow(3, iHeight);	// MoveWindow�ō�����V����iHeight�ɂ���.
			m_iLineCount++;		// �s���𑝂₷.

			// UM_SIZECHILD�Ŏq�E�B���h�E�̃T�C�Y�ɍ��킹��.
			WPARAM wParam;
			wParam = MAKEWPARAM(m_iWidth, m_iHeight);
			SendMessage(GetParent(m_hWnd), UM_SIZECHILD, wParam, (LPARAM)m_hWnd);

			iCount++;

		}
	}

	// �������ǉ�����.
	SendMessage(m_hWnd, EM_REPLACESEL, 0, (LPARAM)tstrString.c_str());	// EM_REPLACESEL��tstrString��ǉ�����.(�{���͒u������, 0���w�肵���Ƃ��͒ǉ�(�}��)�������ƂɂȂ�.)

	// ���͈ʒu�̍X�V.
	SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&m_lStartPos, NULL);	// EM_GETSEL�őI�����Ă��Ȃ��ꍇ�͊J�n�ʒu���擾�ł���.

}

// �o�̓t�H�[���̏o��.
void CConsoleCore::ShowOutputForm() {

	// �o�̓t�H�[����������o��.
	PutConsole(m_tstrOutputFormString);	// PutConsole��m_tstrOutputFormString���o��.

}

// ���̓R�}���h������̎擾�֐�GetCommandString.
tstring CConsoleCore::GetCommandString() {

	// �ϐ��̐錾
	unsigned int uiCommandStringLen;	// �R�}���h������̒���.
	TCHAR *ptszCommandString;	// �R�}���h������ւ̃|�C���^.

	// �������������������j��.
	DestroyTextBuffer();

	// ������擾.
	GetWindowText();

	// �R�}���h������̐؂�o��.
	uiCommandStringLen = (unsigned int)m_iLen - (unsigned int)m_lStartPos;	// �R�}���h�������, �S�̂̒��� - �J�n�ʒu.
	ptszCommandString = new TCHAR[uiCommandStringLen + 1];	// �R�}���h������o�b�t�@�쐬.
	_tcsncpy_s(ptszCommandString, uiCommandStringLen + 1, &m_ptszText[m_lStartPos], uiCommandStringLen);	// �R�}���h�����񕔕������R�s�[.
	ptszCommandString[uiCommandStringLen];	// NULL�I�[.

	// �����o�ɃZ�b�g.
	m_tstrCommandString = ptszCommandString;	// m_tstrCommandString��ptszCommandString���Z�b�g.

	// ���.
	delete[] ptszCommandString;	// delete[]��ptszCommandString�����.

	// ������������j��.
	DestroyTextBuffer();

	// �R�}���h�������Ԃ�.
	return m_tstrCommandString;	// m_tstrCommandString��Ԃ�.

}

// �R�}���h�ɑ΂��鏈�������s����E�B���h�E�̃E�B���h�E�n���h�����Z�b�g����֐�SetProcWindow.
void CConsoleCore::SetProcWindow(HWND hWnd) {

	// �����o�ɃZ�b�g.
	m_hProcWnd = hWnd;	// m_hProcWnd��hWnd���Z�b�g.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CConsoleCore::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �e�N���X��OnCreate���Ă�.
	CScalableEditBox::OnCreate(hwnd, lpCreateStruct);	// CScalableEditBox::OnCreate���Ă�.

	// �z�[���t�H���_(�}�C�h�L�������g�ɕύX.)�̎擾.
	//GetProfilePath(hwnd);	// GetProfilePath�Ŏ擾.
	GetMyDocumentPath(hwnd);	// GetMyDocumentPath�Ŏ擾.

	// ���݂̃p�X�Ƃ��ă}�C�h�L�������g���Z�b�g.
	SetCurrentPath(m_tstrMyDocumentPath);	// SetCurrentPath��m_tstrMyDocumentPath���Z�b�g.

	// �o�̓t�H�[�����擾.
	GetOutputFormString();	// GetOutputFormString�Ŏ擾.

	// �o�̓t�H�[�����o��.
	ShowOutputForm();	// ShowOutputForm�ŏo��.

	// �t�H�[�J�X���Z�b�g.
	::SetFocus(hwnd);	// SetFocus�Ńt�H�[�J�X���Z�b�g.

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// �L�[�������ꂽ���̃n���h��OnKeyDown.
int CConsoleCore::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {

	// ��L�[�������ꂽ��.
	if (nChar == VK_UP) {	// VK_UP�̎�.
		// ��L�[�͂Ƃ肠���������ɂ���, ��ɖ߂�Ȃ�����.
		return -1;	// -1��Ԃ��Ɠ��̓L�����Z���ɂȂ�.
	}

	// ���L�[�������ꂽ��.
	if (nChar == VK_LEFT) {	// VK_LEFT�̎�.
		m_lCurrentPos = 0;	// m_lCurrentPos��0�ɃZ�b�g.
		SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&m_lCurrentPos, NULL);	// �L�����b�g�̈ʒu���擾.
		if (m_lCurrentPos <= m_lStartPos) {	// �J�n�ʒu����O����������̓L�����Z������.
			return -1;	// -1��Ԃ��Ɠ��̓L�����Z���ɂȂ�.
		}
	}

	// �ʏ�͓��͂�L���ɂ���.
	return 0;	// 0��Ԃ��ƗL���ɂȂ�.

}

// �����L�[�������ꂽ���̃n���h��OnChar.
int CConsoleCore::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {

	// �o�b�N�X�y�[�X�������ꂽ��.
	if (nChar == VK_BACK) {	// VK_BACK�̎�.
		m_lCurrentPos = 0;	// m_lCurrentPos��0�ɃZ�b�g.
		SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&m_lCurrentPos, NULL);	// �L�����b�g�̈ʒu���擾.
		if (m_lCurrentPos <= m_lStartPos) {	// �J�n�ʒu����O����������̓L�����Z������.
			return -1;	// -1��Ԃ��Ɠ��̓L�����Z���ɂȂ�.
		}
	}

	// ���^�[���L�[�������ꂽ��.
	if (nChar == VK_RETURN) {	// VK_RETURN�̎�.
		m_ccmdCommand.Clear();	// m_ccmdCommand.Clear�ŃN���A.
		GetCommandString();	// GetCommandString�ŃR�}���h��������擾.
		m_ccmdCommand.Set(m_tstrCommandString);	// m_ccmdCommand.Set��m_tstrCommandString��m_ccmdCommand�ɃZ�b�g���ăp�[�X���Ă��炤.
		//MessageBox(NULL, m_tstrCommandString.c_str(), _T("VizCommand"), MB_OK);	// ���b�Z�[�W�{�b�N�X�ŃR�}���h������̕\��.
		CScalableEditBox::OnKeyDown(nChar, nRepCnt, nFlags);	// CScalableEditBox::OnKeyDown���ĂԂ��Ƃ�, 1�s���₵�ĉ��s�����.
		//PostMessage(m_hProcWnd, UM_CONSOLECORECOMMAND, (WPARAM)m_tstrCommandString.c_str(), (LPARAM)m_hWnd);	// UM_CONSOLECORECOMMAND�ŃR�}���h��������R�}���h�ɑ΂��鏈�������s����E�B���h�E�ɑ��M.
		PostMessage(m_hProcWnd, UM_CONSOLECORECOMMAND, (WPARAM)&m_ccmdCommand, (LPARAM)m_hWnd);	// UM_CONSOLECORECOMMAND�ŃR�}���h�I�u�W�F�N�g���R�}���h�ɑ΂��鏈�������s����E�B���h�E�ɑ��M.
	}

	// �ʏ�͓��͂�L���ɂ���.
	return 0;	// 0��Ԃ��ƗL���ɂȂ�.

}

// �}�E�X���{�^���������ꂽ���̃n���h��OnLButtonUp.
int CConsoleCore::OnLButtonUp(UINT nFlags, POINT pt) {

	// �L�����b�g��\������.
	ShowCaret(m_hWnd);	// ShowCaret�ŃL�����b�g��\������.

	// ���݈ʒu���J�n�ʒu���O�ɂȂ�悤�Ƀ}�E�X�ŃN���b�N���ꂽ�ꍇ, �L�����b�g�������I�ɊJ�n�ʒu�ɖ߂�.
	m_lCurrentPos = 0;	// m_lCurrentPos��0�ɃZ�b�g.
	SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&m_lCurrentPos, NULL);	// �L�����b�g�̈ʒu���擾.
	if (m_lCurrentPos < m_lStartPos) {	// �J�n�ʒu����O��������L�����b�g�̈ʒu���ăZ�b�g.
		SendMessage(m_hWnd, EM_SETSEL, (WPARAM)m_lStartPos, (LPARAM)m_lStartPos);	// �L�����b�g�ʒu��m_lStartPos�ɍăZ�b�g.
	}

	// ���͂͗L���ɂ���.
	return 0;	// 0��Ԃ��ƗL���ɂȂ�.

}

// �}�E�X���{�^���������ꂽ���̃n���h��OnLButtonDown.
int CConsoleCore::OnLButtonDown(UINT nFlags, POINT pt) {

	// �L�����b�g���\���ɂ���.
	HideCaret(m_hWnd);	// HideCaret�ŃL�����b�g���\���ɂ���.

	// ���͂͗L���ɂ���.
	return 0;	// 0��Ԃ��ƗL���ɂȂ�.

}

// ���[�U��`���b�Z�[�W�������������̃n���h��.
void CConsoleCore::OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// switch-case���ŐU�蕪����.
	switch (uMsg) {

		// ���X�|���X���b�Z�[�W��������.
		case UM_RESPONSEMESSAGE:

			// UM_RESPONSEMESSAGE�u���b�N
			{
		
				// OnResponseMessage�ɔC����.
				OnResponseMessage(wParam, lParam);	// OnResponseMessage�ɔC����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ���X�|���X���I��������.
		case UM_FINISHRESPONSE:

			// UM_FINISHRESPONSE�u���b�N
			{

				// OnFinishResponse�ɔC����.
				OnFinishResponse(wParam, lParam);	// OnFinishResponse�ɔC����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ����ȊO.
		default:

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

	}

	// �e�N���X�̃��[�U���b�Z�[�W����.
	CScalableEditBox::OnUserMessage(uMsg, wParam, lParam);	// CScalableEditBox::OnUserMessage�ɔC����.

}

// ���X�|���X���b�Z�[�W���������̓Ǝ��n���h��.
void CConsoleCore::OnResponseMessage(WPARAM wParam, LPARAM lParam) {

	// �ϐ��̐錾
	tstring tstrMessage;	// ���b�Z�[�W������tstring�^tstrMessage.

	// ���b�Z�[�W���擾.
	tstrMessage = (TCHAR *)wParam;	// wParam��TCHAR *�^�ɃL���X�g����tstrMessage�Ɋi�[.

	// ���b�Z�[�W���o��.
	PutConsole(tstrMessage);	// PutConsole��tstrMessage���o��.

}

// ���X�|���X���I���������̓Ǝ��n���h��.
void CConsoleCore::OnFinishResponse(WPARAM wParam, LPARAM lParam) {

	// �o�̓t�H�[�����o��.
	m_ccmdCommand.Clear();	// �R�}���h���N���A.
	ShowOutputForm();	// ShowOutputForm�ŏo��.

}