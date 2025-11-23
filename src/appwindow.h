#pragma once
#include <QMainWindow>

class ChatView;

class AppWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit AppWindow(QWidget *parent = nullptr);

private:
    ChatView *chatView;
};
