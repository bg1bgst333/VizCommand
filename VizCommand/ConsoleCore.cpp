// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "ConsoleCore.h"	// �R���\�[���R�A�N���X

// �R���X�g���N�^CConsoleCore()
CConsoleCore::CConsoleCore() : CScalableEditBox() {

}

// �f�X�g���N�^~CConsoleCore()
CConsoleCore::~CConsoleCore() {

}

// ���̓R�}���h������̎擾�֐�GetCommandString.(���O�̓����o�b�t�@�ɓǂݍ���.)
int CConsoleCore::GetCommandString() {

	// �������������������j��.
	DestroyTextBuffer();

	// ������擾.
	GetWindowText();

	return 0;

}

// �L�[�������ꂽ���̃n���h��OnKeyDown.
void CConsoleCore::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {

	// ���^�[�����[�������ꂽ��.
	if (nChar == VK_RETURN) {		// VK_RETURN�̎�.
		GetCommandString();	// �R�}���h������擾.
		MessageBox(NULL, m_ptszText, _T("VizCommand"), MB_OK);
	}

}