#include <QLabel>

#ifndef RESIZEOBSERVER_H
#define RESIZEOBSERVER_H


class ResizeObserver : public QLabel
{
    Q_OBJECT
public:
    ResizeObserver(QWidget* pwgt = nullptr);
protected:
    virtual void resizeEvent(QResizeEvent* pe);
};
#endif // RESIZEOBSERVER_H
