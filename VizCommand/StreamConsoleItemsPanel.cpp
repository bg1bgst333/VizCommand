// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "StreamConsoleItemsPanel.h"	// �X�g���[���R���\�[���A�C�e���Y�p�l���N���X

// �q����e�փE�B���h�E�T�C�Y�ύX�̗v���������������̓Ǝ��n���h��.
void CStreamConsoleItemsPanel::OnSizeChild(WPARAM wParam, LPARAM lParam){

	// �e�E�B���h�E�̏��������K�v�ȕϐ�������̂ŌĂяo���ł͂Ȃ������ɃR�s�[.
	// �ϐ��̐錾�E������.
	int iWidth;
	int iHeight;
	HWND hWnd;
	BOOL bFound = FALSE;

	// ����̃A�C�e���̃��T�C�Y.
	iWidth = LOWORD(wParam);
	iHeight = HIWORD(wParam);
	hWnd = (HWND)lParam;
	int iTotalHeight = 0;;
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// �C�e���[�^.
	int y = (*itor)->m_y;
	while (itor != m_lstWindowList.end()) {
		(*itor)->MoveWindow(1, y + iTotalHeight);
		iTotalHeight = iTotalHeight + (*itor)->m_iHeight;
		iTotalHeight = iTotalHeight + (PADDING * 2);
		itor++;
	}

	// �E�B���h�E�T�C�Y�̕ύX.
	HWND hParent = GetParent(hWnd);	// hParent�����̃E�B���h�E.(OnCreate�̌�Ȃ̂Ń����o�ɓ����ĂȂ�.)
	::MoveWindow(hParent, m_x, m_y, m_iWidth, iTotalHeight, TRUE);	// �q�E�B���h�E�Ɠ�������.

	// ���ւ̃X�N���[���v��
	SendMessage(GetParent(hParent), UM_REQUESTSCROLLBOTTOM, (WPARAM)iTotalHeight, 0);	// UM_REQUESTSCROLLBOTTOM�ŉ��փX�N���[���v��.

}
