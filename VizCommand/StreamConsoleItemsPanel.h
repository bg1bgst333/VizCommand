// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~.

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WindowListItemsPanel.h"	// �E�B���h�E���X�g�A�C�e���Y�p�l���N���X

// �X�g���[���R���\�[���A�C�e���Y�p�l��CStreamConsoleItemsPanel
class CStreamConsoleItemsPanel : public CWindowListItemsPanel {

	// public�����o
	public:

		// �����o�֐�
		virtual void OnSizeChild(WPARAM wParam, LPARAM lParam);	// �q����e�փE�B���h�E�T�C�Y�ύX�̗v���������������̓Ǝ��n���h��.
};
