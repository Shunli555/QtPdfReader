

#ifndef QTPDFREADER_MAINAPP_H
#define QTPDFREADER_MAINAPP_H

#include "QWidget"
#include "QToolBar"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QRadioButton"
#include "QPdfView"
#include "QPushButton"

class MainApp : public QWidget {
public:
    MainApp();
    ~MainApp();

private:
    QToolBar *mToolbar;
    QVBoxLayout *rootLayout;
    QHBoxLayout *contentLayout;
    QVBoxLayout *leftToolPane;
    QRadioButton *singlePageMode;
    QRadioButton *doublePageMode;

    QPushButton *selectFileButton;
    QPushButton *appendixButton;
    QPushButton *bookmarksButton;
    QPdfView *qPdfView;

    void initSlots();

    void initUI();

    void initPrefs();

private slots:

    void toggleBookmarkVisibility();

    void toggleAppendixVisibility();

    void selectFile();
};


#endif //QTPDFREADER_MAINAPP_H
