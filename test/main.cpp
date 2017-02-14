#include <QApplication>
#include "JournalWatcher.h"
#include "Handler.h"

int main(int argc, char *argv[]) {
    //Handler h(nullptr);
    QApplication a(argc, argv);
    JournalWatcher watcher(&a);
    watcher.watchDirectory(QDir::homePath()+"/Library/Application Support/Frontier Developments/Elite Dangerous/");
    a.exec();
    return 0;
}
