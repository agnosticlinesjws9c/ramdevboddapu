#include <qqtdicthelper.h>

//增加 QOrderedMap<..., ...> 的定义，帮助MSVC export and import。
typedef QOrderedMap<QString, QString> QStringQStringOrderedMap;
typedef QOrderedMap<QByteArray, QByteArray> QByteArryQByteArrayOrderedMap;
typedef QOrderedMap<QString, QVariant> QStringOrderedMap;
typedef QOrderedMap<QByteArray, QVariant> QByteArrayOrderedMap;
typedef QOrderedMap<QVariant, QVariant> QVariantOrderedMap;

typedef QOrderedMap<QString, QQtOrderedDictionary> QQtOrderedDictionaryMap;
typedef QOrderedMapIterator<QString, QQtOrderedDictionary> QQtOrderedDictionaryMapIterator;
typedef QMutableOrderedMapIterator<QString, QQtOrderedDictionary> QQtOrderedDictionaryMutableMapIterator;

typedef QList<QQtOrderedDictionary> QQtOrderedDictionaryList;
typedef QListIterator<QQtOrderedDictionary> QQtOrderedDictionaryListIterator;
typedef QMutableListIterator<QQtOrderedDictionary> QQtOrderedDictionaryMutableListIterator;

QStringQStringOrderedMap ____map1____;
QByteArryQByteArrayOrderedMap ____map2____;
QStringOrderedMap ____map3____;
QByteArrayOrderedMap ____map4____;
QVariantOrderedMap ____map5____;
QQtOrderedDictionaryMap ____map6____;
QQtOrderedDictionaryMapIterator ____map7_iterator____(____map6____);
QQtOrderedDictionaryMutableMapIterator ____map8_iterator____(____map6____);


QQtDictionary& QQtGetDictNode ( QQtDictionary& rootDict, QList<QString>& keyList1, bool numberAsString )
{
    QListIterator<QString> itor ( keyList1 );
    QQtDictionary* pdict = &rootDict;
    while ( itor.hasNext() )
    {
        const QString& key = itor.next();
        QQtDictionary& dict = *pdict;

        if ( numberAsString )
        {
            pdict = & ( dict[key] );
            continue;
        }

        bool ok;
        uint nkey = key.toUInt ( &ok );
        if ( ok )
            pdict = & ( dict[nkey] );
        else
            pdict = & ( dict[key] );
    }
    QQtDictionary& dict = *pdict;
    return dict;
}

QQtOrderedDictionary& QQtGetDictNode ( QQtOrderedDictionary& rootDict, QList<QString>& keyList1, bool numberAsString )
{
    QListIterator<QString> itor ( keyList1 );
    QQtOrderedDictionary* pdict = &rootDict;
    while ( itor.hasNext() )
    {
        const QString& key = itor.next();
        QQtOrderedDictionary& dict = *pdict;

        if ( numberAsString )
        {
            pdict = & ( dict[key] );
            continue;
        }

        bool ok;
        uint nkey = key.toUInt ( &ok );
        if ( ok )
            pdict = & ( dict[nkey] );
        else
            pdict = & ( dict[key] );
    }
    QQtOrderedDictionary& dict = *pdict;
    return dict;
}
