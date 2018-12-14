/********************************************************************************
** Form generated from reading UI file 'osmDirectoryConversion.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSMDIRECTORYCONVERSION_H
#define UI_OSMDIRECTORYCONVERSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_osmDirectoryConversionClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *inDirInputEdit;
    QPushButton *inFileDialogBtn;
    QPushButton *transformBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *outDirInputEdit;
    QPushButton *outFileDialogBtn;
    QPushButton *updateBtn;
    QHBoxLayout *horizontalLayout_3;
    QTreeWidget *infileTree;
    QListWidget *outFileList;

    void setupUi(QWidget *osmDirectoryConversionClass)
    {
        if (osmDirectoryConversionClass->objectName().isEmpty())
            osmDirectoryConversionClass->setObjectName(QString::fromUtf8("osmDirectoryConversionClass"));
        osmDirectoryConversionClass->resize(572, 456);
        gridLayout = new QGridLayout(osmDirectoryConversionClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(osmDirectoryConversionClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        inDirInputEdit = new QLineEdit(osmDirectoryConversionClass);
        inDirInputEdit->setObjectName(QString::fromUtf8("inDirInputEdit"));

        horizontalLayout->addWidget(inDirInputEdit);

        inFileDialogBtn = new QPushButton(osmDirectoryConversionClass);
        inFileDialogBtn->setObjectName(QString::fromUtf8("inFileDialogBtn"));

        horizontalLayout->addWidget(inFileDialogBtn);

        transformBtn = new QPushButton(osmDirectoryConversionClass);
        transformBtn->setObjectName(QString::fromUtf8("transformBtn"));

        horizontalLayout->addWidget(transformBtn);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(osmDirectoryConversionClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        outDirInputEdit = new QLineEdit(osmDirectoryConversionClass);
        outDirInputEdit->setObjectName(QString::fromUtf8("outDirInputEdit"));

        horizontalLayout_2->addWidget(outDirInputEdit);

        outFileDialogBtn = new QPushButton(osmDirectoryConversionClass);
        outFileDialogBtn->setObjectName(QString::fromUtf8("outFileDialogBtn"));

        horizontalLayout_2->addWidget(outFileDialogBtn);

        updateBtn = new QPushButton(osmDirectoryConversionClass);
        updateBtn->setObjectName(QString::fromUtf8("updateBtn"));

        horizontalLayout_2->addWidget(updateBtn);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        infileTree = new QTreeWidget(osmDirectoryConversionClass);
        infileTree->setObjectName(QString::fromUtf8("infileTree"));

        horizontalLayout_3->addWidget(infileTree);

        outFileList = new QListWidget(osmDirectoryConversionClass);
        outFileList->setObjectName(QString::fromUtf8("outFileList"));

        horizontalLayout_3->addWidget(outFileList);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        retranslateUi(osmDirectoryConversionClass);

        QMetaObject::connectSlotsByName(osmDirectoryConversionClass);
    } // setupUi

    void retranslateUi(QWidget *osmDirectoryConversionClass)
    {
        osmDirectoryConversionClass->setWindowTitle(QApplication::translate("osmDirectoryConversionClass", "osmDirectoryConversion", nullptr));
        label->setText(QApplication::translate("osmDirectoryConversionClass", "\351\200\211\346\213\251\347\233\256\345\275\225\357\274\232", nullptr));
        inFileDialogBtn->setText(QApplication::translate("osmDirectoryConversionClass", "...", nullptr));
        transformBtn->setText(QApplication::translate("osmDirectoryConversionClass", "\350\275\254\346\215\242", nullptr));
        label_2->setText(QApplication::translate("osmDirectoryConversionClass", "\350\276\223\345\207\272\347\233\256\345\275\225\357\274\232", nullptr));
        outFileDialogBtn->setText(QApplication::translate("osmDirectoryConversionClass", "...", nullptr));
        updateBtn->setText(QApplication::translate("osmDirectoryConversionClass", "\345\210\267\346\226\260", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = infileTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("osmDirectoryConversionClass", "\346\226\207\344\273\266\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class osmDirectoryConversionClass: public Ui_osmDirectoryConversionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSMDIRECTORYCONVERSION_H
