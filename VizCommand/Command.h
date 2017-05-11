// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// ����̃w�b�_
#include <string>			// std::string
#include <vector>			// std::vector
#include <sstream>			// std::stringstream
#include <windows.h>		// �W��WindowsAPI
#include <tchar.h>			// TCHAR�^

// �}�N���̒�`
// UNICODE�؂�ւ�
#ifdef UNICODE
#define tstring std::wstring
#define tstringstream std::wstringstream
#else
#define tstring std::string
#define tstringstream std::stringstream
#endif

// �R�}���h�N���XCCommand
class CCommand {

	// private�����o
	private:

		// private�����o�ϐ�
		tstring m_tstrCommandString;	// �R�}���h������tstring�^m_tstrCommandString.
		std::vector<tstring> m_vectstrCommandToken;	// �R�}���h������̃g�[�N�����X�gstd::vector<tstring>�^m_vectstrCommandToken.
		tstring m_tstrCommandName;	// �R�}���h��tstring�^m_tstrCommandName.

	// public�����o
	public:

		// public�����o�֐�
		BOOL Set(tstring tstrCommandString);	// �R�}���h�̃Z�b�gSet.
		void Clear();	// �R�}���h�̃N���AClear.
		const tstring GetCommandName();	// �R�}���h���̎擾GetCommandName.
		const tstring GetParam(int index);	// �p�����[�^�̎擾GetParam.

};