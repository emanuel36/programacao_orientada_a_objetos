#ifndef METRO_H
#define METRO_H

#include <QMainWindow>

namespace Ui {
class Metro;
}

class Metro : public QMainWindow
{
    Q_OBJECT

public:
    explicit Metro(QWidget *parent = 0);
    ~Metro();

private:
    Ui::Metro *ui;
};

#endif // METRO_H
