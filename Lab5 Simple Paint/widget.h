#ifndef WIDGET_H
#define WIDGET_H

#include <QTWidgets>
#include <cmath>

class Widget : public QWidget
{
    Q_OBJECT    
private:    
    QCursor cursor_label;
    QCursor cursor_btn;
    QCursor cursor_slider;

    QImage image;

    QLabel *label;
    QSlider *slider;
    QPushButton *saveButton;
    QPushButton *openButton;
    QPushButton *colorButton;
    QPushButton *rectangleButton;
    QPushButton *elipseButton;
    QPushButton *lineButton;
    QPushButton *rombButton;
    QPushButton *triangleButton;
    QPushButton *rubberButton;
    QPushButton *helpButton;

    QColor color;
    QPoint current;
    QBrush brush;
    QPen pen;
    int diametr;
    QList<QPoint> list;

    QString fileName;

    QPoint start;
    QPoint end;

    bool isPressed;
    bool drawRectangle;
    bool drawElipse;
    bool drawLine;
    bool drawRubber;
    bool drawRomb;
    bool drawTriangle;

public:
    Widget(QWidget *parent = 0);

public slots:
    void slot_save();
    void slot_help();
    void set_color();
    void set_size(int);
    void slot_rectangle();
    void slot_elipse();
    void slot_line();
    void slot_romb();
    void slot_triangle();

    void slot_rubber();
    void slot_open();

protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
};

#endif // WIDGET_H
