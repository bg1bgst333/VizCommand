// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "ScalableEditBox.h"	// �X�J���u���G�f�B�b�g�{�b�N�X�N���X

// �R���\�[���R�A�N���XCConsoleCore
class CConsoleCore : public CScalableEditBox {

	// public�����o
	public:

		// �����o�ϐ�
		TCHAR *m_ptszCommandString;	// ���̓R�}���h��������i�[����o�b�t�@�ւ̃|�C���^TCHAR *�^m_ptszCommandString.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CConsoleCore();	// �R���X�g���N�^CConsoleCore()
		virtual ~CConsoleCore();	// �f�X�g���N�^~CConsoleCore()

		// �����o�֐�
		virtual int GetCommandString();		// ���̓R�}���h������̎擾�֐�GetCommandString.(���O�̓����o�b�t�@�ɓǂݍ���.)
		virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	// �L�[�������ꂽ���̃n���h��OnKeyDown.

};