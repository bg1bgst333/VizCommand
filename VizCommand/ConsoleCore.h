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
		tstring m_tstrProfilePath;		// �z�[���t�H���_(CSIDL_PROFILE)�̃p�X���i�[����tstring�^m_tstrProfilePath.
		tstring m_tstrCurrentPath;		// ���݂̃p�X���i�[����tstring�^m_tstrCurrentPath.
		tstring m_tstrFormString;		// �t�H�[��������(����)���i�[����tstring�^m_tstrFormString.
		tstring m_tstrOutputFormString;	// ���ۂɏo�͂���t�H�[����������i�[����tstring�^m_tstrOutputFormString.
		tstring m_tstrCommandString;	// �R�}���h��������i�[����tstring�^m_tstrCommandString.
		long m_lStartPos;				// ���͊J�n�ʒu���i�[����long�^m_lStartPos.
		long m_lCurrentPos;				// ���͌��݈ʒu���i�[����long�^m_lCurrentPos.
		HWND m_hProcWnd;				// �R�}���h�ɑ΂��鏈�������s����E�B���h�E�̃E�B���h�E�n���h��HWND�^m_hProcWnd.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CConsoleCore();	// �R���X�g���N�^CConsoleCore()
		virtual ~CConsoleCore();	// �f�X�g���N�^~CConsoleCore()

		// �����o�֐�
		virtual tstring GetProfilePath(HWND hWnd);	// �z�[���t�H���_(CSIDL_PROFILE)�̃p�X���擾����֐�GetProfilePath.
		virtual tstring GetOutputFormString();		// �o�̓t�H�[����������擾����֐�GetOutputFormString.
		virtual void PutConsole(tstring tstrString);	// �R���\�[���ɕ�������o�͂���֐�PutConsole.
		virtual void ShowOutputForm();	// �o�̓t�H�[���̏o��.
		virtual tstring GetCommandString();		// ���̓R�}���h������̎擾�֐�GetCommandString.
		virtual void SetProcWindow(HWND hWnd);	// �R�}���h�ɑ΂��鏈�������s����E�B���h�E�̃E�B���h�E�n���h�����Z�b�g����֐�SetProcWindow.
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual int OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	// �L�[�������ꂽ���̃n���h��OnKeyDown.
		virtual int OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);		// �����L�[�������ꂽ���̃n���h��OnChar.
		virtual int OnLButtonUp(UINT nFlags, POINT pt);	// �}�E�X���{�^���������ꂽ���̃n���h��OnLButtonUp.
		virtual int OnLButtonDown(UINT nFlags, POINT pt);	// �}�E�X���{�^���������ꂽ���̃n���h��OnLButtonDown.
		virtual void OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);	// ���[�U��`���b�Z�[�W�������������̃n���h��.
		virtual void OnResponseMessage(WPARAM wParam, LPARAM lParam);	// ���X�|���X���b�Z�[�W���������̓Ǝ��n���h��.
		virtual void OnFinishResponse(WPARAM wParam, LPARAM lParam);	// ���X�|���X���I���������̓Ǝ��n���h��.

};