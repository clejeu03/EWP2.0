#ifndef TRACK_H
#define TRACK_H

#include <QDeclarativeItem>
#include <QSlider>
#include <QColor>

 class Track : public QDeclarativeItem
 {
     Q_OBJECT
     Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
     Q_PROPERTY(int duration READ duration WRITE setDuration NOTIFY durationChanged)

 private:
     QString m_name;
     int m_duration;//in milliseconds

 public:
     Track(QString name, int duration, QDeclarativeItem *parent = 0);
     explicit Track(QDeclarativeItem *parent = 0);

     QString name() const;
     void setName(const QString &name);

     int duration() const;
     void setDuration(const int &duration);

     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

signals:
     void nameChanged();
     void durationChanged();
 public slots:


};

#endif // TRACK_H
