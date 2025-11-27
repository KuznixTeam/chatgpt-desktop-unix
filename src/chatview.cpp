#include "chatview.h"
#include <QStandardPaths>
#include <QDir>
#include <QNetworkCookie>
#include <QDebug>

ChatView::ChatView(QWidget *parent)
    : QWebEngineView(parent)
{
    // Ensure we have a profile for this view
    m_profile = page() ? page()->profile() : QWebEngineProfile::defaultProfile();

    // Choose a persistent storage path so cookies and storage survive restarts
    QString storagePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (storagePath.isEmpty())
        storagePath = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
    storagePath += QDir::separator() + QStringLiteral("chatgpt-desktop-unix");
    QDir().mkpath(storagePath);

    m_profile->setPersistentStoragePath(storagePath);
    m_profile->setPersistentCookiesPolicy(QWebEngineProfile::AllowPersistentCookies);

    // Wire up the cookie store to observe and ensure cookies are loaded
    m_cookieStore = m_profile->cookieStore();
    if (m_cookieStore) {
        connect(m_cookieStore, &QWebEngineCookieStore::cookieAdded,
                this, [](const QNetworkCookie &cookie){
                    qDebug() << "Cookie added:" << cookie.name() << cookie.domain() << cookie.isSessionCookie();
                });

        connect(m_cookieStore, &QWebEngineCookieStore::cookieRemoved,
                this, [](const QNetworkCookie &cookie){
                    qDebug() << "Cookie removed:" << cookie.name() << cookie.domain();
                });

        // Load cookies now so cookieAdded signals will be emitted
        m_cookieStore->loadAllCookies();
    }

    load(QUrl("https://chatgpt.com"));  // placeholder
}
