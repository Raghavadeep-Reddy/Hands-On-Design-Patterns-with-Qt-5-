#include <QCoreApplication>
#include <QDebug>
#include "MySkipIterator.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    // create our list
    QList<int>          list {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    // Create a SkipIterator for the list
    MySkipIterator<int> listIter(&list, 1);

    qDebug() << list;                   // display the list

    // try traversing the list with skips 1 to 6
    for (int i = 1; i < 7; ++i)
    {
        QList<int> items;
        listIter.first();
        listIter.setSkipValue(i);

        while (listIter.hasNext())      // check if we can get another
        {
            items << listIter.currentElement();
            listIter.next();
        }
        qDebug() << i << ":" << items;
    }

    return 0;
}
