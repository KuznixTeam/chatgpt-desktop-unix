#pragma once
#include <QWebEngineView>
#include <QWebEngineProfile>
#include <QWebEngineCookieStore>

class ChatView : public QWebEngineView {
    Q_OBJECT
public:
    explicit ChatView(QWidget *parent = nullptr);

private:
    QWebEngineProfile *m_profile = nullptr;
    QWebEngineCookieStore *m_cookieStore = nullptr;
};
