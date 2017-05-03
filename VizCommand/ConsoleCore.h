// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "ScalableEditBox.h"	// �X�J���u���G�f�B�b�g�{�b�N�X�N���X

// �}�N���̒�`
#define GREATER_THAN _T(">")

// �R���\�[���R�A�N���XCConsoleCore
class CConsoleCore : public CScalableEditBox {

	// public�����o
	public:

		// �����o�ϐ�
		//TCHAR *m_ptszCommandString;	// ���̓R�}���h��������i�[����o�b�t�@�ւ̃|�C���^TCHAR *�^m_ptszCommandString.
		tstring m_tstrProfilePath;		// �z�[���t�H���_(CSIDL_PROFILE)�̃p�X���i�[����tstring�^m_tstrProfilePath.
		tstring m_tstrCurrentPath;		// ���݂̃p�X���i�[����tstring�^m_tstrCurrentPath.
		tstring m_tstrFormString;		// �t�H�[��������(����)���i�[����tstring�^m_tstrFormString.
		tstring m_tstrOutputFormString;	// ���ۂɏo�͂���t�H�[����������i�[����tstring�^m_tstrOutputFormString.
		long m_lStartPos;				// ���͊J�n�ʒu���i�[����long�^m_lStartPos.
		long m_lCurrentPos;				// ���͌��݈ʒu���i�[����long�^m_lCurrentPos.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CConsoleCore();	// �R���X�g���N�^CConsoleCore()
		virtual ~CConsoleCore();	// �f�X�g���N�^~CConsoleCore()

		// �����o�֐�
		virtual tstring GetProfilePath(HWND hWnd);	// �z�[���t�H���_(CSIDL_PROFILE)�̃p�X���擾����֐�GetProfilePath.
		virtual tstring GetOutputFormString();		// �o�̓t�H�[����������擾����֐�GetOutputFormString.
		virtual void PutConsole(tstring tstrString);	// �R���\�[���ɕ�������o�͂���֐�PutConsole.
		virtual void ShowOutputForm();	// �o�̓t�H�[���̏o��.
		virtual int GetCommandString();		// ���̓R�}���h������̎擾�֐�GetCommandString.(���O�̓����o�b�t�@�ɓǂݍ���.)]
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	// �L�[�������ꂽ���̃n���h��OnKeyDown.
		virtual int OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);		// �����L�[�������ꂽ���̃n���h��OnChar.

};