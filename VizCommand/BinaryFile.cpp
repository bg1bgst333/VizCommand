// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BinaryFile.h"	// �o�C�i���t�@�C���N���X

// "�J��"�̃t�@�C���_�C�A���O��\����, �I�����ꂽ�t�@�C�������擾���郁���o�֐�GetOpenFileName.(�X�^�e�B�b�N�����o�֐�.)
BOOL CBinaryFile::GetOpenFileName(LPTSTR lptszFileName, int nMax, LPCTSTR lpctszFilter, HWND hWnd, LPTSTR lptszExtension) {

	// �ϐ��̏�����
	OPENFILENAME ofn = { 0 };							// OPENFILENAME�\���̕ϐ�ofn��0�ŏ�����.
	TCHAR tszFilter[1024] = { 0 };						// tszFilter��0�ŏ�����.

	// ofn�̐ݒ�
	ofn.lStructSize = sizeof(OPENFILENAME);				// OPENFILENAME�\���̂̃T�C�Y���Z�b�g.
	ofn.hwndOwner = hWnd;								// �w�肳�ꂽhWnd���Z�b�g.
	int len = _tcslen(lpctszFilter);					// lpctszFilter�̒������擾.
	_tcscpy_s(tszFilter, 1024, lpctszFilter);			// lpctszFilter��tszFilter�ɃR�s�[.
	for (int i = len - 1; i >= 0; i--) {				// ��납��'|'��'\0'�ɒu��������.
		if (tszFilter[i] == FITLER_DELIMITER_CHAR) {	// '|'�������ꍇ.
			tszFilter[i] = _T('\0');					// tszFilter[i]��'|'����.
		}
	}
	ofn.lpstrFilter = tszFilter;						// tszFilter���Z�b�g.
	ofn.lpstrFile = lptszFileName;						// �w�肳�ꂽlpctszFileName���Z�b�g.
	ofn.nMaxFile = nMax;								// �w�肳�ꂽnMax���Z�b�g.
	ofn.Flags = OFN_FILEMUSTEXIST;						// �t�@�C�������݂��Ȃ��ƌ���ł��Ȃ�.

	// "�J��"�t�@�C���_�C�A���O�̕\��.
	if (!::GetOpenFileName(&ofn)) {						// GetOpenFileName��"�J��"�t�@�C���_�C�A���O��\��.

		// �I�����Ȃ������ꍇ.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �g���q���擾.
	_tcscpy_s(lptszExtension, 16, PathFindExtension(lptszFileName));	// PathFindExtension�Ŏ擾�����g���q��lptszExtension�ɃR�s�[.

	// �I�������ꍇ.
	return TRUE;		// TRUE��Ԃ�.

}

// �R���X�g���N�^CBinaryFile()
CBinaryFile::CBinaryFile() {

	// �����o�ϐ��̏�����
	m_hFile = NULL;	// m_hFile��NULL�ŏ�����.
	m_pByte = NULL;	// m_pByte��NULL�ŏ�����.
	ZeroMemory(m_tszFileName, sizeof(TCHAR) * 1024);	// ZeroMemory��m_tszFileName��0�Ŗ��߂�.
	m_hFind = INVALID_HANDLE_VALUE;	// INVALID_HANDLE_VALUE�ŏ�����.

}

// �f�X�g���N�^~CBinaryFile()
CBinaryFile::~CBinaryFile() {

	// �����o�ϐ��̏I������
	FindClose();	// FindClose�ŕ���.
	ZeroMemory(m_tszFileName, sizeof(TCHAR) * 1024);	// ZeroMemory��m_tszFileName��0�Ŗ��߂�.
	if (m_pByte != NULL) {	// NULL�łȂ����.
		delete[] m_pByte;	// delete��m_pByte�����.
		m_pByte = NULL;		// m_pByte��NULL���Z�b�g.
	}
	if (m_hFile != NULL) {	// NULL�łȂ����.
		Close();			// ����.
		m_hFile = NULL;		// m_hFile��NULL���Z�b�g.
	}

}

// �t�@�C���̍쐬����уt�@�C�����J��������s�������o�֐�Open.
BOOL CBinaryFile::Open(LPCTSTR lpctszFileName, DWORD dwDesiredAccess, DWORD dwCreationDisposition) {

	// �t�@�C�����������o�ɃZ�b�g.
	_tcscpy_s(m_tszFileName, 1024, lpctszFileName);	// _tcscpy_s�ň����������o�ɃR�s�[.(��2������WORD�P�ʂł̃T�C�Y.)

	// �t�@�C�����J��.
	m_hFile = CreateFile(m_tszFileName, dwDesiredAccess, 0, NULL, dwCreationDisposition, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile�Ńt�@�C��m_tszFileName���J��.
	if (m_hFile == INVALID_HANDLE_VALUE) {	// ���s.
		return FALSE;	// FALSE��Ԃ�.
	}

	// ����
	return TRUE;	// TRUE��Ԃ�.

}

// �t�@�C������郁���o�֐�Close.
void CBinaryFile::Close() {

	// �t�@�C�������.
	CloseHandle(m_hFile);	// CloseHandle��m_hFile�����.
	m_hFile = NULL;	// NULL���Z�b�g.

}

// �t�@�C�����������ރ����o�֐�Write.(pBytes�͊O���Ńo�b�t�@�������Ă���ꍇ�̏������ݑΏۃo�C�g��.)
BOOL CBinaryFile::Write(BYTE * pBytes, UINT nCount) {

	// �ϐ��̏�����
	DWORD dwBytes = 0;	// DWORD�^dwBytes��0�ŏ�����.

	// pBytes����������.
	return WriteFile(m_hFile, pBytes, nCount, &dwBytes, NULL);	// WriteFile��pBytes�̓��e����������.

}

// "���O��t���ĕۑ�"�̃t�@�C���_�C�A���O��\����, �I�����ꂽ�t�@�C�������擾���郁���o�֐�GetSaveFileName.
BOOL CBinaryFile::GetSaveFileName(LPTSTR lptszFileName, int nMax, LPCTSTR lpctszFilter, HWND hWnd) {

	// �ϐ��̏�����
	OPENFILENAME ofn = { 0 };							// OPENFILENAME�\���̕ϐ�ofn��0�ŏ�����.
	TCHAR tszFilter[1024] = { 0 };						// tszFilter��0�ŏ�����.

	// ofn�̐ݒ�
	ofn.lStructSize = sizeof(OPENFILENAME);				// OPENFILENAME�\���̂̃T�C�Y���Z�b�g.
	ofn.hwndOwner = hWnd;								// �w�肳�ꂽhWnd���Z�b�g.
	int len = _tcslen(lpctszFilter);					// lpctszFilter�̒������擾.
	_tcscpy_s(tszFilter, 1024, lpctszFilter);			// lpctszFilter��tszFilter�ɃR�s�[.
	for (int i = len - 1; i >= 0; i--) {				// ��납��'|'��'\0'�ɒu��������.
		if (tszFilter[i] == FITLER_DELIMITER_CHAR) {	// '|'�������ꍇ.
			tszFilter[i] = _T('\0');					// tszFilter[i]��'|'����.
		}
	}
	ofn.lpstrFilter = tszFilter;						// tszFilter���Z�b�g.
	ofn.lpstrFile = lptszFileName;						// �w�肳�ꂽlpctszFileName���Z�b�g.
	ofn.nMaxFile = nMax;								// �w�肳�ꂽnMax���Z�b�g.
	ofn.Flags = OFN_OVERWRITEPROMPT;					// �㏑�����̃��b�Z�[�W�{�b�N�X�\��.

	// "���O��t���ĕۑ�"�t�@�C���_�C�A���O�̕\��.
	if (!::GetSaveFileName(&ofn)) {						// GetSaveFileName��"���O��t���ĕۑ�"�t�@�C���_�C�A���O��\��.

		// �I�����Ȃ������ꍇ.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �I�������ꍇ.
	return TRUE;		// TRUE��Ԃ�.

}

// �t�@�C����ǂݍ��ރ����o�֐�Read.(pBytes�͊O���Ńo�b�t�@�������Ă���ꍇ�̃o�b�t�@�ւ̃|�C���^.)
BOOL CBinaryFile::Read(BYTE * pBytes, UINT nCount) {

	// �ϐ��̏�����
	DWORD dwBytes = 0;	// DWORD�^dwBytes��0�ŏ�����.

	// pBytes��ǂݍ���.
	return ReadFile(m_hFile, pBytes, nCount, &dwBytes, NULL);	// ReadFile��pBytes�ɓ��e��ǂݍ���.

}

// "�J��"�̃t�@�C���_�C�A���O��\����, �I�����ꂽ�t�@�C�������擾���郁���o�֐�GetOpenFileName.
BOOL CBinaryFile::GetOpenFileName(LPTSTR lptszFileName, int nMax, LPCTSTR lpctszFilter, HWND hWnd) {

	// �ϐ��̏�����
	OPENFILENAME ofn = { 0 };							// OPENFILENAME�\���̕ϐ�ofn��0�ŏ�����.
	TCHAR tszFilter[1024] = { 0 };						// tszFilter��0�ŏ�����.

	// ofn�̐ݒ�
	ofn.lStructSize = sizeof(OPENFILENAME);				// OPENFILENAME�\���̂̃T�C�Y���Z�b�g.
	ofn.hwndOwner = hWnd;								// �w�肳�ꂽhWnd���Z�b�g.
	int len = _tcslen(lpctszFilter);					// lpctszFilter�̒������擾.
	_tcscpy_s(tszFilter, 1024, lpctszFilter);			// lpctszFilter��tszFilter�ɃR�s�[.
	for (int i = len - 1; i >= 0; i--) {				// ��납��'|'��'\0'�ɒu��������.
		if (tszFilter[i] == FITLER_DELIMITER_CHAR) {	// '|'�������ꍇ.
			tszFilter[i] = _T('\0');					// tszFilter[i]��'|'����.
		}
	}
	ofn.lpstrFilter = tszFilter;						// tszFilter���Z�b�g.
	ofn.lpstrFile = lptszFileName;						// �w�肳�ꂽlpctszFileName���Z�b�g.
	ofn.nMaxFile = nMax;								// �w�肳�ꂽnMax���Z�b�g.
	ofn.Flags = OFN_FILEMUSTEXIST;						// �t�@�C�������݂��Ȃ��ƌ���ł��Ȃ�.

	// "�J��"�t�@�C���_�C�A���O�̕\��.
	if (!::GetOpenFileName(&ofn)) {						// GetOpenFileName��"�J��"�t�@�C���_�C�A���O��\��.

		// �I�����Ȃ������ꍇ.
		return FALSE;	// FALSE��Ԃ�.

	}

	// �I�������ꍇ.
	return TRUE;		// TRUE��Ԃ�.

}

// �t�@�C���T�C�Y�̎擾�֐�GetFileSize.
DWORD CBinaryFile::GetFileSize(LPDWORD lpHigh) {

	// �t�@�C���T�C�Y�̎擾.
	return ::GetFileSize(m_hFile, lpHigh);	// WindowsAPI��GetFileSize�ŃT�C�Y���擾��, �����Ԃ�.

}

// �ŏ��̃t�@�C�������֐�FindFirstFile.
HANDLE CBinaryFile::FindFirstFile(LPCTSTR lpctszFileName) {

	// �ŏ��̃t�@�C��������.
	m_hFind = ::FindFirstFile(lpctszFileName, &m_wfdFindData);	// WindowsAPI��FindFirstFile��lpctszFileName�̏����ɍ����ŏ��̃n���h�����擾.
	return m_hFind;	// �����n���h����Ԃ�.

}

// ���̃t�@�C�������֐�FindNextFile.
BOOL CBinaryFile::FindNextFile() {

	// ���̃t�@�C��������.
	return ::FindNextFile(m_hFind, &m_wfdFindData);	// WindowsAPI��FindNextFile�Ŏ��̃t�@�C�������擾.

}

// �����n���h�������֐�FindClose.
BOOL CBinaryFile::FindClose() {

	// �ϐ��̏�����.
	BOOL bRet = FALSE;

	// �n���h�������.
	if (m_hFind != INVALID_HANDLE_VALUE) {
		bRet = ::FindClose(m_hFind);
		m_hFind = INVALID_HANDLE_VALUE;	// INVALID_HANDLE_VALUE�ŏ�����.
	}

	// bRet��Ԃ�.
	return bRet;

}