

#include "MainApp.h"

void MainApp::initSlots() {

}

void MainApp::initUI() {
    rootLayout = new QVBoxLayout(this);
    contentLayout = new QHBoxLayout(this);
    leftToolPane = new QVBoxLayout(this);
    mToolbar = new QToolBar(this);
    singlePageMode = new QRadioButton(this);
    singlePageMode->setText("单页");
    doublePageMode = new QRadioButton(this);
    doublePageMode->setText("双页");

    mToolbar->addWidget(singlePageMode);
    mToolbar->addWidget(doublePageMode);

    contentLayout->addLayout(leftToolPane);


    rootLayout->addWidget(mToolbar);
    rootLayout->addLayout(contentLayout);
}

void MainApp::initPrefs() {

}

void MainApp::toggleBookmarkVisibility() {

}

void MainApp::toggleAppendixVisibility() {

}

void MainApp::selectFile() {

}

MainApp::MainApp() {
    initUI();
    initPrefs();
    initSlots();
}
