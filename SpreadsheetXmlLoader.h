#pragma once

#include <functional>
#include <vector>

#include "pugixml/src/pugixml.hpp"

namespace ssxml
{

// xml ������ ���������Ʈ Loader
class SpreadsheetXmlLoader
{
	pugi::xml_document m_Doc;
	pugi::xml_node m_WorkbookNode;
public:
	SpreadsheetXmlLoader();
	~SpreadsheetXmlLoader();

	// ������ �о �Ľ��Ѵ�.
	bool Open(const char* XmlFilename);

	// ������ sheetname�� �ش��ϴ� �����͸� �о CB���� ������ �ش�.
	bool Load(const char* sheet_name, std::function< void(int, const std::vector<const char*>&) > RowCB);

private:
	pugi::xml_node GetSheetNode(const char* sheet);
	int IncrRow(const pugi::xml_node& RowNode, int& RowIndex);
	const char* AsData(pugi::xml_node Cell, int& ColIndex);

};
}