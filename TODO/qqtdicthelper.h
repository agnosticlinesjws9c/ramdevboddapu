#ifndef QQTDICTHELPER_H
#define QQTDICTHELPER_H

#include <qqt-local.h>

#include <qqtdictionary.h>
#include <qqtordereddictionary.h>

//别名，Q开头的Dictionary。
#define QDictionary QQtDictionary
#define QOrderedDictionary QQtOrderedDictionary

#define QDictionaryMap QQtDictionaryMap
#define QDictionaryMapIterator QQtDictionaryMapIterator
#define QDictionaryMutableMapIterator QQtDictionaryMutableMapIterator

#define QDictionaryList QQtDictionaryList
#define QDictionaryListIterator QQtDictionaryListIterator
#define QDictionaryMutableListIterator QQtDictionaryMutableListIterator

#define QOrderedDictionaryMap QQtOrderedDictionaryMap
#define QOrderedDictionaryMapIterator QQtOrderedDictionaryMapIterator
#define QOrderedDictionaryMutableMapIterator QQtOrderedDictionaryMutableMapIterator

#define QOrderedDictionaryList QQtOrderedDictionaryList
#define QOrderedDictionaryListIterator QQtOrderedDictionaryListIterator
#define QOrderedDictionaryMutableListIterator QQtOrderedDictionaryMutableListIterator

//C++ []操作符重载超过两层就不能赋值给引用变量了，所以这里对于获取深层引用进行封装。
QQTSHARED_EXPORT QQtDictionary& QQtGetDictNode ( QQtDictionary& rootDict,
                                QList<QString>& keyList1, bool numberAsString = false );
QQTSHARED_EXPORT QQtOrderedDictionary& QQtGetDictNode ( QQtOrderedDictionary& rootDict,
                                       QList<QString>& keyList1, bool numberAsString = false );

#endif // QQTDICTHELPER_H
