// �Ǝ��̃w�b�_
#include "Command.h"	// �R�}���h�N���X

// �R�}���h�̃Z�b�gSet.
BOOL CCommand::Set(tstring tstrCommandString){

	// �ϐ��̐錾
	tstringstream tstrsrStream;	// ������X�g���[��
	tstring token;	// �g�[�N��

	// ������X�g���[�����󂯎��.
	tstrsrStream << tstrCommandString;

	// tstrsrStream��EOF�ɂȂ�܂�token��push.
	while (!tstrsrStream.eof()) {
		tstring tmp;
		tstrsrStream >> tmp;
		if (tmp.size() > 0) {	// �Ō�̕������󔒗ނ̘A���̏ꍇ, EOF�ɂȂ�Ȃ��̂ł������Ă���.
			token = tmp;
			m_vectstrCommandToken.push_back(token);
		}
	}

	// 0�Ԗڂ����C���̃R�}���h���ɂ���.
	if (m_vectstrCommandToken.size() > 0) {
		m_tstrCommandName = m_vectstrCommandToken[0];
	}

	// TRUE��Ԃ�.
	return TRUE;	// TRUE

}

void CCommand::Clear(){

	// �N���A
	m_tstrCommandString.clear();
	m_vectstrCommandToken.clear();
	m_tstrCommandName.clear();

}

// �R�}���h���̎擾GetCommandName.
const tstring & CCommand::GetCommandName(){

	// �R�}���h����Ԃ�.
	return m_tstrCommandName;

}