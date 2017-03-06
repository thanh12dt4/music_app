#ifndef MusicList_H
#define MusicList_H
#include <QListWidgetItem>
#include "music.h"

class MusicList : public QListWidgetItem , public Music
{
public:
    MusicList(const QString & text);
    MusicList(const QString & text, const char* name, const char* path);
};

#endif // MusicList_H
