// �w�b�_�̃C���N���[�h
#include "ChildMap.h"	// �`���C���h�}�b�v�N���X

// �ǉ�
void CChildMap::Add(const std::wstring &wstrTag, CChildMapItem *pChild){

	m_mappChildMap.insert(std::make_pair(wstrTag, pChild));

}

// �폜
void CChildMap::Remove(const std::wstring & wszTag){

	m_mappChildMap.erase(wszTag);

}

// �擾
CChildMapItem * CChildMap::Get(const std::wstring & wszTag){
	
	return m_mappChildMap[wszTag];

}
