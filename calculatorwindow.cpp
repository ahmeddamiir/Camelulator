#include "calculatorwindow.h"
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSizePolicy>
#include <QStringList>
#include <QVBoxLayout>
#include <QLayout>
#include <QLabel>

namespace
{
    QPushButton *makeButton(const QString &text, QWidget *parent)
    {
        auto *button = new QPushButton(text, parent);
        // TODO 1: set a size policy so the button can grow horizontally & vertically
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        button->setMinimumSize(50, 50);
        return button;
    }
}

// The keypad: first 16 buttons, row by row (4 per row)
const QStringList labels =
{
    "C", "±", "%", "÷",
    "7", "8", "9", "×",
    "4", "5", "6", "−",
    "1", "2", "3", "+"
};

CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QWidget(parent)
{
    // TODO 2: set the window title and a starting size
    setWindowTitle("Camelulator");
    resize(320, 420);

    // TODO 3: create m_display with the text "0", then:
    //         - make it read-only
    //         - right-align the text
    //         - set a minimum height (for example 60)
    //         - make the font large, e.g. m_display->setStyleSheet("font-size: 28px;");
    auto *m_display = new QLineEdit("0", this);
    // m_display->setText("0");
    m_display->setReadOnly(true);
    m_display->setAlignment(Qt::AlignRight);
    m_display->setMinimumHeight(60);
    m_display->setStyleSheet("font-size: 28px;");

    // TODO 4: create a QGridLayout (without a parent!)
    //         Then loop over the labels and add a button for each one.
    //         Hint: for the i-th label, row = i / 4 and column = i % 4
    //
    //         After the loop, add the last row (row 4):
    //         - "0" spanning two columns (columns 0 and 1)
    //         - "." in column 2
    //         - "=" in column 3
    auto *buttonLayout = new QGridLayout();
    for (int i = 0; i < labels.size(); i++)
    {
        auto row = i / 4, column = i % 4;
        buttonLayout->addWidget(makeButton(labels[i], this), row, column);
    }
    buttonLayout->addWidget(makeButton("0", this), 4, 0, 1, 2);
    buttonLayout->addWidget(makeButton(".", this), 4, 2);
    buttonLayout->addWidget(makeButton("=", this), 4, 3);

    // TODO 5: create the main QVBoxLayout on the window (parent = this)
    //         - set margins and spacing
    //         - add the display
    //         - add the grid layout, with stretch factor 1 so it takes the extra space
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(12);
    mainLayout->addWidget(m_display);
    mainLayout->addLayout(buttonLayout, 1);
}