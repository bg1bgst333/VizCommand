// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "StreamConsole.h"	// �X�g���[���R���\�[���N���X
#include "StreamConsoleItemsPanel.h"	// �X�g���[���R���\�[���A�C�e���Y�p�l���N���X
#include "Console.h"	// �R���\�[���N���X
#include "ListControlPanel.h"	// ���X�g�R���g���[���p�l���N���X
#include "BinaryFile.h"	// �o�C�i���t�@�C���N���X
#include "Command.h"	// �R�}���h�N���X

// �E�B���h�E�N���X�o�^�֐�RegisterClass
BOOL CStreamConsole::RegisterClass(HINSTANCE hInstance) {

	// �E�B���h�E���X�g�A�C�e���Y�p�l����o�^.
	CWindowListItemsPanel::RegisterClass(hInstance);	// �q�E�B���h�E��o�^.

	// ���[�U�R���g���[���Ƃ��ēo�^.
	return CUserControl::RegisterClass(hInstance, _T("StreamConsole"));	// CUserControl::RegisterClass�ŃE�B���h�E�N���X"StreamConsole"��o�^.

}

// �R���X�g���N�^CStreamConsole()
CStreamConsole::CStreamConsole() : CWindowListControl() {

	// �����o�̏�����
	m_nId = 0;

}

// �f�X�g���N�^~CStreamConsole()
CStreamConsole::~CStreamConsole() {

}

// �E�B���h�E�쐬�֐�Create
BOOL CStreamConsole::Create(LPCTSTR lpctszWindowName, DWORD dwStyle, int x, int y, int iWidth, int iHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance) {

	// ���[�U�R���g���[���ō쐬.
	return CUserControl::Create(_T("StreamConsole"), lpctszWindowName, dwStyle, x, y, iWidth, iHeight, hWndParent, hMenu, hInstance);	// CUserControl::Create�ŃE�B���h�E�N���X"StreamConsole"�ȃE�B���h�E���쐬.

}

// �E�B���h�E�쐬���̃n���h��OnCreate.
int CStreamConsole::OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) {

	// �y���ƃu���V�̍쐬.
	m_hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 0));		// ���̃y�����쐬.
	m_hBrush = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));		// ���̃u���V���쐬.

	// �E�B���h�E���X�g�A�C�e���Y�p�l���N���X�̍쐬.
	//m_pWindowListItemsPanel = new CWindowListItemsPanel();	// CWindowListItemsPanel�I�u�W�F�N�g���쐬��, �|�C���^��m_pWindowListItemsPanel�Ɋi�[.
	m_pWindowListItemsPanel = new CStreamConsoleItemsPanel();	// CStreamConsoleItemsPanel�I�u�W�F�N�g���쐬��, �|�C���^��m_pWindowListItemsPanel�Ɋi�[.
	m_pWindowListItemsPanel->Create(_T(""), 0, 0, 0, m_iWidth, m_iHeight, hwnd, (HMENU)IDC_WINDOWLISTITEMSPANEL1, lpCreateStruct->hInstance);	// m_pWindowListItemsPanel->Create�ŃE�B���h�E���X�g�A�C�e���Y�p�l�����쐬.(�e�E�B���h�E��菬����.)

	// �f�t�H���g�A�C�e���̑}��.
	Insert(_T(""), m_nId, 100, lpCreateStruct->hInstance);	// Insert��0�ԖڂɃE�B���h�E��}��
	// �f�t�H���g�A�C�e���Ɏq�E�B���h�E���Z�b�g.
	CWindowListItem *pItem = m_pWindowListItemsPanel->Get(m_nId);	// 0�Ԗڂ��擾.
	CConsole *pConsole = new CConsole();	// �R���\�[���𐶐�.
	pConsole->SetProcWindow(hwnd);	// SetProcWindow�ŏ�������ꏊ���Z�b�g.
	pConsole->Create(_T(""), 0, 0, 0, pItem->m_iWidth, pItem->m_iHeight, pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + m_nId, lpCreateStruct->hInstance);	// �R���\�[���̃E�B���h�E�𐶐�.
	pItem->m_mapChildMap.insert(std::make_pair(_T("Console"), pConsole));	// �A�C�e���Ɏq�E�B���h�E��}��.
	m_nId++;

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// ���[�U��`���b�Z�[�W�������������̃n���h��.
void CStreamConsole::OnUserMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// switch-case���ŐU�蕪����.
	switch (uMsg) {

		// ���ւ̃X�N���[���v��������ꂽ��.
		case UM_REQUESTSCROLLBOTTOM:

			// UM_REQUESTSCROLLBOTTOM�u���b�N
			{

				// OnRequestScrollBottom�ɔC����.
				OnRequestScrollBottom(uMsg, wParam, lParam);	// OnRequestScrollBottom�ɔC����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// CConsole����CStreamConsole�����R�}���h������ꂽ��.
		case UM_STREAMCOMMAND:

			// UM_STREAMCOMMAND�u���b�N
			{

				// OnStreamCommand�ɔC����.
				OnStreamCommand(wParam, lParam);	// OnStreamCommand�ɔC����.

			}

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

		// ����ȊO.
		default:

			// ����̏����֌�����.
			break;	// ������DefWindowProc�Ɍ�����.

	}

}

// ���ւ̃X�N���[���v��.
void CStreamConsole::OnRequestScrollBottom(UINT uMsg, WPARAM wParam, LPARAM lParam) {

	// �X�N���[���\�ɂȂ�����.
	if (m_ScrollInfo.nMax > m_ScrollInfo.nPage + 1) {

		// �ϐ��̏�����.
		int iTotalHeight = (int)wParam;

		// �X�N���[�����擾.
		m_ScrollInfo.fMask = SIF_POS | SIF_RANGE | SIF_PAGE;
		GetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo);

		// iTotalHeight���ő�l�ɂ���, �ʒu����ԉ��ɂ���.
		m_ScrollInfo.nMax = iTotalHeight + PADDING * 2;
		m_ScrollInfo.nPos = m_ScrollInfo.nMax - m_ScrollInfo.nPage;

		// �X�N���[�����ݒ�.
		SetScrollInfo(m_hWnd, SB_VERT, &m_ScrollInfo, TRUE);

		// �A�C�e���Y�p�l���̈ړ�.
		m_pWindowListItemsPanel->MoveWindow(1, -m_ScrollInfo.nPos + PADDING);	// m_pWindowListItemsPanel->MoveWindow��y�������ύX.

	}

}

// CConsole����StreamConsole�����R�}���h������ꂽ���̓Ǝ��n���h��.
int CStreamConsole::OnStreamCommand(WPARAM wParam, LPARAM lParam) {

	// �ϐ��̐錾
	//tstring tstrCommand;	// �R�}���h������tstring�^tstrCommand.
	CCommand *pCommand;	// �R�}���h�I�u�W�F�N�g�|�C���^pCommand.
	HWND hSrc;	// ���M���E�B���h�E�n���h��HWND�^hSrc.

	// �R�}���h�ƃ\�[�X���擾.
	//tstrCommand = (TCHAR *)wParam;	// wParam��TCHAR *�^�ɃL���X�g����tstrCommand�Ɋi�[.
	pCommand = (CCommand *)wParam;		// wParam��CCommand *�^�ɃL���X�g����pCommand�Ɋi�[.
	hSrc = (HWND)lParam;	// lParam��HWND�^�ɃL���X�g����hSrc�Ɋi�[.

#if 0
	// �R�}���h�ƈ����̃p�[�X.
	LPTSTR next;
	tstring command;
	TCHAR *ptszCommand = new TCHAR[tstrCommand.length() + 1];
	_tcscpy_s(ptszCommand, tstrCommand.length() + 1, tstrCommand.c_str());
	TCHAR *p = _tcstok_s(ptszCommand, _T(" ."), &next);
	command = p;
	delete[] ptszCommand;
#endif

	// �R�}���h�̔���.
	tstring tstrCommandName = pCommand->GetCommandName();	// pCommand->GetCommandName�ŃR�}���h�����擾��, tstrCommandName�Ɋi�[.
	if (tstrCommandName == _T("list")) {	// �R�}���h"list".

		// OnList�ɔC����.
		OnList(wParam, lParam);	// OnList�ɔC����.

	}

	// �����Ȃ̂�0��Ԃ�.
	return 0;

}

// "list"�R�}���h�̓Ǝ��n���h��.
int CStreamConsole::OnList(WPARAM wParam, LPARAM lParam) {

	// �ϐ��̐錾
	//tstring tstrCommand;	// �R�}���h������tstring�^tstrCommand.
	HWND hSrc;	// ���M���E�B���h�E�n���h��HWND�^hSrc.
	CCommand *pCommand;	// �R�}���h�I�u�W�F�N�g�|�C���^pCommand.
	tstring tstrCurrentPath;	// �J�����g�p�XtstrCurrentPath.

	// �R�}���h�ƃ\�[�X���擾.
	pCommand = (CCommand *)wParam;	// wParam��CCommand *�^�ɃL���X�g����pCommand�Ɋi�[.
	tstring tstrCommandName = pCommand->GetCommandName();	// pCommand->GetCommandName�ŃR�}���h�����擾��, tstrCommandName�Ɋi�[.
	hSrc = (HWND)lParam;	// lParam��HWND�^�ɃL���X�g����hSrc�Ɋi�[.

	// �p�X�̎擾.
	tstring tstrPath = pCommand->GetParam(1);	// 1�Ԗڂ��p�X�Ȃ̂�, pCommand->GetParam(1)��1�Ԗڂ̃p�X���擾.
	{	// �ꎞ�I�Ƀu���b�N������.
		CWindowListItem *pItem = m_pWindowListItemsPanel->Get(m_nId - 1);	// m_nId - 1�Ԗڂ��擾.
		CConsole *pConsole = (CConsole *)pItem->m_mapChildMap[_T("Console")];	// pConsole�����o��.
		CConsoleCore *pConsoleCore = (CConsoleCore *)pConsole->m_pEditBox;	// pConsoleCore�����o��.
		tstrCurrentPath = pConsoleCore->GetCurrentPath();	// pConsoleCore->GetCurrentPath��tstrCurrentPath�Ɋi�[.
		if (tstrPath == _T("")) {	// �󕶎���̏ꍇ.
			pConsoleCore->GetCurrentPath();	// GetCurrentPath�Ō��݂̃p�X���擾.
			tstrPath = pConsoleCore->m_tstrCurrentPath;	// m_tstrCurrentPath�����o����tstrPath�Ɋi�[.
		}
		else {	// ��łȂ��ꍇ�͑��΃p�X�������ꍇ�ɐ�΃p�X�ɕϊ�����.
			tstring newPath = pConsoleCore->GetFullPath(tstrPath);	// pConsoleCore->GetFullPath�Ńt���p�X�ɕϊ��������̂�newPath�ɑ��.
			tstrPath = newPath;	// newPath��tstrPath�ɑ��.
		}
	}

#if 0
	// �R�}���h�ƈ����̃p�[�X.
	LPTSTR next;
	tstring command;
	tstring pattern;
	tstring path;
	TCHAR *ptszCommand = new TCHAR[tstrCommand.length() + 1];
	_tcscpy_s(ptszCommand, tstrCommand.length() + 1, tstrCommand.c_str());
	TCHAR *p = _tcstok_s(ptszCommand, _T(" ."), &next);
	command = p;
	pattern = next;
	path = next;
	pattern = pattern + _T("\\*");
	delete[] ptszCommand;
#endif

	// �����p�^�[���̑g�ݗ���.
	tstring tstrPattern = tstrPath;
	tstrPattern = tstrPattern + _T("\\*");

	// ���̃A�C�e���̑}��.
	HINSTANCE hInstance = (HINSTANCE)GetWindowLong(m_hWnd, GWL_HINSTANCE);	// �C���X�^���X�n���h�����擾.
	Insert(_T(""), m_nId, 300, hInstance);	// Insert��1�ԖڂɃE�B���h�E��}��

	// ���X�g�R���g���[�����쐬.
	tstring filename;
	tstring fullpath;
	CWindowListItem *pItem = m_pWindowListItemsPanel->Get(m_nId);	// 1�Ԗڂ��擾.
	CListControlPanel *pListControlPanel = new CListControlPanel();	// ���X�g�R���g���[���p�l���𐶐�.
	pListControlPanel->Create(_T(""), 0, 0, 0, pItem->m_iWidth, pItem->m_iHeight, pItem->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + m_nId, hInstance);	// ���X�g�R���g���[���p�l���̃E�B���h�E�𐶐�.
	CBinaryFile *pBinaryFile = new CBinaryFile();	// CBinaryFile�I�u�W�F�N�g���쐬��, pBinaryFile�Ƀ|�C���^���i�[.
	if (pBinaryFile->FindFirstFile(tstrPattern.c_str()) == INVALID_HANDLE_VALUE) {
		delete pBinaryFile;	// �폜.
		return -1;
	}
	filename = pBinaryFile->m_wfdFindData.cFileName;
	fullpath = tstrPath + _T("\\");
	fullpath = fullpath + filename;
	SHFILEINFO sfi;
	LV_ITEM item;
	HIMAGELIST hImageList = ImageList_Create(32, 32, ILC_COLOR24, 24, 0);
	ListView_SetImageList(pListControlPanel->m_pListControl->m_hWnd, hImageList, LVSIL_NORMAL);
	int i = 0;
	while (true) {
		if (!pBinaryFile->FindNextFile()) {
			break;
		}
		filename = pBinaryFile->m_wfdFindData.cFileName;
		fullpath = tstrPath + _T("\\");
		fullpath = fullpath + filename;
		if (filename != _T(".") && filename != _T("..")) {
			::SHGetFileInfo(fullpath.c_str(), 0, &sfi, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_LARGEICON);
			ImageList_AddIcon(hImageList, sfi.hIcon);
			ListView_SetImageList(pListControlPanel->m_pListControl->m_hWnd, hImageList, LVSIL_NORMAL);
			item.mask = LVIF_TEXT | LVIF_IMAGE;
			TCHAR t[1024];
			_tcscpy_s(t, filename.c_str());
			item.pszText = t;
			item.iItem = i;
			item.iSubItem = 0;
			item.iImage = i;
			ListView_InsertItem(pListControlPanel->m_pListControl->m_hWnd, &item);
			i++;
		}
	}
	pBinaryFile->FindClose();
	delete pBinaryFile;	// �폜.
	pItem->m_mapChildMap.insert(std::make_pair(_T("ListControlPanel"), pListControlPanel));	// �A�C�e���Ɏq�E�B���h�E��}��.
	m_nId++;

	// �f�t�H���g�A�C�e���̑}��.
	Insert(_T(""), m_nId, 100, hInstance);	// Insert��0�ԖڂɃE�B���h�E��}��
	// �f�t�H���g�A�C�e���Ɏq�E�B���h�E���Z�b�g.
	CWindowListItem *pItem2 = m_pWindowListItemsPanel->Get(m_nId);	// 0�Ԗڂ��擾.
	CConsole *pConsole = new CConsole(tstrCurrentPath);	// �R���\�[���𐶐�.
	pConsole->SetProcWindow(m_hWnd);	// SetProcWindow�ŏ�������ꏊ���Z�b�g.
	pConsole->Create(_T(""), 0, 0, 0, pItem2->m_iWidth, pItem2->m_iHeight, pItem2->m_hWnd, (HMENU)IDC_WINDOWLISTITEM_CHILD_ID_START + m_nId, hInstance);	// �R���\�[���̃E�B���h�E�𐶐�.
	pItem2->m_mapChildMap.insert(std::make_pair(_T("Console"), pConsole));	// �A�C�e���Ɏq�E�B���h�E��}��.
	m_nId++;

	// �����Ȃ̂�TRUE��Ԃ�.
	return 0;

}