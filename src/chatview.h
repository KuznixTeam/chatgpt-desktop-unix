#pragma once
#include <QWebEngineView>

class ChatView : public QWebEngineView {
    Q_OBJECT
public:
    explicit ChatView(QWidget *parent = nullptr);
};
