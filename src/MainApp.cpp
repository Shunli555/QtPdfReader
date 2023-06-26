

#include "MainApp.h"
#include "qpushbutton.h"
#include "QFileDialog"
#include "QPdfDocument"

void MainApp::initSlots() {
    connect(selectFileButton, &QPushButton::clicked, this, &MainApp::selectFile);
    connect(appendixButton, &QPushButton::clicked, this, &MainApp::toggleAppendixVisibility);
    connect(bookmarksButton, &QPushButton::clicked, this, &MainApp::toggleBookmarkVisibility);
}

void MainApp::initUI() {
    rootLayout = new QVBoxLayout(this);
    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->setSpacing(0);

    auto *contentWidget = new QWidget(this);
    contentLayout = new QHBoxLayout(contentWidget);
    contentLayout->setContentsMargins(0, 0, 0, 0);
    contentLayout->setSpacing(0);

    auto *leftWidget = new QWidget(this);
    leftToolPane = new QVBoxLayout(leftWidget);
    leftToolPane->setAlignment(Qt::AlignmentFlag::AlignTop);

    mToolbar = new QToolBar(this);
    QSizePolicy toolbarPolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    toolbarPolicy.setHorizontalStretch(100);
    mToolbar->setSizePolicy(toolbarPolicy);

    qPdfView = new QPdfView(this);
    qPdfView->move(0, mToolbar->height());
    QSizePolicy policy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    policy.setHorizontalStretch(1);
    policy.setVerticalStretch(1);
    qPdfView->setSizePolicy(policy);

    selectFileButton = new QPushButton(this);
    selectFileButton->setText("选择文件");

    appendixButton = new QPushButton(this);
    appendixButton->setText("目录");
    bookmarksButton = new QPushButton(this);
    bookmarksButton->setText("书签");

    singlePageMode = new QRadioButton();
    singlePageMode->setText("单页");

    doublePageMode = new QRadioButton();
    doublePageMode->setText("双页");

    leftToolPane->addWidget(appendixButton);
    leftToolPane->addWidget(bookmarksButton);

    mToolbar->addWidget(selectFileButton);
    mToolbar->addWidget(singlePageMode);
    mToolbar->addWidget(doublePageMode);
    rootLayout->addWidget(mToolbar);

    contentLayout->addWidget(leftWidget);
    contentLayout->addWidget(qPdfView);

    rootLayout->addWidget(contentWidget);
}

void MainApp::initPrefs() {

}

void MainApp::toggleBookmarkVisibility() {

}

void MainApp::toggleAppendixVisibility() {

}

void MainApp::selectFile() {
    const QString &fileName = QFileDialog::getOpenFileName(this, "选择文件", Q_NULLPTR, "pdf(*.pdf);pdf(*.PDF)");
    if (fileName.isEmpty()) {
        qDebug("No file selected");
        return;
    }
    auto *document = new QPdfDocument();
    document->load(fileName);
    qPdfView->setDocument(document);
    qPdfView->setPageMode(QPdfView::PageMode::MultiPage);
}

MainApp::MainApp() {
    initUI();
    initPrefs();
    initSlots();
}

MainApp::~MainApp() noexcept {
    qPdfView->document()->close();
}
