/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QSplitter *splitter_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *clrPcListBtn;
    QSplitter *splitter_6;
    QTableWidget *pcTable;
    QPushButton *subPcBtn;
    QSplitter *splitter_8;
    QComboBox *resCombo;
    QPushButton *calcBtn;
    QPushButton *addPcBtn;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QSplitter *splitter_4;
    QSplitter *splitter;
    QLabel *label_2;
    QLineEdit *titleEdit;
    QSplitter *splitter_9;
    QLabel *label_3;
    QLineEdit *compEdit;
    QSplitter *splitter_2;
    QListWidget *perfList;
    QPushButton *subPerfBtn;
    QSplitter *splitter_3;
    QLineEdit *perfEdit;
    QPushButton *addPerfBtn;
    QPushButton *clrPcBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(668, 444);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        splitter_5 = new QSplitter(centralWidget);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Vertical);
        groupBox_2 = new QGroupBox(splitter_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        clrPcListBtn = new QPushButton(groupBox_2);
        clrPcListBtn->setObjectName(QStringLiteral("clrPcListBtn"));

        gridLayout_2->addWidget(clrPcListBtn, 2, 0, 1, 1);

        splitter_6 = new QSplitter(groupBox_2);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setOrientation(Qt::Horizontal);
        pcTable = new QTableWidget(splitter_6);
        if (pcTable->columnCount() < 3)
            pcTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        pcTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        pcTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        pcTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        pcTable->setObjectName(QStringLiteral("pcTable"));
        pcTable->setColumnCount(3);
        splitter_6->addWidget(pcTable);
        pcTable->horizontalHeader()->setStretchLastSection(true);

        gridLayout_2->addWidget(splitter_6, 0, 0, 1, 1);

        subPcBtn = new QPushButton(groupBox_2);
        subPcBtn->setObjectName(QStringLiteral("subPcBtn"));

        gridLayout_2->addWidget(subPcBtn, 1, 0, 1, 1);

        splitter_5->addWidget(groupBox_2);
        splitter_6->raise();
        splitter_6->raise();
        clrPcListBtn->raise();
        subPcBtn->raise();
        splitter_8 = new QSplitter(splitter_5);
        splitter_8->setObjectName(QStringLiteral("splitter_8"));
        splitter_8->setOrientation(Qt::Horizontal);
        resCombo = new QComboBox(splitter_8);
        resCombo->setObjectName(QStringLiteral("resCombo"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(5);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(resCombo->sizePolicy().hasHeightForWidth());
        resCombo->setSizePolicy(sizePolicy1);
        splitter_8->addWidget(resCombo);
        calcBtn = new QPushButton(splitter_8);
        calcBtn->setObjectName(QStringLiteral("calcBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(calcBtn->sizePolicy().hasHeightForWidth());
        calcBtn->setSizePolicy(sizePolicy2);
        splitter_8->addWidget(calcBtn);
        splitter_5->addWidget(splitter_8);

        gridLayout_3->addWidget(splitter_5, 0, 0, 1, 1);

        addPcBtn = new QPushButton(centralWidget);
        addPcBtn->setObjectName(QStringLiteral("addPcBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(addPcBtn->sizePolicy().hasHeightForWidth());
        addPcBtn->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(addPcBtn, 0, 1, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        splitter_4 = new QSplitter(groupBox);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_4);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter->addWidget(label_2);
        titleEdit = new QLineEdit(splitter);
        titleEdit->setObjectName(QStringLiteral("titleEdit"));
        splitter->addWidget(titleEdit);
        splitter_4->addWidget(splitter);
        splitter_9 = new QSplitter(splitter_4);
        splitter_9->setObjectName(QStringLiteral("splitter_9"));
        splitter_9->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_9);
        label_3->setObjectName(QStringLiteral("label_3"));
        splitter_9->addWidget(label_3);
        compEdit = new QLineEdit(splitter_9);
        compEdit->setObjectName(QStringLiteral("compEdit"));
        splitter_9->addWidget(compEdit);
        splitter_4->addWidget(splitter_9);
        splitter_2 = new QSplitter(splitter_4);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        perfList = new QListWidget(splitter_2);
        perfList->setObjectName(QStringLiteral("perfList"));
        splitter_2->addWidget(perfList);
        subPerfBtn = new QPushButton(splitter_2);
        subPerfBtn->setObjectName(QStringLiteral("subPerfBtn"));
        splitter_2->addWidget(subPerfBtn);
        splitter_3 = new QSplitter(splitter_2);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        perfEdit = new QLineEdit(splitter_3);
        perfEdit->setObjectName(QStringLiteral("perfEdit"));
        perfEdit->setClearButtonEnabled(false);
        splitter_3->addWidget(perfEdit);
        addPerfBtn = new QPushButton(splitter_3);
        addPerfBtn->setObjectName(QStringLiteral("addPerfBtn"));
        splitter_3->addWidget(addPerfBtn);
        splitter_2->addWidget(splitter_3);
        splitter_4->addWidget(splitter_2);

        gridLayout->addWidget(splitter_4, 3, 0, 1, 1);

        clrPcBtn = new QPushButton(groupBox);
        clrPcBtn->setObjectName(QStringLiteral("clrPcBtn"));

        gridLayout->addWidget(clrPcBtn, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        titleEdit->raise();
        label_2->raise();
        groupBox->raise();
        pcTable->raise();
        calcBtn->raise();
        resCombo->raise();
        groupBox_2->raise();
        compEdit->raise();
        label_3->raise();
        splitter_5->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 668, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(clrPcBtn, titleEdit);
        QWidget::setTabOrder(titleEdit, compEdit);
        QWidget::setTabOrder(compEdit, perfList);
        QWidget::setTabOrder(perfList, subPerfBtn);
        QWidget::setTabOrder(subPerfBtn, perfEdit);
        QWidget::setTabOrder(perfEdit, addPerfBtn);
        QWidget::setTabOrder(addPerfBtn, addPcBtn);
        QWidget::setTabOrder(addPcBtn, pcTable);
        QWidget::setTabOrder(pcTable, subPcBtn);
        QWidget::setTabOrder(subPcBtn, clrPcListBtn);
        QWidget::setTabOrder(clrPcListBtn, resCombo);
        QWidget::setTabOrder(resCombo, calcBtn);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Orchestrator", 0));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QApplication::translate("MainWindow", "Remove Selected Piece from List", 0));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("MainWindow", "List of Pieces", 0));
#ifndef QT_NO_TOOLTIP
        clrPcListBtn->setToolTip(QApplication::translate("MainWindow", "Clear the list", 0));
#endif // QT_NO_TOOLTIP
        clrPcListBtn->setText(QApplication::translate("MainWindow", "Clear", 0));
        QTableWidgetItem *___qtablewidgetitem = pcTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Title", 0));
        QTableWidgetItem *___qtablewidgetitem1 = pcTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Composer", 0));
        QTableWidgetItem *___qtablewidgetitem2 = pcTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Performers", 0));
#ifndef QT_NO_TOOLTIP
        pcTable->setToolTip(QApplication::translate("MainWindow", "Descriptions of Pieces", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        subPcBtn->setToolTip(QApplication::translate("MainWindow", "Remove selected piece from the list", 0));
#endif // QT_NO_TOOLTIP
        subPcBtn->setText(QApplication::translate("MainWindow", "- Piece", 0));
#ifndef QT_NO_TOOLTIP
        resCombo->setToolTip(QApplication::translate("MainWindow", "Calculation Result", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        calcBtn->setToolTip(QApplication::translate("MainWindow", "Calculate the optimal schedule arrangement", 0));
#endif // QT_NO_TOOLTIP
        calcBtn->setText(QApplication::translate("MainWindow", "Calculate", 0));
        addPcBtn->setText(QApplication::translate("MainWindow", "<<", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Piece Information", 0));
        label->setText(QApplication::translate("MainWindow", "Performers:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Title :", 0));
#ifndef QT_NO_TOOLTIP
        titleEdit->setToolTip(QApplication::translate("MainWindow", "Title of the piece", 0));
#endif // QT_NO_TOOLTIP
        titleEdit->setPlaceholderText(QApplication::translate("MainWindow", "Title", 0));
        label_3->setText(QApplication::translate("MainWindow", "Composer :", 0));
#ifndef QT_NO_TOOLTIP
        compEdit->setToolTip(QApplication::translate("MainWindow", "Composer of the piece", 0));
#endif // QT_NO_TOOLTIP
        compEdit->setPlaceholderText(QApplication::translate("MainWindow", "Composer", 0));
#ifndef QT_NO_TOOLTIP
        perfList->setToolTip(QApplication::translate("MainWindow", "List of Performers", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        subPerfBtn->setToolTip(QApplication::translate("MainWindow", "Remove Selected Performer from List", 0));
#endif // QT_NO_TOOLTIP
        subPerfBtn->setText(QApplication::translate("MainWindow", "- Performer", 0));
        perfEdit->setPlaceholderText(QApplication::translate("MainWindow", "Performer", 0));
#ifndef QT_NO_TOOLTIP
        addPerfBtn->setToolTip(QApplication::translate("MainWindow", "Add Performer Name to List", 0));
#endif // QT_NO_TOOLTIP
        addPerfBtn->setText(QApplication::translate("MainWindow", "+ Performer", 0));
#ifndef QT_NO_TOOLTIP
        clrPcBtn->setToolTip(QApplication::translate("MainWindow", "Clear Beneath Information", 0));
#endif // QT_NO_TOOLTIP
        clrPcBtn->setText(QApplication::translate("MainWindow", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
