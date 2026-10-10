#pragma once

#include <QWidget>

class QLineEdit;
class CalculatorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorWindow(QWidget *parent = nullptr);

private:
    QLineEdit *m_display = nullptr;
};