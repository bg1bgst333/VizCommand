// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �Ǝ��̃w�b�_
#include "EditBox.h"	// �G�f�B�b�g�{�b�N�X�N���X

// �X�J���u���G�f�B�b�g�{�b�N�X�N���XCWindowListControl
class CScalableEditBox : public CEditBox {

	// public�����o
	public:

		// public�����o�ϐ�
		int m_iLineHeight;	// 1�s�̍���.
		int m_iLineCount;	// �s��.

		// public�����o�֐�
		// �R���X�g���N�^�E�f�X�g���N�^
		CScalableEditBox();	// �R���X�g���N�^CScalableEditBox()
		virtual ~CScalableEditBox();	// �f�X�g���N�^~CScalableEditBox()

		// �����o�֐�
		virtual int OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);	// �E�B���h�E�쐬���̃n���h��OnCreate.
		virtual int OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	// �L�[�������ꂽ���̃n���h��OnKeyDown.
		virtual void OnSize(UINT nType, int cx, int cy);	// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.

};