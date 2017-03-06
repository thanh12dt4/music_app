#include "musiclist.h"
#include <QListWidgetItem>
MusicList::MusicList(const QString & text) :
    QListWidgetItem(text)
{

}

MusicList::MusicList(const QString & text, const char* name, const char* path) :
    QListWidgetItem(text),
    Music (name, path)
{

}
