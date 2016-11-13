// ��d�C���N���[�h�h�~
#pragma once	// #pragma once�œ�d�C���N���[�h�h�~

// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <map>	// std::map
// �Ǝ��̃w�b�_
#include "Window.h"		// �E�B���h�E�N���X
#include "ChildMapItem.h"	// �`���C���h�}�b�v�A�C�e���N���X

// �`���C���h�}�b�v�N���X
class CChildMap {

	// public�����o
	public:

		// public�����o�ϐ�
		// �����o�ϐ�
		std::map<std::wstring, CChildMapItem *> m_mappChildMap;	// �`���C���h�}�b�vm_mappChildMap.

		// public�����o�֐�
		// �����o�֐�
		void Add(const std::wstring &wstrTag, CChildMapItem *pChild);	// �ǉ�
		void Remove(const std::wstring &wstrTag);	// �폜.
		CChildMapItem *Get(const std::wstring &wstrTag);	// �擾.

};

