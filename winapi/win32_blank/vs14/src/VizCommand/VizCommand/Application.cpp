// �w�b�_�̃C���N���[�h
#include "Application.h"	// �A�v���P�[�V�����N���X

// ���b�Z�[�W���[�v�֐�Run
int CApplication::Run() {

	// �ϐ��̐錾
	MSG msg;	// ���b�Z�[�W���msg

	// ���b�Z�[�W�擾
	while (GetMessage(&msg, NULL, 0, 0) > 0) {	// GetMessage�Ń��b�Z�[�W�擾.

		// �E�B���h�E���b�Z�[�W�̑��o
		DispatchMessage(&msg);	// DispatchMessage�ŃE�B���h�E�v���V�[�W���ɑ��o.
		TranslateMessage(&msg);	// TranslateMessage�ŉ��z�L�[���b�Z�[�W�𕶎��֕ϊ�.

	}

	// �I������
	return ExitInstance();	// ExitInstance�̒l��Ԃ�.

}

// �C���X�^���X�I�������֐�ExitInstance
int CApplication::ExitInstance() {

	// ���C���E�B���h�E�I�u�W�F�N�g������Ή��.
	if (m_pMainWindow != NULL) {	// m_pMainWindow��NULL����Ȃ����.

		// ���.
		delete m_pMainWindow;	// delete��m_pMainWindow�����.
		m_pMainWindow = NULL;	// NULL���Z�b�g.

	}

	// �����Ȃ�0.
	return 0;	// 0��Ԃ�.

}