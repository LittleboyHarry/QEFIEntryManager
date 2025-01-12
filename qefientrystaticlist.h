#ifndef QEFIENTRYSTATICLIST_H
#define QEFIENTRYSTATICLIST_H

#include <qefientry.h>

#include <QMap>
#include <QList>

class QEFIEntryStaticList
{
private:
    QEFIEntryStaticList();

    QMap<quint16, QEFIEntry> m_entries;     // Entries
    QMap<quint16, QByteArray> m_cachedItem; // Cached EFI array
    QList<quint16> m_order;                 // Cached order
    quint16 m_timeout;

public:
    static QEFIEntryStaticList *instance();
    void load();    // TODO: Add an async implementation for progress display

    quint16 timeout() const;
    void setTimeout(const quint16 &timeout);
    QList<quint16> order() const;
    void setOrder(const QList<quint16> &order);
    QMap<quint16, QEFIEntry> entries() const;

    void setBootNext(const quint16 &next);
    void setBootOrder(const QList<quint16> &newOrder);
};

#endif // QEFIENTRYSTATICLIST_H
