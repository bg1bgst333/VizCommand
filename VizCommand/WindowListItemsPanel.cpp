// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "WindowListItemsPanel.h"	// �E�B���h�E���X�g�A�C�e���Y�p�l���N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CWindowListItemsPanel::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E���X�g�A�C�e����o�^.
	CWindowListItem::RegisterClass(hInstance);	// �q�E�B���h�E��o�^.

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("WindowListItemsPanel"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"WindowListItemsPanel"��o�^.

}

// �R���X�g���N�^CWindowListItemsPanel()
CWindowListItemsPanel::CWindowListItemsPanel() : CUserControl() {

	// �����o�̏�����.
	m_nId = 0;	// m_nId��0�ɏ�����.

}

// �f�X�g���N�^~CWindowListItemsPanel()
CWindowListItemsPanel::~CWindowListItemsPanel() {

	// �����o�̏I������.
	Destroy();	// Destroy�Ŕj��.
	m_nId = 0;	// m_nId��0�ɃZ�b�g.

}

// �E�B���h�E�쐬�֐�Create
BOOL CWindowListItemsPanel::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	return CUserControl::Create(_T("WindowListItemsPanel"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"WindowListItemsPanel"�ȃE�B���h�E���쐬.

}

// �E�B���h�E�j���֐�Destroy
void CWindowListItemsPanel::Destroy() {

	// �A�C�e���̈�č폜.
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// �C�e���[�^.
	while (itor != m_lstWindowList.end()) {
		(*itor)->Destroy();
		delete (*itor);
		(*itor) = NULL;
		itor++;
	}
	m_lstWindowList.clear();

	// �y���ƃu���V�̔j��.
	if (m_hBrush) {
		DeleteObject(m_hBrush);	// �u���V�̔j��.
		m_hBrush = NULL;
	}
	if (m_hPen) {
		DeleteObject(m_hPen);	// �y���̔j��.
		m_hPen = NULL;
	}
	// �����̃E�B���h�E���j��.
	CWindow::Destroy();	// CWindow::Destroy�Ŏ��g�̃E�B���h�E���j��.

}

// �A�C�e���}���֐�Insert
BOOL CWindowListItemsPanel::Insert(LPCTSTR lpctszWindowName, int iIndex, int iHeight, HINSTANCE hInstance) {

	// �ϐ��̐錾.
	int iIdx;	// �l�̃`�F�b�N��̃C���f�b�N�Xint�^iIdx.
	CWindowListItem *pItem;	// �E�B���h�E���X�g�A�C�e���|�C���^pItem.
	int iTotalHeight = 0;	// �p�l���S�̂̍���iTotalHeight��0�ɏ�����.

	// �C���f�b�N�X�̒l�ŐU�蕪��.
	if (iIndex < 0) {	// ���̒l
		iIdx = 0;	// 0���Z�b�g.
	}
	else if (iIndex >(int)m_lstWindowList.size()) {	// �T�C�Y���傫��.
		iIdx = m_lstWindowList.size();	// �T�C�Y���Z�b�g.
	}
	else {
		iIdx = iIndex;	// iIndex���Z�b�g.
	}
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// �C�e���[�^.
	int y = 0;
	for (int i = 0; i < (int)m_lstWindowList.size() + 1; i++) {
		if (i == iIdx) {
			pItem = new CWindowListItem();	// ����.
			pItem->Create(lpctszWindowName, 0, 3, iTotalHeight + 3, m_iWidth - (3 * 2), iHeight - (3 * 2), m_hWnd, (HMENU)(IDC_WINDOWLISTITEM_ID_START + m_nId), hInstance);	// �E�B���h�E����.
			iTotalHeight = iTotalHeight + iHeight;	// �}������E�B���h�E�̍����𑫂�.
			m_lstWindowList.insert(itor, pItem);	// �}��.
			m_nId++;
			itor = m_lstWindowList.begin();
			for (int j = 0; j < iIdx; j++) {
				itor++;
			}
		}
		else if (i < iIdx) {
			y = y + (*itor)->m_iHeight;	// �ʒu�v�Z.
			y = y + (3 * 2);	// �]���̑傫��
			iTotalHeight = y;
		}
		else if (i > iIdx) {
			if (itor != m_lstWindowList.end()) {
				iTotalHeight = iTotalHeight + (*itor)->m_iHeight;
				iTotalHeight = iTotalHeight + (3 * 2);
				(*itor)->MoveWindow(false, 0, iHeight);	// iHeight�����炷.
			}
			else {
				break;
			}
		}
		if (itor != m_lstWindowList.end()) {
			itor++;
		}
		else {
			break;
		}
	}

	//�A�C�e���Y�p�l���̑傫�����g������.
	MoveWindow(3, iTotalHeight);	// ������iTotalHeight�ɂ���.

	// �Ƃ肠���������ɂ��Ă���.
	return TRUE;

}

// �A�C�e���폜Remove
BOOL CWindowListItemsPanel::Remove(int iIndex) {

	// �ϐ��̐錾.
	int iIdx;		// �l�̃`�F�b�N��̃C���f�b�N�Xint�^iIdx.
	int iHeight = 0;	// �폜���ꂽ�A�C�e���̍���iHeight��0�ɏ�����.
	int iTotalHeight = 0;	// �p�l���S�̂̍���iTotalHeight��0�ɏ�����.

	// �C���f�b�N�X�̒l�ŐU�蕪��.
	if (iIndex < 0) {	// ���̒l
		iIdx = 0;	// 0���Z�b�g.
	}
	else if (iIndex >(int)m_lstWindowList.size() - 1) {	// �Ō�����傫��.
		iIdx = m_lstWindowList.size() - 1;	// �Ō�����Z�b�g.
	}
	else {
		iIdx = iIndex;	// iIndex���Z�b�g.
	}
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// �C�e���[�^.
	for (int i = 0; i < (int)m_lstWindowList.size(); i++) {
		if (i == iIdx) {
			iHeight = (*itor)->m_iHeight;	// ������ۑ�.
			(*itor)->Destroy();
			delete (*itor);
			m_lstWindowList.remove((*itor));
			itor = m_lstWindowList.begin();
			for (int j = 0; j < iIdx; j++) {
				itor++;
			}
			if (itor != m_lstWindowList.end()) {
				iTotalHeight = iTotalHeight + (*itor)->m_iHeight;
				(*itor)->MoveWindow(false, 0, -iHeight);	// iHeight�����炷.
			}
			else {
				break;
			}
		}
		else if (i > iIdx) {
			if (itor != m_lstWindowList.end()) {
				iTotalHeight = iTotalHeight + (*itor)->m_iHeight;
				(*itor)->MoveWindow(false, 0, -iHeight);	// iHeight�����炷.
			}
			else {
				break;
			}
		}
		else {
			iTotalHeight = iTotalHeight + (*itor)->m_iHeight;
		}
		if (itor != m_lstWindowList.end()) {
			itor++;
		}
		else {
			break;
		}
	}

	//�A�C�e���Y�p�l���̑傫�����k������.
	MoveWindow(3, iTotalHeight);	// ������iTotalHeight�ɂ���.

	// �Ƃ肠���������ɂ��Ă���.
	return TRUE;

}

// �A�C�e���擾�֐�Get
CWindowListItem * CWindowListItemsPanel::Get(int iIndex) {

	// iIndex�Ԗڂ̗v�f��Ԃ�.
	int i = 0;	// i��0�ɏ�����.
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// �C�e���[�^.
	while (itor != m_lstWindowList.end()) {
		if (i == iIndex) {
			return (*itor);
		}
		i++;
		itor++;
	}
	return NULL;

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CWindowListItemsPanel::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �y���ƃu���V�̍쐬.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 0xff));		// ��(�Z)�̃y�����쐬.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0x9d, 0xcc, 0xe0));		// ��(�W)�̃u���V���쐬.

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// �E�B���h�E�T�C�Y���ύX���ꂽ���̃n���h��OnSize.
void CWindowListItemsPanel::OnSize(UINT nType, int cx, int cy) {

	// ���ۂ̃E�B���h�E�T�C�Y���i�[.
	m_iWidth = cx;	// m_iWidth��cx���Z�b�g.
	m_iHeight = cy;	// m_iHeight��cy���Z�b�g.

	// �A�C�e���̈�ă��T�C�Y.
	std::list<CWindowListItem *>::iterator itor = m_lstWindowList.begin();	// �C�e���[�^.
	while (itor != m_lstWindowList.end()) {
		(*itor)->MoveWindow(2, m_iWidth - (3 * 2));	// �e�E�B���h�E�̕��ɍ��킹��.
		itor++;
	}

}

// �E�B���h�E�̕`���v�����ꂽ���̃n���h��OnPaint.
void CWindowListItemsPanel::OnPaint() {

	// �ϐ��̐錾
	HDC hDC;			// �f�o�C�X�R���e�L�X�g�n���h��HDC�^hDC.
	PAINTSTRUCT ps;		// PAINTSTRUCT�\���̕ϐ�ps.

	// �`��J�n.
	hDC = BeginPaint(m_hWnd, &ps);	// BeginPaint�ŕ`��J�n.
	// �y���ƃu���V�̑I��.
	HPEN hOldPen = (HPEN)SelectObject(hDC, m_hPen);		// �̃y����I��.
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, m_hBrush);	// �̃u���V��I��.
	// ��`��`��.(�N���C�A���g�̈�̓X�N���[���o�[���܂܂Ȃ�.)
	RECT rc;
	GetClientRect(m_hWnd, &rc);	// GetClientRect�ŃN���C�A���g�̈�̋�`���擾.
	Rectangle(hDC, 0, 0, rc.right - rc.left, rc.bottom - rc.top);	// Rectangle�ŋ�`��`��.
	// �y���ƃu���V�̕���
	SelectObject(hDC, hOldBrush);		// �Â��u���V��I��.
	SelectObject(hDC, hOldPen);		// �Â��y����I��.
	// �`��I��.
	EndPaint(m_hWnd, &ps);	// EndPaint�ŕ`��I��.

}