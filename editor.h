#ifndef EDITOR_H
#define EDITOR_H

#include <QObject>

class Editor : public QObject
{
    Q_OBJECT
public:
    explicit Editor(QObject *parent = 0);
    Editor(QString filepath, int value1, int value2, QObject *parent = 0);
    static void VideoSplit(Editor *editor);
    
signals:
    
public slots:
private:
    QString m_filepath;
    int m_in;
    int m_out;

};

#endif // EDITOR_H
