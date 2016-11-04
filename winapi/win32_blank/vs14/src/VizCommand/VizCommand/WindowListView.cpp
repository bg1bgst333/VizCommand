// �w�b�_�̃C���N���[�h
#include "WindowListView.h"	// �E�B���h�E���X�g�r���[�N���X

// �E�B���h�E�쐬�֐�Create.
BOOL CWindowListView::Create(int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// �N���X��"WindowListView"�̎q�E�B���h�E���쐬.
	return CWindow::Create(_T("WindowListView"), _T(""), WS_CHILD | WS_VISIBLE | WS_VSCROLL, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CWindow::Create�ŃN���X��"WindowListView"�̎q�E�B���h�E���쐬.

}

// OnClose��OnDestroy�̊ԂɎq�E�B���h�E�Ȃǂ�j�����郁���o�֐�Destroy.
void CWindowListView::Destroy() {

	// �A�C�e�������ׂč폜.
	int c = m_vecpWindowList.size();
	for (int i = 0; i < c; i++) {
		Delete(0);	// Delete�ō폜.
	}

	// �j��.
	DestroyWindow(m_hWnd);	// DestroyWindow��m_hWnd��j��.
	m_hWnd = NULL;	// m_hWnd��NULL�ɂ���.

}

// �E�B���h�E���X�g�A�C�e����}�����郁���o�֐�Insert.
BOOL CWindowListView::Insert(int index, int height, HINSTANCE hInstance){

	// �A�C�e���̐���.
	CWindowListItem *pItem = new CWindowListItem();	// CWindowListItem�I�u�W�F�N�gpItem�𐶐�.
	// �}���ʒu���T�C�Y���傫���ꍇ�͈�ԍŌ�ɒǉ�.
	if ( index > (int)m_vecpWindowList.size()) {
		int position = 0;
		int idx = m_vecpWindowList.size();	// idx��m_vecpWindowList.size()�ɏ�����.
		if (idx == 0) {
			position = 0;
		}
		else {
			position = m_vecpWindowList[idx - 1]->m_y + m_vecpWindowList[idx - 1]->m_iHeight;
		}
		pItem->Create(0, position, 200, height, m_hWnd, (HMENU)(IDC_WINDOW_LISTITEM + idx), hInstance);	// �E�B���h�E����.
		TCHAR tszText[256];
		_stprintf_s(tszText, _T("%d"), idx);
		pItem->SetWindowText(tszText);
		m_vecpWindowList.push_back(pItem);	// �ǉ�
	}
	else {
		int idx;	// idx��p��.
		int position = 0;
		if (index < 0) {	// index���}�C�i�X.
			idx = 0;	// idx��0�ɃZ�b�g.
		}
		else {
			idx = index;	// idx��index�ɃZ�b�g.
		}
		if (idx == 0) {
			position = 0;
		}
		else {
			position = m_vecpWindowList[idx - 1]->m_y + m_vecpWindowList[idx - 1]->m_iHeight;
		}
		pItem->Create(0, position, 200, height, m_hWnd, (HMENU)(IDC_WINDOW_LISTITEM + m_vecpWindowList.size()), hInstance);	// �E�B���h�E����.
		TCHAR tszText[256];
		_stprintf_s(tszText, _T("%d"), idx);
		pItem->SetWindowText(tszText);
		m_vecpWindowList.insert(m_vecpWindowList.begin() + idx, pItem);	// �ǉ�
		// ����height�������.
		for (int i = idx + 1; i <= (int)m_vecpWindowList.size() - 1; i++) {
			m_vecpWindowList[i]->MoveWindow(m_vecpWindowList[i]->m_x, m_vecpWindowList[i]->m_y + height, m_vecpWindowList[i]->m_iWidth, m_vecpWindowList[i]->m_iHeight);
		}
	}
	
	// TRUE��Ԃ�.
	return TRUE;	// TRUE��Ԃ�.

}

// �E�B���h�E���X�g�A�C�e�����폜���郁���o�֐�Delete.
void CWindowListView::Delete(int index){

	// �T�C�Y��0�Ȃ牽�����Ȃ�.
	if (m_vecpWindowList.size() == 0) {
		return;
	}
	else {
		// �T�C�Y�ȏ�Ȃ疖���̍폜.
		if (index >= (int)m_vecpWindowList.size()) {
			CWindowListItem *pItem = m_vecpWindowList.at(m_vecpWindowList.size() - 1);	// m_vecpWindowList.at�Ŏ�o��.
			pItem->Destroy();	// pItem->Destroy�ŃE�B���h�E�̔j��.
			delete pItem;	// delete��pItem�����.
			m_vecpWindowList.erase(m_vecpWindowList.begin() + m_vecpWindowList.size() - 1);	// m_vecpWindowList.size() - 1�Ԗڂ�erase�ō폜.
			return;
		}
		if (index < -1) {	// �}�C�i�X�Ȃ�0�̎�o��.
			CWindowListItem *pItem = m_vecpWindowList.at(0);	// 0���폜..
			pItem->Destroy();	// pItem->Destroy�ŃE�B���h�E�̔j��.
			delete pItem;	// delete��pItem�����.
			m_vecpWindowList.erase(m_vecpWindowList.begin() + 0);	// 0�Ԗڂ�erase�ō폜.
			return;
		}
		// index�Ԗڂ̍폜.
		CWindowListItem *pItem = m_vecpWindowList.at(index);	// m_vecpWindowList.at�Ŏ�o��.
		pItem->Destroy();	// pItem->Destroy�ŃE�B���h�E�̔j��.
		delete pItem;	// delete��pItem�����.
		m_vecpWindowList.erase(m_vecpWindowList.begin() + index);	// index�Ԗڂ�erase�ō폜.
	}

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CWindowListView::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �E�B���h�E�쐬����
	return 0;	// �����Ȃ�0��Ԃ�.

}

// �E�B���h�E�j�����̃n���h��OnDestroy
void CWindowListView::OnDestroy() {

}

// �E�B���h�E�̃T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CWindowListView::OnSize(UINT nType, int cx, int cy){

	// �S�Ă̎q�E�B���h�E�̉��������킹��.
	for (std::vector<CWindowListItem *>::iterator it = m_vecpWindowList.begin(); it != m_vecpWindowList.end(); it++) {

		// �q�E�B���h�E�̃E�B���h�E���X�g�r���[�̃T�C�Y���ύX.
		(*it)->m_iWidth = cx;	// ������cx�ɍ��킹��.
		// �����͂��̂܂�.
		::MoveWindow((*it)->m_hWnd, 0, (*it)->m_y, (*it)->m_iWidth, (*it)->m_iHeight, TRUE);	// MoveWindow�Ŏq�E�B���h�E�̃T�C�Y�����̃E�B���h�E�̉����ɍ��킹��.

	}

}

// �E�B���h�E����鎞�̃n���h��OnClose.
int CWindowListView::OnClose() {

	// 0��Ԃ�.
	return 0;	// 0��Ԃ��ăE�B���h�E�����.

}