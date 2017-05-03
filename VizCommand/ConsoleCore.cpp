// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "ConsoleCore.h"	// �R���\�[���R�A�N���X
#include <shlobj.h>			// �V�F���I�u�W�F�N�g.

// �R���X�g���N�^CConsoleCore()
CConsoleCore::CConsoleCore() : CScalableEditBox() {

	// �����o�̏�����.
	m_tstrFormString = GREATER_THAN;	// �t�H�[���������">"�ɏ�����.
	m_lStartPos = 0;	// ���͊J�n�ʒu��0�ɏ�����.

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

// �o�̓t�H�[����������擾����֐�GetOutputFormString.
tstring CConsoleCore::GetOutputFormString() {

	// �o�̓t�H�[���������"���݂̃p�X"+"�t�H�[��������".
	m_tstrOutputFormString = m_tstrCurrentPath + m_tstrFormString;	// m_tstrOutputFormString��m_tstrCurrentPath��m_tstrFormString��A���������̂��i�[.

	// �o�̓t�H�[���������Ԃ�.
	return m_tstrOutputFormString;	// m_tstrOutputFormString��Ԃ�.

}

// �R���\�[���ɕ�������o�͂���֐�PutConsole.
void CConsoleCore::PutConsole(tstring tstrString) {

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

// ���̓R�}���h������̎擾�֐�GetCommandString.(���O�̓����o�b�t�@�ɓǂݍ���.)
int CConsoleCore::GetCommandString() {

	// �������������������j��.
	DestroyTextBuffer();

	// ������擾.
	GetWindowText();

	return 0;

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CConsoleCore::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �e�N���X��OnCreate���Ă�.
	CScalableEditBox::OnCreate(hwnd, lpCreateStruct);	// CScalableEditBox::OnCreate���Ă�.

	// �z�[���t�H���_�̎擾.
	GetProfilePath(hwnd);	// GetProfilePath�Ŏ擾.

	// ���݂̃p�X���z�[���t�H���_��.
	m_tstrCurrentPath = m_tstrProfilePath;	// m_tstrCurrentPath��m_tstrProfilePath�ɂ���.

	// �o�̓t�H�[�����擾.
	GetOutputFormString();	// GetOutputFormString�Ŏ擾.

	// �o�̓t�H�[�����o��.
	ShowOutputForm();	// ShowOutputForm�ŏo��.

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// �L�[�������ꂽ���̃n���h��OnKeyDown.
int CConsoleCore::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {

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

	// �ʏ�͓��͂�L���ɂ���.
	return 0;	// 0��Ԃ��ƗL���ɂȂ�.

}