#include <QCoreApplication>
#include <QDir>
#include <iostream>

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	QDir dir;
	dir.setFilter(QDir::AllEntries);
	dir.setSorting(QDir::Name | QDir::Type | QDir::Size);

	QFileInfoList list = dir.entryInfoList();
	system("chcp 1251");
	system("cls");
	std::cout << "Список файлов и папок\n";
	std::cout << "    Размер Название" << std::endl;
	for (int i = 0; i < list.size(); ++i) {
		QFileInfo fileInfo = list.at(i);
		std::cout << qPrintable(QString("%1 %2").arg(fileInfo.size(), 10)
			.arg(fileInfo.fileName()));
		std::cout << std::endl;
	}
	return 0;
}
