#include "mainwindow.h"
#include "ui_mainwindow.h"

extern "C" {
#include "../../BACKEND/s21_calc.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->p_0, SIGNAL(clicked()), this, SLOT(digits_press()));
    connect(ui->p_1, SIGNAL(clicked()), this, SLOT(digits_press()));
    connect(ui->p_2, SIGNAL(clicked()), this, SLOT(digits_press()));
    connect(ui->p_3, SIGNAL(clicked()), this, SLOT(digits_press()));
    connect(ui->p_4, SIGNAL(clicked()), this, SLOT(digits_press()));
    connect(ui->p_5, SIGNAL(clicked()), this, SLOT(digits_press()));
    connect(ui->p_6, SIGNAL(clicked()), this, SLOT(digits_press()));
    connect(ui->p_7, SIGNAL(clicked()), this, SLOT(digits_press()));
    connect(ui->p_8, SIGNAL(clicked()), this, SLOT(digits_press()));
    connect(ui->p_9, SIGNAL(clicked()), this, SLOT(digits_press()));

    connect(ui->acos, SIGNAL(clicked()), this, SLOT(trig_press()));
    connect(ui->asin, SIGNAL(clicked()), this, SLOT(trig_press()));
    connect(ui->atan, SIGNAL(clicked()), this, SLOT(trig_press()));
    connect(ui->sin, SIGNAL(clicked()), this, SLOT(trig_press()));
    connect(ui->cos, SIGNAL(clicked()), this, SLOT(trig_press()));
    connect(ui->tan, SIGNAL(clicked()), this, SLOT(trig_press()));
    connect(ui->ln, SIGNAL(clicked()), this, SLOT(trig_press()));
    connect(ui->log, SIGNAL(clicked()), this, SLOT(trig_press()));
    connect(ui->sqrt, SIGNAL(clicked()), this, SLOT(trig_press()));

    connect(ui->div, SIGNAL(clicked()), this, SLOT(bin_press()));
    connect(ui->mul, SIGNAL(clicked()), this, SLOT(bin_press()));
    connect(ui->pow, SIGNAL(clicked()), this, SLOT(bin_press()));
    connect(ui->sub, SIGNAL(clicked()), this, SLOT(bin_press()));
    connect(ui->sum, SIGNAL(clicked()), this, SLOT(bin_press()));
    connect(ui->bracket_l, SIGNAL(clicked()), this, SLOT(bin_press()));
    connect(ui->bracket_r, SIGNAL(clicked()), this, SLOT(bin_press()));
    connect(ui->perem, SIGNAL(clicked()), this, SLOT(bin_press()));
    connect(ui->mod, SIGNAL(clicked()), this, SLOT(bin_press()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_press() {
  if (got_res) {
     ui->inputDisplay->setText("");
     got_res = 0;
  }
  QPushButton *digits = (QPushButton *)sender();

  ui->inputDisplay->setText(ui->inputDisplay->text() + digits->text());
}

void MainWindow::bin_press() {
  if (got_res) {
    ui->inputDisplay->setText("");
    got_res = 0;
  }
  QPushButton *bin = (QPushButton *)sender();

  ui->inputDisplay->setText(ui->inputDisplay->text() + bin->text());
}

void MainWindow::trig_press() {
  if (got_res) {
    ui->inputDisplay->setText("");
    got_res = 0;
  }
  QPushButton *trig = (QPushButton *)sender();

  ui->inputDisplay->setText(ui->inputDisplay->text() + trig->text() + "(");
}

void MainWindow::on_point_clicked() {
  if (got_res) {
    ui->inputDisplay->setText("");
    got_res = 0;
  }
  if (ui->inputDisplay->text().isEmpty() ||
      ui->inputDisplay->text().back() != '.')
    ui->inputDisplay->setText(ui->inputDisplay->text() + ".");
}

void MainWindow::on_AC_clicked()
{
    ui->inputDisplay->setText("");
    ui->outputDisplay->setText("");
    ui->ERR_MES->setText("");
    ui->xDisplay->setText("");

    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->xAxis->setRange(-10, 10);
    ui->widget->yAxis->setRange(-10, 10);
    ui->widget->replot();

    ui->x_min->setText("-10");
    ui->x_max->setText("10");
    ui->y_min->setText("-10");
    ui->y_max->setText("10");
}

void MainWindow::on_equal_clicked()
{
    double x = 0;
    x = ui->xDisplay->text().toDouble();
    std::string str = ui->inputDisplay->text().toStdString();
    char *stroka = (char *)str.c_str();
    char *stroka2 = (char *)str.c_str();
    change(stroka, stroka2, '.',',');
    squeeze(stroka2, stroka);

    if (validate_string(stroka) == 0 && stroka[0] != ',' && stroka[0] != '.') {
      double res = parser(stroka, x);
      std::ostringstream resultStream;
      resultStream << std::fixed << std::setprecision(7) << res;  // Задаем 7 знаков после запятой
      QString result = QString::fromStdString(resultStream.str());

      // убираем нули после точки
      if (result.contains('.')) {
          int length = result.length();
          for (int i = length - 1; i >= 0; --i) {
              if (result[i] == '0') {
                  result.remove(i, 1);
              }
              else if (result[i] == '.') {
                  result.remove(i, 1);
                  break;
              } else {
                  break;
              }
          }
      }

      ui->outputDisplay->setText(result);
      ui->ERR_MES->setText("OK");
    } else {
      ui->outputDisplay->setText("");
      ui->ERR_MES->setText("ERROR");
    }
    got_res = 1;
}


void MainWindow::on_PLOT_clicked()
{
    std::string str = ui->inputDisplay->text().toStdString();
    char *gr_str = (char *)str.c_str();
    char *gr_str2 = (char *)str.c_str();
    change(gr_str, gr_str2, '.',',');
    squeeze(gr_str2, gr_str);
    if (validate_string(gr_str) == 0 && gr_str[0] != ',' && gr_str[0] != '.') {
      double Ymax = ui->y_max->text().toDouble(),
             Ymin = ui->y_min->text().toDouble();
      double min = ui->x_min->text().toDouble();
      double max = ui->x_max->text().toDouble();
      if (Ymax != 0 && Ymin != 0 && max != 0 && min != 0 && max > min &&
          Ymax > Ymin) {
          double yy = 0;
          int N = 10000;
          //if (max <= 5 || min >= -5) N = 100;
          double h = (max - min) / N;
          //double h = 10;
          QVector<double> x(N), y(N);

        int i = 0;
        for (double X = min; X <= max-0.001;) {
          x[i] = X;
          yy = parser(gr_str, X);
          yy > Ymax || yy < Ymin ? y[i] = qQNaN() : y[i] = yy;
          X += h;
          i++;
        }

        ui->widget->clearGraphs();
        ui->widget->addGraph();
        ui->widget->graph(0)->setData(x, y);
        ui->widget->xAxis->setLabel("x");
        ui->widget->yAxis->setLabel("y");
        ui->widget->xAxis->setRange(min, max);
        for (int i = 0; i < N; i++) {
            if (!qIsNaN(y[i])) {
                if (y[i] < Ymin) Ymin = y[i];
                if (y[i] > Ymax) Ymax = y[i];
            }
        }

        ui->widget->yAxis->setRange(Ymin, Ymax);
        ui->widget->replot();
      } else {
        ui->ERR_MES->setText("INCORRECT BORDERS");
        ui->outputDisplay->setText("");
      }
    } else {
      ui->ERR_MES->setText("ERROR");
      ui->outputDisplay->setText("");
    }

    got_res = 1;
}

//void MainWindow::on_PLOT_clicked()
//{
//    //Рисуем график y=x*x
//    //Сгенерируем данные
//    //Для этого создадим два массива точек:
//    //один для сохранения x координат точек,
//    //а второй для y соответственно
//    double a = -1000000; //Начало интервала, где рисуем график по оси Ox
//    double b =  1000000; //Конец интервала, где рисуем график по оси Ox
//    double h = 1000; //Шаг, с которым будем пробегать по оси Ox
//    int N = (b - a) / h + 2; //Вычисляем количество точек, которые будем отрисовывать
//    QVector<double> x(N), y(N); //Массивы координат точек

//    //Вычисляем наши данные
//    int i=0;
//    //Пробегаем по всем точкам
//    for (double X = a; X <= b; X += h) {
//      x[i] = X;
//      y[i] = X * X;//Формула нашей функции
//      i++;
//    }
//    ui->widget->clearGraphs();//Если нужно, но очищаем все графики

//    //Добавляем один график в widget
//    ui->widget->addGraph();

//    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
//    ui->widget->graph(0)->setData(x, y);

//    //Подписываем оси Ox и Oy
//    ui->widget->xAxis->setLabel("x");
//    ui->widget->yAxis->setLabel("y");

//    //Установим область, которая будет показываться на графике
//    ui->widget->xAxis->setRange(a, b);//Для оси Ox

//    //Для показа границ по оси Oy сложнее, так как надо по правильному
//    //вычислить минимальное и максимальное значение в векторах
//    double minY = y[0], maxY = y[0];
//    for (int i = 1; i < N; i++) {
//      if (y[i] < minY) minY = y[i];
//      if (y[i] > maxY) maxY = y[i];
//    }
//    ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

//    //И перерисуем график на нашем widget
//    ui->widget->replot();
//}


