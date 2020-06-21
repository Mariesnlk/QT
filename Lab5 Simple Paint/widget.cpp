#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent)
{
    label = new QLabel;

    slider = new QSlider(Qt::Horizontal);
    slider->setToolTip("Pen width ");
    slider->setMaximumHeight(20);
    slider->setMaximumWidth(800);
    slider->setMinimum(1);
    slider->setMaximum(30);

    saveButton = new QPushButton;
    saveButton->setToolTip("Save");
    saveButton->setText("Save");

    openButton = new QPushButton;
    openButton->setToolTip("Open");
    openButton->setText("Open");

    helpButton = new QPushButton;
    helpButton->setToolTip("Help");
    helpButton->setText("Help");

    colorButton = new QPushButton;
    colorButton->setToolTip("Set pen&color");
    colorButton->setIcon(QIcon(":/new/for_buttons/resourses/color.png"));
    colorButton->setIconSize(QSize(60,20));

    rectangleButton = new QPushButton;
    rectangleButton->setToolTip("Select Rectangle");
    rectangleButton->setIcon(QIcon(":/new/for_buttons/resourses/rectangle.png"));
    rectangleButton->setIconSize(QSize(60,20));

    elipseButton = new QPushButton;
    elipseButton->setToolTip("Select Elipse");
    elipseButton->setIcon(QIcon(":/new/for_buttons/resourses/elipse.png"));
    elipseButton->setIconSize(QSize(60,20));

    lineButton = new QPushButton;
    lineButton->setToolTip("Select Line");
    lineButton->setIcon(QIcon(":/new/for_buttons/resourses/link.png"));
    lineButton->setIconSize(QSize(60,20));

    rombButton = new QPushButton;
    rombButton->setToolTip("Select Romb");
    rombButton->setIcon(QIcon(":/new/for_buttons/resourses/rombo.png"));
    rombButton->setIconSize(QSize(60,20));

    triangleButton = new QPushButton;
    triangleButton->setToolTip("Select Triangle");
    triangleButton->setIcon(QIcon(":/new/for_buttons/resourses/triangle.png"));
    triangleButton->setIconSize(QSize(60,20));

    rubberButton = new QPushButton;
    rubberButton->setToolTip("Select Rubber");
    rubberButton->setIcon(QIcon(":/new/for_buttons/resourses/rubber.png"));
    rubberButton->setIconSize(QSize(60,20));

    resize(800,400);
    setWindowTitle("So Easy Paint");

    elipseButton->setFixedSize(80,30);
    rectangleButton->setFixedSize(80,30);
    saveButton->setFixedSize(80,30);
    openButton->setFixedSize(80,30);
    helpButton->setFixedSize(80,30);
    colorButton->setFixedSize(80,30);
    rubberButton->setFixedSize(80,30);
    rombButton->setFixedSize(80,30);
    triangleButton->setFixedSize(80,30);


    label->setFrameStyle(QFrame::StyledPanel);
    QVBoxLayout *vLout = new QVBoxLayout;
    QHBoxLayout *hBoxLayout = new QHBoxLayout;
    QVBoxLayout *vBoxLayout = new QVBoxLayout;

    vBoxLayout->addWidget(elipseButton);
    vBoxLayout->addWidget(rectangleButton);
    vBoxLayout->addWidget(lineButton);
    vBoxLayout->addWidget(rombButton);
    vBoxLayout->addWidget(triangleButton);
    vBoxLayout->addWidget(colorButton);
    vBoxLayout->addWidget(rubberButton);
    vBoxLayout->addWidget(saveButton);
    vBoxLayout->addWidget(openButton);
    vBoxLayout->addWidget(helpButton);

    hBoxLayout->addWidget(label);
    hBoxLayout->addLayout(vBoxLayout);

    vLout->addLayout(hBoxLayout);
    vLout->addWidget(slider,Qt::AlignBottom);
    vLout->setAlignment(slider,Qt::AlignBottom);
    setLayout(vLout);

    ///--Cursors-----------------------------
    cursor_label = QCursor(QPixmap(":/new/for_cursor/resourses/cursor_brush.png"));
    label->setCursor(cursor_label);

    cursor_btn = QCursor(Qt::PointingHandCursor);
    saveButton->setCursor(cursor_btn);
    colorButton->setCursor(cursor_btn);
    rectangleButton->setCursor(cursor_btn);
    elipseButton->setCursor(cursor_btn);
    lineButton->setCursor(cursor_btn);
    triangleButton->setCursor(cursor_btn);
    rombButton->setCursor(cursor_btn);

    cursor_slider = QCursor(Qt::SizeHorCursor);
    slider->setCursor(cursor_slider);

    connect(saveButton,SIGNAL(clicked(bool)),SLOT(save()));
    connect(openButton,SIGNAL(clicked(bool)),SLOT(slot_open()));
    connect(helpButton,SIGNAL(clicked(bool)),SLOT(slot_help()));
    connect(colorButton,SIGNAL(clicked(bool)),SLOT(color()));
    connect(rubberButton,SIGNAL(clicked(bool)),SLOT(slot_rubber()));
    connect(slider,SIGNAL(valueChanged(int)),SLOT(set_size(int)));
    connect(rectangleButton,SIGNAL(clicked(bool)),SLOT(slot_rectangle()));
    connect(elipseButton,SIGNAL(clicked(bool)),SLOT(slot_elipse()));
    connect(lineButton,SIGNAL(clicked(bool)),SLOT(slot_line()));
    connect(rombButton,SIGNAL(clicked(bool)),SLOT(slot_romb()));
    connect(triangleButton,SIGNAL(clicked(bool)),SLOT(slot_triangle()));


    QImage image2(800,400,QImage::Format_RGB32);
    image = image2;
    image.fill(Qt::white);
    label->setPixmap(QPixmap::fromImage(image));
    color = Qt::black;
    brush.setColor(color);
    pen.setColor(color);

    drawRectangle = false;
    drawElipse = false;
    drawRubber = false;
    drawLine = false;
    drawRomb = false;
    drawTriangle = false;
}

void Widget::slot_save()
{
    fileName = QFileDialog::getSaveFileName(this,
                                                 tr("Save Image"),
                                                 "/untitled.png",
                                                 tr("Images (*.png *.xpm *.jpg)")
                                                 );
    if(fileName == "")
    {        
        return;
    }
    image.save(fileName);
}

void Widget::slot_help()
{
   QMessageBox::about(this, tr("About Simple Paint"),
      tr("<p>This <b>Simple Paint</b> is example of easy paint</p>"));
}

void Widget::set_color()
{
    cursor_label = QCursor(QPixmap(":/new/for_cursor/resourses/cursor_brush.png"));
    pen.setColor(QColorDialog::getColor());
    brush.setColor(pen.color());
    if( drawRubber == true)
    {
        drawRubber = false;
        rectangleButton->setEnabled(true);
        elipseButton->setEnabled(true);
        lineButton->setEnabled(true);
        rombButton->setEnabled(true);
        triangleButton->setEnabled(true);
        cursor_label = QCursor(QPixmap(":/new/for_cursor/resourses/cursor_brush.png"));
        label->setCursor(cursor_label);
        if(pen.color().isValid() == false)
        {
           pen.setColor(Qt::black);
           brush.setColor(pen.color());
        }
    }
}

void Widget::set_size(int a)
{
    pen.setWidth(a);
}

void Widget::slot_rectangle()
{
    drawRectangle = true;
}

void Widget::slot_elipse()
{
    drawElipse = true;
}

void Widget::slot_line()
{
    drawLine = true;
}

void Widget::slot_romb()
{
    drawRomb = true;
}

void Widget::slot_triangle()
{
    drawTriangle = true;
}


void Widget::slot_rubber()
{
    if(drawElipse == true | drawRectangle == true | drawLine == true | drawRomb == true | drawTriangle == true)
    {
        drawElipse = false;
        drawRectangle = false;
        drawLine = false;
        drawRomb = false;
        drawTriangle =false;
    }
    pen.setColor(QColor(Qt::white));
    brush.setColor(pen.color());
    rectangleButton->setEnabled(false);
    elipseButton->setEnabled(false);
    lineButton->setEnabled(false);
    rombButton->setEnabled(false);
    triangleButton->setEnabled(false);

    drawRubber = true;
    cursor_label = QCursor(QPixmap(":/new/for_cursor/resourses/cursor_rubber.png"));
    label->setCursor(cursor_label);
}

void Widget::slot_open()
{
    fileName = QFileDialog::getOpenFileName(this,
                                                 "Open Image",
                                                 0,
                                                 " *.png *.xpm *.jpg ;; *.jpg ;; *.png ;; All files (*.*)"
                                                 );
    if(fileName == "")
    {
        return;
    }
    QImage image2;
    image2.load(fileName);
    image = image2.scaled(800,400);
    label->setPixmap(QPixmap::fromImage(image));
}

void Widget::paintEvent(QPaintEvent *)
{
    if(isPressed == true)
    {
        if( drawRectangle == true)
        {
            if( start != end )
            {
                QPainter painter;
                painter.begin(&image);
                painter.setPen(pen);
                int w = (end.x() - start.x());
                int h = (end.y() - start.y());
                painter.drawRect(start.x(),start.y(),w,h);
                painter.end();
                isPressed = false;
                drawRectangle = false;
                start.setX(0);
                start.setY(0);
                end=start;
                label->setPixmap(QPixmap::fromImage(image));
                return;
            }
        }

        if( drawElipse == true)
        {
            if( start != end )
            {
                QPainter painter;
                painter.begin(&image);
                painter.setPen(pen);
                int w = (end.x() - start.x());
                int h = (end.y() - start.y());
                painter.drawEllipse(start.x(),start.y(),w,h);
                painter.end();
                isPressed = false;
                drawElipse = false;
                start.setX(0);
                start.setY(0);
                end=start;
                label->setPixmap(QPixmap::fromImage(image));
                return;
            }
        }

        if( drawLine == true)
        {
            if( start != end )
            {
                QPainter painter;
                painter.begin(&image);
                painter.setPen(pen);
                painter.drawLine(start.x(),start.y(),end.x(), end.y());
                painter.end();
                isPressed = false;
                drawLine = false;
                start.setX(0);
                start.setY(0);
                end=start;
                label->setPixmap(QPixmap::fromImage(image));
                return;
            }
        }


        if( drawRomb == true)
        {
            if( start != end )
            {
                QPainter painter;
                painter.begin(&image);
                painter.setPen(pen);

                QPolygonF polygon;

                polygon << QPointF(start.x() + (end.x() > start.x() ? + 1 : - 1)*
                                       abs((end.x() - start.x())/2), start.y())
                            << QPointF(end.x(), start.y() + (end.y() > start.y() ? + 1 : - 1)*
                                       abs((end.y() - start.y())/2))
                            << QPointF(start.x() + (end.x() > start.x() ? + 1 : - 1)*
                                       abs((end.x() - start.x())/2), end.y())
                            << QPointF(start.x(), start.y() + (end.y() > start.y() ? + 1 : - 1)*
                                       abs((end.y() - start.y())/2));

                painter.drawPolygon(polygon);


                painter.end();
                isPressed = false;
                drawRomb = false;
                start.setX(0);
                start.setY(0);
                end=start;
                label->setPixmap(QPixmap::fromImage(image));
                return;
            }
        }

        if( drawTriangle == true)
        {
            if( start != end )
            {
                QPainter painter;
                painter.begin(&image);
                painter.setPen(pen);


                QPolygonF polygon;

                polygon << QPointF(start.x() + (end.x() > start.x() ? + 1 : - 1)*
                                       abs((end.x() - start.x())/2), start.y())
                            << QPointF((end.x() > start.x()) ? end.x() : start.x(),
                                       end.y())
                            << QPointF((end.x() > start.x()) ? start.x() : end.x(),
                                       end.y());

                painter.drawPolygon(polygon);


                painter.end();
                isPressed = false;
                drawTriangle = false;
                start.setX(0);
                start.setY(0);
                end=start;
                label->setPixmap(QPixmap::fromImage(image));
                return;
            }
        }



        QPainter painter;
        painter.begin(&image);
        if (list.size() < 2) return;
        painter.setPen(pen);
        QList<QPoint>::const_iterator it = list.begin();
        QPoint start = *it;
        it++;
        while(it != list.end())
        {
            QPoint end = *it;
            painter.drawLine(start,end);
            start = end;
            it++;
        }
        painter.end();
        label->setPixmap(QPixmap::fromImage(image));
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if ( !isPressed )
    {
        return;
    }

    if(drawRectangle == true)
    {
        this->update();
        return;
    }

    if(drawElipse == true)
    {
        this->update();
        return;
    }

    if(drawLine == true)
    {
        this->update();
        return;
    }

    if(drawRomb == true)
    {
        this->update();
        return;
    }

    if(drawTriangle == true)
    {
        this->update();
        return;
    }

    QPoint tmp = event->pos();
    QPoint tmp_correct;
    tmp_correct.setX(tmp.x()-10);
    tmp_correct.setY(tmp.y()-10);
    list.push_back(tmp_correct);
    this->update();
    current = tmp_correct;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
 if (event->button() == Qt::LeftButton)
    {
        if(drawRectangle == true)
        {
            QToolTip::showText(event->globalPos(),"Keep Button pressed and"
                                                  " Move Cursor to"
                                                  " the next position",
                                                  this
                                                  );
            isPressed = true;
            QPoint tmp = event->pos();
            QPoint tmp_correct;
            tmp_correct.setX(tmp.x()-10);
            tmp_correct.setY(tmp.y()-10);
            start=tmp_correct;
            end=start;
            return;
        }

        if(drawElipse == true)
        {
            QToolTip::showText(event->globalPos(),"Keep Button pressed and"
                                                  " Move Cursor to"
                                                  " the next position",
                                                  this
                                                  );
            isPressed = true;
            QPoint tmp = event->pos();
            QPoint tmp_correct;
            tmp_correct.setX(tmp.x()-10);
            tmp_correct.setY(tmp.y()-10);
            start=tmp_correct;
            end=start;
            return;
        }

        if(drawLine == true)
        {
            QToolTip::showText(event->globalPos(),"Keep Button pressed and"
                                                  " Move Cursor to"
                                                  " the next position",
                                                  this
                                                  );
            isPressed = true;
            QPoint tmp = event->pos();
            QPoint tmp_correct;
            tmp_correct.setX(tmp.x()-10);
            tmp_correct.setY(tmp.y()-10);
            start=tmp_correct;
            end=start;
            return;
        }

        if(drawRomb == true)
        {
            QToolTip::showText(event->globalPos(),"Keep Button pressed and"
                                                  " Move Cursor to"
                                                  " the next position",
                                                  this
                                                  );
            isPressed = true;
            QPoint tmp = event->pos();
            QPoint tmp_correct;
            tmp_correct.setX(tmp.x()-10);
            tmp_correct.setY(tmp.y()-10);
            start=tmp_correct;
            end=start;
            return;
        }


        if(drawTriangle == true)
        {
            QToolTip::showText(event->globalPos(),"Keep Button pressed and"
                                                  " Move Cursor to"
                                                  " the next position",
                                                  this
                                                  );
            isPressed = true;
            QPoint tmp = event->pos();
            QPoint tmp_correct;
            tmp_correct.setX(tmp.x()-10);
            tmp_correct.setY(tmp.y()-10);
            start=tmp_correct;
            end=start;
            return;
        }

        isPressed = true;
        QPoint tmp = event->pos();
        QPoint tmp_correct;
        tmp_correct.setX(tmp.x()-10);
        tmp_correct.setY(tmp.y()-10);
        list.push_back(tmp_correct);
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if(drawRectangle == true)
        {
            QPoint tmp = event->pos();
            QPoint tmp_correct;
            tmp_correct.setX(tmp.x()-10);
            tmp_correct.setY(tmp.y()-10);
            end = tmp_correct;
            this->update();
            cursor_label = QCursor(QPixmap(":/new/for_cursor/resourses/cursor_brush.png"));
            label->setCursor(cursor_label);
            return;
        }

        if(drawElipse == true)
        {
            QPoint tmp = event->pos();
            QPoint tmp_correct;
            tmp_correct.setX(tmp.x()-10);
            tmp_correct.setY(tmp.y()-10);
            end = tmp_correct;
            this->update();
            cursor_label = QCursor(QPixmap(":/new/for_cursor/resourses/cursor_brush.png"));
            label->setCursor(cursor_label);
            return;
        }

        if(drawLine == true)
        {
            QPoint tmp = event->pos();
            QPoint tmp_correct;
            tmp_correct.setX(tmp.x()-10);
            tmp_correct.setY(tmp.y()-10);
            end = tmp_correct;
            this->update();
            cursor_label = QCursor(QPixmap(":/new/for_cursor/resourses/cursor_brush.png"));
            label->setCursor(cursor_label);
            return;
        }

        if(drawRomb == true)
        {
            QPoint tmp = event->pos();
            QPoint tmp_correct;
            tmp_correct.setX(tmp.x()-10);
            tmp_correct.setY(tmp.y()-10);
            end = tmp_correct;
            this->update();
            cursor_label = QCursor(QPixmap(":/new/for_cursor/resourses/cursor_brush.png"));
            label->setCursor(cursor_label);
            return;
        }

        if(drawTriangle == true)
        {
            QPoint tmp = event->pos();
            QPoint tmp_correct;
            tmp_correct.setX(tmp.x()-10);
            tmp_correct.setY(tmp.y()-10);
            end = tmp_correct;
            this->update();
            cursor_label = QCursor(QPixmap(":/new/for_cursor/resourses/cursor_brush.png"));
            label->setCursor(cursor_label);
            return;
        }



        isPressed = false;
        QPoint tmp = event->pos();
        QPoint tmp_correct;
        tmp_correct.setX(tmp.x()-10);
        tmp_correct.setY(tmp.y()-10);
        list.push_back(tmp_correct);
        this->update();
        list.clear();
    }
}
