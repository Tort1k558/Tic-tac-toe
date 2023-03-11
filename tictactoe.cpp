#include "tictactoe.h"
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

TicTacToeGame::TicTacToeGame(QWidget *parent) : QWidget(parent)
{
    QGridLayout *gridLayout = new QGridLayout(this);
    m_iconCross = QIcon("assets/Cross.png");
    m_iconZero = QIcon("assets/Zero.png");
    for (int i = 0; i < 9; i++) {
        QPushButton *button = new QPushButton(this);
        button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        button->setObjectName("");
        button->setStyleSheet("background-color: transparent;   margin: 5px;");
        button->setIconSize(m_iconCross.actualSize(QSize(128,128)));
        connect(button, &QPushButton::clicked, this, &TicTacToeGame::handleButton);

        m_buttons.append(button);
        gridLayout->addWidget(button, i / 3, i % 3);
    }

    m_currentPlayer = Player1;
}

void TicTacToeGame::handleButton()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

        if (button->objectName() == "") {
            if (m_currentPlayer == Player1) {
                button->setIcon(m_iconCross);
                //button->setIconSize(button->size());
                button->setObjectName("X");
                m_currentPlayer = Player2;
            } else {
                button->setIcon(m_iconZero);
                //button->setIconSize(button->size());
                button->setObjectName("O");
                m_currentPlayer = Player1;
            }

            checkForWin();
        }

}

void TicTacToeGame::checkForWin()
{
    QString winner = "";

    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (m_buttons[i]->objectName() == m_buttons[i+1]->objectName() && m_buttons[i]->objectName() == m_buttons[i+2]->objectName() && m_buttons[i]->objectName() != "") {
            winner = m_buttons[i]->objectName();
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (m_buttons[i]->objectName() == m_buttons[i+3]->objectName() && m_buttons[i]->objectName() == m_buttons[i+6]->objectName() && m_buttons[i]->objectName() != "") {
            winner = m_buttons[i]->objectName();
        }
    }

    // Check diagonals
    if (m_buttons[0]->objectName() == m_buttons[4]->objectName() && m_buttons[0]->objectName() == m_buttons[8]->objectName() && m_buttons[0]->objectName() != "") {
        winner = m_buttons[0]->objectName();
    }

    if (m_buttons[2]->objectName() == m_buttons[4]->objectName() && m_buttons[2]->objectName() == m_buttons[6]->objectName() && m_buttons[2]->objectName() != "") {
        winner = m_buttons[2]->objectName();
        }
    if (winner != "") {
        QMessageBox::information(this, "Winner!", "Player " + winner + " has won!");

        for (QPushButton *button : m_buttons) {
            button->setIcon(QIcon());
            button->setObjectName("");
        }

        m_currentPlayer = Player1;
    }
    else {
        bool allButtonsUsed = true;
        for (QPushButton *button : m_buttons) {
            if (button->objectName() == "") {
                allButtonsUsed = false;
                break;
            }
        }
        if (allButtonsUsed) {
            QMessageBox::information(this, "Draw!", "The game is a draw.");
            for (QPushButton *button : m_buttons) {
                button->setIcon(QIcon());
                button->setObjectName("");
            }
            m_currentPlayer = Player1;
        }
    }
}
